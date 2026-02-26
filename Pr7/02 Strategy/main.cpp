#include "Array.h"
#include "ConcreteList.h"
#include "Foo.h"
#include "List.h"
#include "TemplateList.h"

int main()
{
  {
    CList list;
    list.append('a').append('b').append('c');
  }
  {
    TList<double> list;
    list.append(1).append(2).append(3);
  }
  {
    // TODO: 7: check Foo and its destructor
    TList<Foo> lf;
    lf.append(Foo(1)).append(Foo(2));
  }
  {
    // TODO: 8: check how destruction being made
    TList<Foo *> plist;
    for (int k = 0; k < 10; ++k)
    {
      plist.append(new Foo(k));
    }
  }
  {
    List<char, NoDeletePolicy> list;
    list.append('a').append('b').append('c');
  }
  {
    List<int *, PtrDeletePolicy> plist;
    for (int k = 0; k < 10; ++k)
    {
      // TODO: 9: check how append is made
      plist.append(new int(k));
    }
  }  // TODO: 10: check how destruction is being called
  {
    List<int *, ArrayDeletePolicy> alist;
    for (int k = 0; k < 10; ++k)
    {
      alist.append(new int[k]);
    }
  }
  {
    List<Foo *, PtrDeletePolicy> flist;
    flist.append(new Foo(1)).append(new Foo(2));
  }
  return 0;
}