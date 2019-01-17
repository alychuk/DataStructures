#include "QueueArray.h"

template <class DataType>
QueueArray<DataType>::QueueArray(int maxNumber) : maxSize(maxNumber), front(-1), back(-1)
{
  dataItems = new DataType[maxSize];
}
template <class DataType>
QueueArray<DataType>::QueueArray(const QueueArray& other) : maxSize(other.maxSize), front(other.front), back(other.back)
{
  if (!other.isEmpty()) {
    dataItems = new DataType[maxSize];
    if (other.back > other.front) {
      for (int i = other.front; i < (other.back+1); i++) {
        dataItems[i] = other.dataItems[i];
      }
    }
    else {
      for (int i = other.front; i < other.maxSize; i++) {
        dataItems[i] = other.dataItems[i];
      }
      for (int i = 0; i < (other.back + 1); i++) {
        dataItems[i] = other.dataItems[i];
      }
    }
  }
  else {
    dataItems = NULL;
  }
}
template <class DataType>
QueueArray<DataType>& QueueArray<DataType>::operator=(const QueueArray& other)
{
  if (other != this) {
    delete [] dataItems;
    if (!other.isEmpty()) {
      dataItems = new DataType[maxSize];
      if (other.back > other.front) {
        for (int i = other.front; i < (other.back+1); i++) {
          dataItems[i] = other.dataItems[i];
        }
      }
      else {
        for (int i = other.front; i < other.maxSize; i++) {
          dataItems[i] = other.dataItems[i];
        }
        for (int i = 0; i < (other.back + 1); i++) {
          dataItems[i] = other.dataItems[i];
        }
      }
    }
    else {
      delete [] dataItems;
      dataItems = NULL;
    }
  }
  return *this;
}
template <class DataType>
QueueArray<DataType>::~QueueArray()
{
  delete [] dataItems;
}
template <class DataType>
void QueueArray<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
  if (isEmpty()) {
    front = back = 0;
    dataItems[back] = newDataItem;
  }
  else if (!isFull()) {
    back = (back + 1) % maxSize;
    dataItems[back] = newDataItem;
  }
  else {
    throw logic_error("Queue is full! Can not enqueue.");
  }
}
template <class DataType>
DataType QueueArray<DataType>::dequeue() throw (logic_error)
{
  DataType temp = dataItems[front];
  if (front == back) {
    front = back = -1;
    return temp;
  }
  else if (!isEmpty()) {
    front = (front+1) % maxSize;
    return temp;
  }
  else {
    throw logic_error("Queue is Empty! No value to return.");
  }
}
template <class DataType>
void QueueArray<DataType>::clear()
{
  front = -1;
  back = -1;
}
template <class DataType>
bool QueueArray<DataType>::isEmpty() const
{
  return ((front == -1) && (back == -1));
}
template <class DataType>
bool QueueArray<DataType>::isFull() const
{
  if(front == ((back+1) % maxSize)) {
    return true;
  }
  return false;
}
template <class DataType>
void QueueArray<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{
  if (!isFull()) {
    if (front != 0) {
      front--;
      dataItems[front] = newDataItem;
    }
    else {
      front = maxSize - 1;
      dataItems[front] = newDataItem;
    }
  }
  else {
    throw logic_error("Queue is full! Can not enqueue.");
  }
}
template <class DataType>
DataType QueueArray<DataType>::getRear() throw (logic_error)
{
  return dataItems[back];
}
template <class DataType>
int QueueArray<DataType>::getLength() const
{
  if (front < back) {
    return ((back-front)+1);
  }
  else {
    return ((front-back)+1);
  }
}


#include "show7.cpp"
