#include "Block.h"
#include "BlockSlot.h"
#include "CodeBlocks.h"
#include <string>
#include <format>
#include <unordered_map>


Block::Block() : id(++nxtId), argCount(0){
  this->BType = CodeBlocks::BlockType::NONE;
  this->SlotCount = CodeBlocks::SlotCountMap[BType];
  //this->ContentStr = "";
  this->Slots.resize(1);
}

Block::Block(CodeBlocks::BlockType blkType) : id(++nxtId), argCount(0){
  // construct if not a dynamic type requiring size parameter 
  if(!CodeBlocks::SizedTypes.contains(blkType)){
    this->BType = blkType;
    this->SlotCount = CodeBlocks::SlotCountMap[blkType];
    //this->ContentStr = CodeBlocks::ContentStrMap[blkType];
    this->Slots.resize(this->SlotCount);
    this->Slots.clear();
  }
}

Block::Block(CodeBlocks::BlockType blkType, int size) : id(++nxtId){
  // construct if dynamic type requiring size parameter 
  if(CodeBlocks::SizedTypes.contains(blkType)){
    this->BType = blkType;
    this->argCount = size;
    this->SlotCount = CodeBlocks::SlotCountMap[blkType] + size;
    //this->ContentStr = CodeBlocks::ContentStrMap[blkType];
    this->Slots.resize(this->SlotCount);
    this->Slots.clear(); 
  }
}

CodeBlocks::BlockType Block::getType(){return this->BType;}

std::string Block::getEmptySlots(){
  int emptySeen = 0;
  std::string missingSlots = "";
  for(int i=0; i<SlotCount; i++){
    if(Slots.at(i).isEmpty()){
      if(emptySeen++) missingSlots += ", ";
      missingSlots += "Slots["+i;
      missingSlots += "]";
    }
  }

  if(emptySeen) return missingSlots;
  return "NONE";
}

bool Block::validDynamSlotCount(){return this->SlotCount == (CodeBlocks::SlotCountMap[this->BType] + this->argCount);}

