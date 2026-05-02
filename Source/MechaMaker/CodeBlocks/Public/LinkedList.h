#pragma once

#include "Node.h"
#include <vector>

class BlockSlot;

class LinkedList{
  public:
    LinkedList();
    ~LinkedList();
    void append(BlockSlot* newSlot);
    void prepend(BlockSlot* newSlot);
    bool insertBefore(BlockSlot* newSlot, BlockSlot* referenceSlot);
    bool insertAfter(BlockSlot* newSlot, BlockSlot* referenceSlot);
    bool remove(BlockSlot* referenceSlot);
    int size();
    bool isEmpty();
    void clearList();
    std::vector<BlockSlot*> getAsArray();
    Node* getHead();
    Node* getTail();


  private:
    Node* head; // points to 1st node
    Node* tail; // points to last node
    Node* curr; // temp storage of nodes during operations
    int listSize;
};

