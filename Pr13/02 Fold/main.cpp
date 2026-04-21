#include <iostream>

int sum() { return 0; }

template <class T, class... Ts>
T sum(T first, Ts... rest)
{
  return first + sum(rest...);
}

template <class... Ts>
void print(Ts... args)
{
  (std::cout << ... << args);
}

template <class... Ts>
auto fold_sum(Ts... args)
{
  return (... + args);
}
int main()
{
  constexpr int c = 10;
  constexpr char a = 'a';
  double x = 3.14;
  auto d = sum(x, a, c);
  std::cout << typeid(d).name() << ':' << d << std::endl;
  d = sum(c, a, x);
  std::cout << typeid(d).name() << ':' << d << std::endl;
  auto d1 = fold_sum(c, a, c);
  print(typeid(d1).name(), ':', d1, '\n');
}