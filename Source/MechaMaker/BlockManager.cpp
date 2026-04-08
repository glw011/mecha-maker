#include "BlockManager.h"
#include "CodeBlocks/Public/MainBlkManager.h"

int32 UBlockManager::NewBlockInArea(int32 BackendBlockType){
    return BlockManager::getInstance().newBlockInArea(
        static_cast<CodeBlocks::BlockType>(BackendBlockType));
}

int32 UBlockManager::NewBlockInSlot(int32 BackendBlockType, int32 ParentId, int32 SlotPos){
    return BlockManager::getInstance().newBlockInSlot(
        static_cast<CodeBlocks::BlockType>(BackendBlockType), ParentId, SlotPos);
}

int32 UBlockManager::NewSizedBlockInArea(int32 BackendBlockType, int32 ArgCount){
    return BlockManager::getInstance().newSizedBlockInArea(
        static_cast<CodeBlocks::BlockType>(BackendBlockType), ArgCount);
}

int32 UBlockManager::NewSizedBlockInSlot(int32 BackendBlockType, int32 ArgCount, int32 ParentId, int32 SlotPos){
    return BlockManager::getInstance().newSizedBlockInSlot(
        static_cast<CodeBlocks::BlockType>(BackendBlockType), ArgCount, ParentId, SlotPos);
}

bool UBlockManager::MoveBlockToSlot(int32 BlockId, int32 NewParentId, int32 NewSlotPos, int32 OldParentId, int32 OldSlotPos){
    return BlockManager::getInstance().moveBlockToSlot(BlockId, NewParentId, NewSlotPos, OldParentId, OldSlotPos);
}

bool UBlockManager::MoveBlockToArea(int32 BlockId, int32 OldParentId, int32 OldSlotPos){
    return BlockManager::getInstance().moveBlockToArea(BlockId, OldParentId, OldSlotPos);
}

bool UBlockManager::ReorderInArea(int32 BlockId, int32 ReferenceBlockId, bool bInsertBefore){
    return BlockManager::getInstance().reorderInArea(BlockId, ReferenceBlockId, bInsertBefore);
}

bool UBlockManager::RemoveBlock(int32 BlockId){
    return BlockManager::getInstance().removeBlock(BlockId);
}

void UBlockManager::SetUserInput(int32 BlockId, int32 SlotPos, const FString& InputStr){
    BlockManager::getInstance().setUserInput(BlockId, SlotPos, TCHAR_TO_UTF8(*InputStr));
}

FString UBlockManager::GetUserInput(int32 BlockId, int32 SlotPos){
    std::string result = BlockManager::getInstance().getUserInput(BlockId, SlotPos);
    return FString(UTF8_TO_TCHAR(result.c_str()));
}

FString UBlockManager::GetProgramString(){
    std::string result = BlockManager::getInstance().getProgramString();
    return FString(UTF8_TO_TCHAR(result.c_str()));
}
