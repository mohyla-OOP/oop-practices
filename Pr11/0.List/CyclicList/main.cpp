#include <iostream.>

#include "CyclicList.h"
#include "List.h"
using namespace std;

int main()
{
  List l('a');
  l.cons('b');
  l.cons('c');

  List copy(l);
  cout << "COPY***" << copy;
  copy.cons('d');
  copy.cons('e');
  cout << "COPY***" << copy;

  List ll('A');
  ll.cons('B');
  ll.cons('C');
  ll.cons('D');
  cout << ll;
  ll = copy;
  cout << ll;

  cout << l;
  l.pop();
  cout << l;
  l.pop();
  cout << l;
  l.pop();
  cout << l;
  l.cons('b');
  l.cons('c');
  cout << l;

  CyclicList cl('x');
  cl.cons('y');
  cl.cons('z');
  cout << cl;
  cl.pop();
  cout << cl;
  cl.pop();
  cout << cl;
  cl.pop();
  cout << cl;
  cl.cons('y');
  cl.cons('z');
  cout << cl;

  // That is the problem
  // TODO: 3: Set a breakpoint here, check console, what is `l`?
  // Object slicing, what is lvalue here and what is rvalue here?
  // LSP? Implementation inheritance is not the best solution, it is unsafe
  l = cl;

  List *pl;

  cout << "-----------" << endl;
  pl = new List('a');
  pl->cons('b');
  pl->cons('c');
  cout << *pl;
  delete pl;
  cout << "-----------" << endl;

  pl = new CyclicList('a');
  pl->cons('b');
  pl->cons('c');
  cout << *pl;
  delete pl;
  cout << "-----------" << endl;

  return 0;
}