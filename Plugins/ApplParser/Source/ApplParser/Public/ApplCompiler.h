#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ApplCompiler.generated.h"

USTRUCT(BlueprintType)
struct FApplParseResult{
  GENERATED_BODY()

  UPROPERTY(BlueprintReadOnly) bool bSuccess = false;
  UPROPERTY(BlueprintReadOnly) TArray<FString> Errors;
  UPROPERTY(BlueprintReadOnly) int32 StmtCount = 0;
};

UCLASS(BlueprintType)
class APPLPARSER_API UApplCompiler : public UObject{
  GENERATED_BODY()

  public:
    UFUNCTION(BlueprintCallable, Category="ApplParser")
    bool CompileAndRun(const FString& Source, FApplParseResult& OutResult);
};