#ifndef _LIST_H
#define _LIST_H

#include <iostream>
using namespace std;

typedef char Elem;
#include "ImpList.h"
// realise operator=
class IList
{
 public:
  IList(const Elem &elem) {};
  virtual ~IList() {};
  virtual IList &operator=(const IList &) = delete;
  void cons(const Elem &elem)
  {
    cout << "Garranteed enter through interface" << endl;
    do_cons(elem);
  }
  const Elem &head() const
  {
    cout << "Garranteed enter through interface" << endl;
    return do_head();
  }
  void pop()
  {
    cout << "Garranteed enter through interface" << endl;
    do_pop();
  }
  ostream &show(ostream &os) const
  {
    cout << "Garranteed enter through interface" << endl;
    return do_show(os);
  }

 private:
  virtual void do_cons(const Elem &elem) = 0;
  virtual const Elem &do_head() const = 0;
  virtual void do_pop() = 0;
  virtual ostream &do_show(ostream &) const = 0;
};

ostream &operator<<(ostream &os, const IList &l) { return l.show(os); }

class List : public IList
{
 private:
  ImpList *_implist;

 public:
  List(const Elem &elem) : IList(elem), _implist(new ImpList(elem)) {};
  virtual ~List() { delete _implist; }
  // That is the problem
  /*virtual List& operator=(const List& l)
  {
    return *this;
  }*/
 private:
  virtual void do_cons(const Elem &elem) { _implist->cons(elem); }
  virtual const Elem &do_head() const { return _implist->head(); };
  virtual void do_pop() { _implist->pop(); }
  virtual ostream &do_show(ostream &os) const { return _implist->show(os); }
};

class CyclicList : public IList
{
 private:
  ImpCyclicList *_implist;

 public:
  CyclicList(const Elem &elem) : IList(elem), _implist(new ImpCyclicList(elem)) {};
  // That is the problem
  /*virtual CyclicList& operator=(const IList& l)
  {
    return *this;
  }*/
 private:
  virtual void do_cons(const Elem &elem) { _implist->cons(elem); }
  virtual const Elem &do_head() const { return _implist->head(); };
  virtual void do_pop() { _implist->pop(); }
  virtual ostream &do_show(ostream &os) const { return _implist->show(os); }
};
#endif