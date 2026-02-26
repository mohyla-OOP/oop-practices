#pragma once
#include <iostream>
using namespace std;

// TODO: 3: Explain what the entity it i
template <bool>
struct CTAssert;
// TODO: 5: why there is not struct body? Uncomment and check what happens?
// template <bool> struct CTAssert{};
// TODO: 4: Explain what it is, remember specialization
template <>
struct CTAssert<true>
{
};

ostream &operator<<(ostream &os, CTAssert<true> &) { return os << "CTAssert<true>" << endl; }

constexpr unsigned int shiftLeft(const unsigned int x, const unsigned int n) { return (x >> (32 - n)) | (x << n); }

constexpr unsigned int shiftRight(const unsigned int x, const unsigned int n) { return (x << (32 - n)) | (x >> n); }

template <class T>
struct Arithm
{
  T _a;
  void print() const { cout << _a << endl; }
};
template <>
struct Arithm<unsigned int>
{
  unsigned int _a;
  void print() const { cout << hex << _a << dec << endl; }
};

template <int n>
struct Power
{
  static constexpr double power(const double x) { return x * Power<n - 1>::power(x); }
};
template <>
struct Power<0>
{
  static constexpr double power(const double x) { return 1; }
};