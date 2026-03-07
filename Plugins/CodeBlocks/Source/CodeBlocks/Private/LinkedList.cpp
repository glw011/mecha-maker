#include "LinkedList.h"
#include "Node.h"
#include "BlockSlot.h"
#include <vector>

LinkedList::LinkedList() : head(nullptr), tail(nullptr), curr(nullptr), listSize(0) {}

// clear @ deconstruct to prevent mem leaks
LinkedList::~LinkedList(){this->clearList();}

bool LinkedList::isEmpty(){return this->listSize < 1;}

int LinkedList::size(){return this->listSize;}

void LinkedList::clearList(){
  Node* nextNode;
  this->curr = head;

  while(this->curr != nullptr){
    nextNode = this->curr->next;
    delete this->curr;
    this->curr = nextNode;
  }

  this->tail = this->head = nullptr;
  this->listSize = 0;
}

Node* LinkedList::getHead(){return this->head;}

Node* LinkedList::getTail(){return this->tail;}

void LinkedList::append(BlockSlot droppedBlock){
  Node* newNode = new Node(droppedBlock);
  
  if(this->isEmpty()){
    this->head = this->tail = newNode;
    return;
  }
  
  this->tail->next = newNode;
  newNode->prev = this->tail;
  this->tail = newNode;
  this->listSize++;
}

void LinkedList::prepend(BlockSlot droppedBlock){
  Node* newNode = new Node(droppedBlock);
  
  if(this->isEmpty()){
    this->head = this->tail = newNode;
    return;
  }
  
  this->head->prev = newNode;
  newNode->next = this->head;
  this->head = newNode;
  this->listSize++;
}

void LinkedList::insertBefore(BlockSlot droppedBlock, BlockSlot referenceBlock){
  Node* newNode = new Node(droppedBlock);
  this->curr = this->head;

  while(this->curr != nullptr){
    if(*curr == referenceBlock){
      if(curr == head) this->head = newNode;
      else{
        curr->prev->next = newNode;
        newNode->prev = curr->prev;
      }
      newNode->next = curr;
      curr->prev = newNode;
      this->listSize++;
      return;
    }
    
    this->curr = this->curr->next;
  }
}

void LinkedList::insertAfter(BlockSlot droppedBlock, BlockSlot referenceBlock){
  this->curr = this->head;
  
  while(this->curr != nullptr){
    if(*curr == referenceBlock){
      //special case if curr is tail
      if(curr->next == nullptr){
        this->append(droppedBlock);
        return;
      }
      // otherwise, insert before next node
      this->insertBefore(droppedBlock, curr->next->data);
      return;
    }
    this->curr = this->curr->next;
  }
}

std::vector<BlockSlot> LinkedList::getAsArray(){
  // init vector (dynamic array) 
  std::vector<BlockSlot> listArr;
  this->curr = this->head;

  while(this->curr != nullptr){
    listArr.push_back(curr->data);
    this->curr = this->curr->next;
  }
  
  return listArr;
}
