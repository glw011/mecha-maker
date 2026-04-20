#include "CodeBlocks.h"
#include <unordered_map>
#include <string>
#include <array>

std::unordered_map<CodeBlocks::BlockType, int> CodeBlocks::SlotCountMap = {
  {BlockType::NONE,           0},
  {BlockType::MAIN,           1},
  {BlockType::ASSIGN_BLK,     1},  // slot0=expr  (varName in userInputVals[0])
  {BlockType::FUNDEF_BLK,     3},  // slot0=funName, slot1=paramList, slot2=cblk
  {BlockType::FUNCALL_BLK,    1},  // slot0=funName  (+argCount dynamic slots)
  {BlockType::RETURN_BLK,     0},  // base=0 (return;), sized +1 (return expr;)
  {BlockType::WHILE_LOOP,     2},  // slot0=condRhs, slot1=cblk  (varName in userInputVals[0], condOp in userInputVals[1])
  {BlockType::FOR_LOOP,       3},  // slot0=initVal, slot1=condVal, slot2=cblk  (varName in [0], eqltyOp in [2], iterOp in [4])
  {BlockType::FOREA_LOOP,     3},  // not implemented
  {BlockType::IFELSE_BLK,     3},  // slot0=cond, slot1=cblk, slot2=elseSblk (optional)
  {BlockType::BINARYOP_BLK,   2},  // slot0=lhs, slot1=rhs  (operator in userInputVals[0])
  {BlockType::UNARYOP_BLK,    1},  // slot0=operand  (operator in [0], pre/post in [1])
  {BlockType::DATA_BLK,       0},  // no child slots — value in userInputVals[0]
  {BlockType::ARGLST_SBLK,    0},  // all slots dynamic (+argCount)
  {BlockType::ELSE_SBLK,      1},  // slot0=cblk
  {BlockType::CBLK_SBLK,      0},  // no fixed child slots — uses internal LinkedList (codeSeq)
  {BlockType::NSTEXPR_SBLK,   1},  // slot0=expr
  {BlockType::VAR_REF,        0},  // no child slots — name in userInputVals[0]
  {BlockType::ARR_BLK,        0},  // not implemented
  {BlockType::AUG_ASSIGN_BLK, 1},  // slot0=expr  (varName in userInputVals[0], augOp in userInputVals[1])
  {BlockType::INCR_BLK,       0},  // no slots — varName in userInputVals[0], iterOp in userInputVals[1]
  {BlockType::COMPFNCALL_BLK, 0},  // base=0 fixed slots; fnName in userInputVals[0], all arg slots dynamic (+argCount)
};

std::unordered_map<CodeBlocks::BlockType, std::string> CodeBlocks::ContentStrMap = {
  {BlockType::NONE, ""},
  {BlockType::MAIN, "main(){"},
  {BlockType::ASSIGN_BLK, "{varIdSlot} = {exprSlot};"},
  {BlockType::FUNDEF_BLK, "def {funIdSlot}({paramListSlot}){cblkSlot}"},
  {BlockType::FUNCALL_BLK, "{funRefSlot}({argListSlot});"},
  {BlockType::RETURN_BLK, "return {exprSlot};"},
  {BlockType::WHILE_LOOP, "while ({varName} {condOp} {condRhsSlot}){cblkSlot}"},
  {BlockType::FOR_LOOP, "for ({varName} = {initValSlot}; {varName} {eqltyOp} {condValSlot}; {varName}{iterOp}){cblkSlot}"},
  {BlockType::FOREA_LOOP, "for each {idRefSlot} in {arrIdRefSlot}{cblkSlot}"},
  {BlockType::IFELSE_BLK, "if ({condSlot}){cblkSlot}{elseSBlkSlot}"},
  {BlockType::BINARYOP_BLK, "{lhsSlot} {op} {rhsSlot}"},
  {BlockType::UNARYOP_BLK, "{op}{operandSlot}"},
  {BlockType::DATA_BLK, "{dataVal}"},
  {BlockType::ARGLST_SBLK, "({argsSlot})"},
  {BlockType::ELSE_SBLK, "{cblkSlot}"},  // "else" keyword prepended by IFELSE_BLK's code gen
  {BlockType::CBLK_SBLK, "{ {stmts} }"},
  {BlockType::NSTEXPR_SBLK, "({exprSlot})"},
  {BlockType::VAR_REF, "{varName}"},
  {BlockType::ARR_BLK, ""},
  {BlockType::AUG_ASSIGN_BLK, "{varRefSlot} {augOp} {exprSlot};"},
  {BlockType::INCR_BLK,       "{varName}{iterOp};"},
  {BlockType::COMPFNCALL_BLK, "{fnName}({args});"},
};

std::set<CodeBlocks::BlockType> CodeBlocks::SizedTypes = {
  BlockType::FUNCALL_BLK,
  BlockType::FUNDEF_BLK,
  BlockType::ARGLST_SBLK,
  BlockType::ARR_BLK,
  BlockType::RETURN_BLK,      // base=0 slots (void return), sized+1 = expr return
  BlockType::COMPFNCALL_BLK,  // base=0 slots; argCount=1 for duration-based fns, 0 for toggle fns
};
