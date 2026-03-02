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
    int id, argCount;
    static std::atomic<int> nxtId;
    void setContentStr(std::string contStr);
    std::string Block::getEmptySlots();
    CodeBlocks::BlockType BType;
    std::string ContentStr;
    int SlotCount;
    std::vector<BlockSlot> Slots;

    std::unordered_map<std::string, std::string> VarMap;
    static std::string assignmentContStr(std::string idRefSlot, std::string exprSlot);
    static std::string funDefContStr(std::string idRefSlot, std::string paramListSlot, std::string cblkSlot);
    static std::string funCallContStr(std::string idRefSlot, std::string argListSlot);
    static std::string whileLoopContStr(std::string condSlot, std::string cblkSlot);
    static std::string forLoopContStr(std::string assignSlot, std::string condSlot, std::string exprSlot, std::string cblkSlot);
    static std::string forEaLoopContStr(std::string idRefSlot, std::string arrRefSlot, std::string cblkSlot);
    static std::string ifStmtContStr(std::string condSlot, std::string cblkSlot);
    static std::string ifElseStmtContStr(std::string condSlot, std::string ifCblkSlot, std::string elsCblkSlot);
    static std::string binaryExprContStr(std::string lOprndSlot, std::string oprtrSlot, std::string rOprndSlot);
    static std::string unaryExprContStr(std::string idRefSlot, std::string oprtrSlot);
    static std::string preUnaryExprContStr(std::string oprtrSlot, std::string idRefSlot);
    static std::string operatorContStr(std::string constRefSlot);
    static std::string operandContStr(std::string exprSlot);
    static std::string constRefContStr(std::string constName);
    static std::string varRefContStr(std::string varName);
    static std::string returnStmtContStr(std::string exprSlot);
    static std::string bscDataRefContStr(std::string dataVal);
    // NOT YET vvv
    static std::string arrRefContStr();
    static std::string argListContStr();
};


