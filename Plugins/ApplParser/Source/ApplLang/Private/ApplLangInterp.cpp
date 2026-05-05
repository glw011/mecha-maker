#include "ApplLangInterp.h"
#include "ApplTypes.h"
#include <stdexcept>
#include <sstream>
#include <cassert>
#include <algorithm>


void ApplLangInterp::pushScope(){scopeStack_.emplace_back();}

void ApplLangInterp::popScope(){
    if(!scopeStack_.empty()){scopeStack_.pop_back();}
}

ApplValue ApplLangInterp::lookupVar(const std::string& name) const{
    for(int i = static_cast<int>(scopeStack_.size()) - 1; i >= 0; --i){
        auto it = scopeStack_[i].find(name);
        if(it != scopeStack_[i].end()){return it->second;}
    }
    throw ApplRuntimeError("Undefined variable: '" + name + "'");
}

void ApplLangInterp::assignVar(const std::string& name, const ApplValue& val){
    // update existing binding in outer scope
    for(int i = static_cast<int>(scopeStack_.size()) - 1; i >= 0; --i){
        auto it = scopeStack_[i].find(name);
        if(it != scopeStack_[i].end()){
            it->second = val; 
            return;
        }
    }
    // new binding goes in inner frame
    if(!scopeStack_.empty()){
        scopeStack_.back()[name] = val;
    }
    else{
        throw ApplRuntimeError("No active scope for variable: '" + name + "'");
    }
}

bool ApplLangInterp::hasVar(const std::string& name) const{
    for(int i = static_cast<int>(scopeStack_.size()) - 1; i >= 0; --i){
        if(scopeStack_[i].count(name)){
            return true;
        }
    }
    return false;
}

ApplValue ApplLangInterp::getVar(const std::string& name) const{
    return lookupVar(name);
}

ApplValue ApplLangInterp::valueFrom(const std::any& a){
    if(!a.has_value()){
        throw ApplRuntimeError("Expression produced no value");
    }

    try{
        return std::any_cast<ApplValue>(a);
    }
    catch(const std::bad_any_cast&){
        throw ApplRuntimeError("InternalError: unexpected value type in expression");
    }
}


// expression eval helper function 
ApplValue ApplLangInterp::evalExpr(APPL_Parse::ExprContext* ctx){
    return valueFrom(visitExpr(ctx));
}

// sequentially execute block of code helper function
void ApplLangInterp::execCblk(APPL_Parse::CblkContext* ctx){
    pushScope();

    try{
        for(auto* stmt : ctx->statement()){
            visitStatement(stmt);
        }
    }
    catch(...){
        popScope();
        throw;
    }

    popScope();
}


// arithmetic operation helper function
//  - if either operand type = FLT: result type = FLT
ApplValue ApplLangInterp::applyArith(const std::string& op, const ApplValue& lhs, const ApplValue& rhs){
    // INT-DIVIDE & MODULUS
    if(op == "//" || op == "%"){
        int l = lhs.toInt();
        int r = rhs.toInt();

        if(r == 0){
            throw ApplRuntimeError("Divide by Zero");
        }

        return ApplValue(op == "//" ? l/r : l%r);
    }

    // check if either operand is FLT
    bool useFloat = false;
    if(lhs.isFlt() || rhs.isFlt()){
        useFloat = true;
    }

    // ADD
    if(op == "+"){
        return useFloat ? ApplValue(lhs.toDouble() + rhs.toDouble()) : ApplValue(lhs.toInt() + rhs.toInt());
    }

    // SUBTRACT
    if(op == "-"){
        return useFloat ? ApplValue(lhs.toDouble() - rhs.toDouble()) : ApplValue(lhs.toInt() - rhs.toInt());
    }

    // MULTIPLY
    if(op == "*"){
        return useFloat ? ApplValue(lhs.toDouble() * rhs.toDouble()) : ApplValue(lhs.toInt() * rhs.toInt());
    }

    // DIVIDE
    if(op == "/"){
        // INT DBZ
        if(!useFloat && rhs.toInt() == 0){
            throw ApplRuntimeError("Divide by Zero");
        }
        // FLT DBZ
        if(useFloat && rhs.toDouble() == 0.0){
            throw ApplRuntimeError("Divide by Zero");
        }

        return useFloat ? ApplValue(lhs.toDouble() / rhs.toDouble()) : ApplValue(lhs.toInt() / rhs.toInt());
    }

    // EXPONENT
    if(op == "**"){
        // use std::pow() to compute val as double & convert returned val to int unless useFloat
        double v = std::pow(lhs.toDouble(), rhs.toDouble());
        return useFloat ? ApplValue(v) : ApplValue(static_cast<int>(std::round(v)));
    }

    // UNKNOWN OP
    throw ApplRuntimeError("Unknown arithmetic operator: '" + op + "'");
}

