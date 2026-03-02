#include "ApplLangListener.h"
#include <unordered_map>
#include <vector>
#include <string>



class ApplLangInterp : public ApplLangListener{
  public:
    explicit ApplLangInterp();

    virtual void enterMain(APPL_Parse::MainContext* mainCtx) override;
    virtual void exitMain(APPL_Parse::MainContext* mainCtx) override;

    //virtual void enterStatement(APPL_Parse::StatementContext* stmtCtx) override;
    virtual void exitStatement(APPL_Parse::StatementContext* stmtCtx) override;

    //virtual void enterAssign(APPL_Parse::AssignContext* assignCtx) override;
    virtual void exitAssign(APPL_Parse::AssignContext* assignCtx) override;

    //virtual void enterFun_def(APPL_Parse::Fun_defContext* funDefCtx) override;
    virtual void exitFun_def(APPL_Parse::Fun_defContext* funDefCtx) override;

    //virtual void enterParam_list(APPL_Parse::Param_listContext* paramListCtx) override;
    virtual void exitParam_list(APPL_Parse::Param_listContext* paramListCtx) override;

    //virtual void enterConditional(APPL_Parse::ConditionalContext* condtnlCtx) override;
    virtual void exitConditional(APPL_Parse::ConditionalContext* condtnlCtx) override;

    //virtual void enterIf_else_stmt(APPL_Parse::If_else_stmtContext* ifElsCtx) override;
    virtual void exitIf_else_stmt(APPL_Parse::If_else_stmtContext* ifElsCtx) override;

    //virtual void enterElse_blk(APPL_Parse::Else_blkContext* elsBlkCtx) override;
    virtual void exitElse_blk(APPL_Parse::Else_blkContext* elsBlkCtx) override;

    //virtual void enterWhile_loop(APPL_Parse::While_loopContext* whlLoopCtx) override;
    virtual void exitWhile_loop(APPL_Parse::While_loopContext* whlLoopCtx) override;

    //virtual void enterFor_loop(APPL_Parse::For_loopContext* forLoopCtx) override;
    virtual void exitFor_loop(APPL_Parse::For_loopContext* forLoopCtx) override;

    //virtual void enterFor_ea_loop(APPL_Parse::For_ea_loopContext* forEaLoopCtx) override;
    virtual void exitFor_ea_loop(APPL_Parse::For_ea_loopContext* forEaLoopCtx) override;

    //virtual void enterCblk(APPL_Parse::CblkContext* cblkCtx) override;
    virtual void exitCblk(APPL_Parse::CblkContext* cblkCtx) override;

    //virtual void enterReturn(APPL_Parse::ReturnContext* returnCtx) override;
    virtual void exitReturn(APPL_Parse::ReturnContext* returnCtx) override;

    //virtual void enterExpr(APPL_Parse::ExprContext* exprCtx) override;
    virtual void exitExpr(APPL_Parse::ExprContext* exprCtx) override;

    //virtual void enterOperatn(APPL_Parse::OperatnContext* oprtnCtx) override;
    virtual void exitOperatn(APPL_Parse::OperatnContext* oprtnCtx) override;

    //virtual void enterUnary_oprtn(APPL_Parse::Unary_oprtnContext* uOprtnCtx) override;
    virtual void exitUnary_oprtn(APPL_Parse::Unary_oprtnContext* uOprtnCtx) override;

    //virtual void enterIteratn(APPL_Parse::IteratnContext* itrCtx) override;
    virtual void exitIteratn(APPL_Parse::IteratnContext* itrCtx) override;

    //virtual void enterPrefx_unary_oprtn(APPL_Parse::Prefx_unary_oprtnContext* prfxuOprtnCtx) override;
    virtual void exitPrefx_unary_oprtn(APPL_Parse::Prefx_unary_oprtnContext* prfxuOprtnCtx) override;

    //virtual void enterNegatn(APPL_Parse::NegatnContext* ngtnCtx) override;
    virtual void exitNegatn(APPL_Parse::NegatnContext* ngtnCtx) override;

    //virtual void enterBinary_oprtn(APPL_Parse::Binary_oprtnContext* bOprtnCtx) override;
    virtual void exitBinary_oprtn(APPL_Parse::Binary_oprtnContext* bOprtnCtx) override;

    //virtual void enterArth_bin_op(APPL_Parse::Arth_bin_opContext* arthbOprtnCtx) override;
    virtual void exitArth_bin_op(APPL_Parse::Arth_bin_opContext* arthbOprtnCtx) override;

    //virtual void enterComparison(APPL_Parse::ComparisonContext* comparCtx) override;
    virtual void exitComparison(APPL_Parse::ComparisonContext* comparCtx) override;

    //virtual void enterAug_bin_op(APPL_Parse::Aug_bin_opContext* augAssignCtx) override;
    virtual void exitAug_bin_op(APPL_Parse::Aug_bin_opContext* augAssignCtx) override;

    //virtual void enterFactor(APPL_Parse::FactorContext* factrCtx) override;
    virtual void exitFactor(APPL_Parse::FactorContext* factrCtx) override;

    //virtual void enterFun_call(APPL_Parse::Fun_callContext* funCallCtx) override;
    virtual void exitFun_call(APPL_Parse::Fun_callContext* funcCallCtx) override;

    //virtual void enterArg_list(APPL_Parse::Arg_listContext* argListCtx) override;
    virtual void exitArg_list(APPL_Parse::Arg_listContext* argListCtx) override;

    //virtual void enterNumber(APPL_Parse::NumberContext* numCtx) override;
    virtual void exitNumber(APPL_Parse::NumberContext* numCtx) override;

    //virtual void enterPos_num(APPL_Parse::Pos_numContext* posNumCtx) override;
    virtual void exitPos_num(APPL_Parse::Pos_numContext* posNumCtx) override;

    //virtual void enterNeg_num(APPL_Parse::Neg_numContext* negNumCtx) override;
    virtual void exitNeg_num(APPL_Parse::Neg_numContext* negNumCtx) override;

    //virtual void enterBooln(APPL_Parse::BoolnContext* boolCtx) override;
    virtual void exitBooln(APPL_Parse::BoolnContext* boolCtx) override;

    // override rule handlers (must match base listener method names)
    // placeholder examples for now...
    // ---------------------------------------------------------------------------
    //virtual void enterMoveStmt(Type* ctx) override;
    //virtual void enterTurnStmt(Type* ctx) override;
    //virtual void enterWaitStmt(Type* ctx) override;

  private:
    std::unordered_map<std::string, std::vector<std::string>> argLists = {};
    std::unordered_map<std::string, std::vector<std::string>> paramLists = {};
    std::unordered_map<int, int> intVariables; 

};


struct ApplParseResult{
  bool success = false;
  std::vector<std::string> applErrors;
  std::vector<std::string> applExcepts;
  int32_t stmtCount = 0;
};