#include "Stack.h"
#include <iostream>

Stack::Stack() 
{
  arr = new int[DEFAULT_SIZE]{};
  size = DEFAULT_SIZE;
}

Stack::~Stack() 
{
  delete [] arr;
}

Stack::Stack(const Stack &old)
{
  delete [] arr;
  arr = new int[old.size];
  size = old.size;
  top = old.top;

  //assign elements
  for(int i = 0; i < size; i++) {
    arr[i] = old.arr[i];
  }
}

void Stack::operator=(const Stack &old)
{
  if(this != &old) {
    delete [] arr;
    arr = new int[old.size];
    size = old.size;
    top = old.top;

    //assign elements
    for(int i = 0; i < size; i++) {
      arr[i] = old.arr[i];
    }
  }
}

void Stack::push(int val)
{
  //move to next index and resize if necessary
  top++;
  if(top == size)
    resize();

  //add value
  arr[top] = val;
}

int Stack::pop()
{
  int value = 0; //topmost stack array value

  //handle empty stack
  if(isEmpty())
    throw EmptyStack();
  
  //get top value, remove element, and change size and topmost index value
  value = arr[top]; 
  arr[top] = 0;
  top--;
  return value;
}

void Stack::resize()
{
  int newSize = size * 1.5; //new array size
  int* oldArr = arr; //the old stack array
  int* newArr = new int[newSize]{}; //the new, resized stack array
  
  //coy all elements from old arr into new arr
  for(int i = 0; i < size; i++) {
    newArr[i] = oldArr[i];
  }

  //delete old arr and assign new arr
  size = newSize;
  delete [] oldArr;
  arr = newArr;
}

int Stack::stackSize()
{
  return top+1;
}

bool Stack::isEmpty()
{
  return top+1 <= 0;
}