// comparison operation helper function
ApplValue ApplLangInterp::applyCompareFn(const std::string& op, const ApplValue& lhs, const ApplValue& rhs){
    if(lhs.isBool() && rhs.isBool()){
        // BOOL (==)
        if(op == "=="){
            return ApplValue(lhs.bval == rhs.bval);
        }
        // BOOL (!=)
        if(op == "!="){
            return ApplValue(lhs.bval != rhs.bval);
        }
        // BOOL (UNKNOWN OP)
        throw ApplRuntimeError("Operator '" + op + "' invalid for bools");
    }

    double l = lhs.toDouble();
    double r = rhs.toDouble();
    // INT/DBL (==)
    if(op == "=="){
        return ApplValue(l == r);
    }
    // INT/DBL (!=)
    if(op == "!="){
        return ApplValue(l != r);
    }
    // INT/DBL (<)
    if(op == "<"){
        return ApplValue(l < r);
    }
    // INT/DBL (<=)
    if(op == "<="){
        return ApplValue(l <= r);
    }
    // INT/DBL (>)
    if(op == ">"){
        return ApplValue(l > r);
    }
    // INT/DBL (>=)
    if(op == ">="){
        return ApplValue(l >= r);
    }
    // INT/DBL (UNKNOWN OP)
    throw ApplRuntimeError("Unknown comparison operator: '" + op + "'");
}

// augmented assignment helper function
ApplValue ApplLangInterp::applyAugop(const std::string& op, const ApplValue& current, const ApplValue& rhs){
    // +=
    if(op == "+="){
        return applyArith("+",  current, rhs);
    }
    // -=
    if(op == "-="){
        return applyArith("-", current, rhs);
    }
    // *=
    if(op == "*="){
        return applyArith("*", current, rhs);
    }
    // /=
    if(op == "/="){
        return applyArith("/", current, rhs);
    }
    // //=
    if(op == "//="){
        return applyArith("//", current, rhs);
    }
    // **=
    if(op == "**="){
        return applyArith("**", current, rhs);
    }
    // UNKNOWN OP
    throw ApplRuntimeError("Unknown augmented-assignment operator: '" + op + "'");
}

// helper function for rules with nested operator types to walk children & return op token
//  - children alternate (i.e. operand, op, operand, op, ...) so operator children at odd indices
//  - opChildIndex is 0 based index into ctx->children
static std::string childOpText(antlr4::ParserRuleContext* ctx, size_t opChildIndex){
    if(opChildIndex < ctx->children.size()){
        auto* node = dynamic_cast<antlr4::tree::TerminalNode*>(ctx->children[opChildIndex]);
        if(node){
            return node->getText();
        }
    }
    return "";
}



//========================= 
//    VISITOR FUNCTIONS
//========================= 

// main : ( statement )* KW_END
std::any ApplLangInterp::visitMain(APPL_Parse::MainContext* ctx){
    // clear function table and stack frames
    scopeStack_.clear();
    functionTable_.clear();
    // push stack frame as global scope
    pushScope();

    // visit/get all function defs in set of 'statement' tokens making up 'main'  
    for(auto* stmt : ctx->statement()){
        if(stmt->fun_def()){
            // visit fun def in parse tree & add to function table
            visitFun_def(stmt->fun_def());
        }
    }

    // sequentially visit/execute statements in 'main' (that are not fun defs)
    try{
        for(auto* stmt : ctx->statement()){
            if(!stmt->fun_def()){
                visitStatement(stmt);
            }
        }
    }
    catch(const ApplReturnException&){
        // return to 'main' so do nothing
        /*
         * TODO: user feedback
         */
    }

    popScope();
    return {};
}

