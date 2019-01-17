#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "PriorityQueueInterface.h"
#include "LinkedSortedList.h"
#include "PrecondViolatedExcept.h"
#include <memory>
template<class ItemType>
class SL_PriorityQueue : public PriorityQueueInterface<ItemType>
{
private:
  // Ptr to sorted list of items
  std::unique_ptr<LinkedSortedList<ItemType>> slistPtr;
public:
  SL_PriorityQueue();
  SL_PriorityQueue(const SL_PriorityQueue& pq);
  ~SL_PriorityQueue();
  bool isEmpty() const;
  bool enqueue(const ItemType& newEntry);
  bool dequeue();
// @throw PrecondViolatedExcept if priority queue is empty
  ItemType peekFront() const; // throw(PrecondViolatedExcept);
}; // end SL_PriorityQueue
#include "SL_PriorityQueue.cpp"
#endif
