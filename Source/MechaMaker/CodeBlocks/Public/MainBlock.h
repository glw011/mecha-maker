#pragma once

#include <string>
#include <vector>
#include "CodeBlocks.h"
#include "BlockSlot.h"
#include "LinkedList.h"

class MainBlock{
  public:
    MainBlock();
    void clear();  // wipes all top-level slots (called by BlockManager::reset())
    bool insertBlock(Block* droppedBlock);
    bool insertBlockBefore(Block* droppedBlock, BlockSlot* blockRef);
    bool insertBlockAfter(Block* droppedBlock, BlockSlot* blockRef);
    bool removeBlock(int blockId);
    bool reorderBlock(int blockId, int referenceBlockId, bool insertBefore);
    bool compileProgram(std::string* failMsgOut, std::string* progStrOut);
    std::string getProgramStr();

  private:
    bool isCompiled;
    int SlotCount;
    std::string EndStr;
    std::string ProgramStr;
    LinkedList SlotList;
    BlockSlot* findSlotByBlockId(int blockId);
    bool compileMainBlock(std::string* failMsgOut);
};

