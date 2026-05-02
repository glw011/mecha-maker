#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlockManager.generated.h"

/**
 * Blueprint-callable wrapper around C++ BlockManager
 * All methods static and callable directly in Blueprints without an instance variable
 *
 * BackendBlockType values correspond to the CodeBlocks::BlockType enum (cast as int):
 *   0=NONE, 
 *   1=MAIN, 
 *   2=ASSIGN_BLK, 
 *   3=FUNDEF_BLK,
 *   4=FUNCALL_BLK,
 *   5=RETURN_BLK,
 *   6=WHILE_LOOP,
 *   7=FOR_LOOP,
 *   8=FOREA_LOOP,
 *   9=IFELSE_BLK,
 *   10=BINARYOP_BLK,
 *   11=UNARYOP_BLK,
 *   12=DATA_BLK,
 *   13=ARGLST_SBLK,
 *   14=ELSE_SBLK,
 *   15=CBLK_SBLK,
 *   16=NSTEXPR_SBLK,
 *   17=VAR_REF,
 *   18=ARR_BLK,
 *   19=AUG_ASSIGN_BLK,
 *   20=INCR_BLK
 */

UCLASS()
class MECHAMAKER_API UBlockManager : public UBlueprintFunctionLibrary{
    GENERATED_BODY()

public:
    /** 
     * Reset block states stored by back-end 
     *  - REMOVE FROM IDE's OnConstruct EVENT FOR FINAL BUILD 
     */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static void ResetBackend();

    //  ---- Block Tracking Functions (MainProgramArea/BlockSlots) ----

    /** 
     * Drop new block from IDE menu into main program area 
     *  - Returns assigned BlockId, or -1 on fail 
     */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static int32 NewBlockInArea(int32 BackendBlockType);

    /** 
     * Drop new block from IDE menu into slot on already existing block
     *  - Returns assigned BlockId, or -1 on fail
     */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static int32 NewBlockInSlot(int32 BackendBlockType, int32 ParentId, int32 SlotPos);

    /** 
     * Drop new variable sized block (FunDef/FunCall/ArgList) from IDE menu into main program area
     *  - Returns BlockId, or -1 on fail
     */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static int32 NewSizedBlockInArea(int32 BackendBlockType, int32 ArgCount);

    /** 
     * Drop new variable sized block from IDE menu into slot 
     *  - Returns BlockId, or -1 on fail 
     */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static int32 NewSizedBlockInSlot(int32 BackendBlockType, int32 ArgCount, int32 ParentId, int32 SlotPos);

    /**
     * Move existing block from slot/main into another slot
     *  - If block dragged from main program area pass OldParentId as -1 
     */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static bool MoveBlockToSlot(int32 BlockId, int32 NewParentId, int32 NewSlotPos, int32 OldParentId, int32 OldSlotPos);

    /**
     * Move existing block from slot/main into main program area
     *  - If block dragged from main program area pass OldParentId as -1 
     */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static bool MoveBlockToArea(int32 BlockId, int32 OldParentId, int32 OldSlotPos);

    /**
     * Move block within main program area to sequential end of area
     *  - Can call for drops until ordered inserts are implemented
     */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static bool MoveBlockToEndOfArea(int32 BlockId);

    /**
     * Reorder block within program area relative to another block in area (before/after reference block)
     *  - bInsertBefore = true --> places BlockId before ReferenceBlockId
     *  - bInsertBefore = false --> places BlockId after ReferenceBlockId
     */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static bool ReorderInArea(int32 BlockId, int32 ReferenceBlockId, bool bInsertBefore);

    /** 
     * Remove block and delete from backend (discard block)
     *  - Returns true on success, else false 
     */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static bool RemoveBlock(int32 BlockId);

    /** 
     * Store user input as string (var name, data val, operator, etc.) for a block's slot 
     */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static void SetUserInput(int32 BlockId, int32 SlotPos, const FString& InputStr);

    /** 
     * Get user input stored as string for a block's slot
     */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static FString GetUserInput(int32 BlockId, int32 SlotPos);

    /**
     * Compile the current block tree into a program string and return it.
     *  - Returns ProgramString on success
     *  - Returns message providing user with feedback on fail
     *  - Pass ProgramString to UApplCompiler::CompileAndRun() to execute
     */
    UFUNCTION(BlueprintCallable, Category="Blocks")
    static FString GetProgramString();


    //  ---- Sequential CodeBlock Tracking Functions (Embedded CodeAreaSlots) ----

    /** 
     * Drop new block from IDE menu into embedded CodeAreaSlot's sequence 
     *  - Returns assigned BlockId, or -1 on fail 
     */
    UFUNCTION(BlueprintCallable, Category="CBlocks")
    static int32 NewBlockInCodeBlock(int32 BackendBlockType, int32 CblkId);

    /** 
     * Drop new SIZED BLOCK from IDE menu into embedded CodeAreaSlot's sequence
     *  - Returns assigned BlockId, or -1 on fail 
     */
    UFUNCTION(BlueprintCallable, Category="CBlocks")
    static int32 NewSizedBlockInCodeBlock(int32 BackendBlockType, int32 ArgCount, int32 CblkId);

    /**
     * Move existing block into embedded CodeAreaSlot's sequence
     *  - OldCblkId != -1 --> block from another embedded CodeAreaSlot
     *  - OldParentId != -1 --> block from BlockSlot (requires OldSlotPos)
     *  - Both == -1 --> block from main program area
     */
    UFUNCTION(BlueprintCallable, Category="CBlocks")
    static bool MoveBlockToCodeBlock(int32 BlockId, int32 CblkId, int32 OldCblkId, int32 OldParentId, int32 OldSlotPos);

    /** 
     * Remove block from embedded CodeAreaSlot's sequence (remains in registry) 
     *  - Returns true on success, else false
     */
    UFUNCTION(BlueprintCallable, Category="CBlocks")
    static bool RemoveBlockFromCodeBlock(int32 BlockId, int32 CblkId);

    /**
     * Reorder block within embedded CodeAreaSlot's sequence relative to given reference block
     *  - bInsertBefore = true --> BlockId inserted before RefBlockId
     *  - bInsertBefore = false --> BlockId inserted after RefBlockId
     *  - Returns true on success, else false
     * 
     *  *** NOT FULLY IMPLEMENTED - WILL ALWAYS RETURN FALSE ***
     */
    UFUNCTION(BlueprintCallable, Category="CBlocks")
    static bool ReorderInCodeBlock(int32 BlockId, int32 RefBlockId, int32 CblkId, bool bInsertBefore);
};


