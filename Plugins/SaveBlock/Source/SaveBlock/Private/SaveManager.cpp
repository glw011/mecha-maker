#include "SaveManager.h"
#include "SaveDataArray.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "JsonObjectConverter.h"

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

