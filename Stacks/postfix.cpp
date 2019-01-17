#include <iostream>
#include <stdexcept>
#include <stdio.h>

using namespace std;

#include "config.h"

#if !LAB6_TEST1
#  include "StackArray.cpp"
#else
#  include "StackLinked.cpp"
#endif

template <typename DataType>
void test_postfix(Stack<DataType>& stack) throw (logic_error)
{
  char readVar;
  int typeCast;
  float operand2;
  cout << "Enter a arithmitic expression in postfix form(ex. 3 4 + 5 2 / *): ";
  readVar = getchar();
  while (readVar != '\n') {
    if ( (readVar >= '0') && (readVar <= '9')) {
      typeCast = readVar - '0';
      stack.push( typeCast );
    }
    else {
      switch (readVar) {
        case '+': stack.push( (stack.pop() + stack.pop()) );
          break;
        // operand 2 is saved as the order of operations matters for subtraction
        case '-': operand2 = stack.pop();
          stack.push( (stack.pop() - operand2) );
          break;
        case '*': stack.push( (stack.pop() * stack.pop()) );
          break;
        // operand 2 is saved as the order of operations matters for division
        case '/': operand2 = stack.pop();
          stack.push( (stack.pop() / operand2) );
          break;
        case ' ':
          break;
        default: /*throw logic_error("Invalid input.");*/
          break;
      }
    }
    readVar = getchar();
  }
  cout << "Result: " << stack.pop() << endl;
}

int main() {
#if !LAB6_TEST1
  cout << "Testing array implementation" << endl;
  StackArray<float> s1;
  test_postfix(s1);
#else
  cout << "Testing linked implementation" << endl;
  StackLinked<float> s2;
  test_postfix(s2);
#endif
return 0;
}
