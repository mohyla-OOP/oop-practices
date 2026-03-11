#include "List.h"

struct Foo
{
  Foo(int k = 0) : _k(k) {}
  int _k = 0;
  operator int() const { return _k; }
};

// ---- main ----
int main()
{
  List<Foo> foo;

  List<int> lst = {1, 2, 3, 4, 5};
  std::cout << lst << '\n';  // 1 2 3 4 5

  lst.push_back(6);
  lst.push_front(0);
  std::cout << lst << '\n';  // 0 1 2 3 4 5 6

  // insert перед третім елементом
  auto it = lst.begin();
  ++it;
  ++it;
  lst.insert(it, 99);
  std::cout << lst << '\n';  // 0 1 99 2 3 4 5 6

  // erase 99
  it = lst.begin();
  ++it;
  ++it;
  lst.erase(it);
  std::cout << lst << '\n';  // 0 1 2 3 4 5 6

  // range-based for
  for (auto &val : lst) val *= 2;
  std::cout << lst << '\n';  // 0 2 4 6 8 10 12

  // зворотна ітерація
  for (auto it = --lst.end(); it != lst.begin(); --it) std::cout << *it << ' ';
  std::cout << *lst.begin() << '\n';  // 12 10 8 6 4 2 0

  for (auto &it : lst) std::cout << it << ' ';
}