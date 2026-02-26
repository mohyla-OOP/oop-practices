#include "ConcreteList.h"

CList::CList() : _head(nullptr), _end(nullptr) {}
CList::~CList()
{
  if (_head == nullptr) return;
  do
  {
    Node *node = _head;
    _head = _head->_next;
    delete node;
  } while (_head != nullptr);
}

CList &CList::append(const Item &item)
{
  Node *node = new Node;
  node->_elem = item;
  node->_next = nullptr;
  if (_head == nullptr)
  {
    _head = _end = node;
  }
  else
  {
    _end->_next = node;
    _end = node;
  }
  return *this;
}