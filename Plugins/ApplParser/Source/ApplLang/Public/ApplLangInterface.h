#pragma once

#include <string>
#include <vector>


struct ApplParseResult{
  bool success = false;
  std::vector<std::string> applErrors;
  std::vector<std::string> applExcepts;
  int32_t stmtCount = 0;
};

class ApplLangInterface{
  public:
    static bool StartParse(const std::string utf8In, ApplParseResult& result);
};

