#include "Node.h"
#include "BlockSlot.h"

// node constructor
Node::Node(BlockSlot droppedBlock) : data(droppedBlock), next(nullptr), prev(nullptr) {}

// allows direct equality comparison of instance of Node with instance of BlockSlot
// by comparing Node's data with the BlockSlot 
bool Node::operator==(const BlockSlot other) const{return &data == &other;}

bool Node::isHead(){return this->prev == nullptr;}

bool Node::isTail(){return this->next == nullptr;}



