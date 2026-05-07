#include "ApplCompiler.h"
#include "ApplLangInterface.h"   // plain C++ — safe to include here
#include "RobotComponentInterface.h"
#include "Logging/LogMacros.h"


DEFINE_LOG_CATEGORY_STATIC(ApplCompilerLog, Log, All);


bool UApplCompiler::CompileAndRun(const FString& Source, FApplParseResult& OutResult){
    OutResult = FApplParseResult{};
    OutResult.Errors.Reset();

    UE_LOG(ApplCompilerLog, Warning, TEXT("[DBG] CompileAndRun called. Source length=%d"), Source.Len());
    UE_LOG(ApplCompilerLog, Warning, TEXT("[DBG] RobotInterface is %s"), RobotInterface ? TEXT("SET") : TEXT("NULL"));

    ApplParseResult parseResult;
    std::string utf8In(TCHAR_TO_UTF8(*Source));

    // clear queue from previous run
    if(RobotInterface && RobotInterface->RobotManager){
        UE_LOG(ApplCompilerLog, Warning, TEXT("[DBG] Calling ClearQueue on RobotManager"));
        RobotInterface->RobotManager->ClearQueue();
    }
    else{
        UE_LOG(ApplCompilerLog, Error, TEXT("[DBG] ClearQueue SKIPPED — RobotInterface=%s, RobotManager=%s"),
            RobotInterface ? TEXT("set") : TEXT("NULL"),
            (RobotInterface && RobotInterface->RobotManager) ? TEXT("set") : TEXT("NULL"));
    }

    /**
     * Component Dispatch (lambda)
     *  - captures RobotInterface (UObject ptr) but type is std::function (can be passed into ApplLang safely)
     */

    ComponentCallFn handler = nullptr;
    if(RobotInterface){
        URobotComponentInterface* iface = RobotInterface;
        UE_LOG(ApplCompilerLog, Warning, TEXT("[DBG] ComponentCallFn handler created (RobotInterface is valid)"));

        handler = [iface](const std::string& name, const std::vector<ApplValue>& args) -> ApplValue {
            return iface->Dispatch(name, args);
        };
    }
    else{
        UE_LOG(ApplCompilerLog, Error, TEXT("[DBG] ComponentCallFn handler is NULL — RobotInterface not set"));
    }

    try{
        bool parseSuccess = ApplLangInterface::StartParse(utf8In, parseResult, handler);

        int exCount  = static_cast<int>(parseResult.applExcepts.size());
        int errCount = static_cast<int>(parseResult.applErrors.size());

        for(int i = 0; i < exCount; ++i){
            FString Msg(UTF8_TO_TCHAR(parseResult.applExcepts[i].c_str()));
            UE_LOG(ApplCompilerLog, Error, TEXT("%s"), *Msg);
        }

        for(int i = 0; i < errCount; ++i){
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
    catch(const std::exception& Ex){
        UE_LOG(ApplCompilerLog, Error, TEXT("ApplCompiler Exception: %s"), UTF8_TO_TCHAR(Ex.what()));
        return false;
    }
    catch (...) {
        UE_LOG(ApplCompilerLog, Error, TEXT("APPL Compile Unknown Exception"));
        return false;
    }
}
