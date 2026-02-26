#pragma once
#include <complex>
#include <concepts>
#include <string>
#include <utility>

// void swap(int& a, int& b)
//{
//	auto tmp = a;
//	a=b;
//	b = tmp;
// }
//
// void swap(double& a, double& b)
//{
//	auto tmp = a;
//	a = b;
//	b = tmp;
// }
//
// void swap(std::string& a, std::string& b)
//{
//	auto tmp = a;
//	a = b;
//	b = tmp;
// }
//
// void swap(std::complex<double>& a, std::complex<double>& b)
//{
//	auto tmp = a;
//	a = b;
//	b = tmp;
// }
//
// void swap(std::complex<float>& a, std::complex<float>& b)
//{
//	auto tmp = a;
//	a = b;
//	b = tmp;
// }

template <typename T>
void swap(std::complex<T> &a, std::complex<T> &b)
{
  auto tmp = a;
  a = b;
  b = tmp;
}

// template void swap < double>(double&, double&);
struct NoAssign
{
  NoAssign &operator=(const NoAssign &) = delete;
};

template <typename T>
T min(const T &a, const T &b)
{
  return a < b ? a : b;
}
struct Complex
{
  double _re, _im;
};

template <typename T>
  requires(std::move_constructible<T> && std::assignable_from<T &, T>)
void swap(T &a, T &b)
{
  T temp = std::move(a);
  a = std::move(b);
  b = std::move(temp);
}
