#include "Widget.h"

#include <string>

template <typename T>
struct Widget<T>::Impl
{
  T _name = {};
};
template <typename T>
Widget<T>::Widget() : _p(new Impl)
{
}
template <typename T>
void Widget<T>::set(const T &a)
{
  _p->_name = a;
}
template <typename T>
const T &Widget<T>::show() const
{
  return _p->_name;
}
template class Widget<std::string>;
