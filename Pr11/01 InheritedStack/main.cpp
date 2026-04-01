#include <complex>
#include <iostream>

#include "ArrayStack.h"
#include "ListStack.h"
#include "Stack.h"
using namespace std;

template <class Elem>
const int ArrayStack<Elem>::_bos = -1;

template <class T, template <typename> class Implementation>
void process(Stack<T, Implementation> &s)
{
  int volume(10);
  for (int elem = 0; elem < volume; elem++) s.push(T(elem));
  for (int elem = 0; elem < volume; elem++)
  {
    cout << s.top();
    s.pop();
  }
  cout << endl;
}

int main()
{
  size_t volume(10);
  {
    ListStack<int> s;
    for (int elem = 0; elem < volume; elem++) s.push(elem);
    for (int elem = 0; elem < volume; elem++)
    {
      cout << s.top();
      s.pop();
    }
    cout << endl;
  }
  {
    // TODO: 1: define array with no elements
    ArrayStack<int> s;
    for (int elem = 0; elem < volume; elem++) s.push(elem);  // TODO: 2: trace this
    for (int elem = 0; elem < volume; elem++)
    {
      cout << s.top();
      s.pop();
    }
    cout << endl;
  }
  {
    Stack<int, ArrayStack> s;
    for (int elem = 0; elem < volume; elem++) s.push(elem);
    for (int elem = 0; elem < volume; elem++)
    {
      cout << s.top();
      s.pop();
    }
    cout << endl;
  }
  {
    Stack<int, ListStack> s;
    for (int elem = 0; elem < volume; elem++) s.push(elem);
    for (size_t elem = 0; elem < volume; elem++)
    {
      cout << s.top();
      s.pop();
    }
    cout << endl;
  }
  {
    Stack<int, ArrayStack> s;
    process<int, ArrayStack>(s);
  }
  {
    Stack<int, ListStack> s;
    process<int, ListStack>(s);
  }
  {
    Stack<complex<double>, ArrayStack> s;
    process<complex<double>, ArrayStack>(s);
  }

  return 0;
}