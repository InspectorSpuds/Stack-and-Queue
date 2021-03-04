

#ifndef QUEUE_H
#define QUEUE_H
struct Node 
{
  int data;
  Node* next;
};

class Queue
{
  private:
    Node* q; //acutal queue list
    Node* head; //the start of the queue
    Node* tail; //the end of the queue
    int size = 0; //size of the queue
  public:
    Queue();
    ~Queue();
    Queue(const Queue &old);
    void operator=(const Queue &old);
    void queue(int val);
    int dequeue();
    int queueSize();
    bool isEmpty();g
};
#endif 
