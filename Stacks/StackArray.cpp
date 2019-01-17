#include "StackArray.h"

template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber) : maxSize(maxNumber), top(-1)
{
  dataItems = new DataType[maxSize];
}

template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other)
{
  top = other.top;
  maxSize = other.maxSize;
  dataItems = new DataType[other.maxSize];
  for (int i = 0; i < (top + 1); i++) {
    dataItems[i] = other[i];
  }
}

template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other)
{
  if (this != other) {
    top = other.top;
    maxSize = other.maxSize;
    delete [] dataItems;
    dataItems = new DataType[other.maxSize];
    for (int i = 0; i < (top + 1); i++) {
      dataItems[i] = other[i];
    }
  }
  return *this;
}

template <typename DataType>
StackArray<DataType>::~StackArray()
{
  maxSize = 0;
  top =0;
  delete [] dataItems;
  dataItems = NULL;
}

template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
  if (!isFull()) {
    top++;
    dataItems[top] = newDataItem;
  }
  else {
    throw logic_error("Stack is Full! Item not added.");
  }
}

template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error)
{
  if (!isEmpty()) {
    top--;
    return dataItems[top+1];
  }
  else {
    throw logic_error("Stack is empty!");
  }
}


template <typename DataType>
void StackArray<DataType>::clear()
{
 top = -1;
}

template <typename DataType>
bool StackArray<DataType>::isEmpty() const
{
  return (top < 0);
}

template <typename DataType>
bool StackArray<DataType>::isFull() const
{
  return (top == maxSize - 1);
}


#include "show6.cpp"
