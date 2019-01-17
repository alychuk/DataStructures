#include <iostream>
#include "SL_PriorityQueue.h"

using namespace std;

int main()
{
  char items[] = {'A', 'b', 'i', 'g', 'a', 'i', 'l'};
  SL_PriorityQueue<char> test;
  for (int i = 0; i < 7; i++) {
    test.enqueue(items[i]);
  }
  while(!test.isEmpty()) {
    cout << test.peekFront() << " ";
    test.dequeue();
  }
  cout << endl;
}
