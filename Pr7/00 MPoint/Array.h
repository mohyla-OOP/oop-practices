#pragma once
#include <array>
template <int size, typename T = double>
class Array
{
 private:
  T _v[size]{};

 public:
  Array() {}
  ~Array() {};
  Array &operator=(const Array &);
  double operator[](int i) const { return _v[i]; }
  double &operator[](int i) { return _v[i]; }
  Array &operator+=(const Array &);
};

// TODO: 1: what is it? what type is it?
template <typename T>
struct Array<3, T>
{
  T _x{}, _y{}, _z{};
};

// TODO: 2: how do they co-exist
template <>
struct Array<3, double>
{
  double _x{}, _y{}, _z{};
};
