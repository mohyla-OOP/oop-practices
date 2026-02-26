#include "BoxA.h"

template <typename T>
BoxA<T>::BoxA(T v) : value_(v)
{
}

template <typename T>
void BoxA<T>::print() const
{
  std::cout << "BoxA: " << value_ << "\n";
}

// Явні інстанції:
// ці інстанції гарантовано створені тут,
// але інші cpp теж МОЖУТЬ створити свої копії...
// TODO: 1: add for string
template class BoxA<int>;
template class BoxA<double>;
// template class BoxA<std::string>;