#include "Block.h"
#include "BlockSlot.h"
#include "CodeBlocks.h"
#include <string>
#include <format>
#include <unordered_map>

// static member definition (must appear in exactly one .cpp)
std::atomic<int> Block::nxtId(0);

// file-scope helper declarations
static std::string assignmentContStr(std::string idRefSlot, std::string exprSlot);
static std::string augAssignContStr(std::string varRefSlot, std::string augOp, std::string exprSlot);
static std::string funDefContStr(std::string funNameSlot, std::string paramListSlot, std::string cblkSlot);
static std::string funCallContStr(std::string funNameRefSlot, std::string argListSlot);
static std::string whileLoopContStr(std::string condExprSlot, std::string cblkSlot);
static std::string forLoopContStr(std::string assignStmtSlot, std::string condSlot, std::string iterSlot, std::string cblkSlot);
static std::string forEaLoopContStr(std::string idRefSlot, std::string arrRefSlot, std::string cblkSlot);
static std::string ifElseStmtContStr(std::string condSlot, std::string ifCblkSlot, std::string elseSBlkSlot);
static std::string binaryOpContStr(std::string lhsSlot, std::string op, std::string rhsSlot);
static std::string unaryOpContStr(std::string op, std::string operandSlot, bool isPrefix);
static std::string varRefContStr(std::string varName);
static std::string returnStmtContStr(std::string exprSlot);
static std::string dataContStr(std::string dataVal);
static std::string arrRefContStr();
static std::string argListContStr(std::vector<BlockSlot>& args, int totlArgs);
static std::string stmtContStr(std::string contStr);
static std::string cblkContStr(std::string contStr);
static std::string nestExprContStr(std::string contStr);
static std::string elseSBlkContStr(std::string contStr);


// ---- Constructors / Destructor ----

Block::Block() : id(++nxtId), argCount(0), SlotCount(0), codeSeq(nullptr){
  this->BType = CodeBlocks::BlockType::NONE;
  this->SlotCount = CodeBlocks::SlotCountMap[BType];
  this->Slots.resize(this->SlotCount);
  this->userInputVals.resize(this->SlotCount, "");
}

Block::Block(CodeBlocks::BlockType blkType) : id(++nxtId), argCount(0), codeSeq(nullptr){
  if(CodeBlocks::SizedTypes.count(blkType) == 0){
    this->BType = blkType;
    this->SlotCount = CodeBlocks::SlotCountMap[blkType];
    this->Slots.resize(this->SlotCount);
    this->userInputVals.resize(this->SlotCount, "");
    if(blkType == CodeBlocks::BlockType::CBLK_SBLK) codeSeq = new LinkedList();
  }
}

Block::Block(CodeBlocks::BlockType blkType, int size) : id(++nxtId), codeSeq(nullptr){
  if(CodeBlocks::SizedTypes.count(blkType) > 0){
    this->BType = blkType;
    this->argCount = size;
    this->SlotCount = CodeBlocks::SlotCountMap[blkType] + size;
    this->Slots.resize(this->SlotCount);
    this->userInputVals.resize(this->SlotCount, "");
  }
}

Block::~Block(){
  if(codeSeq){ delete codeSeq; codeSeq = nullptr; }
}

// ---- Accessors ----

int Block::getId(){return this->id;}
CodeBlocks::BlockType Block::getType(){return this->BType;}

BlockSlot* Block::getSlot(int slotPos){
  if(slotPos < 0 || slotPos >= SlotCount) return nullptr;
  return &this->Slots.at(slotPos);
}

void Block::setUserInput(int slotPos, std::string val){
  if(slotPos >= 0 && slotPos < (int)userInputVals.size()) userInputVals[slotPos] = val;
}

std::string Block::getUserInput(int slotPos){
  if(slotPos >= 0 && slotPos < (int)userInputVals.size()) return userInputVals[slotPos];
  return "";
}

// ---- codeSeq operations (CBLK_SBLK only) ----

bool Block::appendToCodeSeq(Block* block){
  if(!codeSeq || BType != CodeBlocks::BlockType::CBLK_SBLK) return false;
  BlockSlot* newSlot = new BlockSlot();
  newSlot->setChild(block);
  codeSeq->append(newSlot);
  return true;
}

bool Block::removeFromCodeSeq(int blockId){
  if(!codeSeq) return false;
  for(BlockSlot* slot : codeSeq->getAsArray()){
    if(slot && !slot->isEmpty() && slot->getBlock()->getId() == blockId){
      return codeSeq->remove(slot);
    }
  }
  return false;
}

bool Block::reorderInCodeSeq(int blockId, int refId, bool before){
  // TODO: implement reordering within a code block sequence
  return false;
}

