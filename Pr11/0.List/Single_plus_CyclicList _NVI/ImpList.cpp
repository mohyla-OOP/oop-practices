#include "ImpList.h"

#include <iostream>
using namespace std;
using std::ostream;

struct ImpList::Node
{
  Elem _elem;
  Node *_next;
};

ImpList::ImpList(const Elem &elem)
{
  _node = new Node;
  _node->_elem = elem;
  _node->_next = 0;
}

ImpList::~ImpList()
{
  ImpList::Node *next = _node;
  ImpList::Node *cur;
  while (next)
  {
    cur = next;
    next = next->_next;
    delete cur;
  }
}

void ImpList::cons(const Elem &elem)
{
  Node *oldNode = _node;
  _node = new Node;
  _node->_elem = elem;
  _node->_next = oldNode;
}

const Elem &ImpList::head() const
{
  if (_node == 0) throw BadImpList();
  return _node->_elem;
}

void ImpList::pop()
{
  if (_node == 0) throw BadImpList();
  Node *newNode = _node->_next;
  delete _node;
  _node = newNode;
}

ostream &ImpList::show(ostream &os) const
{
  Node *cur = _node;
  while (cur)
  {
    os << cur->_elem << ':';
    cur = cur->_next;
  }
  os << endl;
  return os;
}

ostream &operator<<(ostream &os, const ImpList &ImpList) { return ImpList.show(os); }

ImpCyclicList::ImpCyclicList(const Elem &elem) : ImpList(elem)
{
  if (_node == 0) throw BadImpList();
  _node->_next = _node;
}

ImpCyclicList::~ImpCyclicList()
{
  ImpList::Node *next = _node, *beg = _node;
  ImpList::Node *cur;
  if (next) do
    {
      cur = next;
      next = next->_next;
      delete cur;
    } while (next != beg);
  _node = nullptr;
}

void ImpCyclicList::cons(const Elem &elem)
{
  Node *oldNode = _node;
  if (_node) _node = _node->_next;
  ImpList::cons(elem);
  if (oldNode)
    oldNode->_next = _node;
  else
    _node->_next = _node;
}

void ImpCyclicList::pop()
{
  if (_node->_next == _node)
  {
    delete _node;
    _node = 0;
    return;
  }
  Node *oldNode = _node;
  _node = _node->_next;
  ImpList::pop();
  oldNode->_next = _node;
}

ostream &ImpCyclicList::show(ostream &os) const
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