#pragma once
#include <complex>
#include <iostream>
#include <string>

template <typename T>
std::string info()
{
  return typeid(T).name();
}

template <typename T>
struct wrap
{
};

// wrap the type since typeid forgets all the qualifiers
template <typename T>
std::string my_info()
{
  return typeid(wrap<T>).name();
}

template <typename T1, typename T2>
auto add(T1 a, T2 b) /*-> decltype(a+b)*/
{
  return a + b;
}

template <typename T1, typename T2>
struct my_common_type
{
  using type = decltype(true ? T1{} : T2{});
};

template <typename T1, typename T2>
struct my_common_plus_type
{
  using type = decltype(std::declval<T1>() + std::declval<T2>());
};

template <typename T>
std::complex<T> operator+(int k, const std::complex<T> &z)
{
  return std::complex<T>(T(k)) + z;
}

template <typename T1, typename T2>
auto plus(T1 a, T2 b) -> typename std::common_type<T1, T2>::type
{
  return a + b;
}

std::string operator+(const std::string &s, char a) { return s + new char(a); }

decltype(auto) f()
{
  int x = 42;  // x in stack
  return (x);  // int& to x
}  // x deleted

void g()
{
  int local = 999;  // occupies the same stack
  std::cout << "g called\n";
}
