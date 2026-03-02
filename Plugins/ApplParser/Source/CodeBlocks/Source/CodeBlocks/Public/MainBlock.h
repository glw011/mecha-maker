#pragma once

#include <string>
#include <vector>
#include "CodeBlocks.h"
#include "BlockSlot.h"
#include "LinkedList.h"

class MainBlock{
  public:
    MainBlock();
    bool insertBlockBefore(Block droppedBlock, BlockSlot blockRef);
    bool insertBlockAfter(Block droppedBlock, BlockSlot blockRef);
    bool insertBlock(Block droppedBlock);
    bool compileAndExecute(std::string* failMsgOut);
    
  private:
    int SlotCount;
    std::string SlotStr;
    std::string EndStr;
    std::string ProgramStr;
    LinkedList SlotList;
    std::vector<BlockSlot> Slots;
    std::string getProgramStr();
};
