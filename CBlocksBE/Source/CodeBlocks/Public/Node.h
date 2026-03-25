#pragma once
#include "BlockSlot.h"

class Node{
public:
  Node(BlockSlot droppedBlock);
  BlockSlot data;
  Node* prev;   // points to prev node
  Node* next;   // points to next node
  bool operator==(const BlockSlot other) const;  // easily compare Node to BlockSlot ref
  bool isHead();
  bool isTail();
};




