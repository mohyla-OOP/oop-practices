#include "CyclicList.h"

#include <iostream>

#include "List.h"
using namespace std;

CyclicList::CyclicList(const Elem &elem) : List(elem)
{
  if (_node == 0) throw BadList();
  _node->_next = _node;
}

CyclicList::~CyclicList()
{
  CyclicList::Node *cur, *next = _node, *beg = _node;
  if (next) do
    {
      cur = next;
      next = next->_next;
      delete cur;
    } while (next != beg);

  _node = 0;
}

void CyclicList::cons(const Elem &elem)
{
  Node *oldNode = _node;
  if (_node) _node = _node->_next;
  List::cons(elem);
  if (oldNode)
    oldNode->_next = _node;
  else
    _node->_next = _node;
}

void CyclicList::pop()
{
  if (_node->_next == _node)
  {
    delete _node;
    _node = 0;
    return;
  }
  Node *oldNode = _node;
  _node = _node->_next;
  List::pop();
  oldNode->_next = _node;
}

ostream &CyclicList::show(ostream &os) const
{
  Node *cur = _node, *beg = _node;
  if (cur) do
    {
      os << cur->_elem << ':';
      cur = cur->_next;
    } while (cur != beg);

  os << endl;
  return os;
}

ostream &operator<<(ostream &os, const CyclicList &list) { return list.show(os); }