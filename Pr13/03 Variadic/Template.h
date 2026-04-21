#pragma once
#include <iostream>

template <typename T>
inline T minimum(const T &t)
{
  return t;
}

template <typename T, typename... P>
typename std::common_type<T, P...>::type minimum(const T &t, const P &...p)
{
  typedef typename std::common_type<T, P...>::type res_type;
  return std::min(res_type(t), res_type(minimum(p...)));
}

// Since variadic templates are recursive, must have a base case
template <typename T>
inline T sum(T t)
{
  return t;
}

template <typename T, typename... P>
T sum(T t, P... p)
{
  return t + sum(p...);
}

template <typename... P>
struct sum_type;
template <typename... P>
struct common_type;

template <typename T, typename... P>
struct sum_type<T, P...>
{
  using type = decltype(T() + /*typename*/ sum_type<P...>::type());
};

template <typename T>
struct sum_type<T>
{
  typedef T type;
};

template <typename T>
inline T my_minimum(const T &t)
{
  return t;
}

template <typename T, typename... P>
typename sum_type<T, P...>::type my_minimum(const T &t, const P &...p)
{
  using res_type = typename sum_type<T, P...>::type;
  return std::min(res_type(t), res_type(my_minimum(p...)));
}
template <typename T>
T inline min_magnitude(const T &x, const T &y)
{
  // using std::abs;
  auto ax = abs(x), ay = abs(y);
  return ax < ay ? x : y;
}

template <typename T, typename... Args>
struct Count;

template <typename T, typename First, typename... Rest>
struct Count<T, First, Rest...>
{
  static constexpr int _value = (std::is_same_v<First, T> ? 1 : 0) + Count<T, Rest...>::_value;
};

template <typename T>
struct Count<T>
{
  static constexpr int _value = 0;
};

template <typename... Args>
constexpr int count_ints()
{
  return (... + (std::is_same_v<Args, int> ? 1 : 0));
}

template <typename T, typename... Args>
constexpr int count()
{
  return (0 + ... + (std::is_same_v<Args, T> ? 1 : 0));
}
