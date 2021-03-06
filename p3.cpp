//Filename: p3.cpp
//Author: Ishan Parikh
//Purpose: this is the test/main class for testing out my implemented stack
//and queue
//Input: nothing from the user
//Output: cmd output indicating operations being performed on stack and queues


#include <iostream>
#include "Queue.h"
#include "Stack.h"
using namespace std;

void welcome();
void goodbye();

int main()
{

  welcome();
  Stack stack;

  std::cout << "Inserting all values from 0 to 10 in stack" << endl;
  for(int i = 0; i < 12; i++) {
    std::cout << "Inserting the number " << i << " into stack" << endl;
    stack.push(i);
    std::cout << "New Size: " << stack.stackSize() <<endl << endl;
  }

  std::cout << "Removing all values from stack" << endl;
  while(!stack.isEmpty()) {
    std::cout << stack.pop() << endl;
  }
  //put test methods here

  goodbye();
  return 0;
}

void welcome() 
{
  cout << endl << endl
  << "This is a queue and stack library test program." << endl
  << "The queue program here is implemented via a linkedlist" << endl
  << "and the stack via pointer array." << endl
  << "Test this elsewhere or in other programs as needed" << endl << endl;
}

void goodbye() 
{
  cout << endl << endl
  << "The queue and stack test is over." << endl
  << "The program has now stopped" << endl
  << endl << endl;
}