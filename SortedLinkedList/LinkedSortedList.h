#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template<class ItemType>
class LinkedSortedList;

template <typename ItemType>
std::ostream& operator<<(std::ostream& os, const LinkedSortedList<ItemType>& LinkedSortedList);

template <class ItemType>
class LinkedSortedList {
public:
  LinkedSortedList();
  LinkedSortedList(const LinkedSortedList& otherList);
  ~LinkedSortedList();
  LinkedSortedList& operator= (const LinkedSortedList& otherList);
  void insert(const ItemType& newDataItem) throw (logic_error);
  bool remove() throw (logic_error);
  int itemCount() const;
  void clear();
  bool isEmpty() const;
  bool isFull() const;

  void gotoBeginning() throw (logic_error);
  void gotoEnd() throw (logic_error);
  bool gotoNext() throw (logic_error);
  bool gotoPrior() throw (logic_error);

  ItemType getCursor() const throw (logic_error);

  const ItemType& operator[] (int index) const;
  friend std::ostream& operator<< <>(std::ostream& os, const LinkedSortedList<ItemType>& LinkedSortedList);

private:
  class ListNode {
  public:
    ItemType dataItem;
    ListNode *next;
    ListNode();
    ListNode(const ItemType& newItem, ListNode *nextPtr);
  };
  ListNode *pFirst;
  ListNode *pLast;
  ListNode *cursor;
  int size;
};


#endif


template<class ItemType>
LinkedSortedList<ItemType>::ListNode::ListNode() : next(NULL) {}

template<class ItemType>
LinkedSortedList<ItemType>::ListNode::ListNode(const ItemType& nodeData, ListNode* nextPtr) : dataItem(nodeData), next(nextPtr) {}

// Default constructor, does nothing is ignored
template <class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList() : pFirst(NULL), pLast(NULL), cursor(NULL), size(0) { }

template <class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList& otherList)
{
  if (otherList.isEmpty()) {
    pFirst = NULL;
    pLast = NULL;
    cursor = NULL;
    size = 0;
  }
  else {
    pFirst = new ListNode(otherList.pFirst->dataItem, NULL);
    ListNode *temp = otherList.pFirst;
    for (cursor = pFirst; temp != NULL; cursor = cursor->next) {
      temp = temp->next;
      cursor->next = new ListNode(temp->dataItem, NULL);
    }
    pLast = temp;
    cursor = pFirst;
    size = otherList.itemCount();
  }
}
template <class ItemType>
bool LinkedSortedList<ItemType>::remove() throw (logic_error)
{
  // Special case throws exception
  if (isEmpty()) {
    return false;
    throw logic_error("remove() empty list");
  }
  else {
    size--;
    ListNode *temp;
    // Cursor is at the front of the list
    if (pFirst == cursor) {
      // Cursor is on the only node in the list
      if (pFirst->next == NULL) {
        delete pFirst;
        pFirst = NULL;
        pLast = NULL;
        cursor = NULL;
        temp = NULL;
        return true;
      }
      // Cursor is on the first node, other nodes in the list
      else {
        pFirst = pFirst->next;
        delete cursor;
        temp = NULL;
        return true;
      }
    }
    // Cursor is at the end of the list
    else if (cursor->next == NULL) {
      ListNode *previous = pFirst;
      temp = cursor;
      while (previous->next != cursor) {
        previous = previous->next;
      }
      cursor = previous;
      pLast = cursor;
      cursor->next = NULL;
      cursor = pFirst;
      delete temp;
      temp = NULL;
      return true;
    }
    // Cursor has a node in front and back
    else {
      temp = cursor->next;
      cursor->dataItem = temp->dataItem;
      cursor->next = temp->next;
      delete temp;
      temp = NULL;
      return true;
    }
  }
}
template <class ItemType>
LinkedSortedList<ItemType>& LinkedSortedList<ItemType>::operator=(const LinkedSortedList<ItemType>& otherList)
{
  // checks to make sure it isn't copying itself
  if (this != &otherList) {
    if (otherList.isEmpty()) {
      clear();
    }
    else {
      clear();
      size = otherList.itemCount();
      pFirst = new ListNode(otherList.pFirst->dataItem, NULL);
      ListNode *temp = otherList.pFirst;
      for (cursor = pFirst; temp != NULL; cursor = cursor->next) {
        temp = temp->next;
        cursor->next = new ListNode(temp->dataItem, NULL);
      }
      pLast = cursor;
      cursor = pFirst;
    }
  }
  return *this;
}
// Destructor
template <class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList()
{
  cursor = pFirst;
  while (pFirst != NULL) {
    remove();
  }
}




