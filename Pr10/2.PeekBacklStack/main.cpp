#include <iostream>

#include "Array.h"
#include "Bounded.h"
#include "Derived.h"
#include "Peekback.h"
#include "Stack.h"
#include "StackOnList.h"
using namespace std;

void peekBackCall();
void stackCall();

template <typename T>
void stackCall(Stack<T> &s, int volume)
{
  for (int elem = 0; elem < volume; elem++) s.push(elem);
  for (int elem = 0; elem < volume; elem++)
  {
    cout << s.top();
    s.pop();
  }
  cout << endl;
  return;
}

int main()
{
  //	1.Refactor peekBackCall the same way as stackCall
  //	2. Define a single template to generalize both functions
  //     peekBackCall();
  stackCall();

  return 0;
}

void stackCall()
{
  Stack<int> *s;
  int volume;
  char choice;
  bool flag = false;
  do
  {
    cout << "Which type of stack?(Aggregating/Derived/Listed)";
    cin >> choice;
    if (choice == 'l')
    {
      s = new StackOnList<int>;
      cout << "The length of your circle?";
      cin >> volume;
    }
    else
    {
      cout << "Which volume of stack?";
      cin >> volume;
      if (choice == 'd')
        s = new StackDerivedArray<int>(volume);
      else
        s = new StackAgregatingArray<int>(volume);
    }

    stackCall<int>(*s, volume);

    delete s;
    cout << "Once more?(y/n)";
    cin >> choice;
  } while (choice == 'y');
}

void peekBackCall()
{
  PeekbackStack<int> *s;
  int volume;
  char choice;
  int el;
  bool flag = false;
  do
  {
    cout << "Which type of stack?(Aggregating/Derived/Listed)";
    cin >> choice;
    if (choice == 'l')
    {
      s = new ListedPeekbackStack<int>;
      cout << "The length of your circle?";
      cin >> volume;
    }
    else
    {
      cout << "Which volume of stack?";
      cin >> volume;
      if (choice == 'd')
        s = new DerivedPeekbackStack<int>(volume);
      else
        s = new AgregatingPeekbackStack<int>(volume);
    }
    for (int elem = 0; elem < volume - 2; elem++) s->push(elem);
    for (int elem = 0; elem < volume; elem++)
    {
      flag = s->peekback(elem, el);
      if (!flag) cout << endl << "Out of size: ";
      cout << el << ',';
    }
    cout << endl;
    delete s;
    cout << "Once more?(y/n)";
    cin >> choice;
  } while (choice == 'y');
}