#pragma once
#include <iostream>

#include "Array.h"

template <class Elem>
class ArrayStack
{
 private:
  static const int _bos;  // bottom of stack
  size_t _top;
  Array<Elem> *_ar;

 public:
  class BadStack
  {
  };
  ArrayStack();
  ~ArrayStack();

  bool empty() const;
  bool full() const;
  const Elem &top() const;
  void pop();
  void push(const Elem &value);
  size_t size() const;
  size_t volume() const;
  void resize();
};

template <class Elem>
ArrayStack<Elem>::ArrayStack() : _ar(new Array<Elem>(0)), _top(_bos)
{
#ifndef NDEBUG_
  std::cout << "Constructor ArrayStack " << size() << std::endl;
#endif
};
template <class Elem>
ArrayStack<Elem>::~ArrayStack()
{
#ifndef NDEBUG_
  std::cout << "Destructor ArrayStack" << std::endl;
#endif
};

template <class Elem>
bool ArrayStack<Elem>::empty() const
{
  return _top == _bos;
}
template <class Elem>
bool ArrayStack<Elem>::full() const
{
  return _top == _ar->size() - 1;
}
template <class Elem>
const Elem &ArrayStack<Elem>::top() const
{
  return (*_ar)[_top];
}
template <class Elem>
void ArrayStack<Elem>::pop()
{
  if (empty()) throw BadStack();
  _top--;
}
template <class Elem>
void ArrayStack<Elem>::push(const Elem &value)
{
  if (full()) resize();
  (*_ar)[++_top] = value;
}
template <class Elem>
size_t ArrayStack<Elem>::size() const
{
  return _top + 1;
}
// delegating:
template <class Elem>
size_t ArrayStack<Elem>::volume() const
{
  return _ar->size();
}
template <class Elem>
void ArrayStack<Elem>::resize()
{
  size_t size = volume();
  size_t newsize = 2 * size + 1;

  Array<Elem> *newarray = new Array<Elem>(newsize);
  for (size_t i = 0; i < size; ++i) (*newarray)[i] = (*_ar)[i];

  delete _ar;
  _ar = newarray;
}