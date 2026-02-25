
// Generated from APPL_Parse.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime/antlr4-runtime.h"




class  APPL_Parse : public antlr4::Parser {
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

  enum {
    RuleMain = 0, RuleStatement = 1, RuleAssign = 2, RuleFun_def = 3, RuleParam_list = 4, 
    RuleConditional = 5, RuleIf_else_stmt = 6, RuleElse_blk = 7, RuleWhile_loop = 8, 
    RuleFor_loop = 9, RuleFor_ea_loop = 10, RuleCblk = 11, RuleReturn = 12, 
    RuleExpr = 13, RuleOperatn = 14, RuleUnary_oprtn = 15, RuleIteratn = 16, 
    RulePrefx_unary_oprtn = 17, RuleNegatn = 18, RuleBinary_oprtn = 19, 
    RuleArth_bin_op = 20, RuleComparison = 21, RuleAug_bin_op = 22, RuleAugop = 23, 
    RuleFactor = 24, RuleFun_call = 25, RuleArg_list = 26, RuleNumber = 27, 
    RulePos_num = 28, RuleNeg_num = 29, RuleBooln = 30
  };

  explicit APPL_Parse(antlr4::TokenStream *input);

  APPL_Parse(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~APPL_Parse() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class MainContext;
  class StatementContext;
  class AssignContext;
  class Fun_defContext;
  class Param_listContext;
  class ConditionalContext;
  class If_else_stmtContext;
  class Else_blkContext;
  class While_loopContext;
  class For_loopContext;
  class For_ea_loopContext;
  class CblkContext;
  class ReturnContext;
  class ExprContext;
  class OperatnContext;
  class Unary_oprtnContext;
  class IteratnContext;
  class Prefx_unary_oprtnContext;
  class NegatnContext;
  class Binary_oprtnContext;
  class Arth_bin_opContext;
  class ComparisonContext;
  class Aug_bin_opContext;
  class AugopContext;
  class FactorContext;
  class Fun_callContext;
  class Arg_listContext;
  class NumberContext;
  class Pos_numContext;
  class Neg_numContext;
  class BoolnContext; 

  class  MainContext : public antlr4::ParserRuleContext {
  public:
    MainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MainContext* main();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignContext *assign();
    antlr4::tree::TerminalNode *SC();
    Fun_defContext *fun_def();
    ConditionalContext *conditional();
    ExprContext *expr();
    ReturnContext *return_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementContext* statement();

  class  AssignContext : public antlr4::ParserRuleContext {
  public:
    AssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *EQL();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AssignContext* assign();

  class  Fun_defContext : public antlr4::ParserRuleContext {
  public:
    Fun_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_DEF();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    CblkContext *cblk();
    Param_listContext *param_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Fun_defContext* fun_def();

  class  Param_listContext : public antlr4::ParserRuleContext {
  public:
    Param_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Param_listContext* param_list();

  class  ConditionalContext : public antlr4::ParserRuleContext {
  public:
    ConditionalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    If_else_stmtContext *if_else_stmt();
    While_loopContext *while_loop();
    For_loopContext *for_loop();
    For_ea_loopContext *for_ea_loop();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConditionalContext* conditional();

  class  If_else_stmtContext : public antlr4::ParserRuleContext {
  public:
    If_else_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_IF();
    antlr4::tree::TerminalNode *LPAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAREN();
    CblkContext *cblk();
    Else_blkContext *else_blk();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  If_else_stmtContext* if_else_stmt();

  class  Else_blkContext : public antlr4::ParserRuleContext {
  public:
    Else_blkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_ELSE();
    If_else_stmtContext *if_else_stmt();
    CblkContext *cblk();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Else_blkContext* else_blk();

  class  While_loopContext : public antlr4::ParserRuleContext {
  public:
    While_loopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_WHILE();
    antlr4::tree::TerminalNode *LPAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAREN();
    CblkContext *cblk();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  While_loopContext* while_loop();

  class  For_loopContext : public antlr4::ParserRuleContext {
  public:
    For_loopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_FOR();
    antlr4::tree::TerminalNode *LPAREN();
    AssignContext *assign();
    std::vector<antlr4::tree::TerminalNode *> SC();
    antlr4::tree::TerminalNode* SC(size_t i);
    ExprContext *expr();
    IteratnContext *iteratn();
    antlr4::tree::TerminalNode *RPAREN();
    CblkContext *cblk();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  For_loopContext* for_loop();

  class  For_ea_loopContext : public antlr4::ParserRuleContext {
  public:
    For_ea_loopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_FOR();
    antlr4::tree::TerminalNode *KW_EACH();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *KW_IN();
    CblkContext *cblk();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  For_ea_loopContext* for_ea_loop();

  class  CblkContext : public antlr4::ParserRuleContext {
  public:
    CblkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCRLYB();
    antlr4::tree::TerminalNode *RCRLYB();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CblkContext* cblk();

  class  ReturnContext : public antlr4::ParserRuleContext {
  public:
    ReturnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_RETURN();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ReturnContext* return_();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Fun_callContext *fun_call();
    OperatnContext *operatn();
    FactorContext *factor();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExprContext* expr();

  class  OperatnContext : public antlr4::ParserRuleContext {
  public:
    OperatnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unary_oprtnContext *unary_oprtn();
    Binary_oprtnContext *binary_oprtn();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OperatnContext* operatn();

  class  Unary_oprtnContext : public antlr4::ParserRuleContext {
  public:
    Unary_oprtnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IteratnContext *iteratn();
    Prefx_unary_oprtnContext *prefx_unary_oprtn();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Unary_oprtnContext* unary_oprtn();

  class  IteratnContext : public antlr4::ParserRuleContext {
  public:
    IteratnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FactorContext *factor();
    antlr4::tree::TerminalNode *INCR();
    antlr4::tree::TerminalNode *DECR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IteratnContext* iteratn();

  class  Prefx_unary_oprtnContext : public antlr4::ParserRuleContext {
  public:
    Prefx_unary_oprtnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NegatnContext *negatn();
    FactorContext *factor();
    antlr4::tree::TerminalNode *INCR();
    antlr4::tree::TerminalNode *DECR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Prefx_unary_oprtnContext* prefx_unary_oprtn();

  class  NegatnContext : public antlr4::ParserRuleContext {
  public:
    NegatnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FactorContext *factor();
    antlr4::tree::TerminalNode *LGCL_NOT();
    antlr4::tree::TerminalNode *KW_NOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NegatnContext* negatn();

  class  Binary_oprtnContext : public antlr4::ParserRuleContext {
  public:
    Binary_oprtnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Arth_bin_opContext *arth_bin_op();
    ComparisonContext *comparison();
    std::vector<FactorContext *> factor();
    FactorContext* factor(size_t i);
    antlr4::tree::TerminalNode *KW_OR();
    antlr4::tree::TerminalNode *LGCL_OR();
    antlr4::tree::TerminalNode *KW_AND();
    antlr4::tree::TerminalNode *LGCL_AND();
    Aug_bin_opContext *aug_bin_op();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Binary_oprtnContext* binary_oprtn();

  class  Arth_bin_opContext : public antlr4::ParserRuleContext {
  public:
    Arth_bin_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FactorContext *> factor();
    FactorContext* factor(size_t i);
    antlr4::tree::TerminalNode *POW();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *INT_DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Arth_bin_opContext* arth_bin_op();

  class  ComparisonContext : public antlr4::ParserRuleContext {
  public:
    ComparisonContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FactorContext *> factor();
    FactorContext* factor(size_t i);
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *LTE();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *GTE();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *NOT_EQUAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ComparisonContext* comparison();

  class  Aug_bin_opContext : public antlr4::ParserRuleContext {
  public:
    Aug_bin_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FactorContext *> factor();
    FactorContext* factor(size_t i);
    antlr4::tree::TerminalNode *POW_AUGOP();
    AugopContext *augop();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Aug_bin_opContext* aug_bin_op();

  class  AugopContext : public antlr4::ParserRuleContext {
  public:
    AugopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MUL_AUGOP();
    antlr4::tree::TerminalNode *INTDIV_AUGOP();
    antlr4::tree::TerminalNode *DIV_AUGOP();
    antlr4::tree::TerminalNode *INCR_AUGOP();
    antlr4::tree::TerminalNode *DECR_AUGOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AugopContext* augop();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAREN();
    NumberContext *number();
    BoolnContext *booln();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FactorContext* factor();

  class  Fun_callContext : public antlr4::ParserRuleContext {
  public:
    Fun_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Arg_listContext *arg_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Fun_callContext* fun_call();

  class  Arg_listContext : public antlr4::ParserRuleContext {
  public:
    Arg_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Arg_listContext* arg_list();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Pos_numContext *pos_num();
    Neg_numContext *neg_num();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NumberContext* number();

  class  Pos_numContext : public antlr4::ParserRuleContext {
  public:
    Pos_numContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Pos_numContext* pos_num();

  class  Neg_numContext : public antlr4::ParserRuleContext {
  public:
    Neg_numContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SUB();
    Pos_numContext *pos_num();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Neg_numContext* neg_num();

  class  BoolnContext : public antlr4::ParserRuleContext {
  public:
    BoolnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_TRUE();
    antlr4::tree::TerminalNode *KW_FALSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BoolnContext* booln();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

