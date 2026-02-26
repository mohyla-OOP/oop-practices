#pragma once
template <typename T>
T add(T a, T b)
{
  static_assert(std::is_arithmetic_v<T>, "T must be arithmetic");
  return a + b;
}

template <typename T>
auto foo(T t) -> decltype(t.size(), void())
{
  std::cout << "who said meow?\n";
}

void foo(...) { std::cout << "none said meow\n"; }