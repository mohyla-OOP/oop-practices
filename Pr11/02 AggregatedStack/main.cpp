#include <iostream>

#include "ArrayStack.h"
#include "ListStack.h"
#include "Stack.h"
using namespace std;

template <class Elem>
const int ArrayStack<Elem>::_bos = -1;

template <class T, template <typename> class Implementation>
void process(Stack<T, Implementation> &s, size_t volume)
{
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
    ArrayStack<int> s;
    for (int elem = 0; elem < volume; elem++) s.push(elem);
    for (int elem = 0; elem < volume; elem++)
    {
      cout << s.top();
      s.pop();
    }
    cout << endl;
    // process(s);
  }
  {
    Stack<char, ArrayStack> s;
    for (char elem = 'a'; elem <= 'z'; elem++) s.push(elem);
    while (!s.empty())
    {
      cout << s.top() << ' ';
      s.pop();
    }
    cout << endl;
  }
  {
    Stack<char, ListStack> s;
    for (char elem = 'A'; elem <= 'Z'; elem++) s.push(elem);
    while (!s.empty())
    {
      cout << s.top() << ' ';
      s.pop();
    }
    cout << endl;
  }
  {
    Stack<int, ArrayStack> s;
    process(s, volume);
  }
  {
    Stack<int, ListStack> s;
    process(s, volume);
  }

  return 0;
}