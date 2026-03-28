#pragma once

#include "CoreMinimal.h"
#include "SaveData.h"
#include "SaveDataArray.generated.h"

USTRUCT()
struct SAVEBLOCK_API FSaveDataArray
{
    GENERATED_BODY()

    UPROPERTY()
    TArray<FSaveData> Saves;
};