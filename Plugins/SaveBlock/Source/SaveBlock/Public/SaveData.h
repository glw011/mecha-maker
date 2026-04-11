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
    FString instructions;

};