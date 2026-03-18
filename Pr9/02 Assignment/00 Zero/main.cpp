#include "Assign.h"

int main()
{
  // TODO: 2: run the code, why does it fails?
  A a(1);
  A b(2);

  a.dump("a");
  b.dump("b");
  std::cout << "------------------" << std::endl;

  a = b;

  a.dump("a");
}