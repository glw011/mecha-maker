#pragma once

#include "CoreMinimal.h"
#include "antlr4-runtime.h"

// collects syntax errors from antlr + formats into array of strings usable in UE
class FApplErrorListener final : public antlr4::BaseErrorListener{
  public:
    explicit FApplErrorListener(TArray<FString>& InErr) : Errors(InErr){}

    void syntaxError(
      antlr4::Recognizer* /*r*/, antlr4::Token* /*t*/, 
      size_t line, size_t charPos, const std::string& msg, 
      std::exception_ptr /*e*/
    )override{
      Errors.Add(FString::Printf(TEXT("Line %d:%d %s"), (int32)line, (int32)charPos, UTF8_TO_TCHAR(msg.c_str())));
    }

  private:
    TArray<FString>& Errors;
};