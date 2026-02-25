
// Generated from APPL_Lex.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime/antlr4-runtime.h"




class  APPL_Lex : public antlr4::Lexer {
public:
  enum {
    KW_TRUE = 1, KW_FALSE = 2, KW_AND = 3, KW_OR = 4, KW_NOT = 5, KW_RETURN = 6, 
    KW_IF = 7, KW_ELSE = 8, KW_SWITCH = 9, KW_CASE = 10, KW_DFLT = 11, KW_DEF = 12, 
    KW_CONT = 13, KW_BREAK = 14, KW_FOR = 15, KW_EACH = 16, KW_IN = 17, 
    KW_WHILE = 18, KW_TRY = 19, KW_CATCH = 20, KW_PRINT = 21, POW_AUGOP = 22, 
    MUL_AUGOP = 23, INTDIV_AUGOP = 24, DIV_AUGOP = 25, INCR_AUGOP = 26, 
    DECR_AUGOP = 27, INCR = 28, DECR = 29, COMMA = 30, SC = 31, DOT = 32, 
    LPAREN = 33, RPAREN = 34, LCRLYB = 35, RCRLYB = 36, LBRCKT = 37, RBRCKT = 38, 
    POW = 39, MUL = 40, INT_DIV = 41, DIV = 42, MOD = 43, ADD = 44, SUB = 45, 
    EQUAL = 46, NOT_EQUAL = 47, LGCL_NOT = 48, LTE = 49, LT = 50, GTE = 51, 
    GT = 52, EQL = 53, LGCL_OR = 54, LGCL_AND = 55, FLT = 56, INT = 57, 
    ID = 58, WS = 59
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

