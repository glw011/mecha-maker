#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ApplCompiler.generated.h"

USTRUCT(BlueprintType)
struct FApplParseResult{
  GENERATED_BODY()

  UPROPERTY(BlueprintReadOnly) bool bSuccess = false;
  UPROPERTY(BlueprintReadOnly) TArray<FString> Errors;
};

UCLASS()
class APPLPARSER_API UApplCompiler : public UObject{
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintCallable)
  bool Compile(const FString& Source, FApplParseResult& OutErr);
};