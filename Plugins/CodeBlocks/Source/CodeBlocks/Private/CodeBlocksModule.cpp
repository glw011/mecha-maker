#include "CodeBlocks.h"
#include <unordered_map>
#include <string>
#include <array>

// populate mapping of ea type to an int defining total slots that type will have 
std::unordered_map<CodeBlocks::BlockType, int> CodeBlocks::SlotCountMap = {
  {BlockType::NONE, 1},
  {BlockType::MAIN, 1},
  {BlockType::ASSIGNMENT, 2},
  {BlockType::FUN_DEF, 2},
  {BlockType::WHILE_LOOP, 2},
  {BlockType::FOR_LOOP, 4},
  {BlockType::FOR_EA_LOOP, 3},
  {BlockType::IF_ELSE_STMT, 3},
  {BlockType::IF_STMT, 2},
  {BlockType::BINRY_EXPR, 3},
  {BlockType::UNARY_EXPR, 2},
  {BlockType::PRE_UNARY_EXPR, 2},
  {BlockType::OPERATOR, 1},
  {BlockType::OPERAND, 1},
  {BlockType::CONST_REF, 1},
  {BlockType::VAR_REF, 1},
  {BlockType::FUN_CALL, 1},
  {BlockType::RETURN_STMT, 2},
  {BlockType::ARG_LIST, 1},
  {BlockType::BSC_DATA_REF, 1},
  {BlockType::ARR_REF, 1},
};

std::unordered_map<CodeBlocks::BlockType, std::string> CodeBlocks::ContentStrMap = {
  {BlockType::NONE, ""},
  {BlockType::MAIN, "main(){"},
  {BlockType::ASSIGNMENT, "{idRefSlot} = {exprSlot};"},
  {BlockType::FUN_DEF, "def {idRefSlot}({paramListSlot}){cblkSlot}"},
  {BlockType::WHILE_LOOP, "while({condSlot}){cblkSlot}"},
  {BlockType::FOR_LOOP, "for({assignSlot} {condSlot} {exprSlot}){cblkSlot}"},
  {BlockType::FOR_EA_LOOP, "for each {idRefSlot} in {arrRefSlot}{cblkSlot}"},
  {BlockType::IF_ELSE_STMT, "if({condSlot}){cblkSlot} else {elsBlkSlot}"},
  {BlockType::IF_STMT, ""},
  {BlockType::BINRY_EXPR, "{lOprndSlot} {oprtrSlot} {rOprndSlot}"},
  {BlockType::UNARY_EXPR, "{idRefSlot}{oprtrSlot}"},
  {BlockType::PRE_UNARY_EXPR, "{oprtrSlot}{idRefSlot}"},
  {BlockType::OPERATOR, "{constRefSlot}"},
  {BlockType::OPERAND, "{exprSlot}"},
  {BlockType::CONST_REF, "{CONSTANT}"},
  {BlockType::VAR_REF, "{VARIABLE}"},
  {BlockType::FUN_CALL, "{idRefSlot}({argListSlot});"},
  {BlockType::RETURN_STMT, "return {exprSlot};"},
  {BlockType::ARG_LIST, ""},
  {BlockType::BSC_DATA_REF, "{DATA}"},
  {BlockType::ARR_REF, "[{arrayData}]"},
};

std::set<CodeBlocks::BlockType> CodeBlocks::SizedTypes = {
  BlockType::FUN_CALL,
  BlockType::FUN_DEF,
  BlockType::ARR_REF
};

std::unordered_map<CodeBlocks::BlockType, std::vector<std::string>> TypeVarsMap = {
};








