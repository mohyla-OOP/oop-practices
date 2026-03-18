#include <iostream.>

#include "CyclicList.h"
#include "List.h"
using namespace std;

// How to remove the problem below?

// TODO: 1: Check the diagram CLASS_DIAGRAM.md
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

  // TODO: HW: this should be fixed
  //  That is the problem
  //	l=cl; // TODO: 2: uncomment and set a breakpoint here and trace
  //           why the assignment fails?

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
  // That is the problem
  // TODO: 3: uncomment and check what happens here
  //	cout<<*pl;
  //	delete pl;
  cout << "-----------" << endl;

  return 0;
}