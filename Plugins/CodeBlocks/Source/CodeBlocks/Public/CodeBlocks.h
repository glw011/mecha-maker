#include <unordered_map>
#include <string>
#include <set>
#include <array>
#include <vector>

#ifndef CODE_BLOCKS
  #define CODE_BLOCKS

  // shared codeblock enums needed by Appl plugin 
  namespace CodeBlocks{

    // DO NOT CHANGE ORDERING, MUST MATCH ORDER IN 'TypeNames'
    enum class BlockType{
      NONE,
      MAIN,
      ASSIGNMENT,
      FUN_DEF,
      WHILE_LOOP,
      FOR_LOOP,
      FOR_EA_LOOP,
      IF_ELSE_STMT,
      IF_STMT,
      BINRY_EXPR,
      UNARY_EXPR,       
      PRE_UNARY_EXPR,
      OPERATOR,
      OPERAND,
      CONST_REF,
      VAR_REF,
      FUN_CALL,
      RETURN_STMT,
      ARG_LIST,
      BSC_DATA_REF,
      ARR_REF
    };

    static std::array TypeNames = {
      "NONE", 
      "MainBlock", 
      "AssignBlock",
      "FunDefBlock",
      "WhileLoopBlock",
      "ForLoopBlock",
      "ForEaLoopBlock",
      "IfElseStmtBlock",
      "IfStmtBlock",
      "BinaryExprBlock",
      "UnaryExprBlock",
      "UnaryExprBlock(Prefix)",
      "OperatorBlock",
      "OperandBlock",
      "RefBlock(Constant)",
      "RefBlock(Variable)",
      "FunCallBlock",
      "ReturnStmtBlock",
      "ArgList",
      "RefBlock(BData)",
      "RefBlock(Array)"
    };

    // basic data types supported by Appl 
    enum class BasicDataType{
      BOOLN,
      INTGR,
      FLOAT
    };

    // derived data types supported by Appl 
    enum class DerivDataType{
      ARRAY
    };

    extern std::unordered_map<BlockType, int> SlotCountMap;
    extern std::unordered_map<BlockType, std::string> ContentStrMap;
    extern std::unordered_map<BlockType, std::vector<std::string>> TypeVarsMap; // maps type to array of str var names used by ContentStr of type
    extern std::set<BlockType> SizedTypes;
  }

#endif