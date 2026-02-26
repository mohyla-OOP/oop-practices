#pragma once
#include <iostream>
using namespace std;

template <class Item>
class TList
{
 public:
  class BadTList;
  TList();
  TList(const TList &);
  ~TList();
  TList &append(const Item &);

 private:
  struct Node
  {
    Item _elem;
    Node *_next;
  };
  //	Where the fist element is located
  Node *_head;
  //	Where the last element is located
  Node *_end;
};

template <class Item>
TList<Item>::TList() : _head(nullptr), _end(nullptr)
{
}

template <class Item>
TList<Item>::~TList()
{
  if (_head == nullptr) return;
  do
  {
    Node *node = _head;
    _head = _head->_next;
    // cout << node->_elem << endl;
    delete node;
  } while (_head != nullptr);
}

template <class Item>
TList<Item> &TList<Item>::append(const Item &item)
{
  Node *node = new Node;
  node->_elem = item;
  if (_head == nullptr)
  {
    node->_next = nullptr;
    _head = _end = node;
  }
  else
  {
    _end->_next = node;
    node->_next = nullptr;
    _end = node;
  }
  return *this;
}