std::string Block::getCodeSeqStr(){
  if(!codeSeq || codeSeq->isEmpty()) return "";
  std::string body;
  for(BlockSlot* slot : codeSeq->getAsArray()){
    if(slot && !slot->isEmpty()) body += slot->getBlock()->getContentStr();
  }
  return body;
}

// ---- Internal helpers ----

std::string Block::getEmptySlots(){
  int emptySeen = 0;
  std::string missingSlots;
  for(int i = 0; i < SlotCount; i++){
    // slot2 of IFELSE_BLK is optional (the else branch) — exclude from empty check
    if(BType == CodeBlocks::BlockType::IFELSE_BLK && i == 2) continue;
    if(Slots.at(i).isEmpty()){
      if(emptySeen++) missingSlots += ", ";
      missingSlots += "Slots[" + std::to_string(i) + "]";
    }
  }
  return emptySeen ? missingSlots : "NONE";
}

bool Block::validDynamSlotCount(){return this->SlotCount == (CodeBlocks::SlotCountMap[this->BType] + this->argCount);}

// ---- getContentStr ----

std::string Block::getContentStr(){
  // Leaf types: value comes from userInputVals, no child block slots
  if(BType == CodeBlocks::BlockType::VAR_REF)
    return varRefContStr(userInputVals.empty() ? "" : userInputVals[0]);
  if(BType == CodeBlocks::BlockType::DATA_BLK)
    return dataContStr(userInputVals.empty() ? "" : userInputVals[0]);

  // Sequence container: content comes from the internal codeSeq LinkedList
  if(BType == CodeBlocks::BlockType::CBLK_SBLK)
    return cblkContStr(getCodeSeqStr());

  // Void return: no expression slot
  if(BType == CodeBlocks::BlockType::RETURN_BLK && SlotCount == 0)
    return "return; ";

  // Validate all required slots are filled
  std::string missing = getEmptySlots();
  if(missing != "NONE"){
    std::string typeName = CodeBlocks::TypeNames[static_cast<int>(BType)];
    return typeName + "(id=" + std::to_string(id) + ") Missing: " + missing;
  }

  std::string fContStr;
  switch(BType){
    case CodeBlocks::BlockType::ASSIGN_BLK:
      fContStr = assignmentContStr(Slots[0].getBlock()->getContentStr(), Slots[1].getBlock()->getContentStr());
      break;

    case CodeBlocks::BlockType::AUG_ASSIGN_BLK:
      fContStr = augAssignContStr(
        Slots[0].getBlock()->getContentStr(),
        userInputVals.empty() ? "+=" : userInputVals[0],
        Slots[1].getBlock()->getContentStr()
      );
      break;

    case CodeBlocks::BlockType::FUNDEF_BLK:
      fContStr = funDefContStr(Slots[0].getBlock()->getContentStr(), Slots[1].getBlock()->getContentStr(), Slots[2].getBlock()->getContentStr());
      break;

    case CodeBlocks::BlockType::WHILE_LOOP:
      fContStr = whileLoopContStr(Slots[0].getBlock()->getContentStr(), Slots[1].getBlock()->getContentStr());
      break;

    case CodeBlocks::BlockType::FOR_LOOP:
      fContStr = forLoopContStr(Slots[0].getBlock()->getContentStr(), Slots[1].getBlock()->getContentStr(), Slots[2].getBlock()->getContentStr(), Slots[3].getBlock()->getContentStr());
      break;

    case CodeBlocks::BlockType::FOREA_LOOP:
      fContStr = forEaLoopContStr(Slots[0].getBlock()->getContentStr(), Slots[1].getBlock()->getContentStr(), Slots[2].getBlock()->getContentStr());
      break;

    case CodeBlocks::BlockType::IFELSE_BLK:{
      bool hasElse = !Slots[2].isEmpty();
      fContStr = ifElseStmtContStr(
        Slots[0].getBlock()->getContentStr(),
        Slots[1].getBlock()->getContentStr(),
        hasElse ? Slots[2].getBlock()->getContentStr() : ""
      );
      break;
    }

    case CodeBlocks::BlockType::ELSE_SBLK:
      fContStr = elseSBlkContStr(Slots[0].getBlock()->getContentStr());
      break;

    case CodeBlocks::BlockType::BINARYOP_BLK:
      fContStr = binaryOpContStr(
        Slots[0].getBlock()->getContentStr(),
        userInputVals.empty() ? "" : userInputVals[0],
        Slots[1].getBlock()->getContentStr()
      );
      break;

    case CodeBlocks::BlockType::UNARYOP_BLK:{
      bool isPrefix = userInputVals.size() < 2 || userInputVals[1] != "post";
      fContStr = unaryOpContStr(
        userInputVals.empty() ? "" : userInputVals[0],
        Slots[0].getBlock()->getContentStr(),
        isPrefix
      );
      break;
    }

    case CodeBlocks::BlockType::FUNCALL_BLK:
      fContStr = funCallContStr(Slots[0].getBlock()->getContentStr(), Slots[1].getBlock()->getContentStr());
      break;

    case CodeBlocks::BlockType::RETURN_BLK:
      fContStr = returnStmtContStr(Slots[0].getBlock()->getContentStr());
      break;

    case CodeBlocks::BlockType::ARGLST_SBLK:
      fContStr = argListContStr(Slots, SlotCount);
      break;

    case CodeBlocks::BlockType::NSTEXPR_SBLK:
      fContStr = nestExprContStr(Slots[0].getBlock()->getContentStr());
      break;

    case CodeBlocks::BlockType::ARR_BLK:
      fContStr = arrRefContStr();
      break;

    default:
      fContStr = "ERROR: Unhandled block type, id=" + std::to_string(id);
      break;
  }
  return fContStr;
}

