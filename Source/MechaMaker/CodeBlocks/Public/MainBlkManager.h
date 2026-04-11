#pragma once
#include "CodeBlocks.h"
#include "MainBlock.h"
#include <unordered_map>
#include <memory>
#include <string>
#include <vector>

class BlockManager {
  public:
    static BlockManager& getInstance();

    // Called from Unreal when block dragged into ProgramArea from side menu
    //  - Returns: BlockId or -1 on fail
    int newBlockInArea(CodeBlocks::BlockType blkType);

    // Called from Unreal when block dragged into a slot within a block from side menu
    //  - Returns: BlockId or -1 on failure
    int newBlockInSlot(CodeBlocks::BlockType blkType, int parentId, int slotPos);

    // Called from Unreal when a sized block (funDef/funCall) is dragged into ProgramArea from side menu
    //  - Returns: BlockId or -1 on failure
    int newSizedBlockInArea(CodeBlocks::BlockType blkType, int argCount);

    // Called from Unreal when a sized block is dragged into a slot from side menu
    //  - Returns: BlockId or -1 on failure
    int newSizedBlockInSlot(CodeBlocks::BlockType blkType, int argCount, int parentId, int slotPos);

    // Called from Unreal when an existing block is moved from one slot into another slot
    //  - oldParentId/oldSlotPos: where block came from (-1 if it came from the program area)
    //  - Returns: true on success, else false
    bool moveBlockToSlot(int blockId, int newParentId, int newSlotPos, int oldParentId, int oldSlotPos);

    // Called from Unreal when an existing block is moved out of a slot into the program area
    //  - oldParentId/oldSlotPos: the slot block came from (-1 if already in area — then it's a reorder)
    //  - Returns: true on success, else false
    bool moveBlockToArea(int blockId, int oldParentId, int oldSlotPos);

    // Called from Unreal when a block already in the program area is re-dropped onto the area.
    // Removes it from its current position and appends it to the end.
    //  - Returns: true on success, else false
    bool moveBlockToEndOfArea(int blockId);

    // Called from Unreal when a block is reordered within the program area
    //  - insertBefore: true = place before referenceBlockId, false = place after
    //  - Returns: true on success, else false
    bool reorderInArea(int blockId, int referenceBlockId, bool insertBefore);

    // Called from Unreal when block is discarded/deleted
    //  - Returns: true on success, else false
    bool removeBlock(int blockId);

    // ----------------------------------------------------------------
    // Code block sequence (CBLK_SBLK / nested CodeAreaSlot)
    // ----------------------------------------------------------------

    // Create new block from side menu and append to a CBLK_SBLK sequence
    int newBlockInCodeBlock(CodeBlocks::BlockType blkType, int cblkId);

    // Create new sized block from side menu and append to a CBLK_SBLK sequence
    int newSizedBlockInCodeBlock(CodeBlocks::BlockType blkType, int argCount, int cblkId);

    // Move an existing block into a CBLK_SBLK sequence.
    // oldCblkId != -1   → came from another CBLK_SBLK
    // oldParentId != -1 → came from a single BlockSlot (supply oldSlotPos too)
    // both == -1        → came from the main program area
    bool moveBlockToCodeBlock(int blockId, int cblkId, int oldCblkId, int oldParentId, int oldSlotPos);

    // Remove a block from a CBLK_SBLK sequence (does not delete it from the registry)
    bool removeBlockFromCodeBlock(int blockId, int cblkId);

    // Reorder within a CBLK_SBLK sequence — stub, implement later
    bool reorderInCodeBlock(int blockId, int refBlockId, int cblkId, bool insertBefore);

    // Store user-input string for a specific slot on a block (e.g. var name, data value)
    void setUserInput(int blockId, int slotPos, std::string inputStr);

    // Get user-input string for a specific slot on a block
    std::string getUserInput(int blockId, int slotPos);

    // Get the full compiled ProgramString (or error message on failure)
    std::string getProgramString();

  private:
    BlockManager();
    BlockManager(const BlockManager&) = delete;
    BlockManager& operator=(const BlockManager&) = delete;

    int nextId = 0;
    MainBlock mainBlock;
    std::unordered_map<int, std::unique_ptr<Block>> blockRegistry;

    int registerNewBlock(CodeBlocks::BlockType blkType);
    int registerNewSizedBlock(CodeBlocks::BlockType blkType, int argCount);
};
