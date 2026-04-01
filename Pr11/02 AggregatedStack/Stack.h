#pragma once

template <class T, template <typename> class Implementation>
class Stack
{
 private:
  Implementation<T> *_implementation;

 public:
  Stack() : _implementation(new Implementation<T>) {}
  virtual ~Stack() {}
  void push(const T &x) { _implementation->push(x); }
  void pop() { _implementation->pop(); }
  const T &top() { return _implementation->top(); }
  bool empty() const { return _implementation->empty(); }
};
