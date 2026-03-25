#include "BlockSlot.h"
#include "Block.h"
#include <set>

BlockSlot::BlockSlot(){
  this->AllowTypes = {};
  this->ChildSlot = Block();
}

void BlockSlot::addAllow(CodeBlocks::BlockType blkType){this->AllowTypes.insert(blkType);}

void BlockSlot::rmAllow(CodeBlocks::BlockType blkType){this->AllowTypes.erase(blkType);}

bool BlockSlot::setChild(Block droppedBlock){
  if(this->isValid(droppedBlock)){                                                                      // ensure empty with '&& this->isEmpty()'?
    this->setChild(droppedBlock);
    return true;
  }

  return false;
}

void BlockSlot::rmChild(){
  this->AllowTypes.clear();
  this->ChildSlot = Block();
}

Block BlockSlot::getBlock(){return this->ChildSlot;}

bool BlockSlot::isEmpty(){return this->getBlock().getType() == CodeBlocks::BlockType::NONE;}            // **TODO** prob should make better check...

bool BlockSlot::isValid(Block droppedBlock){return isValid(droppedBlock.getType());}

bool BlockSlot::isValid(CodeBlocks::BlockType droppedType){return this->AllowTypes.count(droppedType);}
