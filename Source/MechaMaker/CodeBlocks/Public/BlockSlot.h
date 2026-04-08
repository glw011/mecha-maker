#pragma once

#include "CodeBlocks.h"
#include <set>

class Block;

class BlockSlot{
  public:
    BlockSlot();
    ~BlockSlot();
    void addAllow(CodeBlocks::BlockType blkType);
    void rmAllow(CodeBlocks::BlockType blkType);
    bool setChild(Block* droppedBlock);
    void rmChild();
    bool isEmpty();
    Block* getBlock();

  private:
    Block* ChildSlot;  // non-owning; BlockManager's registry is the sole owner
    std::set<CodeBlocks::BlockType> AllowTypes;
    bool isValid(Block* droppedBlock);
    bool isValid(CodeBlocks::BlockType droppedType);
};

