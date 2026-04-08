#include "Block.h"
#include "BlockSlot.h"
#include "CodeBlocks.h"
#include <string>
#include <format>
#include <unordered_map>

std::atomic<int> Block::nxtId(0);

// file-scope helper declarations (defined at bottom of file)
static std::string assignmentContStr(std::string idRefSlot, std::string exprSlot);
static std::string funDefContStr(std::string funNameSlot, std::string paramListSlot, std::string cblkSlot);
static std::string funCallContStr(std::string funNameRefSlot, std::string argListSlot);
static std::string whileLoopContStr(std::string condExprSlot, std::string cblkSlot);
static std::string forLoopContStr(std::string assignStmtSlot, std::string condSlot, std::string exprSlot, std::string cblkSlot);
static std::string forEaLoopContStr(std::string idRefSlot, std::string arrRefSlot, std::string cblkSlot);
static std::string ifElseStmtContStr(std::string condSlot, std::string ifCblkSlot, std::string elseSBlkSlot);
static std::string binaryOpContStr(std::string lOprndSlot, std::string oprtrSlot, std::string rOprndSlot);
static std::string unaryOpContStr(std::string leftSlot, std::string rightSlot);
static std::string varRefContStr(std::string varName);
static std::string returnStmtContStr(std::string exprSlot);
static std::string dataContStr(std::string dataVal);
static std::string arrRefContStr();
static std::string argListContStr(std::vector<BlockSlot>& args, int totlArgs);
static std::string stmtContStr(std::string contStr);
static std::string cblkContStr(std::string contStr);
static std::string nestExprContStr(std::string contStr);
static std::string elseSBlkContStr(std::string contStr);


Block::Block() : id(++nxtId), argCount(0), SlotCount(0){
  this->BType = CodeBlocks::BlockType::NONE;
  this->SlotCount = CodeBlocks::SlotCountMap[BType];
  this->Slots.resize(this->SlotCount);
  this->userInputVals.resize(this->SlotCount, "");
}

Block::Block(CodeBlocks::BlockType blkType) : id(++nxtId), argCount(0){
  // construct if not a dynamic type requiring size parameter
  if(!CodeBlocks::SizedTypes.contains(blkType)){
    this->BType = blkType;
    this->SlotCount = CodeBlocks::SlotCountMap[blkType];
    this->Slots.resize(this->SlotCount);
    this->userInputVals.resize(this->SlotCount, "");
  }
}

Block::Block(CodeBlocks::BlockType blkType, int size) : id(++nxtId){
  // construct if dynamic type requiring size parameter
  if(CodeBlocks::SizedTypes.contains(blkType)){
    this->BType = blkType;
    this->argCount = size;
    this->SlotCount = CodeBlocks::SlotCountMap[blkType] + size;
    this->Slots.resize(this->SlotCount);
    this->userInputVals.resize(this->SlotCount, "");
  }
}

int Block::getId(){return this->id;}

CodeBlocks::BlockType Block::getType(){return this->BType;}

BlockSlot* Block::getSlot(int slotPos){
  if(slotPos < 0 || slotPos >= SlotCount){return nullptr;}
  return &this->Slots.at(slotPos);
}

void Block::setUserInput(int slotPos, std::string val){
  if(slotPos >= 0 && slotPos < (int)userInputVals.size()) userInputVals[slotPos] = val;
}

std::string Block::getUserInput(int slotPos){
  if(slotPos >= 0 && slotPos < (int)userInputVals.size()) return userInputVals[slotPos];
  return "";
}

std::string Block::getEmptySlots(){
  int emptySeen = 0;
  std::string missingSlots = "";
  for(int i=0; i<SlotCount; i++){
    if(Slots.at(i).isEmpty()){
      if(emptySeen++) missingSlots += ", ";
      missingSlots += "Slots[" + std::to_string(i) + "]";
    }
  }

  if(emptySeen) return missingSlots;
  return "NONE";
}

bool Block::validDynamSlotCount(){return this->SlotCount == (CodeBlocks::SlotCountMap[this->BType] + this->argCount);}