// statement : assign SC | fun_def | conditional | expr SC | return SC
std::any ApplLangInterp::visitStatement(APPL_Parse::StatementContext* ctx){
    if(ctx->assign()){
        visitAssign(ctx->assign());
    }
    else if(ctx->fun_def()){
        visitFun_def(ctx->fun_def());
    }
    else if(ctx->conditional()){
        visitConditional(ctx->conditional());
    }
    else if(ctx->expr()){
        visitExpr(ctx->expr());
    }
    else if(ctx->return_()){
        visitReturn(ctx->return_());
    }
    return {};
}

// assign : ID EQL expr
std::any ApplLangInterp::visitAssign(APPL_Parse::AssignContext* ctx){
    assignVar(ctx->ID()->getText(), evalExpr(ctx->expr()));
    return {};
}

// fun_def : KW_DEF ID LPAREN ( param_list )? RPAREN cblk
std::any ApplLangInterp::visitFun_def(APPL_Parse::Fun_defContext* ctx){
    FunctionDef def;
    // store function's body in struct
    def.body = ctx->cblk();
    // store function's parameters in struct (if any)
    if(ctx->param_list()){
        for(auto* p : ctx->param_list()->ID()){
            def.params.push_back(p->getText());
        }
    }
    // add function to table
    functionTable_[ctx->ID()->getText()] = std::move(def);
    return {};
}

// TODO: MIGHT NEED TO IMPLEMENT SOME LOGIC DEPENDING ON FINALIZED GRAMMAR
std::any ApplLangInterp::visitParam_list(APPL_Parse::Param_listContext*){return {};}

// conditional : if_else_stmt | while_loop | for_loop | for_ea_loop
std::any ApplLangInterp::visitConditional(APPL_Parse::ConditionalContext* ctx){
    if(ctx->if_else_stmt()){
        visitIf_else_stmt(ctx->if_else_stmt());
    }
    else if(ctx->while_loop()){
        visitWhile_loop(ctx->while_loop());
    }
    else if(ctx->for_loop()){
        visitFor_loop(ctx->for_loop());
    }
    else if(ctx->for_ea_loop()){
        visitFor_ea_loop(ctx->for_ea_loop());
    }
    return {};
}

// if_else_stmt : KW_IF LPAREN expr RPAREN cblk ( else_blk )?
std::any ApplLangInterp::visitIf_else_stmt(APPL_Parse::If_else_stmtContext* ctx){
    if(evalExpr(ctx->expr()).toBool()){
        execCblk(ctx->cblk());
    }
    else if(ctx->else_blk()){
        visitElse_blk(ctx->else_blk());
    }
    return {};
}

// else_blk : KW_ELSE if_else_stmt | KW_ELSE cblk
std::any ApplLangInterp::visitElse_blk(APPL_Parse::Else_blkContext* ctx){
    if(ctx->if_else_stmt()){
        visitIf_else_stmt(ctx->if_else_stmt());
    }
    else{
        execCblk(ctx->cblk());
    }
    return {};
}

// while_loop : KW_WHILE LPAREN expr RPAREN cblk
std::any ApplLangInterp::visitWhile_loop(APPL_Parse::While_loopContext* ctx){
    int iterations = 0;
    while(evalExpr(ctx->expr()).toBool()){
        // inf loop safety check
        if(++iterations > kMaxLoopIterations){
            throw ApplRuntimeError("While loop exceeded maximum iteration limit");
        }
        execCblk(ctx->cblk());
    }
    return {};
}

// for_loop : KW_FOR LPAREN assign SC expr SC operatn RPAREN cblk
std::any ApplLangInterp::visitFor_loop(APPL_Parse::For_loopContext* ctx){
    pushScope();
    try{
        visitAssign(ctx->assign());
        int iterations = 0;
        while(evalExpr(ctx->expr()).toBool()){
            // inf loop safety check
            if(++iterations > kMaxLoopIterations){
                throw ApplRuntimeError("For loop exceeded maximum iteration limit");
            }

            execCblk(ctx->cblk());
            visitOperatn(ctx->operatn());
        }
    }
    catch(...){
        popScope();
        throw;
    }

    popScope();
    return {};
}

// for_ea_loop : KW_FOR KW_EACH ID KW_IN ID cblk
std::any ApplLangInterp::visitFor_ea_loop(APPL_Parse::For_ea_loopContext* ctx){
    throw ApplRuntimeError("for each loop in tree but not supported");
    return {};
}

