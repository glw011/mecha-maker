#pragma once
#include <memory>

class BlockSlot;

class Node{
  public:
    Node(BlockSlot* slot);
    std::unique_ptr<BlockSlot> data;
    Node* prev;   // points to prev node
    Node* next;   // points to next node
    bool operator==(const BlockSlot* other) const;  // easily compare Node to BlockSlot ref
    bool isHead();
    bool isTail();
};




