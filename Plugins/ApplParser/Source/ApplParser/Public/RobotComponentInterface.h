#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ApplTypes.h"
#include "RobotManager.h"

#include "RobotComponentInterface.generated.h"


UCLASS(BlueprintType, Blueprintable)
class APPLPARSER_API URobotComponentInterface : public UObject{
    GENERATED_BODY()

public:
   /** 
    *  Called by ApplCompiler's ComponentCallFn lambda 
    *    - translates interpreter function name + evaluated args into queued movement actions on RobotManager 
    */
    ApplValue Dispatch(const std::string& name, const std::vector<ApplValue>& args);

    // set to URobotManager component on robot actor during robot config (MUST happen before calling CompileAndRun) 
    UPROPERTY(BlueprintReadWrite, Category="Robot")
    URobotManager* RobotManager = nullptr;
};
