#include "ApplCompiler.h"
#include "ApplLangInterface.h"   // plain C++ — safe to include here
#include "RobotComponentInterface.h"
#include "Logging/LogMacros.h"


DEFINE_LOG_CATEGORY_STATIC(ApplCompilerLog, Log, All);


bool UApplCompiler::CompileAndRun(const FString& Source, FApplParseResult& OutResult) {
    OutResult = FApplParseResult{};
    OutResult.Errors.Reset();

    ApplParseResult parseResult;
    std::string utf8In(TCHAR_TO_UTF8(*Source));

    // Build the component dispatch lambda here in the UE-facing module.
    // It captures RobotInterface (a UObject ptr) but its type is plain
    // std::function — safe to pass into the UE-blind ApplLang module.
    ComponentCallFn handler = nullptr;
    if (RobotInterface) {
        URobotComponentInterface* iface = RobotInterface;
        handler = [iface](const std::string& name,
                          const std::vector<ApplValue>& args) -> ApplValue {
            return iface->Dispatch(name, args);
        };
    }

    try {
        bool parseSuccess = ApplLangInterface::StartParse(utf8In, parseResult, handler);

        int exCount  = static_cast<int>(parseResult.applExcepts.size());
        int errCount = static_cast<int>(parseResult.applErrors.size());

        for (int i = 0; i < exCount; ++i) {
            FString Msg(UTF8_TO_TCHAR(parseResult.applExcepts[i].c_str()));
            UE_LOG(ApplCompilerLog, Error, TEXT("%s"), *Msg);
        }

        for (int i = 0; i < errCount; ++i) {
            FString Msg(UTF8_TO_TCHAR(parseResult.applErrors[i].c_str()));
            UE_LOG(ApplCompilerLog, Error, TEXT("%s"), *Msg);
            OutResult.Errors.Add(Msg);
        }

        OutResult.StmtCount = parseResult.stmtCount;
        OutResult.bSuccess  = parseResult.success;

        UE_LOG(ApplCompilerLog, Log,
            TEXT("ApplCompiler: Success=%s, Statements=%d, Errors=%d, Exceptions=%d"),
            OutResult.bSuccess ? TEXT("true") : TEXT("false"),
            OutResult.StmtCount, errCount, exCount);

        return OutResult.bSuccess;
    }
    catch (const std::exception& Ex) {
        UE_LOG(ApplCompilerLog, Error, TEXT("ApplCompiler Exception: %s"),
               UTF8_TO_TCHAR(Ex.what()));
        return false;
    }
    catch (...) {
        UE_LOG(ApplCompilerLog, Error, TEXT("APPL Compile Unknown Exception"));
        return false;
    }
}