std::string Block::getContentStr(){
  std::string fContStr;

  // VAR_REF and DATA_BLK read directly from userInputVals — no child slots needed
  if(this->BType == CodeBlocks::BlockType::VAR_REF){
    return varRefContStr(userInputVals[0]);
  }
  if(this->BType == CodeBlocks::BlockType::DATA_BLK){
    return dataContStr(userInputVals[0]);
  }

  // validate all slots are filled before building string
  std::string missing = this->getEmptySlots();
  if(missing != "NONE"){
    std::string typeName = CodeBlocks::TypeNames[static_cast<int>(this->BType)];
    fContStr = typeName + "(id=" + std::to_string(this->id) + ") Missing: " + missing;
    return fContStr;
  }

  // assemble/get formatted content str according to block type
  switch(this->BType){
    case CodeBlocks::BlockType::ASSIGN_BLK:
      // "{idRefSlot} = {exprSlot};"
      fContStr = assignmentContStr(
        this->Slots[0].getBlock()->getContentStr(),
        this->Slots.at(1).getBlock()->getContentStr()
      );
      break;
    case CodeBlocks::BlockType::FUNDEF_BLK:
      fContStr = funDefContStr(
        this->Slots.at(0).getBlock()->getContentStr(),
        this->Slots.at(1).getBlock()->getContentStr(),
        this->Slots.at(2).getBlock()->getContentStr()
      );
      break;
    case CodeBlocks::BlockType::WHILE_LOOP:
      fContStr = whileLoopContStr(
        this->Slots.at(0).getBlock()->getContentStr(),
        this->Slots.at(1).getBlock()->getContentStr()
      );
      break;
    case CodeBlocks::BlockType::FOR_LOOP:
      fContStr = forLoopContStr(
        this->Slots.at(0).getBlock()->getContentStr(),
        this->Slots.at(1).getBlock()->getContentStr(),
        this->Slots.at(2).getBlock()->getContentStr(),
        this->Slots.at(3).getBlock()->getContentStr()
      );
      break;
    case CodeBlocks::BlockType::FOREA_LOOP:
      fContStr = forEaLoopContStr(
        this->Slots.at(0).getBlock()->getContentStr(),
        this->Slots.at(1).getBlock()->getContentStr(),
        this->Slots.at(2).getBlock()->getContentStr()
      );
      break;
    case CodeBlocks::BlockType::IFELSE_BLK:{
      CodeBlocks::BlockType elseSBlkType = this->Slots.at(2).getBlock()->getType();
      fContStr = ifElseStmtContStr(
        this->Slots.at(0).getBlock()->getContentStr(),
        this->Slots.at(1).getBlock()->getContentStr(),
        // pass empty string as elseSBlkSlot if block has no else block (i.e. Slots[2].BType is NONE)
        elseSBlkType == CodeBlocks::BlockType::NONE ? "" : this->Slots.at(2).getBlock()->getContentStr()
      );
      break;
    }
    case CodeBlocks::BlockType::ELSE_SBLK:
      fContStr = elseSBlkContStr(
        this->Slots.at(0).getBlock()->getContentStr()
      );
      break;
    case CodeBlocks::BlockType::BINARYOP_BLK:
      fContStr = binaryOpContStr(
        this->Slots.at(0).getBlock()->getContentStr(),
        this->Slots.at(1).getBlock()->getContentStr(),
        this->Slots.at(2).getBlock()->getContentStr()
      );
      break;
    case CodeBlocks::BlockType::UNARYOP_BLK:
      fContStr = unaryOpContStr(
        this->Slots.at(0).getBlock()->getContentStr(),
        this->Slots.at(1).getBlock()->getContentStr()
      );
      break;
    case CodeBlocks::BlockType::FUNCALL_BLK:
      fContStr = funCallContStr(
        this->Slots.at(0).getBlock()->getContentStr(),
        this->Slots.at(1).getBlock()->getContentStr()
      );
      break;
    case CodeBlocks::BlockType::RETURN_BLK:
      fContStr = returnStmtContStr(
        this->Slots.at(0).getBlock()->getContentStr()
      );
      break;
    case CodeBlocks::BlockType::ARGLST_SBLK:
      fContStr = argListContStr(this->Slots, this->SlotCount);
      break;
    case CodeBlocks::BlockType::CBLK_SBLK:
      fContStr = cblkContStr(
        this->Slots.at(0).getBlock()->getContentStr()
      );
      break;
    case CodeBlocks::BlockType::NSTEXPR_SBLK:
      fContStr = nestExprContStr(
        this->Slots.at(0).getBlock()->getContentStr()
      );
      break;
    case CodeBlocks::BlockType::ARR_BLK:
      fContStr = arrRefContStr();  // not implemented
      break;
    default:
      fContStr = "ERROR: Reached Default Switch Case... blockId=" + std::to_string(this->id);
      break;
  };

  return fContStr;
}

