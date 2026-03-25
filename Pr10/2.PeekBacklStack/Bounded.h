#ifndef _StackAgregatingArray_h
#define _StackAgregatingArray_h

template <class Elem>
class Array;
template <class Elem>
class Stack;

template <class Elem>

#define _DEBUG_

class StackAgregatingArray : virtual public Stack<Elem>
{
 private:
  static const int bos;  // bottom of stack

 protected:
  int _top;
  Array<Elem> stackArray;

 public:
  class BadStack
  {
  };
  explicit StackAgregatingArray(int size) : stackArray(size), _top(bos)
  {
#ifdef _DEBUG_
    cout << "Constructor StackAgregatingArray " << size << endl;
#endif
  };
  virtual ~StackAgregatingArray()
  {
#ifdef _DEBUG_
    cout << "Destructor StackAgregatingArray" << endl;
#endif
  };

  bool empty() const { return _top == bos; }
  bool full() const { return _top == stackArray.size() - 1; }
  const Elem &top() const { return stackArray[_top]; }
  void pop()
  {
    if (empty()) throw BadStack();
    _top--;
  }
  void push(const Elem &value)
  {
    if (full()) throw BadStack();
    stackArray[++_top] = value;
  }
  int size() const { return _top + 1; }
  // delegating:
  int volume() const { return stackArray.size(); }
};

template <class Elem>
const int StackAgregatingArray<Elem>::bos = -1;

#endif