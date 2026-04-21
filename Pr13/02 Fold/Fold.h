#pragma once
// Quest
// 1
int x = 0;
const int cx = 0;

auto a = cx;
decltype(cx) b = cx;

// type of a, type of b
//
// 2
template <class T1, class T2>
auto f(T1 a, T2 b)
{
  return a + b;
}
// type of results
// f(1, 2)
// f(1, 2.0)
// f(1u, -2)

// 3
template <class T1, class T2>
struct my_common_type
{
  using type = ? ? ? ;
};
