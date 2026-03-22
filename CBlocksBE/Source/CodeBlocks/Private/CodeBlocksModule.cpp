#include "CodeBlocks.h"
#include <unordered_map>
#include <string>
#include <array>

// populate mapping of ea type to an int defining total slots that type will have 
std::unordered_map<CodeBlocks::BlockType, int> CodeBlocks::SlotCountMap = {
  {BlockType::NONE, 0},
  {BlockType::MAIN, 1},
  {BlockType::ASSIGN_BLK, 2},
  {BlockType::FUNDEF_BLK, 2},
  {BlockType::FUNCALL_BLK, 1},
  {BlockType::RETURN_BLK, 2},
  {BlockType::WHILE_LOOP, 2},
  {BlockType::FOR_LOOP, 4},
  {BlockType::FOREA_LOOP, 3},
  {BlockType::IFELSE_BLK, 3},
  {BlockType::BINARYOP_BLK, 3},
  {BlockType::UNARYOP_BLK, 2},

  {BlockType::DATA_BLK, 1},
  //{BlockType::PARLST_SBLK, 0},
  {BlockType::ARGLST_SBLK, 0},
  {BlockType::ELSE_SBLK, 1},
  {BlockType::CBLK_SBLK, 1},  // handle special case (use linked list since variable size?)
  {BlockType::NSTEXPR_SBLK, 1},
  {BlockType::VAR_REF, 1},
  {BlockType::ARR_BLK, 0}
};

std::unordered_map<CodeBlocks::BlockType, std::string> CodeBlocks::ContentStrMap = {
  {BlockType::NONE, ""},
  {BlockType::MAIN, "main(){"},
  {BlockType::ASSIGN_BLK, " {varIdSlot} ={exprSlot};"},
  {BlockType::FUNDEF_BLK, " def {funIdSlot}({paramListSlot}){cblkSlot}"},
  {BlockType::FUNCALL_BLK, " {funRefSlot}({argListSlot});"},
  {BlockType::RETURN_BLK, " return{exprSlot};"},
  {BlockType::WHILE_LOOP, " while ({boolExprSlot}){cblkSlot}"},
  {BlockType::FOR_LOOP, " for ({lclVarIdSlot}{boolExprSlot}{iterExprSlot}){cblkSlot}"},
  {BlockType::FOREA_LOOP, " for each {idRefSlot} in {arrIdRefSlot}{cblkSlot}"},
  {BlockType::IFELSE_BLK, " if ({boolExprSlot}){cblkSlot}{elseSBlkSlot}"},
  {BlockType::BINARYOP_BLK, " {lOprndSlot}{oprtrSlot}{rOprndSlot}"},
  {BlockType::UNARYOP_BLK, " {leftSlot}{rightSlot}"},

  {BlockType::DATA_BLK, " {dataSlot}"},
  //{BlockType::PARLST_SBLK, " ({paramListSlot}) "},
  {BlockType::ARGLST_SBLK, " ( {argsListSlot} )"},
  {BlockType::ELSE_SBLK, ""},
  {BlockType::CBLK_SBLK, " \{ {codeSlot} \}"}, 
  {BlockType::NSTEXPR_SBLK, " ( {exprSlot} )"},
  {BlockType::VAR_REF, " {varnameSlot}"},
  {BlockType::ARR_BLK, ""},
};

std::set<CodeBlocks::BlockType> CodeBlocks::SizedTypes = {
  BlockType::FUNCALL_BLK,
  BlockType::FUNDEF_BLK,
  //BlockType::PARLST_SBLK,
  BlockType::ARGLST_SBLK,
  BlockType::ARR_BLK,
};







