#include "MainBlock.h"
#include "Block.h"
#include "BlockSlot.h"
#include "CodeBlocks.h"
#include <string>
#include <format>
#include <vector>

MainBlock::MainBlock(){
  EndStr = " $$__ENDMAIN__$$";
  this->isCompiled = false;
  this->ProgramStr = "";
  this->SlotCount = 0;
  this->SlotList = LinkedList();
}

void MainBlock::clear(){
  SlotList.clearList();
  SlotCount = 0;
  isCompiled = false;
  ProgramStr = "";
}

bool MainBlock::insertBlock(Block* droppedBlock){
  if(isCompiled){
    this->isCompiled = false;
    this->ProgramStr = "";
  }

  BlockSlot* newSlot = new BlockSlot();
  newSlot->setChild(droppedBlock);
  SlotList.append(newSlot);
  this->SlotCount++;
  return true;
}

bool MainBlock::insertBlockBefore(Block* droppedBlock, BlockSlot* blockRef){
  if(isCompiled){ isCompiled = false; ProgramStr = ""; }
  BlockSlot* newSlot = new BlockSlot();
  newSlot->setChild(droppedBlock);
  if(SlotList.insertBefore(newSlot, blockRef)){
    this->SlotCount++;
    return true;
  }
  delete newSlot;
  return false;
}

bool MainBlock::insertBlockAfter(Block* droppedBlock, BlockSlot* blockRef){
  if(isCompiled){ isCompiled = false; ProgramStr = ""; }
  BlockSlot* newSlot = new BlockSlot();
  newSlot->setChild(droppedBlock);
  if(SlotList.insertAfter(newSlot, blockRef)){
    this->SlotCount++;
    return true;
  }
  delete newSlot;
  return false;
}

BlockSlot* MainBlock::findSlotByBlockId(int blockId){
  std::vector<BlockSlot*> slots = SlotList.getAsArray();
  for(BlockSlot* slot : slots){
    if(slot && !slot->isEmpty() && slot->getBlock()->getId() == blockId){
      return slot;
    }
  }
  return nullptr;
}

bool MainBlock::removeBlock(int blockId){
  BlockSlot* slot = findSlotByBlockId(blockId);
  if(!slot) return false;
  if(isCompiled){ isCompiled = false; ProgramStr = ""; }
  if(SlotList.remove(slot)){
    this->SlotCount--;
    return true;
  }
  return false;
}

bool MainBlock::reorderBlock(int blockId, int referenceBlockId, bool insertBefore){
  BlockSlot* targetSlot = findSlotByBlockId(blockId);
  BlockSlot* refSlot = findSlotByBlockId(referenceBlockId);
  if(!targetSlot || !refSlot || targetSlot == refSlot) return false;

  if(isCompiled){ isCompiled = false; ProgramStr = ""; }

  // get the block pointer before removing the slot (slot owns nothing, block still in registry)
  Block* blk = targetSlot->getBlock();

  // remove target slot from list (this deletes the Node and the BlockSlot)
  if(!SlotList.remove(targetSlot)) return false;
  this->SlotCount--;

  // reinsert relative to reference; refSlot pointer is still valid (not affected by removal)
  BlockSlot* newSlot = new BlockSlot();
  newSlot->setChild(blk);
  bool ok = insertBefore ? SlotList.insertBefore(newSlot, refSlot)
                         : SlotList.insertAfter(newSlot, refSlot);
  if(ok){
    this->SlotCount++;
    return true;
  }
  delete newSlot;
  return false;
}

bool MainBlock::compileProgram(std::string* failMsgOut, std::string* progStrOut){
  if(!isCompiled){
    isCompiled = compileMainBlock(failMsgOut);
  }

  if(isCompiled){
    *progStrOut = this->ProgramStr;
    return true;
  }

  return false;
}

bool MainBlock::compileMainBlock(std::string* failMsgOut){
  this->ProgramStr = "";
  std::string bodyStr = "";
  std::vector<BlockSlot*> slotArr = SlotList.getAsArray();

  try{
    for(int i = 0; i < (int)slotArr.size(); i++){
      bodyStr += slotArr.at(i)->getBlock()->getContentStr();
    }
    bodyStr += EndStr;
    this->ProgramStr = bodyStr;
    isCompiled = true;
  }
  catch(...){
    *failMsgOut = "Unknown Error: Compile was not successful";
    isCompiled = false;
  }

  return isCompiled;
}

std::string MainBlock::getProgramStr(){return this->ProgramStr;}
