#ifndef _REFWRAPPER_H_
#define _REFWRAPPER_H_

template <typename Type>
class RefWrapper
{
 private:
  const Type &_data;

 public:
  RefWrapper(Type &data) : _data(data) {};
  operator const Type &() const { return _data; }
  const Type &data() const { return _data; }
  Type &data() { return _data; }
};

template <typename Type>
ostream &operator<<(ostream &os, const RefWrapper<Type> &a)
{
  return os << a.data();
}

template <typename Type>
const Type operator+(const RefWrapper<Type> &a, const RefWrapper<Type> &b)
{
  return a.data() + b.data();
}

template <typename Type>
const Type operator-(const RefWrapper<Type> &a, const RefWrapper<Type> &b)
{
  return a.data() - b.data();
}
template <typename Type>
const Type operator*(const RefWrapper<Type> &a, const RefWrapper<Type> &b)
{
  return a.data() * b.data();
}
template <typename Type>
const Type operator/(const RefWrapper<Type> &a, const RefWrapper<Type> &b)
{
  return a.data() / b.data();
}

#endif