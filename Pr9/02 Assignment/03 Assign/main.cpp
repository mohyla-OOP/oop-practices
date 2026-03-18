#include "Assign.h"

int main()
{
  A a(1);
  A b(2);

  a.dump("a");
  b.dump("b");
  std::cout << "------------------" << std::endl;

  a = b;

  a.dump("a");
  std::cout << "------------------" << std::endl;

  B c(3, 1);
  B d(4, 2);

  c = d;
  a.dump("a");
  b.dump("b");
  c.dump("c");
  d.dump("d");
}