#include "BoxB.h"
template <typename T>
BoxB<T>::BoxB(T v) : value_(v)
{
}

template <typename T>
void BoxB<T>::print() const
{
  std::cout << "BoxB: " << value_ << "\n";
}

// ЄДИНЕ місце, де реально створюється код
template class BoxB<int>;
template class BoxB<double>;