#ifndef _LIST_H
#define _LIST_H

#include <iostream>
using namespace std;

typedef char Elem;

class List
{
 public:
  class BadList
  {
  };
  List(const Elem &elem);
  List(const List &);
  virtual ~List();
  List &operator=(const List &);
  virtual void cons(const Elem &elem);
  virtual const Elem &head() const;
  virtual void pop();
  virtual ostream &show(ostream &) const;

 protected:
  struct Node
  {
    Elem _elem;
    Node *_next;
    Node *_prev;
  };
  Node *_node;

 private:
  void del();
  void copy(const List &s);
};

ostream &operator<<(ostream &, const List &);
#endif