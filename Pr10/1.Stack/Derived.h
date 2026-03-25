#ifndef _StackDerivedArray_h
#define _StackDerivedArray_h

template <class Elem>
class Array;
template <class Elem>
class Stack;

template <class Elem>
class StackDerivedArray
    : public Array<Elem>
    , public Stack<Elem>
// should stack have array behaviour?
// class StackDerivedArray : private Array<Elem>, public Stack<Elem>
{
 private:
  static const int _bos;  // bottom of stack
  int _top;

 public:
  class BadStack
  {
  };
  explicit StackDerivedArray<Elem>(int size) : Array<Elem>(size), _top(_bos)
  {
#ifndef NDEBUG_
    cout << "Constructor StackDerivedArray " << size << endl;
#endif
  };
  virtual ~StackDerivedArray()
  {
#ifndef NDEBUG_
    cout << "Destructor StackDerivedArray" << endl;
#endif
  }
  bool empty() const { return _top == _bos; }
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
    (*this)[++_top] = value;
  }
  int size() const { return _top + 1; }
  // delegating:
  int volume() const { return Array<Elem>::size(); }
  //	int size() const; Inherited
};
#endif