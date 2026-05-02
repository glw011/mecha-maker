#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SaveData.h"
#include "SaveManager.generated.h"

UCLASS()
class SAVEBLOCK_API USaveManager : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

    public:

        UFUNCTION(BlueprintCallable, Category="Block Save")
        static void AddSave(FString Name, TArray<FString> ArgNames, TArray<int32> ArgTypes, FString ContentString);

        UFUNCTION(BlueprintCallable, Category="Block Save")
        static TArray<FSaveData> LoadAllSaves();

        // Just to check and see if Movement can be called without cast
        UFUNCTION(BlueprintCallable, Category="Block Save")
        static void TestMove(ACharacter* Character);
};