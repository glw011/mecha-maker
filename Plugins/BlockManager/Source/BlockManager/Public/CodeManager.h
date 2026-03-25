#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlockData.h"
#include "CodeManager.generated.h"

UCLASS()
class BLOCKMANAGER_API UCodeManager : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

    private: 

        static TArray<FBlockData> BlockArray;

    public:

        // CHANGE THIS TO ADD VARIABLES
        UFUNCTION(BlueprintCallable, Category="Code Block")
        static void AddCodeBlock(FString Name, int32 Widget, float LeftMotor, float RightMotor, float Time, int32 NumTimes);

        UFUNCTION(BlueprintCallable, Category="Code Block")
        static void PrintAllCodeBlocks();

        UFUNCTION(BlueprintCallable, Category="Code Block")
        static void ClearAllCodeBlocks();

        UFUNCTION(BlueprintCallable, Category="Code Block")
        static void AddChildBlock(int32 ParentIndex, FString ChildName, int32 ChildWidget, float LeftMotor, float RightMotor, float Time, int32 NumTimes);

        UFUNCTION(BlueprintCallable, Category="Code Block")
        static void PrintRecursive(const FBlockData& Block);
};