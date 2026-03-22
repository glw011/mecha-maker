#pragma once

THIRD_PARTY_INCLUDES_START
#include "antlr4-runtime.h"
THIRD_PARTY_INCLUDES_END


// collects syntax errors from antlr + formats into array of strings usable in UE to give code feedback after fail
class ApplErrorListener final : public antlr4::BaseErrorListener{
  public:
    explicit ApplErrorListener(std::vector<std::string>& InErr) : Errors(InErr){}

    void syntaxError(
      antlr4::Recognizer* /*r*/, antlr4::Token* token, 
      size_t line, size_t /*charPos*/, const std::string& msg, 
      std::exception_ptr /*e*/)override{
        //Errors.push_back("'" + token->getText() + "' at [Line " + std::to_string(line) + ":" + std::to_string(charPos) + "] " + msg);
        Errors.push_back(
          // "[Line 5:26] 'varName' - could not be parsed as a valid reference"
          "[Line " + std::to_string(line) + ":" + std::to_string(token->getCharPositionInLine()) + "] '" + token->getText() + "' - " + msg
        );
    }

  private:
    std::vector<std::string>& Errors;
};