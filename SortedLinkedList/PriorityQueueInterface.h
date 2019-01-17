#ifndef PRIORITY_QUEUE_INTERFACE_H
#define PRIORITY_QUEUE_INTERFACE_H
#include <stdexcept>

template<class ItemType>
class PriorityQueueInterface
{
public:
  virtual ~PriorityQueueInterface() {};
  virtual bool isEmpty() const = 0;
  virtual bool enqueue(const ItemType& newEntry) = 0;
  virtual bool dequeue() = 0;
// @throw PrecondViolatedExcept if priority queue is empty
  ItemType peekFront() const;//noexcept = 0;
}; // end SL_PriorityQueue

#endif