void Block::setType(CodeBlocks::BlockType blkType){
  // set if not a dynamic type requiring size parameter
  if(!CodeBlocks::SizedTypes.contains(blkType)){
    this->BType = blkType;
    this->SlotCount = CodeBlocks::SlotCountMap[blkType];
    this->Slots.resize(this->SlotCount);
    this->userInputVals.resize(this->SlotCount, "");
  }
}

void Block::setType(CodeBlocks::BlockType blkType, int runtimeArgCount){
  this->BType = blkType;
  this->argCount = CodeBlocks::SizedTypes.contains(blkType) ? runtimeArgCount : 0;
  this->SlotCount = CodeBlocks::SlotCountMap[blkType];
  this->Slots.resize(this->SlotCount);
  this->userInputVals.resize(this->SlotCount, "");
}

// --- File-scope string builder helpers ---

static std::string assignmentContStr(std::string idRefSlot, std::string exprSlot){
  // "{idRefSlot} = {exprSlot};"
  return stmtContStr(idRefSlot + " = " + exprSlot);
}

static std::string funDefContStr(std::string funNameSlot, std::string paramListSlot, std::string cblkSlot){
  // "def {funNameSlot}{paramListSlot}{cblkSlot}"
  return "def " + funNameSlot + paramListSlot + cblkSlot;
}

static std::string funCallContStr(std::string funNameRefSlot, std::string argListSlot){
  // "{funNameRefSlot}({argListSlot});"
  return stmtContStr(funNameRefSlot + argListSlot);
}

static std::string whileLoopContStr(std::string condExprSlot, std::string cblkSlot){
  // "while ({condExprSlot}){cblkSlot}"
  return "while " + nestExprContStr(condExprSlot) + cblkSlot;
}

static std::string forLoopContStr(std::string assignStmtSlot, std::string condSlot, std::string exprSlot, std::string cblkSlot){
  // "for ({assignStmtSlot}{condSlot}{exprSlot}){cblkSlot}"
  return "for " + nestExprContStr(assignStmtSlot + stmtContStr(condSlot) + exprSlot) + cblkSlot;
}

static std::string forEaLoopContStr(std::string idRefSlot, std::string arrRefSlot, std::string cblkSlot){
  // "for each {idRefSlot} in {arrRefSlot}{cblkSlot}"
  return "for each " + idRefSlot + " in " + arrRefSlot + cblkSlot;
}

static std::string ifElseStmtContStr(std::string condSlot, std::string ifCblkSlot, std::string elseSBlkSlot){
  // "if ({condSlot}){cblkSlot}{elseSBlkSlot}"
  return "if " + nestExprContStr(condSlot) + ifCblkSlot + elseSBlkSlot;
}

static std::string binaryOpContStr(std::string lOprndSlot, std::string oprtrSlot, std::string rOprndSlot){
  // "{lOprndSlot} {oprtrSlot} {rOprndSlot}"
  return lOprndSlot + oprtrSlot + rOprndSlot;
}

static std::string unaryOpContStr(std::string leftSlot, std::string rightSlot){
  // "{leftSlot}{rightSlot}"
  return leftSlot + rightSlot;
}

static std::string varRefContStr(std::string varName){
  return varName;
}

static std::string returnStmtContStr(std::string exprSlot){
  // "return {exprSlot};"
  return stmtContStr("return " + exprSlot);
}

static std::string dataContStr(std::string dataVal){
  return dataVal;
}

static std::string arrRefContStr(){
  // NOT IMPLEMENTED "[{arrayData}]"
  return "[]";
}

static std::string argListContStr(std::vector<BlockSlot>& args, int totlArgs){
  std::string fstr = "(";
  for(int i = 0; i < totlArgs; i++){
    if(i > 0) fstr += ", ";
    fstr += args.at(i).getBlock()->getContentStr();
  }
  return fstr + ") ";
}

static std::string stmtContStr(std::string contStr){
  return contStr + "; ";
}

static std::string cblkContStr(std::string contStr){
  return " {" + contStr + "} ";
}

static std::string nestExprContStr(std::string contStr){
  return " (" + contStr + ") ";
}

static std::string elseSBlkContStr(std::string contStr){
  return " else " + contStr;
}