// cblk : LCRLYB ( statement )* RCRLYB
std::any ApplLangInterp::visitCblk(APPL_Parse::CblkContext* ctx){
    execCblk(ctx);
    return {};
}

// return : KW_RETURN expr | KW_RETURN
std::any ApplLangInterp::visitReturn(APPL_Parse::ReturnContext* ctx){
    throw ApplReturnException(ctx->expr() ? evalExpr(ctx->expr()) : ApplValue(0));
    return {};
}

// expr : operatn | factor
std::any ApplLangInterp::visitExpr(APPL_Parse::ExprContext* ctx){
    if(ctx->operatn()){
        return visitOperatn(ctx->operatn());
    }
    return visitFactor(ctx->factor());
}

// operatn : unary_oprtn | binary_oprtn
std::any ApplLangInterp::visitOperatn(APPL_Parse::OperatnContext* ctx){
    if(ctx->unary_oprtn()){
        return visitUnary_oprtn(ctx->unary_oprtn());
    }
    return visitBinary_oprtn(ctx->binary_oprtn());
}

// unary_oprtn : iteratn | prefx_unary_oprtn
std::any ApplLangInterp::visitUnary_oprtn(APPL_Parse::Unary_oprtnContext* ctx){
    if(ctx->iteratn()){
        return visitIteratn(ctx->iteratn());
    }
    return visitPrefx_unary_oprtn(ctx->prefx_unary_oprtn());
}

// iteratn : factor INCR | factor DECR
std::any ApplLangInterp::visitIteratn(APPL_Parse::IteratnContext* ctx){
    if(!ctx->factor()->ID()){
        throw ApplRuntimeError("Increment/decrement requires operand to be variable");
    }

    const std::string name = ctx->factor()->ID()->getText();
    ApplValue curr = lookupVar(name);
    ApplValue result = curr; // returned value

    if (ctx->INCR()){
        assignVar(name, curr.isInt() ? ApplValue(curr.ival + 1) : ApplValue(curr.dval + 1.0));
    }
    else
        assignVar(name, curr.isInt() ? ApplValue(curr.ival - 1) : ApplValue(curr.dval - 1.0));

    return result;
}

// prefx_unary_oprtn : negatn | INCR factor | DECR factor
std::any ApplLangInterp::visitPrefx_unary_oprtn(APPL_Parse::Prefx_unary_oprtnContext* ctx){
    if(ctx->negatn()){
        return visitNegatn(ctx->negatn());
    }

    if(!ctx->factor()->ID()){
        throw ApplRuntimeError("Prefix increment/decrement requires operand to be variable");
    }

    const std::string name = ctx->factor()->ID()->getText();
    ApplValue updated;
    ApplValue curr = lookupVar(name);

    if(ctx->INCR()){
        updated = curr.isInt() ? ApplValue(curr.ival + 1) : ApplValue(curr.dval + 1.0);
    }
    else{
        updated = curr.isInt() ? ApplValue(curr.ival - 1) : ApplValue(curr.dval - 1.0);
    }

    assignVar(name, updated);
    return updated;  // return updated val
}

// negatn : ( LGCL_NOT | KW_NOT ) factor
std::any ApplLangInterp::visitNegatn(APPL_Parse::NegatnContext* ctx){
    return ApplValue(!valueFrom(visitFactor(ctx->factor())).toBool());
}

// binary_oprtn : logic_or_expr | factor augop expr
std::any ApplLangInterp::visitBinary_oprtn(APPL_Parse::Binary_oprtnContext* ctx){
    if(ctx->logic_or_expr()){
        return visitLogic_or_expr(ctx->logic_or_expr());
    }

    if(!ctx->factor()->ID()){
        throw ApplRuntimeError("Left side of augmented assignment must be a variable");
    }

    const std::string name = ctx->factor()->ID()->getText();
    ApplValue result = applyAugop(ctx->augop()->getText(), lookupVar(name), evalExpr(ctx->expr()));
    assignVar(name, result);
    return result;
}

