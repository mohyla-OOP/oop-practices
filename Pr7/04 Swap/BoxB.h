#pragma once
#include <iostream>

template <typename T>
class BoxB
{
 public:
  BoxB(T v);
  void print() const;

 private:
  T value_;
};

// Заборонити автоматичне інстанціювання:
extern template class BoxB<int>;
extern template class BoxB<double>;

// #include "BoxB.tpp"