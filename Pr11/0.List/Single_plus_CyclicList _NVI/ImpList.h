#pragma once

#include <iostream>
using namespace std;

typedef char Elem;

class ImpList
{
 public:
  class BadImpList
  {
  };
  ImpList(const Elem &elem);
  void cons(const Elem &elem);
  const Elem &head() const;
  void pop();
  ~ImpList();
  ostream &show(ostream &) const;

 protected:
  struct Node;
  Node *_node;
};

class ImpCyclicList : private ImpList
{
 public:
  ImpCyclicList(const Elem &elem);
  ~ImpCyclicList();
  void cons(const Elem &elem);
  void pop();
  const Elem &head() const { return ImpList::head(); }
  ostream &show(ostream &) const;
};
