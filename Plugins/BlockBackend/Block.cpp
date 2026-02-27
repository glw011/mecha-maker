#include "Block.h"
#include "BlockSlot.h"
#include "CodeBlocks.h"
#include <string>
#include <format>
#include <unordered_map>


Block::Block() : id(++nxtId){
  this->BType = CodeBlocks::BlockType::NONE;
  this->SlotCount = CodeBlocks::SlotCountMap[BType];
  this->ContentStr = "";
  this->Slots.resize(1);
  this->argCount = 0;
}

Block::Block(CodeBlocks::BlockType blkType) : id(++nxtId){
  // construct if not a dynamic type requiring size parameter 
  if(!CodeBlocks::SizedTypes.contains(blkType)){
    this->BType = blkType;
    this->SlotCount = CodeBlocks::SlotCountMap[blkType];
    this->ContentStr = CodeBlocks::ContentStrMap[blkType];
    this->Slots.resize(this->SlotCount);
    this->Slots.clear();
  }
}

Block::Block(CodeBlocks::BlockType blkType, int size) : id(++nxtId){
  // construct if dynamic type requiring size parameter 
  if(CodeBlocks::SizedTypes.contains(blkType)){
    this->BType = blkType;

    // array's SlotCount is user indicated array size 
    if(blkType == CodeBlocks::BlockType::ARR_REF){this->SlotCount = size;}
    // functions have static slots plus user defined num of params 
    else{
      this->argCount = size;
      this->SlotCount = CodeBlocks::SlotCountMap[blkType] + size;
    }

    this->ContentStr = CodeBlocks::ContentStrMap[blkType];
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

std::string Block::getContentStr(){
  std::string fContStr;

  // perform slot count safety check
  if(CodeBlocks::SizedTypes.contains(this->BType)){
    // validate correctnumber of slots for dynamic size blocks
    if(this->SlotCount != (CodeBlocks::SlotCountMap[this->BType] + this->argCount)){
      fContStr = CodeBlocks::TypeNames[this->BType] + ("(id=" + this->id);
      fContStr += ") Bad SlotCount: argCount=" + this->argCount;
      fContStr += ", SlotCount=" + this->SlotCount;
      fContStr += ", Expected=" + (CodeBlocks::SlotCountMap[this->BType] + this->argCount);
      return fContStr;
    }
  }
  else{
    // validate correctnumber of slots for static size blocks
    if(this->SlotCount != CodeBlocks::SlotCountMap[this->BType]){
      fContStr = CodeBlocks::TypeNames[this->BType] + ("(id=" + this->id);
      fContStr += ") Bad SlotCount: SlotCount=" + this->SlotCount;
      fContStr += ", Expected=" + (CodeBlocks::SlotCountMap[this->BType]);
      return fContStr;
    }
  }

  // validate all blocks are completed (i.e. have no empty slots)
  std::string missing = this->getEmptySlots();
  if(missing != "NONE"){
    fContStr = CodeBlocks::TypeNames[this->BType] + ("(id=" + this->id);
    fContStr += ") Missing: " + missing;
    return fContStr;
  }

  // assemble/get formatted content str according to block type
  switch(this->BType){
    case CodeBlocks::BlockType::ASSIGNMENT:
      // "{idRefSlot} = {exprSlot};"
      fContStr = assignmentContStr(
        this->Slots.at(0).getBlock().getContentStr(), 
        this->Slots.at(1).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::FUN_DEF:
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
    case CodeBlocks::BlockType::FOR_EA_LOOP:
      fContStr = forEaLoopContStr(
        this->Slots.at(0).getBlock().getContentStr(),
        this->Slots.at(1).getBlock().getContentStr(),
        this->Slots.at(2).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::IF_ELSE_STMT:
      CodeBlocks::BlockType elsBType = this->Slots.at(0).getBlock().getType();

      // format text as 'if(..){...} else if(...){...}' when 'ifStmt' or 'ifElseStmt' nested within else cblk
      if(elsBType == CodeBlocks::BlockType::IF_ELSE_STMT || elsBType == CodeBlocks::BlockType::IF_STMT){
        fContStr = ifElseStmtContStr(
          this->Slots.at(0).getBlock().getContentStr(),
          this->Slots.at(1).getBlock().getContentStr(),
          this->Slots.at(2).getBlock().getContentStr()
        );
      }
      // otherwise: wrap as '{' + cblk + '}'
      else{
          fContStr = ifElseStmtContStr(
          this->Slots.at(0).getBlock().getContentStr(),
          this->Slots.at(1).getBlock().getContentStr(),
          cblkContStr(this->Slots.at(2).getBlock().getContentStr())
        );
      }
      break;
    case CodeBlocks::BlockType::IF_STMT:
      fContStr = ifStmtContStr(
        this->Slots.at(0).getBlock().getContentStr(),
        this->Slots.at(1).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::BINRY_EXPR:
      fContStr = binaryExprContStr(
        this->Slots.at(0).getBlock().getContentStr(),
        this->Slots.at(1).getBlock().getContentStr(),
        this->Slots.at(2).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::UNARY_EXPR:
      fContStr = unaryExprContStr(
        this->Slots.at(0).getBlock().getContentStr(),
        this->Slots.at(1).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::PRE_UNARY_EXPR:
      fContStr = preUnaryExprContStr(
        this->Slots.at(0).getBlock().getContentStr(),
        this->Slots.at(1).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::OPERATOR:
      fContStr = operatorContStr(
        this->Slots.at(0).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::OPERAND:
      fContStr = operandContStr(
        this->Slots.at(0).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::CONST_REF:
      fContStr = constRefContStr(
        this->Slots.at(0).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::VAR_REF:
      fContStr = varRefContStr(
        this->Slots.at(0).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::FUN_CALL:
      fContStr = funCallContStr(
        this->Slots.at(0).getBlock().getContentStr(),
        this->Slots.at(1).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::RETURN_STMT:
      fContStr = returnStmtContStr(
        this->Slots.at(0).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::BSC_DATA_REF:
      fContStr = bscDataRefContStr(
        this->Slots.at(0).getBlock().getContentStr()
      );
      break;
    case CodeBlocks::BlockType::ARG_LIST:
      fContStr = argListContStr();
      break;
    case CodeBlocks::BlockType::ARR_REF:
      fContStr = arrRefContStr();
      break;
    default:
      fContStr = "ERROR: Block Reached Switch Default Case... blockId=" + this->id;
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
    this->ContentStr = CodeBlocks::ContentStrMap[blkType];
    this->Slots.resize(this->SlotCount);
    this->Slots.clear();
  }
}

void Block::setType(CodeBlocks::BlockType blkType, int runtimeSize){
  // set if not a dynamic type requiring size parameter  
  if(!CodeBlocks::SizedTypes.contains(blkType)){
    this->BType = blkType;
    this->SlotCount = CodeBlocks::SlotCountMap[blkType];
    this->ContentStr = CodeBlocks::ContentStrMap[blkType];
    this->Slots.resize(this->SlotCount);
    this->Slots.clear();
  }
}

void Block::setContentStr(std::string contStr){this->ContentStr = contStr;}

std::string Block::assignmentContStr(std::string idRefSlot, std::string exprSlot){
  // "{idRefSlot} = {exprSlot};"
  std::string fstr = idRefSlot + " = " + exprSlot;
  return fstr;
}

std::string Block::funDefContStr(std::string idRefSlot, std::string paramListSlot, std::string cblkSlot){
  // "def {idRefSlot}({paramListSlot}){cblkSlot}"
  std::string fstr = "def " + idRefSlot + "(" + paramListSlot + ")" + cblkSlot;
  return fstr;
}

std::string Block::funCallContStr(std::string idRefSlot, std::string argListSlot){
  // "{idRefSlot}({argListSlot});"
  std::string fstr = idRefSlot + "(" + argListSlot + ")";
  return fstr;
}

std::string Block::whileLoopContStr(std::string condSlot, std::string cblkSlot){
  // "while({condSlot}){cblkSlot}"
  std::string fstr = "while(" + condSlot + "){" + cblkSlot + "}";
  return fstr;
}

std::string Block::forLoopContStr(std::string assignSlot, std::string condSlot, std::string exprSlot, std::string cblkSlot){
  // "for({assignSlot}{condSlot}{exprSlot}){cblkSlot}"
  std::string fstr = "for(" + stmtContStr(assignSlot) + " " + stmtContStr(condSlot) + exprSlot + ")" + cblkContStr(cblkSlot);
  return fstr;
}

std::string Block::forEaLoopContStr(std::string idRefSlot, std::string arrRefSlot, std::string cblkSlot){
  // "for each {idRefSlot} in {arrRefSlot}{cblkSlot}"
  std::string fstr = "for each " + idRefSlot + " in " + arrRefSlot + cblkContStr(cblkSlot);
  return fstr;
}

std::string Block::ifStmtContStr(std::string condSlot, std::string cblkSlot){
  // "if({condSlot}){cblkSlot}"
  std::string fstr = "if(" + condSlot + ")" + cblkContStr(cblkSlot);
  return fstr;
}

std::string Block::ifElseStmtContStr(std::string condSlot, std::string ifCblkSlot, std::string elsCblkSlot){
  // "if({condSlot}){ifCblkSlot}else{elsCblkSlot}"
  std::string fstr = "if(" + condSlot + ")" + cblkContStr(ifCblkSlot) + "else " + elsCblkSlot;
  return fstr;
}

std::string Block::binaryExprContStr(std::string lOprndSlot, std::string oprtrSlot, std::string rOprndSlot){
  // "{lOprndSlot} {oprtrSlot} {rOprndSlot}"
  std::string fstr = lOprndSlot + oprtrSlot + rOprndSlot;
  return fstr;
}

std::string Block::unaryExprContStr(std::string idRefSlot, std::string oprtrSlot){
  // "{idRefSlot}{oprtrSlot}"
  std::string fstr = idRefSlot + oprtrSlot;
  return fstr;
}

std::string Block::preUnaryExprContStr(std::string oprtrSlot, std::string idRefSlot){
  // "{oprtrSlot}{idRefSlot}"
  std::string fstr = oprtrSlot + idRefSlot;
  return fstr;
}

std::string Block::operatorContStr(std::string constRefSlot){
  // NOT NEEDED "{constRefSlot}"
}

std::string Block::operandContStr(std::string exprSlot){
  // NOT NEEDED "{exprSlot}"
}

std::string Block::constRefContStr(std::string constName){
  // NOT NEEDED "{CONSTNAME}"
}

std::string Block::varRefContStr(std::string varName){
  // NOT NEEDED "{VARNAME}"
}

std::string Block::returnStmtContStr(std::string exprSlot){
  // "return {exprSlot};"
}

std::string Block::bscDataRefContStr(std::string dataVal){
  // "{DATAVAL}"
}

std::string Block::arrRefContStr(){
  // NOT IMPLEMENTED "[{arrayData}]"
}

std::string Block::argListContStr(){
  // NOT IMPLEMENTED ""
}

static std::string stmtContStr(std::string contStr){
  return (contStr + ";");
}

static std::string cblkContStr(std::string contStr){
  return "{" + contStr + "}";
}


// exprSlot = "(" + {expr} + ")";
// cblkSlot = "{" + {expr} + "}";
// NEED CONSTBLOCK
