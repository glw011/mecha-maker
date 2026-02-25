#include "ApplCompiler.h"
#include "Logging/LogMacros.h"
#include "ApplErrorListener.h"
#include "antlr4-runtime/antlr4-runtime.h"
#include "ApplLang/APPL_Lex.h"
#include "ApplLang/APPL_Parse.h"


DEFINE_LOG_CATEGORY_STATIC(ApplCompilerLog, Log, All);


bool UApplCompiler::CompileAndRun(const FString& Source, FApplParseResult& OutResult){
  OutResult = FApplParseResult{};
  OutResult.Errors.Reset();

  // convert UE string to utf-8 (i.e. std::string)
  std::string utf8In = TCHAR_TO_UTF8(*Source);

  try{
    // create text stream from utf-8 input
    antlr4::ANTLRInputStream InputStream(utf8In);
    // lex text stream
    APPL_Lex Lexer(&InputStream);
    // tokenize input
    antlr4::CommonTokenStream Tokens(&Lexer);
    // parse tokens
    APPL_Parse Parser(&Tokens);

    // catch parse syntax errors with custom ApplErrorListener
    FApplErrorListener ErrListener(OutResult.Errors);
    Parser.removeErrorListeners();
    Parser.addErrorListener(&ErrListener);

    // start at entry rule (i.e. main) and build parse tree
    APPL_Parse::MainContext* Tree = Parser.main();

    // count statements in parse tree (unless parse fails)
    const int32 stmtCount = Tree ? (int32)Tree->statement().size() : 0;
    // store count in result struct
    OutResult.StmtCount = stmtCount;
    
    // *** TODO ***   -->   implement checks to set flag
    OutResult.bSuccess = (OutResult.Errors.Num() == 0);   // placeholder

    // log results 
    UE_LOG(ApplCompilerLog, Log, TEXT("ApplCompiler: Success=%s, Statements=%d, Errors=%d"),
      OutResult.bSuccess ? TEXT("true") : TEXT("false"),
      OutResult.StmtCount,
      OutResult.Errors.Num()
    );
    
    return OutResult.bSuccess;
  }
  // catch standard exceptions (set flag/ApplErrorListener and log in UE)
  catch(const std::exception& Ex){
    OutResult.Errors.Add(FString::Printf(TEXT("Parsing Exception: %s"), UTF8_TO_TCHAR(Ex.what())));
    OutResult.bSuccess = false;
    UE_LOG(ApplCompilerLog, Error, TEXT("ApplCompiler Exception: %s"), UTF8_TO_TCHAR(Ex.what()));
    return false;
  }
  // catch other exceptions (set flag/ApplErrorListener and log in UE)
  catch(...){
    OutResult.Errors.Add(TEXT("Unknown exception occurred during parsing..."));
    OutResult.bSuccess = false;
    UE_LOG(ApplCompilerLog, Error, TEXT("APPL Compile Unknown Exception"));
    return false;
  }
}