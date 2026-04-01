#include "List.h"

#include <iostream>
using namespace std;
using std::ostream;

List::List(const Elem &elem)
{
  _node = new Node;
  _node->_elem = elem;
  _node->_next = 0;
}

List::~List() { del(); }

void List::del()
{
  List::Node *next = _node;
  List::Node *cur;
  while (next)
  {
    cur = next;
    next = next->_next;
    delete cur;
  }
}

void List::copy(const List &s)
{
  _node = 0;
  Node *itor = s._node;
  while (itor)
  {
    cons(itor->_elem);
    itor = itor->_next;
  }
}
List::List(const List &s) { copy(s); }

List &List::operator=(const List &s)
{
  if (_node == s._node) return *this;
  del();
  copy(s);
  return *this;
}

void List::cons(const Elem &elem)
{
  Node *oldNode = _node;
  _node = new Node;
  _node->_elem = elem;
  _node->_next = oldNode;
}

const Elem &List::head() const
{
  if (_node == 0) throw BadList();
  return _node->_elem;
}

void List::pop()
{
  if (_node == 0) throw BadList();
  Node *newNode = _node->_next;
  delete _node;
  _node = newNode;
}

ostream &List::show(ostream &os) const
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

ostream &operator<<(ostream &os, const List &list) { return list.show(os); }