// ---- setType ----

void Block::setType(CodeBlocks::BlockType blkType){
  if(CodeBlocks::SizedTypes.count(blkType) == 0){
    BType = blkType;
    SlotCount = CodeBlocks::SlotCountMap[blkType];
    Slots.resize(SlotCount);
    userInputVals.resize(SlotCount, "");
    if(blkType == CodeBlocks::BlockType::CBLK_SBLK && !codeSeq) codeSeq = new LinkedList();
  }
}

void Block::setType(CodeBlocks::BlockType blkType, int runtimeArgCount){
  BType = blkType;
  argCount = CodeBlocks::SizedTypes.count(blkType) > 0 ? runtimeArgCount : 0;
  SlotCount = CodeBlocks::SlotCountMap[blkType] + argCount;
  Slots.resize(SlotCount);
  userInputVals.resize(SlotCount, "");
}

// ---- String builder helpers ----

static std::string assignmentContStr(std::string idRefSlot, std::string exprSlot){
  return stmtContStr(idRefSlot + " = " + exprSlot);
}

static std::string augAssignContStr(std::string varRefSlot, std::string augOp, std::string exprSlot){
  return stmtContStr(varRefSlot + " " + augOp + " " + exprSlot);
}

static std::string funDefContStr(std::string funNameSlot, std::string paramListSlot, std::string cblkSlot){
  return "def " + funNameSlot + paramListSlot + cblkSlot;
}

static std::string funCallContStr(std::string funNameRefSlot, std::string argListSlot){
  return stmtContStr(funNameRefSlot + argListSlot);
}

static std::string whileLoopContStr(std::string condExprSlot, std::string cblkSlot){
  return "while " + nestExprContStr(condExprSlot) + cblkSlot;
}

static std::string forLoopContStr(std::string assignStmtSlot, std::string condSlot, std::string iterSlot, std::string cblkSlot){
  return "for " + nestExprContStr(assignStmtSlot + stmtContStr(condSlot) + iterSlot) + cblkSlot;
}

static std::string forEaLoopContStr(std::string idRefSlot, std::string arrRefSlot, std::string cblkSlot){
  return "for each " + idRefSlot + " in " + arrRefSlot + cblkSlot;
}

static std::string ifElseStmtContStr(std::string condSlot, std::string ifCblkSlot, std::string elseSBlkSlot){
  return "if " + nestExprContStr(condSlot) + ifCblkSlot + elseSBlkSlot;
}

static std::string binaryOpContStr(std::string lhsSlot, std::string op, std::string rhsSlot){
  return lhsSlot + " " + op + " " + rhsSlot;
}

static std::string unaryOpContStr(std::string op, std::string operandSlot, bool isPrefix){
  return isPrefix ? op + operandSlot : operandSlot + op;
}

static std::string varRefContStr(std::string varName){return varName;}
static std::string returnStmtContStr(std::string exprSlot){return stmtContStr("return " + exprSlot);}
static std::string dataContStr(std::string dataVal){return dataVal;}
static std::string arrRefContStr(){return "[]";}  // not implemented

static std::string argListContStr(std::vector<BlockSlot>& args, int totlArgs){
  std::string fstr = "(";
  for(int i = 0; i < totlArgs; i++){
    if(i > 0) fstr += ", ";
    fstr += args.at(i).getBlock()->getContentStr();
  }
  return fstr + ") ";
}

static std::string stmtContStr(std::string contStr){return contStr + "; ";}
static std::string cblkContStr(std::string contStr){return " {" + contStr + "} ";}
static std::string nestExprContStr(std::string contStr){return " (" + contStr + ") ";}
static std::string elseSBlkContStr(std::string contStr){return " else " + contStr;}
