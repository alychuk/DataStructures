#include "SL_PriorityQueue.h"

template <class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue() : slistPtr(new LinkedSortedList<char>() ) {}

template <class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue(const SL_PriorityQueue& pq)
{
  slistPtr = new LinkedSortedList<ItemType>(pq);
}

template <class ItemType>
SL_PriorityQueue<ItemType>::~SL_PriorityQueue()
{
  slistPtr.reset();
}

template <class ItemType>
bool SL_PriorityQueue<ItemType>::isEmpty() const
{
  return slistPtr->isEmpty();
}

template <class ItemType>
bool SL_PriorityQueue<ItemType>::enqueue(const ItemType& newEntry)
{
  slistPtr->insert(newEntry);
  // assume stack/heap is never full
  return true;
}

template <class ItemType>
bool SL_PriorityQueue<ItemType>::dequeue()
{
  slistPtr->gotoBeginning();
  return slistPtr->remove();
}

// @throw PrecondViolatedExcept if priority queue is empty template <class ItemType>
ItemType SL_PriorityQueue<ItemType>::peekFront() const //throw(PrecondViolatedExcept)
{
  /*
  if (slistPtr->isEmpty()) {
    throw PrecondViolatedExcept("Queue is Empty.");
  }
  */
  slistPtr->gotoBeginning();
  return slistPtr->getCursor();
}
