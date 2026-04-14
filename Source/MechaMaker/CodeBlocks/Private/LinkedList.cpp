#include "LinkedList.h"
#include "BlockSlot.h"

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

void LinkedList::append(BlockSlot* newSlot){
  Node* newNode = new Node(newSlot);
  this->listSize++;
  
  if(this->head == nullptr){
    this->head = this->tail = newNode;
    return;
  }
  
  this->tail->next = newNode;
  newNode->prev = this->tail;
  this->tail = newNode;
}

void LinkedList::prepend(BlockSlot* newSlot){
  Node* newNode = new Node(newSlot);
  this->listSize++;
  
  if(this->head == nullptr){
    this->head = this->tail = newNode;
    return;
  }
  
  this->head->prev = newNode;
  newNode->next = this->head;
  this->head = newNode;
}

bool LinkedList::insertBefore(BlockSlot* newSlot, BlockSlot* refSlot){
  this->curr = this->head;

  while(this->curr != nullptr){
    if(*curr == refSlot){
      Node* newNode = new Node(newSlot);
      if(curr == head){this->head = newNode;}
      else{
        curr->prev->next = newNode;
        newNode->prev = curr->prev;
      }
      newNode->next = curr;
      curr->prev = newNode;
      this->listSize++;
      return true;
    }
    this->curr = this->curr->next;
  }
  return false;
}

bool LinkedList::insertAfter(BlockSlot* newSlot, BlockSlot* refSlot){
  this->curr = this->head;
  
  while(this->curr != nullptr){
    if(*curr == refSlot){
      //special case if curr is tail
      if(curr->next == nullptr){
        this->append(newSlot);
        return true;
      }
      // otherwise, insert before next node
      return this->insertBefore(newSlot, curr->next->data.get());
    }
    this->curr = this->curr->next;
  }
  return false;
}

bool LinkedList::remove(BlockSlot* refSlot){
  this->curr = this->head;
  while(this->curr != nullptr){
    if(*curr == refSlot){
      if(curr->prev){curr->prev->next = curr->next;}
      else{this->head = curr->next;}

      if(curr->next){curr->next->prev = curr->prev;}
      else{this->tail = curr->prev;}

      delete curr;
      this->listSize--;
      return true;
    }
    this->curr = this->curr->next;
  }
  return false;
}

std::vector<BlockSlot*> LinkedList::getAsArray(){
  // init vector (dynamic array) 
  std::vector<BlockSlot*> listArr;
  this->curr = this->head;

  while(this->curr != nullptr){
    listArr.push_back(curr->data.get());
    this->curr = this->curr->next;
  }
  return listArr;
}
