
// Generated from APPL_Parse.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "APPL_ParseListener.h"


/**
 * This class provides an empty implementation of APPL_ParseListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  APPL_ParseBaseListener : public APPL_ParseListener {
public:

  virtual void enterMain(APPL_Parse::MainContext * /*ctx*/) override { }
  virtual void exitMain(APPL_Parse::MainContext * /*ctx*/) override { }

  virtual void enterStatement(APPL_Parse::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(APPL_Parse::StatementContext * /*ctx*/) override { }

  virtual void enterAssign(APPL_Parse::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(APPL_Parse::AssignContext * /*ctx*/) override { }

  virtual void enterFun_def(APPL_Parse::Fun_defContext * /*ctx*/) override { }
  virtual void exitFun_def(APPL_Parse::Fun_defContext * /*ctx*/) override { }

  virtual void enterParam_list(APPL_Parse::Param_listContext * /*ctx*/) override { }
  virtual void exitParam_list(APPL_Parse::Param_listContext * /*ctx*/) override { }

  virtual void enterConditional(APPL_Parse::ConditionalContext * /*ctx*/) override { }
  virtual void exitConditional(APPL_Parse::ConditionalContext * /*ctx*/) override { }

  virtual void enterIf_else_stmt(APPL_Parse::If_else_stmtContext * /*ctx*/) override { }
  virtual void exitIf_else_stmt(APPL_Parse::If_else_stmtContext * /*ctx*/) override { }

  virtual void enterElse_blk(APPL_Parse::Else_blkContext * /*ctx*/) override { }
  virtual void exitElse_blk(APPL_Parse::Else_blkContext * /*ctx*/) override { }

  virtual void enterWhile_loop(APPL_Parse::While_loopContext * /*ctx*/) override { }
  virtual void exitWhile_loop(APPL_Parse::While_loopContext * /*ctx*/) override { }

  virtual void enterFor_loop(APPL_Parse::For_loopContext * /*ctx*/) override { }
  virtual void exitFor_loop(APPL_Parse::For_loopContext * /*ctx*/) override { }

  virtual void enterFor_ea_loop(APPL_Parse::For_ea_loopContext * /*ctx*/) override { }
  virtual void exitFor_ea_loop(APPL_Parse::For_ea_loopContext * /*ctx*/) override { }

  virtual void enterCblk(APPL_Parse::CblkContext * /*ctx*/) override { }
  virtual void exitCblk(APPL_Parse::CblkContext * /*ctx*/) override { }

  virtual void enterReturn(APPL_Parse::ReturnContext * /*ctx*/) override { }
  virtual void exitReturn(APPL_Parse::ReturnContext * /*ctx*/) override { }

  virtual void enterExpr(APPL_Parse::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(APPL_Parse::ExprContext * /*ctx*/) override { }

  virtual void enterOperatn(APPL_Parse::OperatnContext * /*ctx*/) override { }
  virtual void exitOperatn(APPL_Parse::OperatnContext * /*ctx*/) override { }

  virtual void enterUnary_oprtn(APPL_Parse::Unary_oprtnContext * /*ctx*/) override { }
  virtual void exitUnary_oprtn(APPL_Parse::Unary_oprtnContext * /*ctx*/) override { }

  virtual void enterIteratn(APPL_Parse::IteratnContext * /*ctx*/) override { }
  virtual void exitIteratn(APPL_Parse::IteratnContext * /*ctx*/) override { }

  virtual void enterPrefx_unary_oprtn(APPL_Parse::Prefx_unary_oprtnContext * /*ctx*/) override { }
  virtual void exitPrefx_unary_oprtn(APPL_Parse::Prefx_unary_oprtnContext * /*ctx*/) override { }

  virtual void enterNegatn(APPL_Parse::NegatnContext * /*ctx*/) override { }
  virtual void exitNegatn(APPL_Parse::NegatnContext * /*ctx*/) override { }

  virtual void enterBinary_oprtn(APPL_Parse::Binary_oprtnContext * /*ctx*/) override { }
  virtual void exitBinary_oprtn(APPL_Parse::Binary_oprtnContext * /*ctx*/) override { }

  virtual void enterLogic_or_expr(APPL_Parse::Logic_or_exprContext * /*ctx*/) override { }
  virtual void exitLogic_or_expr(APPL_Parse::Logic_or_exprContext * /*ctx*/) override { }

  virtual void enterLogic_and_expr(APPL_Parse::Logic_and_exprContext * /*ctx*/) override { }
  virtual void exitLogic_and_expr(APPL_Parse::Logic_and_exprContext * /*ctx*/) override { }

  virtual void enterComparison_expr(APPL_Parse::Comparison_exprContext * /*ctx*/) override { }
  virtual void exitComparison_expr(APPL_Parse::Comparison_exprContext * /*ctx*/) override { }

  virtual void enterAdd_expr(APPL_Parse::Add_exprContext * /*ctx*/) override { }
  virtual void exitAdd_expr(APPL_Parse::Add_exprContext * /*ctx*/) override { }

  virtual void enterMult_expr(APPL_Parse::Mult_exprContext * /*ctx*/) override { }
  virtual void exitMult_expr(APPL_Parse::Mult_exprContext * /*ctx*/) override { }

  virtual void enterPow_expr(APPL_Parse::Pow_exprContext * /*ctx*/) override { }
  virtual void exitPow_expr(APPL_Parse::Pow_exprContext * /*ctx*/) override { }

  virtual void enterAugop(APPL_Parse::AugopContext * /*ctx*/) override { }
  virtual void exitAugop(APPL_Parse::AugopContext * /*ctx*/) override { }

  virtual void enterFactor(APPL_Parse::FactorContext * /*ctx*/) override { }
  virtual void exitFactor(APPL_Parse::FactorContext * /*ctx*/) override { }

  virtual void enterFun_call(APPL_Parse::Fun_callContext * /*ctx*/) override { }
  virtual void exitFun_call(APPL_Parse::Fun_callContext * /*ctx*/) override { }

  virtual void enterArg_list(APPL_Parse::Arg_listContext * /*ctx*/) override { }
  virtual void exitArg_list(APPL_Parse::Arg_listContext * /*ctx*/) override { }

  virtual void enterNumber(APPL_Parse::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(APPL_Parse::NumberContext * /*ctx*/) override { }

  virtual void enterPos_num(APPL_Parse::Pos_numContext * /*ctx*/) override { }
  virtual void exitPos_num(APPL_Parse::Pos_numContext * /*ctx*/) override { }

  virtual void enterNeg_num(APPL_Parse::Neg_numContext * /*ctx*/) override { }
  virtual void exitNeg_num(APPL_Parse::Neg_numContext * /*ctx*/) override { }

  virtual void enterBooln(APPL_Parse::BoolnContext * /*ctx*/) override { }
  virtual void exitBooln(APPL_Parse::BoolnContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