std::string Block::getContentStr(){
  std::string fContStr;

  // validate all blocks are completed (i.e. have no empty slots)
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
        this->Slots.at(0).getBlock().getContentStr(), 
        this->Slots.at(1).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::FUNDEF_BLK:
      fContStr = funDefContStr(
        this->Slots.at(0).getBlock().getContentStr(),
        this->Slots.at(1).getBlock().getContentStr(),
        this->Slots.at(2).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::WHILE_LOOP:
      fContStr = whileLoopContStr(
        this->Slots.at(0).getBlock().getContentStr(),
        this->Slots.at(1).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::FOR_LOOP:
      fContStr = forLoopContStr(
        this->Slots.at(0).getBlock().getContentStr(),
        this->Slots.at(1).getBlock().getContentStr(),
        this->Slots.at(2).getBlock().getContentStr(),
        this->Slots.at(3).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::FOREA_LOOP:
      fContStr = forEaLoopContStr(
        this->Slots.at(0).getBlock().getContentStr(),
        this->Slots.at(1).getBlock().getContentStr(),
        this->Slots.at(2).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::IFELSE_BLK:
      //{BlockType::IFELSE_BLK, " if({condSlot}){cblkSlot}{elseSBlkSlot} "}
      CodeBlocks::BlockType elseSBlkType = this->Slots.at(2).getBlock().getType();

      fContStr = ifElseStmtContStr(
        this->Slots.at(0).getBlock().getContentStr(),
        this->Slots.at(1).getBlock().getContentStr(),
        // pass empty string as elseSBlkSlot if block has no else block (i.e. Slots[2].BType is NONE)
        elseSBlkType == CodeBlocks::BlockType::NONE ? "" : this->Slots.at(2).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::ELSE_SBLK:
      fContStr = elseSBlkContStr(
        this->Slots.at(0).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::BINARYOP_BLK:
      fContStr = binaryOpContStr(
        this->Slots.at(0).getBlock().getContentStr(),
        this->Slots.at(1).getBlock().getContentStr(),
        this->Slots.at(2).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::UNARYOP_BLK:
      fContStr = unaryOpContStr(
        this->Slots.at(0).getBlock().getContentStr(),
        this->Slots.at(1).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::VAR_REF:
      fContStr = varRefContStr(
        this->Slots.at(0).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::FUNCALL_BLK:
      fContStr = funCallContStr(
        this->Slots.at(0).getBlock().getContentStr(),
        this->Slots.at(1).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::RETURN_BLK:
      fContStr = returnStmtContStr(
        this->Slots.at(0).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::DATA_BLK:
      fContStr = dataContStr(
        this->Slots.at(0).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::ARGLST_SBLK:
      fContStr = argListContStr(this->Slots, this->SlotCount);
      break;
    case CodeBlocks::BlockType::CBLK_SBLK:
      fContStr = cblkContStr(
        this->Slots.at(0).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::NSTEXPR_SBLK:
      fContStr = nestExprContStr(
        this->Slots.at(0).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::ARR_BLK:
      fContStr = arrRefContStr();
      break;
    default:
      fContStr = "ERROR: Reached Default Switch Case... blockId=" + this->id;
      // throw an exception too?
      break;
  };

  return fContStr;
}

void Block::setType(CodeBlocks::BlockType blkType){
  // set if not a dynamic type requiring size parameter  
  if(!CodeBlocks::SizedTypes.contains(blkType)){
    this->BType = blkType;
    this->SlotCount = CodeBlocks::SlotCountMap[blkType];
    //this->ContentStr = CodeBlocks::ContentStrMap[blkType];
    this->Slots.resize(this->SlotCount);
    this->Slots.clear();
  }
}

void Block::setType(CodeBlocks::BlockType blkType, int runtimeArgCount){
  this->BType = blkType;
  this->argCount = CodeBlocks::SizedTypes.contains(blkType) ? runtimeArgCount : 0;
  this->SlotCount = CodeBlocks::SlotCountMap[blkType];
  //this->ContentStr = CodeBlocks::ContentStrMap[blkType];
  this->Slots.resize(this->SlotCount);
  this->Slots.clear();
}

//void Block::setContentStr(std::string contStr){this->ContentStr = contStr;}

static std::string assignmentContStr(std::string idRefSlot, std::string exprSlot){
  // "{idRefSlot} = {exprSlot};"
  std::string fstr = stmtContStr(idRefSlot + " = " + exprSlot);
  return fstr;
}

static std::string funDefContStr(std::string funNameSlot, std::string paramListSlot, std::string cblkSlot){
  // "def {funNameSlot}{paramListSlot}{cblkSlot}"
  std::string fstr = "def " + funNameSlot + paramListSlot + cblkSlot;
  return fstr;
}

static std::string funCallContStr(std::string funNameRefSlot, std::string argListSlot){
  // "{funNameRefSlot}({argListSlot});"
  std::string fstr = stmtContStr(funNameRefSlot + argListSlot);
  return fstr;
}

static std::string whileLoopContStr(std::string condExprSlot, std::string cblkSlot){
  // "while({condExprSlot}){cblkSlot}"
  std::string fstr = "while " + nestExprContStr(condExprSlot) + cblkSlot;
  return fstr;
}

static std::string forLoopContStr(std::string assignStmtSlot, std::string condSlot, std::string exprSlot, std::string cblkSlot){
  // "for({assignStmtSlot}{condSlot}{exprSlot}){cblkSlot}"
  std::string fstr = "for " + nestExprContStr(assignStmtSlot + stmtContStr(condSlot) + exprSlot) + cblkSlot;
  return fstr;
}

static std::string forEaLoopContStr(std::string idRefSlot, std::string arrRefSlot, std::string cblkSlot){
  // "for each {idRefSlot} in {arrRefSlot}{cblkSlot}"
  std::string fstr = "for each " + idRefSlot + " in " + arrRefSlot + cblkSlot;
  return fstr;
}

static std::string ifElseStmtContStr(std::string condSlot, std::string ifCblkSlot, std::string elseSBlkSlot){
  // " if({condSlot}){cblkSlot}{elseSBlkSlot} "}
  std::string fstr = "if " + nestExprContStr(condSlot) + ifCblkSlot + elseSBlkSlot;
  return fstr;
}

static std::string binaryOpContStr(std::string lOprndSlot, std::string oprtrSlot, std::string rOprndSlot){
  // "{lOprndSlot} {oprtrSlot} {rOprndSlot}"
  std::string fstr = lOprndSlot + oprtrSlot + rOprndSlot;
  return fstr;
}

static std::string unaryOpContStr(std::string leftSlot, std::string rightSlot){
  // "{idRefSlot}{oprtrSlot}"
  std::string fstr = leftSlot + rightSlot;
  return fstr;
}

static std::string varRefContStr(std::string varName){
  // NOT NEEDED "{VARNAME}"
}

static std::string returnStmtContStr(std::string exprSlot){
  // "return {exprSlot};"
}

static std::string dataContStr(std::string dataVal){
  // "{DATAVAL}"
}

static std::string arrRefContStr(){
  // NOT IMPLEMENTED "[{arrayData}]"
}

static std::string argListContStr(std::vector<BlockSlot> args, int totlArgs){
  std::string fstr = "(";

  for(int i=0; i<totlArgs;){
    fstr += args.at(i).getBlock().getContentStr();
    if(!args.at(++i).isEmpty()){fstr += ", ";}
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
