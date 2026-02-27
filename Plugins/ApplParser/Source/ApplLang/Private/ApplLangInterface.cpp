#pragma GCC visibility push(default)
#include "ApplLangInterface.h"

THIRD_PARTY_INCLUDES_START
#include "antlr4-runtime.h"
THIRD_PARTY_INCLUDES_END

#include "ApplErrorListener.h"
#include "APPL_Lex.h"
#include "APPL_Parse.h"


bool ApplLangInterface::StartParse(const std::string utf8In, ApplParseResult& result){
  // ensure cleared result struct
  result.success = false;
  result.applErrors.clear();
  result.applExcepts.clear();
  result.stmtCount = 0;

  try{
    // text stream from utf-8 input
    antlr4::ANTLRInputStream InputStream(utf8In);
    // lexer from text stream
    APPL_Lex Lexer(&InputStream);
    // tokenizer from lexer
    antlr4::CommonTokenStream Tokens(&Lexer);
    // parser from tokenizer
    APPL_Parse Parser(&Tokens);

    // init custom ApplErrorListener
    ApplErrorListener ErrListener(result.applErrors);
    // remove default listener
    Parser.removeErrorListeners();
    // use custom ApplErrorListener to catch syntax errors 
    Parser.addErrorListener(&ErrListener);

    // start at entry rule (i.e. main) and build parse tree
    APPL_Parse::MainContext* Tree = Parser.main();

    // count statements in parse tree (unless parse fails)
    const int32_t statmentCount = Tree ? (int32)Tree->statement().size() : 0;
    // store count in result struct
    result.stmtCount = statmentCount;

    // walk tree w/ listener to trigger robot behavior when encountered
    //antlr4::tree::ParseTreeWalker Walker;
    //FApplListener Listener(Context);
    //Walker.walk(&Listener, Tree);

    
    // *** TODO ***   -->   implement real checks to set flag
    result.success = (result.applErrors.size() == 0);   // placeholder
    
    return result.success;
  }
  // catch standard exceptions (set flag/ApplErrorListener and log in UE)
  catch(const std::exception& ex){
    result.applExcepts.push_back(std::string("Parsing Exception: ") + ex.what());
    result.success = false;
    return false;
  }
  // catch other exceptions (set flag/ApplErrorListener and log in UE)
  catch(...){
    result.applExcepts.push_back("Unknown exception during parsing!");
    result.success = false;
    return false;
  }
}
#pragma GCC visibility pop
