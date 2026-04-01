#ifndef _LIST_H
#define _LIST_H

#include <iostream>
using namespace std;
// Define templates and add Doubly linked list
typedef char Elem;
#include "ImpList.h"
class IList
{
 public:
  IList(const Elem &elem) {};
  virtual ~IList() {};  // TODO: 1: try =0 here and compile
  virtual void cons(const Elem &elem) = 0;
  virtual const Elem &head() const = 0;
  virtual void pop() = 0;
  virtual ostream &show(ostream &) const = 0;
};

// TODO: 2: define destructor here

ostream &operator<<(ostream &os, const IList &l)
{
  cout << "Garranteed enter through interface" << endl;
  return l.show(os);
}

class List : public IList
{
 private:
  ImpList *_implist;

 public:
  List(const Elem &elem) : IList(elem), _implist(new ImpList(elem)) {};
  virtual ~List() { delete _implist; }
  virtual void cons(const Elem &elem) { _implist->cons(elem); }
  virtual const Elem &head() const { return _implist->head(); };
  virtual void pop() { _implist->pop(); }

 private:
  virtual ostream &show(ostream &os) const { return _implist->show(os); }
};

class CyclicList : public IList
{
 private:
  ImpCyclicList *_implist;

 public:
  CyclicList(const Elem &elem) : IList(elem), _implist(new ImpCyclicList(elem)) {};
  ~CyclicList() { delete _implist; }
  virtual void cons(const Elem &elem) { _implist->cons(elem); }
  virtual const Elem &head() const { return _implist->head(); };
  virtual void pop() { _implist->pop(); }

 private:
  virtual ostream &show(ostream &os) const { return _implist->show(os); }
};
#endif