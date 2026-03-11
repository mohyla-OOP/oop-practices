#pragma once
#include <array>
template <std::size_t size, typename T = double>
class Array
{
 private:
  T _v[size];

 public:
  Array() {}
  ~Array() {};
  Array(const Array &);
  Array &operator=(const Array &);
  // TODO: 6: use proper return type
  double operator[](std::size_t i) const { return _v[i]; }
  // TODO: 7: use proper return type
  double &operator[](std::size_t i) { return _v[i]; }
  Array &operator+=(const Array &);
};

template <std::size_t size, typename T>
Array<size, T> operator+(const Array<size, T> &a, const Array<size, T> &b)
{
  Array<size, T> result;
  for (std::size_t i = 0; i < size; ++i) result[i] = a[i] + b[i];
  return result;
}
template <std::size_t size, typename T>
double operator*(const Array<size, T> &u, const Array<size, T> &v)
{
  double res = 0;
  for (std::size_t i = 0; i < size; i++) res += u[i] * v[i];
  return res;
}
template <std::size_t size, typename T>
Array<size, T> &Array<size, T>::operator=(const Array<size, T> &vec)
{
  //	Чи потрібна тепер ця перевірка?
  //	if (this==&vec)
  //		return *this;
  for (std::size_t i = 0; i < size; i++) _v[i] = vec._v[i];
  return *this;
}

// TODO: 14: what is it, explain this?

template <typename T>
struct Array<3, T>
{
  T _x{}, _y{}, _z{};
};

template <>
struct Array<3, double>
{
  double _x{}, _y{}, _z{};
};

template <>
struct std::array<double, 3>
{
  double _x{}, _y{}, _z{};
};

template <typename T>
struct std::array<T, 3>
{
  T _x{}, _y{}, _z{};
};
