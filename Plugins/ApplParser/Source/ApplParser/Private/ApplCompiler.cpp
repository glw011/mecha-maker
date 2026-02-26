#include "ApplCompiler.h"
#include "ApplLangInterface.h"
#include "Logging/LogMacros.h"


DEFINE_LOG_CATEGORY_STATIC(ApplCompilerLog, Log, All);


bool UApplCompiler::CompileAndRun(const FString& Source, FApplParseResult& OutResult){
  OutResult = FApplParseResult{};
  OutResult.Errors.Reset();

  // init c++ result struct
  ApplParseResult parseResult;

  // need utf-8 for string in c++
  std::string utf8In(TCHAR_TO_UTF8(*Source));

  try{
    // pass utf-8 string and c++ result struct to ApplLang and begin parsing
    bool parseSuccess = ApplLangInterface::StartParse(utf8In, parseResult);

    // log any exceptions caught during parse
    int exCount = (int)parseResult.applExcepts.size();
    if(exCount > 0){
      for(int i=0; i<exCount; i++){
        //UE_LOG(ApplCompilerLog, Error, TEXT(UTF8_TO_TCHAR(parseResult.applExcepts.at(i))));
        FString Msg(UTF8_TO_TCHAR(parseResult.applExcepts[i].c_str()));
        UE_LOG(ApplCompilerLog, Error, TEXT("%s"), *Msg);
      }
    }

    int errCount = (int)parseResult.applErrors.size();
    // log any syntax errors
    if(errCount > 0){
      for(int i=0; i<errCount; i++){
        //UE_LOG(ApplCompilerLog, Error, TEXT(UTF8_TO_TCHAR(parseResult.applErrors.at(i))));
        FString Msg(UTF8_TO_TCHAR(parseResult.applErrors[i].c_str()));
        UE_LOG(ApplCompilerLog, Error, TEXT("%s"), *Msg);
        OutResult.Errors.Add(Msg); 
      }
    }

    // store c++ struct in UE result struct
    OutResult.StmtCount = parseResult.stmtCount;
    OutResult.bSuccess = parseResult.success;

    // log parse results 
    UE_LOG(ApplCompilerLog, Log, TEXT("ApplCompiler: Success=%s, Statements=%d, SyntaxErrors=%d, Exceptions=%d"),
      OutResult.bSuccess ? TEXT("true") : TEXT("false"),
      OutResult.StmtCount,
      errCount,
      exCount
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