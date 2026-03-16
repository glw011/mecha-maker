
// Generated from APPL_Parse.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "APPL_Parse.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by APPL_Parse.
 */
class  APPL_ParseVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by APPL_Parse.
   */
    virtual std::any visitMain(APPL_Parse::MainContext *context) = 0;

    virtual std::any visitStatement(APPL_Parse::StatementContext *context) = 0;

    virtual std::any visitAssign(APPL_Parse::AssignContext *context) = 0;

    virtual std::any visitFun_def(APPL_Parse::Fun_defContext *context) = 0;

    virtual std::any visitParam_list(APPL_Parse::Param_listContext *context) = 0;

    virtual std::any visitConditional(APPL_Parse::ConditionalContext *context) = 0;

    virtual std::any visitIf_else_stmt(APPL_Parse::If_else_stmtContext *context) = 0;

    virtual std::any visitElse_blk(APPL_Parse::Else_blkContext *context) = 0;

    virtual std::any visitWhile_loop(APPL_Parse::While_loopContext *context) = 0;

    virtual std::any visitFor_loop(APPL_Parse::For_loopContext *context) = 0;

    virtual std::any visitFor_ea_loop(APPL_Parse::For_ea_loopContext *context) = 0;

    virtual std::any visitCblk(APPL_Parse::CblkContext *context) = 0;

    virtual std::any visitReturn(APPL_Parse::ReturnContext *context) = 0;

    virtual std::any visitExpr(APPL_Parse::ExprContext *context) = 0;

    virtual std::any visitOperatn(APPL_Parse::OperatnContext *context) = 0;

    virtual std::any visitUnary_oprtn(APPL_Parse::Unary_oprtnContext *context) = 0;

    virtual std::any visitIteratn(APPL_Parse::IteratnContext *context) = 0;

    virtual std::any visitPrefx_unary_oprtn(APPL_Parse::Prefx_unary_oprtnContext *context) = 0;

    virtual std::any visitNegatn(APPL_Parse::NegatnContext *context) = 0;

    virtual std::any visitBinary_oprtn(APPL_Parse::Binary_oprtnContext *context) = 0;

    virtual std::any visitLogic_or_expr(APPL_Parse::Logic_or_exprContext *context) = 0;

    virtual std::any visitLogic_and_expr(APPL_Parse::Logic_and_exprContext *context) = 0;

    virtual std::any visitComparison_expr(APPL_Parse::Comparison_exprContext *context) = 0;

    virtual std::any visitAdd_expr(APPL_Parse::Add_exprContext *context) = 0;

    virtual std::any visitMult_expr(APPL_Parse::Mult_exprContext *context) = 0;

    virtual std::any visitPow_expr(APPL_Parse::Pow_exprContext *context) = 0;

    virtual std::any visitAugop(APPL_Parse::AugopContext *context) = 0;

    virtual std::any visitFactor(APPL_Parse::FactorContext *context) = 0;

    virtual std::any visitFun_call(APPL_Parse::Fun_callContext *context) = 0;

    virtual std::any visitArg_list(APPL_Parse::Arg_listContext *context) = 0;

    virtual std::any visitNumber(APPL_Parse::NumberContext *context) = 0;

    virtual std::any visitPos_num(APPL_Parse::Pos_numContext *context) = 0;

    virtual std::any visitNeg_num(APPL_Parse::Neg_numContext *context) = 0;

    virtual std::any visitBooln(APPL_Parse::BoolnContext *context) = 0;


};

