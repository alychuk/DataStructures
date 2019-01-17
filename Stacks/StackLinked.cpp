#include "StackLinked.h"

template <typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& nodeData, StackNode* nextPtr) : dataItem(nodeData), next(nextPtr) {}


template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber) : top(NULL) {}


template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{
  StackNode *cursorList, *cursorOther;
  top = new StackNode(other.top->dataItem, NULL);
  cursorList = top;
  for (cursorOther = other.top->next; cursorOther != NULL; cursorOther = cursorOther->next) {
    cursorList->next = new StackNode(cursorOther->dataItem, NULL);
    cursorList = cursorList->next;
  }
  cursorList = NULL;
  cursorOther = NULL;
}


template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{
  if (this != other) {
    clear();
    StackNode *cursorList, *cursorOther;
    top = new StackNode(other.top->dataItem, NULL);
    cursorList = top;
    for (cursorOther = other.top->next; cursorOther != NULL; cursorOther = cursorOther->next) {
      cursorList->next = new StackNode(cursorOther->dataItem, NULL);
      cursorList = cursorList->next;
    }
    cursorList = NULL;
    cursorOther = NULL;
  }
  return *this;
}


template <typename DataType>
StackLinked<DataType>::~StackLinked()
{
  clear();
}


template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
  if (top != NULL) {
    StackNode *temp = top;
    top = new StackNode(newDataItem, temp);
    temp = NULL;
  }
  else {
    top = new StackNode(newDataItem, NULL);
  }
}


template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{
  if (!isEmpty()) {
    DataType copy = top->dataItem;
    StackNode *temp = top;
    top = top->next;
    delete temp;
    temp = NULL;
    return copy;
  }
  else {
    throw logic_error("List is Empty!");
  }
}


template <typename DataType>
void StackLinked<DataType>::clear()
{
  StackNode *temp;
  while (top) {
    temp = top;
    top = top->next;
    delete temp;
  }
  temp = NULL;
  top = NULL;
}


template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
  return (top == NULL);
}


template <typename DataType>
bool StackLinked<DataType>::isFull() const
{
   cout << "Stack size limited only by heap memory. Included for polymorphism." << endl;
   return 0;
}

#include "show6.cpp"
