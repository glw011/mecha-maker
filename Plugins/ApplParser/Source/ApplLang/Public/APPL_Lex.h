
// Generated from APPL_Lex.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  APPL_Lex : public antlr4::Lexer {
public:
  enum {
    KW_END = 1, KW_TRUE = 2, KW_FALSE = 3, KW_AND = 4, KW_OR = 5, KW_NOT = 6, 
    KW_RETURN = 7, KW_IF = 8, KW_ELSE = 9, KW_SWITCH = 10, KW_CASE = 11, 
    KW_DFLT = 12, KW_DEF = 13, KW_CONT = 14, KW_BREAK = 15, KW_FOR = 16, 
    KW_EACH = 17, KW_IN = 18, KW_WHILE = 19, KW_TRY = 20, KW_CATCH = 21, 
    KW_PRINT = 22, POW_AUGOP = 23, MUL_AUGOP = 24, INTDIV_AUGOP = 25, DIV_AUGOP = 26, 
    INCR_AUGOP = 27, DECR_AUGOP = 28, INCR = 29, DECR = 30, COMMA = 31, 
    SC = 32, DOT = 33, LPAREN = 34, RPAREN = 35, LCRLYB = 36, RCRLYB = 37, 
    LBRCKT = 38, RBRCKT = 39, POW = 40, MUL = 41, INT_DIV = 42, DIV = 43, 
    MOD = 44, ADD = 45, SUB = 46, EQUAL = 47, NOT_EQUAL = 48, LGCL_NOT = 49, 
    LTE = 50, LT = 51, GTE = 52, GT = 53, EQL = 54, LGCL_OR = 55, LGCL_AND = 56, 
    FLT = 57, INT = 58, ID = 59, WS = 60
  };

  explicit APPL_Lex(antlr4::CharStream *input);

  ~APPL_Lex() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

