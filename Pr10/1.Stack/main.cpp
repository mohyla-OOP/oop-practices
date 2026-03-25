#include <iostream>

#include "Array.h"
#include "Bounded.h"
#include "Derived.h"
#include "Stack.h"
#include "StackOnList.h"
using namespace std;

template <class Elem>
const int StackDerivedArray<Elem>::_bos = -1;
template <class Elem>
const int StackAgregatingArray<Elem>::_bos = -1;
void stackCall();

int main()
{
  // Acompany this function with a referenced parameter
  stackCall();
  return 0;
}

void stackCall()
{
  Stack<int> *s = nullptr;
  int volume;
  char choice;
  //	int el;
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

    for (int elem = 0; elem < volume; elem++) s->push(elem);
    for (int elem = 0; elem < volume; elem++)
    {
      cout << s->top();
      s->pop();
    }
    cout << endl;

    delete s;
    cout << "Once more?(y/n)";
    cin >> choice;
  } while (choice == 'y');
}
