#pragma once

#include <string>
#include <vector>
#include <atomic>
#include "CodeBlocks.h"
#include "BlockSlot.h"

class Block{
  public:
    Block();
    Block(CodeBlocks::BlockType blkType);
    Block(CodeBlocks::BlockType blkType, int size);

    void setType(CodeBlocks::BlockType blkType);
    void setType(CodeBlocks::BlockType blkType, int runtimeSize);  // construct for dynamic sized types (fun def/call & arrays)
    std::string getContentStr();
    CodeBlocks::BlockType getType();
    int getId();
    
  private:
    int id, argCount, SlotCount;
    CodeBlocks::BlockType BType;
    std::vector<BlockSlot> Slots;
    
    bool Block::validDynamSlotCount();
    std::string Block::getEmptySlots();
    
    static std::atomic<int> nxtId;

    static std::string assignmentContStr(std::string idRefSlot, std::string exprSlot);
    static std::string funDefContStr(std::string idRefSlot, std::string paramListSlot, std::string cblkSlot);
    static std::string funCallContStr(std::string idRefSlot, std::string argListSlot);
    static std::string whileLoopContStr(std::string condSlot, std::string cblkSlot);
    static std::string forLoopContStr(std::string assignSlot, std::string condSlot, std::string exprSlot, std::string cblkSlot);
    static std::string forEaLoopContStr(std::string idRefSlot, std::string arrRefSlot, std::string cblkSlot);
    static std::string ifElseStmtContStr(std::string condSlot, std::string ifCblkSlot, std::string elsCblkSlot);
    static std::string binaryOpContStr(std::string lOprndSlot, std::string oprtrSlot, std::string rOprndSlot);
    static std::string unaryOpContStr(std::string leftSlot, std::string rightSlot);
    static std::string varRefContStr(std::string varName);
    static std::string returnStmtContStr(std::string exprSlot);
    static std::string dataContStr(std::string dataVal);
    static std::string nestExprContStr(std::string contStr);
    static std::string elseSBlkContStr(std::string contStr);
    static std::string cblkContStr(std::string contStr);
    static std::string argListContStr(std::vector<BlockSlot> args, int totlArgs);
    // NOT IMPLEMENTED YET vvv
    static std::string arrRefContStr();
};


