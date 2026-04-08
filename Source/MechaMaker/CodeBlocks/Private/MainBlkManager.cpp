#include "MainBlkManager.h"
#include "Block.h"

BlockManager& BlockManager::getInstance(){
  static BlockManager instance;
  return instance;
}

BlockManager::BlockManager() : nextId(0), mainBlock() {}

// --- Private helpers ---

int BlockManager::registerNewBlock(CodeBlocks::BlockType blkType){
  int id = ++nextId;
  blockRegistry[id] = std::make_unique<Block>(blkType);
  return id;
}

int BlockManager::registerNewSizedBlock(CodeBlocks::BlockType blkType, int argCount){
  int id = ++nextId;
  blockRegistry[id] = std::make_unique<Block>(blkType, argCount);
  return id;
}

// --- Public API ---

int BlockManager::newBlockInArea(CodeBlocks::BlockType blkType){
  int id = registerNewBlock(blkType);
  if(id < 0) return -1;
  mainBlock.insertBlock(blockRegistry[id].get());
  return id;
}

int BlockManager::newBlockInSlot(CodeBlocks::BlockType blkType, int parentId, int slotPos){
  if(!blockRegistry.count(parentId)) return -1;
  int id = registerNewBlock(blkType);
  Block* parent = blockRegistry[parentId].get();
  BlockSlot* slot = parent->getSlot(slotPos);
  if(!slot) return -1;
  slot->setChild(blockRegistry[id].get());
  return id;
}

int BlockManager::newSizedBlockInArea(CodeBlocks::BlockType blkType, int argCount){
  int id = registerNewSizedBlock(blkType, argCount);
  if(id < 0) return -1;
  mainBlock.insertBlock(blockRegistry[id].get());
  return id;
}

int BlockManager::newSizedBlockInSlot(CodeBlocks::BlockType blkType, int argCount, int parentId, int slotPos){
  if(!blockRegistry.count(parentId)) return -1;
  int id = registerNewSizedBlock(blkType, argCount);
  Block* parent = blockRegistry[parentId].get();
  BlockSlot* slot = parent->getSlot(slotPos);
  if(!slot) return -1;
  slot->setChild(blockRegistry[id].get());
  return id;
}

bool BlockManager::moveBlockToSlot(int blockId, int newParentId, int newSlotPos, int oldParentId, int oldSlotPos){
  if(!blockRegistry.count(blockId)) return false;
  if(!blockRegistry.count(newParentId)) return false;

  // clear old parent slot (if block came from a slot, not the program area)
  if(oldParentId >= 0 && blockRegistry.count(oldParentId)){
    BlockSlot* oldSlot = blockRegistry[oldParentId]->getSlot(oldSlotPos);
    if(oldSlot) oldSlot->rmChild();
  }

  Block* newParent = blockRegistry[newParentId].get();
  BlockSlot* newSlot = newParent->getSlot(newSlotPos);
  if(!newSlot) return false;
  return newSlot->setChild(blockRegistry[blockId].get());
}

bool BlockManager::moveBlockToArea(int blockId, int oldParentId, int oldSlotPos){
  if(!blockRegistry.count(blockId)) return false;

  // clear old parent slot (if block came from a slot, not the program area)
  if(oldParentId >= 0 && blockRegistry.count(oldParentId)){
    BlockSlot* oldSlot = blockRegistry[oldParentId]->getSlot(oldSlotPos);
    if(oldSlot) oldSlot->rmChild();
  }

  return mainBlock.insertBlock(blockRegistry[blockId].get());
}

bool BlockManager::reorderInArea(int blockId, int referenceBlockId, bool insertBefore){
  return mainBlock.reorderBlock(blockId, referenceBlockId, insertBefore);
}

bool BlockManager::removeBlock(int blockId){
  if(!blockRegistry.count(blockId)) return false;

  // attempt to remove from program area (no-op if block is nested inside another block)
  mainBlock.removeBlock(blockId);

  // remove from registry — this frees the Block
  blockRegistry.erase(blockId);
  return true;
}

void BlockManager::setUserInput(int blockId, int slotPos, std::string inputStr){
  if(!blockRegistry.count(blockId)) return;
  blockRegistry[blockId]->setUserInput(slotPos, inputStr);
}

std::string BlockManager::getUserInput(int blockId, int slotPos){
  if(!blockRegistry.count(blockId)) return "";
  return blockRegistry[blockId]->getUserInput(slotPos);
}

std::string BlockManager::getProgramString(){
  std::string failMsg;
  std::string progStr;
  bool success = mainBlock.compileProgram(&failMsg, &progStr);

  if(success){
    return progStr;
  }

  return failMsg;
}
