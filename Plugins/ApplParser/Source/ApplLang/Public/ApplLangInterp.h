#pragma once

//  interpreter walks tree to perform operations and funtion calls
// ---------------------------------------------------------------------------

#include "APPL_ParseBaseVisitor.h"
#include "APPL_Parse.h"
#include "ApplTypes.h"          
#include <unordered_map>
#include <vector>
#include <string>
#include <any>
#include <functional>
#include <cmath>


//  struct for internal exceptions (returns vals back to call stack)
struct ApplReturnException{
    ApplValue value;
    explicit ApplReturnException(ApplValue v) : value(std::move(v)) {}
};


//  frame created for each scope within tree 
using ScopeFrame = std::unordered_map<std::string, ApplValue>;

// struct for function definitions encountered by interpreter 
struct FunctionDef{
    std::vector<std::string> params;
    APPL_Parse::CblkContext* body = nullptr;
};


//  ApplLangInterp is interpreter extending BaseVisitor class and used to traverse created parse trees
class ApplLangInterp : public APPL_ParseBaseVisitor{
  public:

    // component function dispatch hook set by ApplLangInterface before calling visitMain
    //  - lambda function constructed in ApplCompiler to UE types never appear in this header.
    ComponentCallFn componentCallHandler;

    // helper functions used by ApplLangInterface
    bool hasVar(const std::string& name) const;
    ApplValue getVar(const std::string& name) const;

    //  visitor overrides
    std::any visitMain(APPL_Parse::MainContext* ctx) override;
    std::any visitStatement(APPL_Parse::StatementContext* ctx) override;
    std::any visitAssign(APPL_Parse::AssignContext* ctx) override;
    std::any visitFun_def(APPL_Parse::Fun_defContext* ctx) override;
    std::any visitParam_list(APPL_Parse::Param_listContext* ctx) override;
    std::any visitConditional(APPL_Parse::ConditionalContext* ctx) override;
    std::any visitIf_else_stmt(APPL_Parse::If_else_stmtContext* ctx) override;
    std::any visitElse_blk(APPL_Parse::Else_blkContext* ctx) override;
    std::any visitWhile_loop(APPL_Parse::While_loopContext* ctx) override;
    std::any visitFor_loop(APPL_Parse::For_loopContext* ctx) override;
    std::any visitFor_ea_loop(APPL_Parse::For_ea_loopContext* ctx) override;
    std::any visitCblk(APPL_Parse::CblkContext* ctx) override;
    std::any visitReturn(APPL_Parse::ReturnContext* ctx) override;
    std::any visitExpr(APPL_Parse::ExprContext* ctx) override;
    std::any visitOperatn(APPL_Parse::OperatnContext* ctx) override;
    std::any visitUnary_oprtn(APPL_Parse::Unary_oprtnContext* ctx) override;
    std::any visitIteratn(APPL_Parse::IteratnContext* ctx) override;
    std::any visitPrefx_unary_oprtn(APPL_Parse::Prefx_unary_oprtnContext* ctx) override;
    std::any visitNegatn(APPL_Parse::NegatnContext* ctx) override;
    std::any visitBinary_oprtn(APPL_Parse::Binary_oprtnContext* ctx) override;
    std::any visitLogic_or_expr(APPL_Parse::Logic_or_exprContext* ctx) override;
    std::any visitLogic_and_expr(APPL_Parse::Logic_and_exprContext* ctx) override;
    std::any visitComparison_expr(APPL_Parse::Comparison_exprContext* ctx) override;
    std::any visitAdd_expr(APPL_Parse::Add_exprContext* ctx) override;
    std::any visitMult_expr(APPL_Parse::Mult_exprContext* ctx) override;
    std::any visitPow_expr(APPL_Parse::Pow_exprContext* ctx) override;
    std::any visitAugop(APPL_Parse::AugopContext* ctx) override;
    std::any visitFactor(APPL_Parse::FactorContext* ctx) override;
    std::any visitFun_call(APPL_Parse::Fun_callContext* ctx) override;
    std::any visitArg_list(APPL_Parse::Arg_listContext* ctx) override;
    std::any visitNumber(APPL_Parse::NumberContext* ctx) override;
    std::any visitPos_num(APPL_Parse::Pos_numContext* ctx) override;
    std::any visitNeg_num(APPL_Parse::Neg_numContext* ctx) override;
    std::any visitBooln(APPL_Parse::BoolnContext* ctx) override;

  private:
    std::vector<ScopeFrame> scopeStack_;
    std::unordered_map<std::string, FunctionDef> functionTable_;

    void pushScope();
    void popScope();
    ApplValue lookupVar(const std::string& name) const;
    void assignVar(const std::string& name, const ApplValue& val);

    static ApplValue valueFrom (const std::any& a);
    ApplValue evalExpr (APPL_Parse::ExprContext* ctx);
    void execCblk (APPL_Parse::CblkContext* ctx);

    static ApplValue applyArith(const std::string& op, const ApplValue& l, const ApplValue& r);
    static ApplValue applyCompareFn(const std::string& op, const ApplValue& l, const ApplValue& r);
    static ApplValue applyAugop(const std::string& op, const ApplValue& cur, const ApplValue& r);

    static constexpr int kMaxLoopIterations = 100000;
};
