#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlockManager.generated.h"

/**
 * Blueprint-callable wrapper around the CodeBlocks C++ BlockManager singleton.
 * All methods are static — call them directly in Blueprint without an instance variable.
 *
 * BackendBlockType values correspond to the CodeBlocks::BlockType enum (cast as int):
 *   0=NONE, 1=MAIN, 2=ASSIGN_BLK, 3=FUNDEF_BLK, 4=FUNCALL_BLK, 5=RETURN_BLK,
 *   6=WHILE_LOOP, 7=FOR_LOOP, 8=FOREA_LOOP, 9=IFELSE_BLK, 10=BINARYOP_BLK,
 *   11=UNARYOP_BLK, 12=DATA_BLK, 13=ARGLST_SBLK, 14=ELSE_SBLK, 15=CBLK_SBLK,
 *   16=NSTEXPR_SBLK, 17=VAR_REF, 18=ARR_BLK, 19=AUG_ASSIGN_BLK, 20=INCR_BLK
 */
UCLASS()
class MECHAMAKER_API UBlockManager : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /** Drop a new block from the side menu into the program area. Returns assigned BlockId, or -1 on failure. */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static int32 NewBlockInArea(int32 BackendBlockType);

    /** Drop a new block from the side menu into a slot on an existing block. Returns assigned BlockId, or -1 on failure. */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static int32 NewBlockInSlot(int32 BackendBlockType, int32 ParentId, int32 SlotPos);

    /** Drop a new variable-sized block (FunDef/FunCall/ArgList) from the side menu into the program area. Returns BlockId, or -1 on failure. */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static int32 NewSizedBlockInArea(int32 BackendBlockType, int32 ArgCount);

    /** Drop a new variable-sized block from the side menu into a slot. Returns BlockId, or -1 on failure. */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static int32 NewSizedBlockInSlot(int32 BackendBlockType, int32 ArgCount, int32 ParentId, int32 SlotPos);

    /**
     * Move an existing block from one slot into another slot.
     * Pass OldParentId = -1 if the block came from the program area rather than a slot.
     */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static bool MoveBlockToSlot(int32 BlockId, int32 NewParentId, int32 NewSlotPos, int32 OldParentId, int32 OldSlotPos);

    /**
     * Move an existing block out of a slot back into the program area.
     * Pass OldParentId = -1 if the block was already in the program area.
     */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static bool MoveBlockToArea(int32 BlockId, int32 OldParentId, int32 OldSlotPos);

    /**
     * Move a block that is already in the program area to the end of the area.
     * Use this for OriginType=3 (Area→Area) drops until full reordering is implemented.
     */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static bool MoveBlockToEndOfArea(int32 BlockId);

    /**
     * Reorder a block within the program area relative to another block.
     * bInsertBefore = true places BlockId before ReferenceBlockId; false places it after.
     */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static bool ReorderInArea(int32 BlockId, int32 ReferenceBlockId, bool bInsertBefore);

    /** Remove a block entirely (deletes it from the backend). Returns true on success. */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static bool RemoveBlock(int32 BlockId);

    /** Store a user-typed string (variable name, literal value, operator) for a block's slot. */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static void SetUserInput(int32 BlockId, int32 SlotPos, const FString& InputStr);

    /** Retrieve the stored user-typed string for a block's slot. */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static FString GetUserInput(int32 BlockId, int32 SlotPos);

    /**
     * Compile the current block tree into a program string and return it.
     * Returns the program string on success, or an error/diagnostic message on failure.
     * Pass this string to UApplCompiler::CompileAndRun() to execute the program.
     */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static FString GetProgramString();

    // ----------------------------------------------------------------
    // Code block sequence (CBLK_SBLK / CodeAreaSlot)
    // ----------------------------------------------------------------

    /** Drop a new block from the side menu into a CBLK_SBLK sequence. Returns assigned BlockId, or -1 on failure. */
    UFUNCTION(BlueprintCallable, Category="CBlocks")
    static int32 NewBlockInCodeBlock(int32 BackendBlockType, int32 CblkId);

    /** Drop a new variable-sized block from the side menu into a CBLK_SBLK sequence. Returns BlockId, or -1 on failure. */
    UFUNCTION(BlueprintCallable, Category="CBlocks")
    static int32 NewSizedBlockInCodeBlock(int32 BackendBlockType, int32 ArgCount, int32 CblkId);

    /**
     * Move an existing block into a CBLK_SBLK sequence.
     * OldCblkId != -1  → block came from another CBLK_SBLK sequence.
     * OldParentId != -1 → block came from a single BlockSlot (supply OldSlotPos too).
     * Both == -1        → block came from the main program area.
     */
    UFUNCTION(BlueprintCallable, Category="CBlocks")
    static bool MoveBlockToCodeBlock(int32 BlockId, int32 CblkId, int32 OldCblkId, int32 OldParentId, int32 OldSlotPos);

    /** Remove a block from a CBLK_SBLK sequence (does not delete it from the registry). Returns true on success. */
    UFUNCTION(BlueprintCallable, Category="CBlocks")
    static bool RemoveBlockFromCodeBlock(int32 BlockId, int32 CblkId);

    /**
     * Reorder a block within a CBLK_SBLK sequence relative to a reference block.
     * bInsertBefore = true places BlockId before RefBlockId; false places it after.
     * (Stub — returns false until reordering is implemented.)
     */
    UFUNCTION(BlueprintCallable, Category="CBlocks")
    static bool ReorderInCodeBlock(int32 BlockId, int32 RefBlockId, int32 CblkId, bool bInsertBefore);
};
