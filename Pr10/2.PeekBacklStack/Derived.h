#ifndef _StackDerivedArray_h
#define _StackDerivedArray_h

template <class Elem>
class Array;
template <class Elem>
class Stack;

#define _DEBUG_

template <class Elem>
class StackDerivedArray
    : protected Array<Elem>
    , virtual public Stack<Elem>
{
 private:
  static const int bos;  // bottom of stack
 protected:
  int _top;
  //	Array<Elem> stackArray;

 public:
  class BadStack
  {
  };
  explicit StackDerivedArray<Elem>(int size) : Array<Elem>(size), _top(bos)
  {
#ifdef _DEBUG_
    cout << "Constructor StackDerivedArray " << size << endl;
#endif
  };
  virtual ~StackDerivedArray()
  {
#ifdef _DEBUG_
    cout << "Destructor StackDerivedArray" << endl;
#endif
  }
  bool empty() const { return _top == bos; }
  bool full() const { return _top == volume() - 1; }
  const Elem &top() const { return (*this)[_top]; }
  void pop()
  {
    if (empty()) throw BadStack();
    _top--;
  }
  void push(const Elem &value)
  {
    if (full()) throw BadStack();
    ia[++_top] = value;
  }
  int size() const { return _top + 1; }
  // delegating:
  int volume() const { return Array<Elem>::size(); }
  //	int size() const; Inherited
};
template <class Elem>
const int StackDerivedArray<Elem>::bos = -1;

#endif