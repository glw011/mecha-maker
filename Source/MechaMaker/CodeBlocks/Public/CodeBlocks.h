#pragma once

#include <unordered_map>
#include <string>
#include <set>
#include <array>
#include <vector>

#ifndef CODE_BLOCKS
  #define CODE_BLOCKS

  // shared codeblock enums needed by plugin 
  namespace CodeBlocks{

    // DO NOT CHANGE ORDERING, MUST MATCH ORDER IN 'TypeNames'
    enum class BlockType{
      NONE,
      MAIN,
      ASSIGN_BLK,
      FUNDEF_BLK,
      FUNCALL_BLK,
      RETURN_BLK,
      WHILE_LOOP,
      FOR_LOOP,
      FOREA_LOOP,  // not implemented
      IFELSE_BLK,  
      BINARYOP_BLK,
      UNARYOP_BLK,
      DATA_BLK,
      ARGLST_SBLK,
      ELSE_SBLK,
      CBLK_SBLK,
      NSTEXPR_SBLK,
      VAR_REF,
      ARR_BLK  // not implemented
    };

    static std::array TypeNames = {
      "NONE",
      "MainBlock",
      "AssignBlock",
      "FunDefBlock",
      "FunCallBlock",
      "ReturnBlock",
      "WhileLoopBlock",
      "ForLoopBlock",
      "ForEaLoopBlock",
      "IfElseStmtBlock",
      "BinaryOpBlock",
      "UnaryOpBlock",
      "DataBlock",
      "ArgListSBlock",
      "ElseSBlock",
      "CblkSBlock",
      "NestedExprSBlock",
      "VarRefBlock",
      "ArrayBlock"
    };

    // basic data types supported 
    enum class BasicDataType{
      BOOLN,
      INTGR,
      FLOAT
    };

    // derived data types supported (maybe in future) 
    enum class DerivDataType{
      ARRAY
    };

    extern std::unordered_map<BlockType, int> SlotCountMap;
    extern std::unordered_map<BlockType, std::string> ContentStrMap;
    extern std::set<BlockType> SizedTypes;
  }

#endif