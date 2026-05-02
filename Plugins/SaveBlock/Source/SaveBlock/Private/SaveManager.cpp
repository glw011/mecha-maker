#include "SaveManager.h"
#include "SaveDataArray.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "JsonObjectConverter.h"

// Just to check and see if Movement can be called without cast
#include "BaseMovement.h"           
#include "GameFramework/Character.h"  

static FString GetFilePath()
{
    return FPaths::ProjectSavedDir() + "SaveData.json";
}

void USaveManager::AddSave(FString Name, TArray<FString> ArgNames, TArray<int32> ArgTypes, FString ContentString)
{
    FSaveDataArray SavedBlocks;

    FString FilePath = GetFilePath();
    FString JsonString;

    if (FFileHelper::LoadFileToString(JsonString, *FilePath))
    {
        FJsonObjectConverter::JsonObjectStringToUStruct(JsonString, &SavedBlocks, 0, 0);
    }

    FSaveData NewBlock;
    NewBlock.Name = Name;
    NewBlock.ArgNames = ArgNames;
    NewBlock.ArgTypes = ArgTypes;
    NewBlock.ContentString = ContentString; 

    SavedBlocks.Saves.Add(NewBlock);

    FJsonObjectConverter::UStructToJsonObjectString(SavedBlocks, JsonString);
    FFileHelper::SaveStringToFile(JsonString, *FilePath);
}

TArray<FSaveData> USaveManager::LoadAllSaves()
{
    FSaveDataArray SavedBlocks;

    FString FilePath = GetFilePath();
    FString JsonString;

    if (FFileHelper::LoadFileToString(JsonString, *FilePath))
    {
        FJsonObjectConverter::JsonObjectStringToUStruct(JsonString, &SavedBlocks, 0,0);
    }

    return SavedBlocks.Saves;
}

// Just to check and see if Movement can be called without cast
void USaveManager::TestMove(ACharacter* Character)
{
    UBaseMovement* MoveComp = Character->FindComponentByClass<UBaseMovement>();

    if(MoveComp)
    {
        MoveComp->StartMove(100, 100, 3, 1000, 10);
    }
}