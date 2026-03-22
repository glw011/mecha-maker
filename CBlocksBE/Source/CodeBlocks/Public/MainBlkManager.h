#include "CodeBlocks.h"

using namespace CodeBlocks;

class MainBlk_Manager{
  public:
    // --------------------------------------
    //        Add New Empty Blocks
    // --------------------------------------
    //  - Called: 
    //      * Whenever user drops new empty block anywhere in 'Main' block/prog area
    //  - Returns: 
    //      * Unique int BlockId assigned by back-end to be saved as part of block's struct in Unreal/used as reference
    //      * OR -1 on failure
    // --------------------------------------
    static int newAssignBlk();
    static int newFunDefBlk();
    static int newFunCallBlk();
    static int newIfElseBlk();
    static int newReturnBlk();
    static int newForLoopBlk();
    static int newWhileLoopBlk();
    static int newUnaryOpBlk();
    static int newBinaryOpBlk();
    static int newIntDataBlk();
    static int newFltDataBlk();
    static int newBoolDataBlk();
    static int newStrDataBlk();   // not fully functional yet
    
    // --------------------------------------
    //        Drop Child Block in Slot
    // --------------------------------------
    //  - Called: 
    //      * Whenever user drops child block into parent block
    //  - Returns: 
    //      * true on succeed
    //      * OR false on failure
    // --------------------------------------
    static bool setChildBlock(int parentBlockId, int blockSlotPos, int childBlockId);

    // --------------------------------------
    //      Drop New Empty Block in Slot
    // --------------------------------------
    //  - Called: 
    //      * Whenever user drops new empty child block into parent block
    //  - Returns: 
    //      * Unique int BlockId assigned by back-end to new child block dropped into parent
    //      * OR -1 on failure
    // --------------------------------------
    static int dropNewAssignBlk(int parentBlockId, int blockSlotPos);
    static int dropNewFunDefBlk(int parentBlockId, int blockSlotPos);
    static int dropNewFunCallBlk(int parentBlockId, int blockSlotPos);
    static int dropNewIfElseBlk(int parentBlockId, int blockSlotPos);
    static int dropNewReturnBlk(int parentBlockId, int blockSlotPos);
    static int dropNewForLoopBlk(int parentBlockId, int blockSlotPos);
    static int dropNewWhileLoopBlk(int parentBlockId, int blockSlotPos);
    static int dropNewUnaryOpBlk(int parentBlockId, int blockSlotPos);
    static int dropNewBinaryOpBlk(int parentBlockId, int blockSlotPos);
    static int dropNewIntDataBlk(int parentBlockId, int blockSlotPos);
    static int dropNewFltDataBlk(int parentBlockId, int blockSlotPos);
    static int dropNewBoolDataBlk(int parentBlockId, int blockSlotPos);
    static int dropNewStrDataBlk(int parentBlockId, int blockSlotPos);   // not fully functional yet
    
    // --------------------------------------
    // New Component Library FunCall Blocks 
    // --------------------------------------
    //  - Called: 
    //      * Whenever user drops new empty component FunCallBlk from their library anywhere in prog area
    //  - Args:
    //      * comptFunId: unique int id mapping to user's selected component function to call
    //  - Returns: 
    //      * Unique int BlockId assigned by back-end (-1 on failure)    
    // --------------------------------------
    static int newComptFunCallBlk(int compFunId);
    
    // --------------------------------------
    //   New Saved User FunDef/Call Blocks 
    // --------------------------------------
    //  - Called: 
    //      * Whenever user drops new empty component FunCallBlk from their library anywhere in prog area
    //  - Args:
    //      * comptFunId: unique int id mapping to user's selected component function to call
    //  - Returns: 
    //      * Unique int BlockId assigned by back-end (-1 on failure)
    // --------------------------------------
    static int newUserFunDefBlk(int savdFunId);
    static int newUserFunCallBlk(int savdFunId);
    
};