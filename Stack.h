#ifndef STACK_H
#define STACK_H

class Stack 
{
  class EmptyStack{};
  private: 
    const int DEFAULT_SIZE = 10; //default array size
    int* arr; //stack array
    int size = 0; //current stack array size (not used index size)
    int top = -1; //the topmost element's index's previous index
    //starts at -1 to handle for 0 being the first index
    void resize();
  public: 
    Stack();
    ~Stack();
    Stack(const Stack &old);
    void operator=(const Stack &old);
    void push(int val);
    int pop();
    int stackSize();
    bool isEmpty();
};

#endif