
// Generated from APPL_Parse.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "APPL_ParseVisitor.h"


/**
 * This class provides an empty implementation of APPL_ParseVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  APPL_ParseBaseVisitor : public APPL_ParseVisitor {
public:

  virtual std::any visitMain(APPL_Parse::MainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(APPL_Parse::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign(APPL_Parse::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFun_def(APPL_Parse::Fun_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam_list(APPL_Parse::Param_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConditional(APPL_Parse::ConditionalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_else_stmt(APPL_Parse::If_else_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElse_blk(APPL_Parse::Else_blkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhile_loop(APPL_Parse::While_loopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_loop(APPL_Parse::For_loopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_ea_loop(APPL_Parse::For_ea_loopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCblk(APPL_Parse::CblkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn(APPL_Parse::ReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(APPL_Parse::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperatn(APPL_Parse::OperatnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_oprtn(APPL_Parse::Unary_oprtnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIteratn(APPL_Parse::IteratnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrefx_unary_oprtn(APPL_Parse::Prefx_unary_oprtnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNegatn(APPL_Parse::NegatnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinary_oprtn(APPL_Parse::Binary_oprtnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogic_or_expr(APPL_Parse::Logic_or_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogic_and_expr(APPL_Parse::Logic_and_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparison_expr(APPL_Parse::Comparison_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdd_expr(APPL_Parse::Add_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMult_expr(APPL_Parse::Mult_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPow_expr(APPL_Parse::Pow_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAugop(APPL_Parse::AugopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor(APPL_Parse::FactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFun_call(APPL_Parse::Fun_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArg_list(APPL_Parse::Arg_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber(APPL_Parse::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPos_num(APPL_Parse::Pos_numContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNeg_num(APPL_Parse::Neg_numContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBooln(APPL_Parse::BoolnContext *ctx) override {
    return visitChildren(ctx);
  }


};

