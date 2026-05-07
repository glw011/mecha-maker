
// Generated from APPL_Parse.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  APPL_Parse : public antlr4::Parser {
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

  enum {
    RuleMain = 0, RuleStatement = 1, RuleAssign = 2, RuleFun_def = 3, RuleParam_list = 4, 
    RuleConditional = 5, RuleIf_else_stmt = 6, RuleElse_blk = 7, RuleWhile_loop = 8, 
    RuleFor_loop = 9, RuleFor_ea_loop = 10, RuleCblk = 11, RuleReturn = 12, 
    RuleExpr = 13, RuleOperatn = 14, RuleUnary_oprtn = 15, RuleIteratn = 16, 
    RulePrefx_unary_oprtn = 17, RuleNegatn = 18, RuleBinary_oprtn = 19, 
    RuleLogic_or_expr = 20, RuleLogic_and_expr = 21, RuleComparison_expr = 22, 
    RuleAdd_expr = 23, RuleMult_expr = 24, RulePow_expr = 25, RuleAugop = 26, 
    RuleFactor = 27, RuleFun_call = 28, RuleArg_list = 29, RuleNumber = 30, 
    RulePos_num = 31, RuleNeg_num = 32, RuleBooln = 33
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
  class Logic_or_exprContext;
  class Logic_and_exprContext;
  class Comparison_exprContext;
  class Add_exprContext;
  class Mult_exprContext;
  class Pow_exprContext;
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
    antlr4::tree::TerminalNode *KW_END();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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
    OperatnContext *operatn();
    antlr4::tree::TerminalNode *RPAREN();
    CblkContext *cblk();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnContext* return_();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OperatnContext *operatn();
    FactorContext *factor();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IteratnContext* iteratn();

  class  Prefx_unary_oprtnContext : public antlr4::ParserRuleContext {
  public:
    Prefx_unary_oprtnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NegatnContext *negatn();
    antlr4::tree::TerminalNode *INCR();
    FactorContext *factor();
    antlr4::tree::TerminalNode *DECR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NegatnContext* negatn();

  class  Binary_oprtnContext : public antlr4::ParserRuleContext {
  public:
    Binary_oprtnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_or_exprContext *logic_or_expr();
    FactorContext *factor();
    AugopContext *augop();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Binary_oprtnContext* binary_oprtn();

  class  Logic_or_exprContext : public antlr4::ParserRuleContext {
  public:
    Logic_or_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Logic_and_exprContext *> logic_and_expr();
    Logic_and_exprContext* logic_and_expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> KW_OR();
    antlr4::tree::TerminalNode* KW_OR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LGCL_OR();
    antlr4::tree::TerminalNode* LGCL_OR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logic_or_exprContext* logic_or_expr();

  class  Logic_and_exprContext : public antlr4::ParserRuleContext {
  public:
    Logic_and_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Comparison_exprContext *> comparison_expr();
    Comparison_exprContext* comparison_expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> KW_AND();
    antlr4::tree::TerminalNode* KW_AND(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LGCL_AND();
    antlr4::tree::TerminalNode* LGCL_AND(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logic_and_exprContext* logic_and_expr();

  class  Comparison_exprContext : public antlr4::ParserRuleContext {
  public:
    Comparison_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Add_exprContext *> add_expr();
    Add_exprContext* add_expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LT();
    antlr4::tree::TerminalNode* LT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LTE();
    antlr4::tree::TerminalNode* LTE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GT();
    antlr4::tree::TerminalNode* GT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GTE();
    antlr4::tree::TerminalNode* GTE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EQUAL();
    antlr4::tree::TerminalNode* EQUAL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NOT_EQUAL();
    antlr4::tree::TerminalNode* NOT_EQUAL(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Comparison_exprContext* comparison_expr();

  class  Add_exprContext : public antlr4::ParserRuleContext {
  public:
    Add_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Mult_exprContext *> mult_expr();
    Mult_exprContext* mult_expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ADD();
    antlr4::tree::TerminalNode* ADD(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SUB();
    antlr4::tree::TerminalNode* SUB(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Add_exprContext* add_expr();

  class  Mult_exprContext : public antlr4::ParserRuleContext {
  public:
    Mult_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Pow_exprContext *> pow_expr();
    Pow_exprContext* pow_expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MUL();
    antlr4::tree::TerminalNode* MUL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DIV();
    antlr4::tree::TerminalNode* DIV(size_t i);
    std::vector<antlr4::tree::TerminalNode *> INT_DIV();
    antlr4::tree::TerminalNode* INT_DIV(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MOD();
    antlr4::tree::TerminalNode* MOD(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mult_exprContext* mult_expr();

  class  Pow_exprContext : public antlr4::ParserRuleContext {
  public:
    Pow_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FactorContext *factor();
    antlr4::tree::TerminalNode *POW();
    Pow_exprContext *pow_expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pow_exprContext* pow_expr();

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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AugopContext* augop();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAREN();
    Fun_callContext *fun_call();
    NumberContext *number();
    BoolnContext *booln();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BoolnContext* booln();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

