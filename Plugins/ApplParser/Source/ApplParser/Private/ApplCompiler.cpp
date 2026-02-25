#include "ApplCompiler.h"
#include "ApplLangInterface.h"
#include "Logging/LogMacros.h"


DEFINE_LOG_CATEGORY_STATIC(ApplCompilerLog, Log, All);


bool UApplCompiler::CompileAndRun(const FString& Source, FApplParseResult& OutResult){
  OutResult = FApplParseResult{};
  OutResult.Errors.Reset();

  // init c++ result struct
  ApplLangInterface::ApplParseResult& parseResult;

  // convert UE string to utf-8 (i.e. std::string)
  std::string& utf8In = TCHAR_TO_UTF8(*Source);

  try{
    // pass utf-8 string and c++ result struct to ApplLang and begin parsing
    bool parseSuccess = ApplLangInterface::StartParse(utf8In, parseResult);

    // log any exceptions caught during parse
    if((int exceptCount = parseResult.applExcepts.size()) > 0){
      for(int i=0; i<exceptCount; i++) UE_LOG(ApplCompilerLog, Error, TEXT(UTF8_TO_TCHAR(parseResult.applExcepts.at(i))));
    }

    // log any syntax/other errors
    if((int errCount = parseResult.applErrors.size()) > 0){
      for(int i=0; i<errCount; i++) UE_LOG(ApplCompilerLog, Error, TEXT(UTF8_TO_TCHAR(parseResult.applErrors.at(i))));
    }

    // store c++ struct in UE result struct
    OutResult.StmtCount = parseResult.stmtCount;
    OutResult.bSuccess = parseResult.success;

    // log parse results 
    UE_LOG(ApplCompilerLog, Log, TEXT("ApplCompiler: Success=%s, Statements=%d, Errors=%d"),
      OutResult.bSuccess ? TEXT("true") : TEXT("false"),
      OutResult.StmtCount,
      OutResult.Errors.Num()
    );

    return OutResult.bSuccess;
  }

  // catch standard exceptions
  catch(const std::exception& Ex){
    UE_LOG(ApplCompilerLog, Error, TEXT("ApplCompiler Exception: %s"), UTF8_TO_TCHAR(Ex.what()));
    return false;
  }
  // catch other exceptions
  catch(...){
    UE_LOG(ApplCompilerLog, Error, TEXT("APPL Compile Unknown Exception"));
    return false;
  }
}