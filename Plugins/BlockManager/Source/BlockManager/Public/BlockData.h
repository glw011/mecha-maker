#pragma once

#include "CoreMinimal.h"
#include "BlockData.generated.h"

USTRUCT(BlueprintType)
struct BLOCKMANAGER_API FBlockData
{
    GENERATED_BODY()

    public:

        UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="CodeBlock")
        FString BlockName;

        UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="CodeBlock")
        int32 Widget;

        UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="CodeBlock")
        float LeftMotor;

        UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="CodeBlock")
        float RightMotor;

        UPROPERTY(BlueprintReadWrite, Editanywhere, Category="CodeBlock")
        float Time;

        UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="CodeBlock")
        int32 NumTimes;

        // Doesn't need UProp since only in C++
        TArray<FBlockData> ChildBlocks;

        FBlockData() : BlockName("UnNamed"), Widget(0), LeftMotor(0.f), RightMotor(0.f), Time(0.f), NumTimes(0) {}
        FBlockData(FString InName, int32 InWidget, float FlLeft, float FlRight, float FlTime, int32 InNumTimes) : BlockName(InName), Widget(InWidget), LeftMotor(FlLeft), RightMotor(FlRight), Time(FlTime), NumTimes(InNumTimes) {}
};