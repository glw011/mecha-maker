#include "CodeManager.h"
#include "Engine/Engine.h"

TArray<FBlockData> UCodeManager::BlockArray;

void UCodeManager::AddCodeBlock(FString Name, int32 Widget, float LeftMotor, float RightMotor, float Time, int32 NumTimes)
{
    FBlockData NewBlock(Name, Widget, LeftMotor, RightMotor, Time, NumTimes);
    BlockArray.Add(NewBlock);
}

void UCodeManager::PrintAllCodeBlocks()
{
    for (const FBlockData& Block : BlockArray)
    {
        PrintRecursive(Block);
    }
}

void UCodeManager::PrintRecursive(const FBlockData& Block)
{
    if(GEngine)
    {
        // Check if block is Left Motor, send appropriate vars
        if (Block.BlockName == "Left Motor")
        {
            FString Msg = FString::Printf(TEXT("Block: %s | Widget: %d | Left: %0.2f"), *Block.BlockName, Block.Widget, Block.LeftMotor);
            GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Purple, Msg);
        }

        // Check if block is Right Motor, send appropriate vars
        else if (Block.BlockName == "Right Motor")
        {
            FString Msg = FString::Printf(TEXT("Block: %s | Widget: %d | Right: %0.2f"), *Block.BlockName, Block.Widget, Block.RightMotor);
            GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, Msg);
        }

        // Check if block is Time, send appropriate vars
        else if (Block.BlockName == "Time")
        {
            FString Msg = FString::Printf(TEXT("Block: %s | Widget: %d | Time: %0.2f"), *Block.BlockName, Block.Widget, Block.Time);
            GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan, Msg);
        }

        //else if (Block.BlockName == "NumTimes")

        else 
        {
            FString Msg = FString::Printf(TEXT("Block: %s | Widget: %d | Left: %0.2f | Right: %0.2f | Time: %0.2f | NumTimes: %d"), *Block.BlockName, Block.Widget, Block.LeftMotor, Block.RightMotor, Block.Time, Block.NumTimes);
            GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, Msg);
        }
        

        if (Block.Widget != 4 && Block.ChildBlocks.Num() > 0)
        {
            for (const FBlockData& Child : Block.ChildBlocks)
            {
                PrintRecursive(Child);
            }
        }
    }
}


void UCodeManager::ClearAllCodeBlocks()
{
    BlockArray.Empty();
}

void UCodeManager::AddChildBlock(int32 ParentIndex, FString ChildName, int32 ChildWidget, float ChildLeft, float ChildRight, float ChildTime, int32 ChildNumTimes)
{
    if (!BlockArray.IsValidIndex(ParentIndex))
        return;

    FBlockData& Parent = BlockArray[ParentIndex];

    // Allows any widget except Vars to contain children (need add in Parameters too?)
    if (Parent.Widget != 4)
    {
        Parent.ChildBlocks.Add(FBlockData(ChildName, ChildWidget, ChildLeft, ChildRight, ChildTime, ChildNumTimes));
    }
    else
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red,
                TEXT("This block cannot contain children!"));
        }
    }
}