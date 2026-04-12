#include "BlockSlot.h"
#include "Block.h"
#include <set>

BlockSlot::BlockSlot() : ChildSlot(nullptr), AllowTypes({}) {}

BlockSlot::~BlockSlot() {}  // BlockManager's registry owns all Block instances

void BlockSlot::addAllow(CodeBlocks::BlockType blkType){this->AllowTypes.insert(blkType);}

void BlockSlot::rmAllow(CodeBlocks::BlockType blkType){this->AllowTypes.erase(blkType);}

bool BlockSlot::setChild(Block* droppedBlock){
  if(this->isValid(droppedBlock)){
    this->ChildSlot = droppedBlock;
    return true;
  }
  return false;
}

void BlockSlot::rmChild(){
  // clear occupying block only but do NOT clear AllowTypes
  this->ChildSlot = nullptr;
}

Block* BlockSlot::getBlock(){return ChildSlot;}

bool BlockSlot::isEmpty(){return this->ChildSlot == nullptr;}

bool BlockSlot::isValid(Block* droppedBlock){return isValid(droppedBlock->getType());}

bool BlockSlot::isValid(CodeBlocks::BlockType droppedType){
  // empty AllowTypes means "allow all block types" and bypasses type validation until type restrictions configured
  if(this->AllowTypes.empty()) return true;
  return this->AllowTypes.count(droppedType) > 0;
}
