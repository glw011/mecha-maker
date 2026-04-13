#pragma once

#include "CoreMinimal.h"
#include "SaveData.generated.h"

USTRUCT(BlueprintType)
struct SAVEBLOCK_API FSaveData
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    FString Name;

    UPROPERTY(BlueprintReadWrite)
    TArray<FString> ArgNames;

    UPROPERTY(BlueprintReadWrite)
    TArray<int32> ArgTypes;

    UPROPERTY(BlueprintReadWrite)
    FString ContentString;
};