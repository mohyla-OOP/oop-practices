#ifndef _CyclicList_h_
#define _CyclicList_h_
#include "List.h"
typedef char Elem;

class CyclicList : public List
{
 public:
  CyclicList(const Elem &elem);
  ~CyclicList();
  void cons(const Elem &elem);
  void pop();
  ostream &show(ostream &) const;
};
ostream &operator<<(ostream &, const CyclicList &);
#endif
