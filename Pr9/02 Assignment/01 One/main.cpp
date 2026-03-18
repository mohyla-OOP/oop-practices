#include "Assign.h"

int main()
{
  // TODO: 1: check the A declaration and run, check the console and explain why the project succeeds
  A a(1);
  A b(2);

  a.dump("a");
  b.dump("b");
  std::cout << "------------------" << std::endl;

  a = b;

  a.dump("a");
}