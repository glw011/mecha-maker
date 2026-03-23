#pragma once

#include "ApplVisibility.h"
#include "ApplTypes.h"  
#include <string>
#include <vector>


struct ApplParseResult{
  bool success = false;
  std::vector<std::string> applErrors;
  std::vector<std::string> applExcepts;
  int32_t stmtCount = 0;
};

class APPL_API ApplLangInterface {
  public:
    // componentHandler can be nullptr for parse testing
    static bool StartParse(
      const std::string& utf8In,
      ApplParseResult& result,
      ComponentCallFn componentHandler = nullptr
  );
};
