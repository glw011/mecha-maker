#pragma once

#include <string>
#include <vector>
#include <atomic>
#include "CodeBlocks.h"
#include "BlockSlot.h"
#include "LinkedList.h"

class Block{
  public:
    Block();
    Block(CodeBlocks::BlockType blkType);
    Block(CodeBlocks::BlockType blkType, int size);
    ~Block();

    void setType(CodeBlocks::BlockType blkType);
    void setType(CodeBlocks::BlockType blkType, int runtimeSize);
    std::string getContentStr();
    CodeBlocks::BlockType getType();
    int getId();
    BlockSlot* getSlot(int slotPos);
    void setUserInput(int slotPos, std::string val);
    std::string getUserInput(int slotPos);

    // codeSeq operations — only valid on CBLK_SBLK blocks
    bool appendToCodeSeq(Block* block);
    bool removeFromCodeSeq(int blockId);
    bool reorderInCodeSeq(int blockId, int refId, bool before);

  private:
    int id, argCount, SlotCount;
    CodeBlocks::BlockType BType;
    std::vector<BlockSlot> Slots;
    std::vector<std::string> userInputVals;

    // sequence container for CBLK_SBLK (nullptr for other block types)
    LinkedList* codeSeq;

    bool validDynamSlotCount();
    std::string getEmptySlots();
    std::string getCodeSeqStr();   // builds string for CBLK_SBLK body

    static std::atomic<int> nxtId;
};
