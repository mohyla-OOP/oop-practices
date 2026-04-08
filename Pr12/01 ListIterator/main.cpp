#include "List.h"

int main()
{
  List lst;

  // наповнення списку
  for (int i = 0; i < 10; ++i)
  {
    lst.push_front(0);  // поки що нулі
  }

  // ваш ітератор
  ListIterator itor(lst);

  itor.begin();
  while (!itor.end())
  {
    *itor = rand() % 100;  // наповнення
    ++itor;
  }

  // перевірка
  ListIterator print(lst);

  print.begin();
  while (!print.end())
  {
    std::cout << *print << " ";
    ++print;
  }

  std::cout << std::endl;

  itor.begin();
  bool res = find(itor, 24);
  if (res) std::cout << *itor << std::endl;

  itor.begin();
  res = find(itor, 24, equal);
  if (res) std::cout << *itor << std::endl;

  itor.begin();
  res = find(itor, 10, [](auto x, auto y) { return x > y; });
  if (res) std::cout << *itor << std::endl;

  itor.begin();
  res = find(itor, 10, [](auto x, auto y) { return x == y; });
  if (res) std::cout << *itor << std::endl;
}