// logic_or_expr : logic_and_expr ( ( KW_OR | LGCL_OR ) logic_and_expr )*
std::any ApplLangInterp::visitLogic_or_expr(APPL_Parse::Logic_or_exprContext* ctx){
    const auto clauses = ctx->logic_and_expr();
    ApplValue result = valueFrom(visitLogic_and_expr(clauses[0]));
    for(size_t i = 1; i < clauses.size(); ++i){
        // break on true clause if/when found
        if(result.toBool()) break;
        result = valueFrom(visitLogic_and_expr(clauses[i]));
    }

    if(clauses.size() > 1) return ApplValue(result.toBool());
    return result;
}

// logic_and_expr : comparison_expr ( ( KW_AND | LGCL_AND ) comparison_expr )*
std::any ApplLangInterp::visitLogic_and_expr(APPL_Parse::Logic_and_exprContext* ctx){
    const auto clauses = ctx->comparison_expr();
    ApplValue result = valueFrom(visitComparison_expr(clauses[0]));
    for(size_t i = 1; i < clauses.size(); ++i){
        // break on false clause if/when found
        if(!result.toBool()) break;
        result = valueFrom(visitComparison_expr(clauses[i]));
    }
    // Same guard as visitLogic_or_expr — only coerce when AND operators were present.
    if(clauses.size() > 1) return ApplValue(result.toBool());
    return result;
}

// comparison_expr : add_expr ( ( LT | LTE | GT | GTE | EQUAL | NOT_EQUAL ) add_expr )*
std::any ApplLangInterp::visitComparison_expr(APPL_Parse::Comparison_exprContext* ctx){
    const auto operands = ctx->add_expr();
    ApplValue lhs = valueFrom(visitAdd_expr(operands[0]));

    if(operands.size() <= 1) return lhs;

    std::vector<std::pair<size_t, std::string>> ops;
    auto collect = [&](std::vector<antlr4::tree::TerminalNode*> nodes, const std::string& text){
        for(auto* n : nodes) ops.push_back({n->getSymbol()->getTokenIndex(), text});
    };
    collect(ctx->LT(), "<");
    collect(ctx->LTE(), "<=");
    collect(ctx->GT(), ">");
    collect(ctx->GTE(), ">=");
    collect(ctx->EQUAL(), "==");
    collect(ctx->NOT_EQUAL(),"!=");
    std::sort(ops.begin(), ops.end());

    for(size_t i = 1; i < operands.size(); ++i){
        ApplValue rhs = valueFrom(visitAdd_expr(operands[i]));
        std::string op = (i-1 < ops.size()) ? ops[i-1].second : "";
        lhs = applyCompareFn(op, lhs, rhs);
    }
    return lhs;
}

// add_expr : mult_expr ( ( ADD | SUB ) mult_expr )*
std::any ApplLangInterp::visitAdd_expr(APPL_Parse::Add_exprContext* ctx){
    const auto terms = ctx->mult_expr();
    ApplValue result = valueFrom(visitMult_expr(terms[0]));

    if(terms.size() <= 1) return result;

    std::vector<std::pair<size_t, std::string>> ops;
    auto collect = [&](std::vector<antlr4::tree::TerminalNode*> nodes, const std::string& text){
        for(auto* n : nodes) ops.push_back({n->getSymbol()->getTokenIndex(), text});
    };
    collect(ctx->ADD(), "+");
    collect(ctx->SUB(), "-");
    std::sort(ops.begin(), ops.end());

    for(size_t i = 1; i < terms.size(); ++i){
        ApplValue rhs = valueFrom(visitMult_expr(terms[i]));
        std::string op = (i-1 < ops.size()) ? ops[i-1].second : "";
        result = applyArith(op, result, rhs);
    }
    return result;
}

// mult_expr : pow_expr ( ( MUL | DIV | INT_DIV | MOD ) pow_expr )*
std::any ApplLangInterp::visitMult_expr(APPL_Parse::Mult_exprContext* ctx){
    const auto factors = ctx->pow_expr();
    ApplValue result = valueFrom(visitPow_expr(factors[0]));

    if(factors.size() <= 1) return result;

    std::vector<std::pair<size_t, std::string>> ops;
    auto collect = [&](std::vector<antlr4::tree::TerminalNode*> nodes, const std::string& text){
        for(auto* n : nodes) ops.push_back({n->getSymbol()->getTokenIndex(), text});
    };
    collect(ctx->MUL(), "*");
    collect(ctx->DIV(), "/");
    collect(ctx->INT_DIV(), "//");
    collect(ctx->MOD(), "%");
    std::sort(ops.begin(), ops.end());

    for(size_t i = 1; i < factors.size(); ++i){
        ApplValue rhs = valueFrom(visitPow_expr(factors[i]));
        std::string op = (i-1 < ops.size()) ? ops[i-1].second : "";
        result = applyArith(op, result, rhs);
    }
    return result;
}

