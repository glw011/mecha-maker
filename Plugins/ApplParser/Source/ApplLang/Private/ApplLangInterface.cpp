#include "ApplVisibility.h"
APPL_VISIBILITY_PUSH

#include "ApplLangInterface.h"
#include "ApplLangInterp.h"

THIRD_PARTY_INCLUDES_START
#include "antlr4-runtime.h"
THIRD_PARTY_INCLUDES_END

#include "ApplErrorListener.h"
#include "APPL_Lex.h"
#include "APPL_Parse.h"


bool ApplLangInterface::StartParse(
    const std::string& utf8In,
    ApplParseResult&   result,
    ComponentCallFn    componentHandler)
{
    result.success = false;
    result.applErrors.clear();
    result.applExcepts.clear();
    result.stmtCount = 0;

    try {
        antlr4::ANTLRInputStream  InputStream(utf8In);
        APPL_Lex                  Lexer(&InputStream);
        antlr4::CommonTokenStream Tokens(&Lexer);
        APPL_Parse                Parser(&Tokens);

        ApplErrorListener ErrListener(result.applErrors);
        Parser.removeErrorListeners();
        Parser.addErrorListener(&ErrListener);

        APPL_Parse::MainContext* Tree = Parser.main();

        result.stmtCount = Tree
            ? static_cast<int32_t>(Tree->statement().size())
            : 0;

        if (result.applErrors.empty() && Tree) {
            ApplLangInterp Interpreter;

            if (componentHandler)
                Interpreter.componentCallHandler = componentHandler;

            try {
                Interpreter.visitMain(Tree);
            } catch (const ApplRuntimeError& rte) {
                result.applErrors.push_back(
                    std::string("Runtime error: ") + rte.what());
            }
        }

        result.success = result.applErrors.empty();
        return result.success;
    }
    catch (const std::exception& ex) {
        result.applExcepts.push_back(std::string("Parsing exception: ") + ex.what());
        result.success = false;
        return false;
    }
    catch (...) {
        result.applExcepts.push_back("Unknown exception during parsing!");
        result.success = false;
        return false;
    }
}

APPL_VISIBILITY_POP
