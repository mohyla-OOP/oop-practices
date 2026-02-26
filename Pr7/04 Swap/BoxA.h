#pragma once
#pragma once
#include <iostream>

template <typename T>
class BoxA
{
 public:
  BoxA(T v);
  void print() const;

 private:
  T value_;
};

// НІЯКИХ extern template тут немає
// #include "BoxA.tpp"