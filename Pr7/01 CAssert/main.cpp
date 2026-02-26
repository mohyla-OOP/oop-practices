#include <cassert>
#include <numbers>

#include "Meta.h"
// Define CTAssert for function factorial

constexpr double base = 2.;
const int N = 10;
const unsigned int x(0xDEADBEAF);
const unsigned int n = 16;
int main()
{
  assert(shiftLeft(x, n) == shiftRight(x, n));
  // TODO: 1: Uncomment, check what happens
  //  assert(shiftLeft(x, n+1) == shiftRight(x, n));
  CTAssert<shiftLeft(x, n) == shiftRight(x, n)> a;
  // TODO: 2: Uncomment, check what happens
  //  CTAssert<shiftLeft(x, n+1) == shiftRight(x, n)> a;
  cout << a << endl;

  Arithm<double> d;
  d._a = numbers::pi;
  d.print();
  Arithm<unsigned int> ui;
  ui._a = 0xDEADBEAF;
  ui.print();
  Arithm<int> i;
  i._a = 0xDEADBEAF;
  i.print();
  // CTAssert<shiftLeft(x, n) != shiftRight(x, n)> b;

  assert(Power<N>::power(base) == 1024);
  CTAssert<Power<N>::power(base) == 1024> y;

  return 0;
}