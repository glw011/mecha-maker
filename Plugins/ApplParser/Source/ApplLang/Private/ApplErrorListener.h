#pragma once

#include "antlr4-runtime.h"


// collects syntax errors from antlr + formats into array of strings usable in UE to give code feedback after fail
class ApplErrorListener final : public antlr4::BaseErrorListener{
  public:
    explicit ApplErrorListener(std::vector<std::string>& InErr) : Errors(InErr){}

    void syntaxError(
      antlr4::Recognizer* /*r*/, antlr4::Token* /*t*/, 
      size_t line, size_t charPos, const std::string& msg, 
      std::exception_ptr /*e*/
    )override{
      Errors.push_back("[Line " + (int32_t)line + ":" + (int32_t)charPos + "] " + msg.c_str());
    }

  private:
    std::vector<std::string>& Errors;
};