template <class ItemType>
void LinkedSortedList<ItemType>::insert(const ItemType& newDataItem) throw (logic_error)
{
  size++;
  // Create first node in list
  if (isEmpty()) {
    pFirst = new ListNode(newDataItem, NULL);
    cursor = pFirst;
    pLast = cursor;
  }
  // List can only be full if heap is used completely, unlikely outcome
  // assumed to never be full
  else if (isFull()) {
    throw logic_error("insert() full list");
  }
  else {
    // find placement of new item
    if (newDataItem < pFirst->dataItem) {
      ListNode *temp = pFirst;
      pFirst = new ListNode(newDataItem, temp);
      cursor = pFirst;
      temp = NULL;
    }
    // Insert at the end of the list
    else if (newDataItem > pLast->dataItem) {
      pLast->next = new ListNode(newDataItem, NULL);
      pLast = pLast->next;
      cursor = pLast;
    }
    // Insert in the middle of the list
    else {
      ListNode *temp, *temp2;
      for (temp = pFirst; (temp->next != NULL) && (newDataItem > temp->dataItem); temp = temp->next) {
        if (temp->next->dataItem >= newDataItem) {
          temp2 = temp->next;
          temp->next = new ListNode(newDataItem, temp2);
          temp2 = NULL;
        }
      }
    }
  }
}


template <class ItemType>
void LinkedSortedList<ItemType>::clear() {
  cursor = pFirst;
  while (pFirst != NULL) {
    remove();
  }
}

template <class ItemType>
int LinkedSortedList<ItemType>::itemCount() const
{
  return size;
}


template <class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const {
  if (pFirst == NULL) {
    return true;
  }
  else {
    return false;
  }
}
template <class ItemType>
bool LinkedSortedList<ItemType>::isFull() const {
  return false;
}




template <class ItemType>
void LinkedSortedList<ItemType>::gotoBeginning() throw (logic_error) {
  cursor = pFirst;
}
template <class ItemType>
void LinkedSortedList<ItemType>::gotoEnd() throw (logic_error) {
  cursor = pLast;
}
template <class ItemType>
bool LinkedSortedList<ItemType>::gotoNext() throw (logic_error) {
  if (isEmpty()) {
    throw logic_error("gotoNext() empty list");
  }
  else if (cursor->next == NULL) {
    return false;
  }
  else {
    cursor = cursor->next;
    return true;
  }
}
template <class ItemType>
bool LinkedSortedList<ItemType>::gotoPrior() throw (logic_error) {
  if (isEmpty()) {
    throw logic_error("gotoPrior() empty list");
  }
  else if (pFirst == cursor) {
    return false;
  }
  else {
    // Searches list to find previous and then moves the cursor to it
    ListNode *previous = pFirst;
    while (previous->next != cursor) {
      previous = previous->next;
    }
    cursor = previous;
    previous = NULL;
    return true;
  }
}




template <class ItemType>
ItemType LinkedSortedList<ItemType>::getCursor() const throw (logic_error) {
  if (isEmpty()) {
    throw logic_error("getCursor() empty list");
  }
  else {
    return cursor->dataItem;
  }
}


template <class ItemType>
const ItemType& LinkedSortedList<ItemType>::operator[] (int index) const
{
  if (index >= size) {
    cout << "Array out of bounds!" << endl;
    return 0;
  }
  else {
    ItemType *temp = pFirst;
    for (int i = 0; i < (index+1); temp = temp->nextPtr) {}
    return temp->dataItem;
  }
}

template <typename ItemType>
std::ostream& operator<<(std::ostream& os, const LinkedSortedList<ItemType>& LinkedSortedList)
{
  if (LinkedSortedList.isEmpty()) {
    os << "List is Empty." << endl;
  }
  else {
    for(int i=0; i < LinkedSortedList.itemCount(); i++) {
      os << "[" << LinkedSortedList[i] << "]" << " ";
    }
    os << endl;
  }
  return os;
}
