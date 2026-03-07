#pragma once

#include "Node.h"
#include "BlockSlot.h"
#include <vector>

class LinkedList{
  public:
    LinkedList();
    ~LinkedList();
    void insertBefore(BlockSlot droppedBlock, BlockSlot referenceBlock);
    void insertAfter(BlockSlot droppedBlock, BlockSlot referenceBlock);
    int size();
    bool isEmpty();
    void clearList();
    std::vector<BlockSlot> getAsArray();
    Node* getHead();
    Node* getTail();


  private:
    Node* head; // points to 1st node
    Node* tail; // points to last node
    Node* curr; // temp storage of nodes during operations
    int listSize;
    void append(BlockSlot droppedBlock);
    void prepend(BlockSlot droppedBlock);
};

