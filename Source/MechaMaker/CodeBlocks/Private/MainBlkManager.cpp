#include "MainBlkManager.h"
#include "Block.h"

BlockManager& BlockManager::getInstance(){
  static BlockManager instance;
  return instance;
}

BlockManager::BlockManager() : nextId(0), mainBlock() {}

// --- Private Helper Functions ---

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

  // clear old location
  // IDs start at 1 (++nextId), so oldParentId > 0 means a real block slot origin
  if(oldParentId > 0 && blockRegistry.count(oldParentId)){
    BlockSlot* oldSlot = blockRegistry[oldParentId]->getSlot(oldSlotPos);
    if(oldSlot) oldSlot->rmChild();
  } 
  else{
    // came from the main program area — safe no-op if block isn't there
    mainBlock.removeBlock(blockId);
  }

  Block* newParent = blockRegistry[newParentId].get();
  BlockSlot* newSlot = newParent->getSlot(newSlotPos);
  if(!newSlot) return false;
  return newSlot->setChild(blockRegistry[blockId].get());
}

bool BlockManager::moveBlockToArea(int blockId, int oldParentId, int oldSlotPos){
  if(!blockRegistry.count(blockId)) return false;

  // IDs start at 1, so oldParentId > 0 means a real block slot origin
  if(oldParentId > 0 && blockRegistry.count(oldParentId)){
    BlockSlot* oldSlot = blockRegistry[oldParentId]->getSlot(oldSlotPos);
    if(oldSlot) oldSlot->rmChild();
  }

  return mainBlock.insertBlock(blockRegistry[blockId].get());
}

bool BlockManager::moveBlockToEndOfArea(int blockId){
  if(!blockRegistry.count(blockId)) return false;
  Block* blk = blockRegistry[blockId].get();
  mainBlock.removeBlock(blockId);    // detach from current position (no-op if not in area)
  return mainBlock.insertBlock(blk); // append to tail
}

bool BlockManager::reorderInArea(int blockId, int referenceBlockId, bool insertBefore){
  return mainBlock.reorderBlock(blockId, referenceBlockId, insertBefore);
}

void BlockManager::reset(){
  blockRegistry.clear();    // clears all block instances (frees ea unique_ptr)
  mainBlock.clear();        // clears main LinkedList top-level slots
  nextId = 0;               // registry key counter
  Block::resetIdCounter();  // block internal id counter — must stay in sync with nextId
}

bool BlockManager::removeBlock(int blockId){
  if(!blockRegistry.count(blockId)) return false;

  // remove from top-level program area (no-op if block nested inside another block)
  mainBlock.removeBlock(blockId);

  // clear any raw BlockSlot pointers in other blocks that reference this block —
  // prevents dangling pointer access if a child was removed independently of its parent
  Block* dying = blockRegistry[blockId].get();
  for(auto& [id, blk] : blockRegistry){
    if(id == blockId) continue;
    int n = blk->getSlotCount();
    for(int i = 0; i < n; i++){
      BlockSlot* s = blk->getSlot(i);
      if(s && !s->isEmpty() && s->getBlock() == dying) s->rmChild();
    }
  }

  // remove from registry and free block instance
  blockRegistry.erase(blockId);
  return true;
}

// ----------------------------------------------------------------
// Sequential code blocks (CBLK_SBLK/CodeAreaSlot embedded in block)
// ----------------------------------------------------------------

int BlockManager::newBlockInCodeBlock(CodeBlocks::BlockType blkType, int cblkId){
  if(!blockRegistry.count(cblkId)) return -1;
  int id = registerNewBlock(blkType);
  blockRegistry[cblkId]->appendToCodeSeq(blockRegistry[id].get());
  return id;
}

int BlockManager::newSizedBlockInCodeBlock(CodeBlocks::BlockType blkType, int argCount, int cblkId){
  if(!blockRegistry.count(cblkId)) return -1;
  int id = registerNewSizedBlock(blkType, argCount);
  blockRegistry[cblkId]->appendToCodeSeq(blockRegistry[id].get());
  return id;
}

bool BlockManager::moveBlockToCodeBlock(int blockId, int cblkId, int oldCblkId, int oldParentId, int oldSlotPos){
  if(!blockRegistry.count(blockId) || !blockRegistry.count(cblkId)) return false;

  // clear origin (IDs start at 1, so ID > 0 => real block origin)
  if(oldCblkId > 0 && blockRegistry.count(oldCblkId)){
    blockRegistry[oldCblkId]->removeFromCodeSeq(blockId);
  } 
  else if(oldParentId > 0 && blockRegistry.count(oldParentId)){
    BlockSlot* oldSlot = blockRegistry[oldParentId]->getSlot(oldSlotPos);
    if(oldSlot) oldSlot->rmChild();
  } 
  else{
    // came from the main program area (safe no-op if block not there)
    mainBlock.removeBlock(blockId);
  }

  return blockRegistry[cblkId]->appendToCodeSeq(blockRegistry[blockId].get());
}

bool BlockManager::removeBlockFromCodeBlock(int blockId, int cblkId){
  if(!blockRegistry.count(cblkId)) return false;
  return blockRegistry[cblkId]->removeFromCodeSeq(blockId);
}

bool BlockManager::reorderInCodeBlock(int blockId, int refBlockId, int cblkId, bool insertBefore){
  if(!blockRegistry.count(cblkId)) return false;
  return blockRegistry[cblkId]->reorderInCodeSeq(blockId, refBlockId, insertBefore);
}

void BlockManager::setUserInput(int blockId, int slotPos, std::string inputStr){
  if(!blockRegistry.count(blockId)) return;
  blockRegistry[blockId]->setUserInput(slotPos, inputStr);
  mainBlock.invalidateCache();
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
