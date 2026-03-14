#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ApplCompiler.generated.h"

// Forward declare — defined in same module, no cross-module UE issue.
class URobotComponentInterface;


USTRUCT(BlueprintType)
struct FApplParseResult {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly) bool           bSuccess   = false;
    UPROPERTY(BlueprintReadOnly) TArray<FString> Errors;
    UPROPERTY(BlueprintReadOnly) int32           StmtCount  = 0;
};


UCLASS(BlueprintType)
class APPLPARSER_API UApplCompiler : public UObject {
    GENERATED_BODY()

public:
    // Set this before calling CompileAndRun so component function calls in
    // the player's program are dispatched to the correct robot Blueprint events.
    // If nullptr, component function calls will produce a runtime error.
    UPROPERTY(BlueprintReadWrite, Category="ApplParser")
    URobotComponentInterface* RobotInterface = nullptr;

    UFUNCTION(BlueprintCallable, Category="ApplParser")
    bool CompileAndRun(const FString& Source, FApplParseResult& OutResult);
};
