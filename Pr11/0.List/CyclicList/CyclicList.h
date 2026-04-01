#ifndef _CyclicList_h_
#define _CyclicList_h_
#include "List.h"
typedef char Elem;

class CyclicList : public List
{
 public:
  CyclicList(const Elem &elem);
  virtual ~CyclicList();
  virtual void cons(const Elem &elem);
  virtual void pop();
  virtual ostream &show(ostream &) const;
};
#endif
