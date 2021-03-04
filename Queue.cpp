#include "Queue.h"


Queue::Queue()
{
  q = nullptr;
  head = nullptr;
  tail = nullptr;
}

Queue::~Queue()
{
  delete q;
}

Queue::Queue(const Queue &old)
{
  size  = old.size;
  Node* traverse = old.q->next;

  if(old.size == 0)
    return;

  //assign initial list vals
  q = new Node{old.q->data, nullptr};
  head = q;
  tail = q;
  //copy values
  while(traverse != nullptr) {
    tail->next = new Node{traverse->data, nullptr};
    traverse = traverse->next;
    tail = tail->next;
  }

  tail = tail->next;
}

void Queue::operator=(const Queue &old)
{
  //if the memory is not the same
  if(this != &old) {
    delete q;
    size  = old.size;
    Node* traverse = old.q->next;

    if(old.size == 0)
      return;

    //assign initial list vals
    q = new Node{old.q->data, nullptr};
    head = q;
    tail = q;
    //copy values
    while(traverse != nullptr) {
      tail->next = new Node{traverse->data, nullptr};
      traverse = traverse->next;
      tail = tail->next;
    }

    tail = tail->next;
  }
}

void Queue::queue(int val)
{ 
  //if the queue is empty, initialize node value
  if(q == nullptr) {
    q = new Node{val, nullptr};
    tail = q;
    head = q;
  } else { //just add to the tail and move tail
    tail->next = new Node{val, nullptr};
    tail = tail->next;
  }
  //increment size
  size++;
}

int Queue::dequeue()
{
  int val = 0; //the head value
  //error check for an empty queue
  if(size == 0)
    throw 0;
  val = head->data; //get data
  //move list contents, delete memory, and return old value
  q = q->next;
  size--;
  delete head;
  head = q;
  return val;
}

int Queue::queueSize()
{
  return size;
}

bool Queue::isEmpty()
{
  return size == 0;
}

std::string Queue::queueOrder()
{
  std::string order = "";
  Node* traverse = q;
  
  while(traverse != nullptr) {
    order += std::to_string(traverse->data) + " ";
    traverse = traverse->next;
  }

  return order;
}