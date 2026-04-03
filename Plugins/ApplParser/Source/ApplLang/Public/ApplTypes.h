#pragma once

// ---------------------------------------------------------------------------
//  CANNOT INCLUDE 'antlr4-runtime.h' or any headers that do since
//  ApplParser compiled without RTTI and antlr's CPPUtils.h uses typeid 
//  and requires RTTI...
// ---------------------------------------------------------------------------

#include <string>
#include <vector>
#include <functional>
#include <stdexcept>


// runtime error thrown by interpreter and caught in ApplLangInterface
struct ApplRuntimeError : public std::runtime_error{
    explicit ApplRuntimeError(const std::string& msg) : std::runtime_error(msg){}
};



// enum for types that ApplValues can have (STR not fully implemented!)
enum class ApplType{
    INT, 
    FLT, 
    BOOL, 
    STR
};


//  ApplValue struct for storing runtime values
struct ApplValue{
    ApplType type = ApplType::INT;
    int ival = 0;
    double dval = 0.0;
    bool bval = false;
    std::string sval;

    // constructors
    ApplValue() = default;
    explicit ApplValue(int v) : type(ApplType::INT), ival(v), dval(static_cast<double>(v)), bval(false){}
    explicit ApplValue(double v) : type(ApplType::FLT), ival(static_cast<int>(v)), dval(v), bval(false){}
    explicit ApplValue(bool v) : type(ApplType::BOOL), ival(v ? 1 : 0), dval(v ? 1.0 : 0.0), bval(v){}
    explicit ApplValue(const std::string& v) : type(ApplType::STR), ival(0), dval(0.0), bval(!v.empty()), sval(v){}

    // type checks
    bool isInt() const{return type == ApplType::INT;}
    bool isFlt() const{return type == ApplType::FLT;}
    bool isBool() const{return type == ApplType::BOOL;}
    bool isStr() const{return type == ApplType::STR;}

    // type coercions
    double toDouble() const{
        switch(type){
            case ApplType::INT: return static_cast<double>(ival);
            case ApplType::FLT: return dval;
            case ApplType::BOOL: return bval ? 1.0 : 0.0;
            default: throw ApplRuntimeError("Cannot convert string to number");
        }
    }

    int toInt() const{
        switch(type){
            case ApplType::INT: return ival;
            case ApplType::FLT: return static_cast<int>(dval);
            case ApplType::BOOL: return bval ? 1 : 0;
            default: throw ApplRuntimeError("Cannot convert string to int");
        }
    }

    bool toBool() const{
        switch(type){
            case ApplType::BOOL: return bval;
            case ApplType::INT: return ival != 0;
            case ApplType::FLT: return dval != 0.0;
            case ApplType::STR: return !sval.empty();
        }

        return false;
    }

    // type strings
    std::string typeName() const{
        switch(type){
            case ApplType::INT: return "int";
            case ApplType::FLT: return "float";
            case ApplType::BOOL: return "bool";
            case ApplType::STR: return "string";
        }
        return "unknown";
    }
};


//  ComponentCallFn is the callback type passed from ApplParser into ApplLang
//      - actual function implementation takes string (component function name in library) as 1st arg
//      - actual function implementation takes array of vals (args to pass to component function) as 2nd arg
//      - actual function implementation calls the real function located on robot matching passed name and passes args from passed array
using ComponentCallFn = std::function<ApplValue(const std::string&, const std::vector<ApplValue>&)>;
