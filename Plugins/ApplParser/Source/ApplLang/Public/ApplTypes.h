#pragma once

// ---------------------------------------------------------------------------
//  ApplTypes.h
//
//  Minimal plain-C++ types shared between the ApplLang module (UE-blind) and
//  the ApplParser module (UE-facing).
//
//  IMPORTANT: This header must never include antlr4-runtime.h or any header
//  that transitively does so.  The ApplParser module is compiled without RTTI
//  (-fno-rtti) and antlr4's CPPUtils.h uses typeid, which requires RTTI.
//  By isolating ApplValue here we allow RobotComponentInterface.h to get the
//  types it needs without dragging in the antlr4 include chain.
// ---------------------------------------------------------------------------

#include <string>
#include <vector>
#include <functional>
#include <stdexcept>


// ---------------------------------------------------------------------------
//  Runtime error — thrown by the interpreter, caught in ApplLangInterface.
// ---------------------------------------------------------------------------
struct ApplRuntimeError : public std::runtime_error {
    explicit ApplRuntimeError(const std::string& msg) : std::runtime_error(msg) {}
};


// ---------------------------------------------------------------------------
//  ApplType — tag for the ApplValue union.
// ---------------------------------------------------------------------------
enum class ApplType { INT, FLT, BOOL, STR };


// ---------------------------------------------------------------------------
//  ApplValue — tagged runtime value.
//  Fields are declared in the order they are initialized in every constructor
//  to satisfy -Wreorder-ctor (Werror in UE builds).
// ---------------------------------------------------------------------------
struct ApplValue {
    ApplType    type  = ApplType::INT;
    int         ival  = 0;
    double      dval  = 0.0;
    bool        bval  = false;
    std::string sval;

    // Constructors — initializer-list order matches declaration order above.
    ApplValue() = default;

    explicit ApplValue(int v)
        : type(ApplType::INT), ival(v), dval(static_cast<double>(v)), bval(false) {}

    // dval initialized before ival in the original code triggered -Wreorder.
    // Fixed: ival comes first in the initializer list, matching the struct layout.
    explicit ApplValue(double v)
        : type(ApplType::FLT), ival(static_cast<int>(v)), dval(v), bval(false) {}

    explicit ApplValue(bool v)
        : type(ApplType::BOOL), ival(v ? 1 : 0), dval(v ? 1.0 : 0.0), bval(v) {}

    explicit ApplValue(const std::string& v)
        : type(ApplType::STR), ival(0), dval(0.0), bval(!v.empty()), sval(v) {}

    // Type queries
    bool isInt()  const { return type == ApplType::INT;  }
    bool isFlt()  const { return type == ApplType::FLT;  }
    bool isBool() const { return type == ApplType::BOOL; }
    bool isStr()  const { return type == ApplType::STR;  }

    // Coercions
    double toDouble() const;
    int    toInt()    const;
    bool   toBool()   const;

    std::string typeName() const;
};


// ---------------------------------------------------------------------------
//  ComponentCallFn — the callback type passed from ApplParser into ApplLang.
//  Using a plain std::function keeps antlr4 types out of the ApplParser module.
// ---------------------------------------------------------------------------
using ComponentCallFn =
    std::function<ApplValue(const std::string&, const std::vector<ApplValue>&)>;
