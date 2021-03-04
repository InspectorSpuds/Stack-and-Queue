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

}

void Queue::queue(int val)
{ 
  if(q = nullptr) {
    q = new Node{val, nullptr};
    tail = q;
    head = q;
  } else {
    tail->next = new Node{val, nullptr};
    size++;
    tail = tail->next;
  }
}

int Queue::dequeue()
{
  //if empty throw exception
  if(size == 0)
    throw 0;

  int val = head->data;
  //head->next = nullptr;
  //move list contents and return old value
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
