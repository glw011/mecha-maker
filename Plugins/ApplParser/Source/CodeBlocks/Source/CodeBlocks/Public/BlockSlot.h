#pragma once

#include "Block.h"
#include "CodeBlocks.h"
#include <set>

class BlockSlot{
  public:
    BlockSlot();
    void addAllow(CodeBlocks::BlockType blkType);
    void rmAllow(CodeBlocks::BlockType blkType);
    bool setChild(Block droppedBlock);
    void rmChild();
    bool isEmpty();
    Block getBlock();

  private:
    Block ChildSlot;
    std::set<CodeBlocks::BlockType> AllowTypes;
    bool isValid(Block droppedBlock);
    bool isValid(CodeBlocks::BlockType droppedType);
};

