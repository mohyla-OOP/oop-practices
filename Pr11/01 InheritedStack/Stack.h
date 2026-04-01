#pragma once
template <class T, template <typename> class Implementation>
class Stack : private Implementation<T>
{
 public:
  Stack() {}
  virtual ~Stack() {}
  void push(const T &x) { Implementation<T>::push(x); }
  void pop() { Implementation<T>::pop(); }
  const T &top() { return Implementation<T>::top(); }
  bool empty() const { return Implementation<T>::empty(); }
};