// pow_expr : factor | factor POW pow_expr
std::any ApplLangInterp::visitPow_expr(APPL_Parse::Pow_exprContext* ctx){
    ApplValue base = valueFrom(visitFactor(ctx->factor()));

    if(ctx->pow_expr()){
        return applyArith("**", base, valueFrom(visitPow_expr(ctx->pow_expr())));
    }

    return base;
}

// TODO: NEED TO TEST MORE (don't think need do anything here since should have already handled but leaving note in case) 
std::any ApplLangInterp::visitAugop(APPL_Parse::AugopContext*){return {};}

// factor : LPAREN expr RPAREN | fun_call | number | booln | ID
std::any ApplLangInterp::visitFactor(APPL_Parse::FactorContext* ctx){
    if(ctx->expr()){return visitExpr(ctx->expr());}
    if(ctx->fun_call()){return visitFun_call(ctx->fun_call());}
    if(ctx->number()){return visitNumber(ctx->number());}
    if(ctx->booln()){return visitBooln(ctx->booln());}
    return lookupVar(ctx->ID()->getText());
}

// fun_call : ID LPAREN ( arg_list )? RPAREN
std::any ApplLangInterp::visitFun_call(APPL_Parse::Fun_callContext* ctx){
    const std::string name = ctx->ID()->getText();

    std::vector<ApplValue> args;
    if(ctx->arg_list()){
        for(auto* ex : ctx->arg_list()->expr()){
            args.push_back(evalExpr(ex));
        }
    }

    // check if user defined function
    auto it = functionTable_.find(name);
    if(it != functionTable_.end()){
        const FunctionDef& def = it->second;
        if(args.size() != def.params.size()){
            throw ApplRuntimeError("Function '" + name + "' expects " + std::to_string(def.params.size()) + " args, got " + std::to_string(args.size()));
        }

        pushScope();
        for(size_t i = 0; i < def.params.size(); ++i){
            scopeStack_.back()[def.params[i]] = args[i];
        }

        ApplValue returnVal(0);
        try{
            for(auto* stmt : def.body->statement()){
                visitStatement(stmt);
            }
        }
        catch(const ApplReturnException& ret){
            returnVal = ret.value;
        }
        catch(...){
            popScope();
            throw;
        }
        
        popScope();
        return returnVal;
    }

    if(componentCallHandler){
        return componentCallHandler(name, args);
    }

    throw ApplRuntimeError("Unknown function '" + name + "' was called");
}

// TODO: NEED TO TEST MORE (don't think need do anything here since should have already handled but leaving note in case) 
std::any ApplLangInterp::visitArg_list(APPL_Parse::Arg_listContext*){return {};}

// number : pos_num | neg_num
std::any ApplLangInterp::visitNumber(APPL_Parse::NumberContext* ctx){
    if(ctx->pos_num()){return visitPos_num(ctx->pos_num());}
    return visitNeg_num(ctx->neg_num());
}

// pos_num : INT | FLT
std::any ApplLangInterp::visitPos_num(APPL_Parse::Pos_numContext* ctx){
    if(ctx->FLT()){return ApplValue(std::stod(ctx->FLT()->getText()));}
    return ApplValue(std::stoi(ctx->INT()->getText()));
}

// neg_num : SUB pos_num
std::any ApplLangInterp::visitNeg_num(APPL_Parse::Neg_numContext* ctx){
    ApplValue v = valueFrom(visitPos_num(ctx->pos_num()));
    return v.isFlt() ? ApplValue(-v.dval) : ApplValue(-v.ival);
}

// booln : KW_TRUE | KW_FALSE
std::any ApplLangInterp::visitBooln(APPL_Parse::BoolnContext* ctx){
    return ApplValue(ctx->KW_TRUE() != nullptr);
}
