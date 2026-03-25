#ifndef _StackAgregatingArray_h
#define _StackAgregatingArray_h

template <class Elem>
class Array;
template <class Elem>
class Stack;

template <class Elem>
class StackAgregatingArray : public Stack<Elem>
{
 private:
  static const int _bos;  // bottom of stack
  // protected:
  int _top;
  Array<Elem> *_ar;

 public:
  class BadStack
  {
  };
  explicit StackAgregatingArray(int size) : _ar(new Array<Elem>(size)), _top(_bos)
  {
#ifndef NDEBUG_
    cout << "Constructor StackAgregatingArray " << size << endl;
#endif
  };
  ~StackAgregatingArray()
  {
    delete _ar;
#ifndef NDEBUG_
    cout << "Destructor StackAgregatingArray" << endl;
#endif
  };

  bool empty() const { return _top == _bos; }
  bool full() const { return _top == _ar->size() - 1; }
  const Elem &top() const { return (*_ar)[_top]; }
  void pop()
  {
    if (empty()) throw BadStack();
    _top--;
  }
  void push(const Elem &value)
  {
    if (full()) throw BadStack();
    (*_ar)[++_top] = value;
  }
  int size() const { return _top + 1; }
  // delegating:
  int volume() const { return _ar->size(); }
};
#endif