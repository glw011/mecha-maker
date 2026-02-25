
// Generated from APPL_Parse.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "APPL_Parse.h"


/**
 * This interface defines an abstract listener for a parse tree produced by APPL_Parse.
 */
class  APPL_ParseListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterMain(APPL_Parse::MainContext *ctx) = 0;
  virtual void exitMain(APPL_Parse::MainContext *ctx) = 0;

  virtual void enterStatement(APPL_Parse::StatementContext *ctx) = 0;
  virtual void exitStatement(APPL_Parse::StatementContext *ctx) = 0;

  virtual void enterAssign(APPL_Parse::AssignContext *ctx) = 0;
  virtual void exitAssign(APPL_Parse::AssignContext *ctx) = 0;

  virtual void enterFun_def(APPL_Parse::Fun_defContext *ctx) = 0;
  virtual void exitFun_def(APPL_Parse::Fun_defContext *ctx) = 0;

  virtual void enterParam_list(APPL_Parse::Param_listContext *ctx) = 0;
  virtual void exitParam_list(APPL_Parse::Param_listContext *ctx) = 0;

  virtual void enterConditional(APPL_Parse::ConditionalContext *ctx) = 0;
  virtual void exitConditional(APPL_Parse::ConditionalContext *ctx) = 0;

  virtual void enterIf_else_stmt(APPL_Parse::If_else_stmtContext *ctx) = 0;
  virtual void exitIf_else_stmt(APPL_Parse::If_else_stmtContext *ctx) = 0;

  virtual void enterElse_blk(APPL_Parse::Else_blkContext *ctx) = 0;
  virtual void exitElse_blk(APPL_Parse::Else_blkContext *ctx) = 0;

  virtual void enterWhile_loop(APPL_Parse::While_loopContext *ctx) = 0;
  virtual void exitWhile_loop(APPL_Parse::While_loopContext *ctx) = 0;

  virtual void enterFor_loop(APPL_Parse::For_loopContext *ctx) = 0;
  virtual void exitFor_loop(APPL_Parse::For_loopContext *ctx) = 0;

  virtual void enterFor_ea_loop(APPL_Parse::For_ea_loopContext *ctx) = 0;
  virtual void exitFor_ea_loop(APPL_Parse::For_ea_loopContext *ctx) = 0;

  virtual void enterCblk(APPL_Parse::CblkContext *ctx) = 0;
  virtual void exitCblk(APPL_Parse::CblkContext *ctx) = 0;

  virtual void enterReturn(APPL_Parse::ReturnContext *ctx) = 0;
  virtual void exitReturn(APPL_Parse::ReturnContext *ctx) = 0;

  virtual void enterExpr(APPL_Parse::ExprContext *ctx) = 0;
  virtual void exitExpr(APPL_Parse::ExprContext *ctx) = 0;

  virtual void enterOperatn(APPL_Parse::OperatnContext *ctx) = 0;
  virtual void exitOperatn(APPL_Parse::OperatnContext *ctx) = 0;

  virtual void enterUnary_oprtn(APPL_Parse::Unary_oprtnContext *ctx) = 0;
  virtual void exitUnary_oprtn(APPL_Parse::Unary_oprtnContext *ctx) = 0;

  virtual void enterIteratn(APPL_Parse::IteratnContext *ctx) = 0;
  virtual void exitIteratn(APPL_Parse::IteratnContext *ctx) = 0;

  virtual void enterPrefx_unary_oprtn(APPL_Parse::Prefx_unary_oprtnContext *ctx) = 0;
  virtual void exitPrefx_unary_oprtn(APPL_Parse::Prefx_unary_oprtnContext *ctx) = 0;

  virtual void enterNegatn(APPL_Parse::NegatnContext *ctx) = 0;
  virtual void exitNegatn(APPL_Parse::NegatnContext *ctx) = 0;

  virtual void enterBinary_oprtn(APPL_Parse::Binary_oprtnContext *ctx) = 0;
  virtual void exitBinary_oprtn(APPL_Parse::Binary_oprtnContext *ctx) = 0;

  virtual void enterArth_bin_op(APPL_Parse::Arth_bin_opContext *ctx) = 0;
  virtual void exitArth_bin_op(APPL_Parse::Arth_bin_opContext *ctx) = 0;

  virtual void enterComparison(APPL_Parse::ComparisonContext *ctx) = 0;
  virtual void exitComparison(APPL_Parse::ComparisonContext *ctx) = 0;

  virtual void enterAug_bin_op(APPL_Parse::Aug_bin_opContext *ctx) = 0;
  virtual void exitAug_bin_op(APPL_Parse::Aug_bin_opContext *ctx) = 0;

  virtual void enterAugop(APPL_Parse::AugopContext *ctx) = 0;
  virtual void exitAugop(APPL_Parse::AugopContext *ctx) = 0;

  virtual void enterFactor(APPL_Parse::FactorContext *ctx) = 0;
  virtual void exitFactor(APPL_Parse::FactorContext *ctx) = 0;

  virtual void enterFun_call(APPL_Parse::Fun_callContext *ctx) = 0;
  virtual void exitFun_call(APPL_Parse::Fun_callContext *ctx) = 0;

  virtual void enterArg_list(APPL_Parse::Arg_listContext *ctx) = 0;
  virtual void exitArg_list(APPL_Parse::Arg_listContext *ctx) = 0;

  virtual void enterNumber(APPL_Parse::NumberContext *ctx) = 0;
  virtual void exitNumber(APPL_Parse::NumberContext *ctx) = 0;

  virtual void enterPos_num(APPL_Parse::Pos_numContext *ctx) = 0;
  virtual void exitPos_num(APPL_Parse::Pos_numContext *ctx) = 0;

  virtual void enterNeg_num(APPL_Parse::Neg_numContext *ctx) = 0;
  virtual void exitNeg_num(APPL_Parse::Neg_numContext *ctx) = 0;

  virtual void enterBooln(APPL_Parse::BoolnContext *ctx) = 0;
  virtual void exitBooln(APPL_Parse::BoolnContext *ctx) = 0;


};

