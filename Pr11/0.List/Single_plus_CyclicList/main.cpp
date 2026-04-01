#include <iostream>

#include "List.h"
using namespace std;

int main()
{
  List l('a');
  l.cons('b');
  l.cons('c');
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

  // l = cl; //TODO: 3: uncomment here, why it doesn't work

  IList *pl;

  // TODO: 4 trace here.
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