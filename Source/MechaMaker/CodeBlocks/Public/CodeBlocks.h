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
      NONE,           // 0
      MAIN,           // 1
      ASSIGN_BLK,     // 2  --> x = expr;
      FUNDEF_BLK,     // 3  --> def f(params) { body } (skipped for now)
      FUNCALL_BLK,    // 4  --> f(args);
      RETURN_BLK,     // 5  --> return; / return expr; (sized: base=0, +1 for expr)
      WHILE_LOOP,     // 6  --> while (cond) { body }
      FOR_LOOP,       // 7  --> for (init; cond; iter) { body }
      FOREA_LOOP,     // 8  --> NOT IMPLEMENTED
      IFELSE_BLK,     // 9  --> if (cond) { body } [else { body }]  **(slot2 is OPTIONAL)
      BINARYOP_BLK,   // 10 --> lhs op rhs  **(op stored in userInputVals[0])
      UNARYOP_BLK,    // 11 --> "pre": op operand / "post": operand op  **(op always in [0], pre/post always in [1])
      DATA_BLK,       // 12 --> literal value **(stored in userInputVals[0])
      ARGLST_SBLK,    // 13 --> (arg0, arg1, ...) **(sized block)
      ELSE_SBLK,      // 14 --> else { body }
      CBLK_SBLK,      // 15 --> { stmt* }  **(sequential container using LinkedList)
      NSTEXPR_SBLK,   // 16 --> ( expr )
      VAR_REF,        // 17 --> variable identifier  **(stored in userInputVals[0])
      ARR_BLK,        // 18 --> NOT IMPLEMENTED
      AUG_ASSIGN_BLK, // 19 --> x += expr;  **(varName: userInputVals[0], augOp: userInputVals[1])
      INCR_BLK        // 20 --> x++; / x--;  **(varName: userInputVals[0], iterOp: userInputVals[1])
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
      "ArrayBlock",
      "AugAssignBlock",
      "IncrementBlock"
    };

    // basic data types supported
    enum class BasicDataType{
      BOOLN,
      INTGR,
      FLOAT
    };

    // derived data types supported (maybe in future?)
    enum class DerivDataType{
      ARRAY
    };

    extern std::unordered_map<BlockType, int> SlotCountMap;
    extern std::unordered_map<BlockType, std::string> ContentStrMap;
    extern std::set<BlockType> SizedTypes;
  }

#endif
