#pragma once

// ---------------------------------------------------------------------------
//  ApplLangInterface.h  (ApplLang module — UE-blind)
//
//  NOTE: This header intentionally does NOT include ApplLangInterp.h.
//  Including it here would drag antlr4-runtime.h into every translation unit
//  that includes ApplLangInterface.h (including the ApplParser module), which
//  is compiled with -fno-rtti and would break on antlr4's use of typeid.
//
//  Only ApplTypes.h is included here — it contains no antlr4 dependencies.
// ---------------------------------------------------------------------------

#include "ApplTypes.h"   // ApplValue, ComponentCallFn — no antlr4 includes
#include <string>
#include <vector>


struct ApplParseResult {
    bool                     success    = false;
    std::vector<std::string> applErrors;
    std::vector<std::string> applExcepts;
    int32_t                  stmtCount  = 0;
};

class ApplLangInterface {
public:
    // componentHandler may be nullptr (parse-only / syntax-check mode).
    static bool StartParse(
        const std::string&  utf8In,
        ApplParseResult&    result,
        ComponentCallFn     componentHandler = nullptr
    );
};
