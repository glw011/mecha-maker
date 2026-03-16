#pragma once

// ---------------------------------------------------------------------------
//  ApplLangInterp.h
//
//  Tree-walking interpreter for APPL. Extends APPL_ParseBaseVisitor.
//  Lives in the ApplLang module — must remain UE-blind.
// ---------------------------------------------------------------------------

#include "APPL_ParseBaseVisitor.h"
#include "APPL_Parse.h"
#include "ApplTypes.h"          // ApplValue, ComponentCallFn, ApplRuntimeError

#include <unordered_map>
#include <vector>
#include <string>
#include <any>
#include <functional>
#include <cmath>


// ---------------------------------------------------------------------------
//  Internal control-flow exception — propagates return values back up through
//  the visitor call stack. Never escapes ApplLangInterface::StartParse.
// ---------------------------------------------------------------------------
struct ApplReturnException {
    ApplValue value;
    explicit ApplReturnException(ApplValue v) : value(std::move(v)) {}
};


// ---------------------------------------------------------------------------
//  Scope frame and function definition — used internally by the interpreter.
// ---------------------------------------------------------------------------
using ScopeFrame = std::unordered_map<std::string, ApplValue>;

struct FunctionDef {
    std::vector<std::string>  params;
    APPL_Parse::CblkContext*  body = nullptr;
};


// ---------------------------------------------------------------------------
//  ApplLangInterp
// ---------------------------------------------------------------------------
class ApplLangInterp : public APPL_ParseBaseVisitor {
public:

    // Component function dispatch hook. Set by ApplLangInterface before
    // calling visitMain. The lambda is constructed in the ApplParser module
    // (UApplCompiler) so UE types never appear in this header.
    ComponentCallFn componentCallHandler;

    // Variable inspection (used by tests / ApplLangInterface).
    bool       hasVar(const std::string& name) const;
    ApplValue  getVar(const std::string& name) const;

    // -----------------------------------------------------------------------
    //  Visitor overrides
    // -----------------------------------------------------------------------
    std::any visitMain             (APPL_Parse::MainContext*              ctx) override;
    std::any visitStatement        (APPL_Parse::StatementContext*         ctx) override;
    std::any visitAssign           (APPL_Parse::AssignContext*            ctx) override;
    std::any visitFun_def          (APPL_Parse::Fun_defContext*           ctx) override;
    std::any visitParam_list       (APPL_Parse::Param_listContext*        ctx) override;
    std::any visitConditional      (APPL_Parse::ConditionalContext*       ctx) override;
    std::any visitIf_else_stmt     (APPL_Parse::If_else_stmtContext*      ctx) override;
    std::any visitElse_blk         (APPL_Parse::Else_blkContext*          ctx) override;
    std::any visitWhile_loop       (APPL_Parse::While_loopContext*        ctx) override;
    std::any visitFor_loop         (APPL_Parse::For_loopContext*          ctx) override;
    std::any visitFor_ea_loop      (APPL_Parse::For_ea_loopContext*       ctx) override;
    std::any visitCblk             (APPL_Parse::CblkContext*              ctx) override;
    std::any visitReturn           (APPL_Parse::ReturnContext*            ctx) override;
    std::any visitExpr             (APPL_Parse::ExprContext*              ctx) override;
    std::any visitOperatn          (APPL_Parse::OperatnContext*           ctx) override;
    std::any visitUnary_oprtn      (APPL_Parse::Unary_oprtnContext*       ctx) override;
    std::any visitIteratn          (APPL_Parse::IteratnContext*           ctx) override;
    std::any visitPrefx_unary_oprtn(APPL_Parse::Prefx_unary_oprtnContext* ctx) override;
    std::any visitNegatn           (APPL_Parse::NegatnContext*            ctx) override;
    std::any visitBinary_oprtn     (APPL_Parse::Binary_oprtnContext*      ctx) override;
    std::any visitLogic_or_expr    (APPL_Parse::Logic_or_exprContext*     ctx) override;
    std::any visitLogic_and_expr   (APPL_Parse::Logic_and_exprContext*    ctx) override;
    std::any visitComparison_expr  (APPL_Parse::Comparison_exprContext*   ctx) override;
    std::any visitAdd_expr         (APPL_Parse::Add_exprContext*          ctx) override;
    std::any visitMult_expr        (APPL_Parse::Mult_exprContext*         ctx) override;
    std::any visitPow_expr         (APPL_Parse::Pow_exprContext*          ctx) override;
    std::any visitAugop            (APPL_Parse::AugopContext*             ctx) override;
    std::any visitFactor           (APPL_Parse::FactorContext*            ctx) override;
    std::any visitFun_call         (APPL_Parse::Fun_callContext*          ctx) override;
    std::any visitArg_list         (APPL_Parse::Arg_listContext*          ctx) override;
    std::any visitNumber           (APPL_Parse::NumberContext*            ctx) override;
    std::any visitPos_num          (APPL_Parse::Pos_numContext*           ctx) override;
    std::any visitNeg_num          (APPL_Parse::Neg_numContext*           ctx) override;
    std::any visitBooln            (APPL_Parse::BoolnContext*             ctx) override;

private:
    std::vector<ScopeFrame>                      scopeStack_;
    std::unordered_map<std::string, FunctionDef> functionTable_;

    void       pushScope();
    void       popScope();
    ApplValue  lookupVar(const std::string& name) const;
    void       assignVar(const std::string& name, const ApplValue& val);

    static ApplValue valueFrom   (const std::any& a);
    ApplValue        evalExpr    (APPL_Parse::ExprContext* ctx);
    void             execCblk    (APPL_Parse::CblkContext* ctx);

    static ApplValue applyArith    (const std::string& op, const ApplValue& l, const ApplValue& r);
    static ApplValue applyCompareFn(const std::string& op, const ApplValue& l, const ApplValue& r);
    static ApplValue applyAugop   (const std::string& op, const ApplValue& cur, const ApplValue& r);

    static constexpr int kMaxLoopIterations = 100'000;
};
