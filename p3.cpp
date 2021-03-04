#include <iostream>
#include "Queue.h"
using namespace std;

void welcome();
void goodbye();

int main()
{
  Queue original;

  welcome();

  //put test methods here

  goodbye();
  return 0;
}

void welcome() 
{
  cout << endl << endl
  << "This is a queue and stack api test program." << endl
  << "The queue program here is implemented via a linkedlist" << endl
  << "and the stack via pointer array." << endl
  << "Test this elsewhere or in other programs as needed" << endl << endl;
}

void goodbye() 
{
  cout << endl << endl
  << "The queue and stack api test is over." << endl
  << "The program has now stopped" << endl
  << endl << endl;
}