#include "ApplLangInterp.h"



ApplLangInterp::ApplLangInterp(){
  // placeholder for now
}

void ApplLangInterp::enterMain(APPL_Parse::MainContext* mainCtx){}
//void ApplLangInterp::exitMain(APPL_Parse::MainContext* Ctx){}

//void ApplLangInterp::enterStatement(APPL_Parse::StatementContext* Ctx){}
//void ApplLangInterp::exitStatement(APPL_Parse::StatementContext* Ctx){}

void ApplLangInterp::enterAssign(APPL_Parse::AssignContext* assignCtx){}
//void ApplLangInterp::exitAssign(APPL_Parse::AssignContext* Ctx){}

void ApplLangInterp::enterFun_def(APPL_Parse::Fun_defContext* funDefCtx){}
//void ApplLangInterp::exitFun_def(APPL_Parse::Fun_defContext* Ctx){}

void ApplLangInterp::enterParam_list(APPL_Parse::Param_listContext* paramListCtx){}
//void ApplLangInterp::exitParam_list(APPL_Parse::Param_listContext* Ctx){}

//void ApplLangInterp::enterConditional(APPL_Parse::ConditionalContext* Ctx){}
//void ApplLangInterp::exitConditional(APPL_Parse::ConditionalContext* Ctx){}

void ApplLangInterp::enterIf_else_stmt(APPL_Parse::If_else_stmtContext* ifElsCtx){}
//void ApplLangInterp::exitIf_else_stmt(APPL_Parse::If_else_stmtContext* Ctx){}

void ApplLangInterp::enterElse_blk(APPL_Parse::Else_blkContext* elsBlkCtx){}
//void ApplLangInterp::exitElse_blk(APPL_Parse::Else_blkContext* Ctx){}

void ApplLangInterp::enterWhile_loop(APPL_Parse::While_loopContext* whlLoopCtx){}
//void ApplLangInterp::exitWhile_loop(APPL_Parse::While_loopContext* Ctx){}

void ApplLangInterp::enterFor_loop(APPL_Parse::For_loopContext* forLoopCtx){}
//void ApplLangInterp::exitFor_loop(APPL_Parse::For_loopContext* Ctx){}

void ApplLangInterp::enterFor_ea_loop(APPL_Parse::For_ea_loopContext* forEaLoopCtx){}
//void ApplLangInterp::exitFor_ea_loop(APPL_Parse::For_ea_loopContext* Ctx){}

void ApplLangInterp::enterCblk(APPL_Parse::CblkContext* cblkCtx){}
//void ApplLangInterp::exitCblk(APPL_Parse::CblkContext* Ctx){}

void ApplLangInterp::enterReturn(APPL_Parse::ReturnContext* returnCtx){}
//void ApplLangInterp::exitReturn(APPL_Parse::ReturnContext* Ctx){}

//void ApplLangInterp::enterExpr(APPL_Parse::ExprContext* exprCtx){}
//void ApplLangInterp::exitExpr(APPL_Parse::ExprContext* Ctx){}

//void ApplLangInterp::enterOperatn(APPL_Parse::OperatnContext* oprtnCtx){}
//void ApplLangInterp::exitOperatn(APPL_Parse::OperatnContext* Ctx){}

void ApplLangInterp::enterUnary_oprtn(APPL_Parse::Unary_oprtnContext* uOprtnCtx){}
//void ApplLangInterp::exitUnary_oprtn(APPL_Parse::Unary_oprtnContext* Ctx){}

void ApplLangInterp::enterIteratn(APPL_Parse::IteratnContext* itrCtx){}
//void ApplLangInterp::exitIteratn(APPL_Parse::IteratnContext* Ctx){}

void ApplLangInterp::enterPrefx_unary_oprtn(APPL_Parse::Prefx_unary_oprtnContext* prfxuOprtnCtx){}
//void ApplLangInterp::exitPrefx_unary_oprtn(APPL_Parse::Prefx_unary_oprtnContext* Ctx){}

void ApplLangInterp::enterNegatn(APPL_Parse::NegatnContext* ngtnCtx){}
//void ApplLangInterp::exitNegatn(APPL_Parse::NegatnContext* Ctx){}

void ApplLangInterp::enterBinary_oprtn(APPL_Parse::Binary_oprtnContext* bOprtnCtx){}
//void ApplLangInterp::exitBinary_oprtn(APPL_Parse::Binary_oprtnContext* Ctx){}

void ApplLangInterp::enterArth_bin_op(APPL_Parse::Arth_bin_opContext* arthbOprtnCtx){}
//void ApplLangInterp::exitArth_bin_op(APPL_Parse::Arth_bin_opContext* Ctx){}

void ApplLangInterp::enterComparison(APPL_Parse::ComparisonContext* comparCtx){}
//void ApplLangInterp::exitComparison(APPL_Parse::ComparisonContext* Ctx){}

void ApplLangInterp::enterAug_bin_op(APPL_Parse::Aug_bin_opContext* augasgnOprtnCtx){}
//void ApplLangInterp::exitAug_bin_op(APPL_Parse::Aug_bin_opContext* Ctx){}

//void ApplLangInterp::enterAugop(APPL_Parse::AugopContext* Ctx){}
//void ApplLangInterp::exitAugop(APPL_Parse::AugopContext* Ctx){}

void ApplLangInterp::enterFactor(APPL_Parse::FactorContext* factrCtx){}
//void ApplLangInterp::exitFactor(APPL_Parse::FactorContext* Ctx){}

void ApplLangInterp::enterFun_call(APPL_Parse::Fun_callContext* funCallCtx){}
//void ApplLangInterp::exitFun_call(APPL_Parse::Fun_callContext* Ctx){}

void ApplLangInterp::enterArg_list(APPL_Parse::Arg_listContext* argListCtx){}
//void ApplLangInterp::exitArg_list(APPL_Parse::Arg_listContext* Ctx){}

//void ApplLangInterp::enterNumber(APPL_Parse::NumberContext* numCtx){}
//void ApplLangInterp::exitNumber(APPL_Parse::NumberContext* Ctx){}

void ApplLangInterp::enterPos_num(APPL_Parse::Pos_numContext* posNumCtx){}
//void ApplLangInterp::exitPos_num(APPL_Parse::Pos_numContext* Ctx){}

void ApplLangInterp::enterNeg_num(APPL_Parse::Neg_numContext* negNumCtx){}
//void ApplLangInterp::exitNeg_num(APPL_Parse::Neg_numContext* Ctx){}

void ApplLangInterp::enterBooln(APPL_Parse::BoolnContext* boolCtx){}
//void ApplLangInterp::exitBooln(APPL_Parse::BoolnContext* Ctx){}






/*
// placeholder terminal function examples...
void FApplListener::enterMoveStmt(APPL_Parse::MoveStmtContext* ctx){
  if (RobotCmd) RobotCmd->Cmd_MoveForward(1);
}

void FApplListener::enterTurnStmt(APPL_Parse::TurnStmtContext* ctx){
  if (RobotCmd) RobotCmd->Cmd_TurnLeft(90.0f);
}

void FApplListener::enterWaitStmt(APPL_Parse::WaitStmtContext* ctx){
  if (RobotCmd) RobotCmd->Cmd_Wait(1.0f);
}
*/
