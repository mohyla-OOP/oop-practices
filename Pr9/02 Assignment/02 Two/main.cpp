#include "Assign.h"

int main()
{
  // TODO: 2: run and check the console output
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

  c = d;  // TODO: 4: set a breakpoint here, and trace the execution from main.cpp
  c.A::dump("a");
  b.A::dump("b");
  c.dump("c");
  d.dump("d");  // TODO: 3: explain the output of this line, what changed after assignment?
}