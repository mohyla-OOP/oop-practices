#include <iostream>
#include <vector>

#include "BoxA.h"
#include "BoxB.h"
#include "SomeOther.h"
#include "Swap.h"
#include "Widget.h"
#include "assert.h"

int main()
{
  bar();
  BoxA<int> a1(10);
  BoxA<double> a2(3.14);

  BoxB<int> b1(20);
  BoxB<double> b2(6.28);

  a1.print();
  a2.print();

  /*std::string s{ "first" };
  BoxA< std::string> bs(s);*/

  b1.print();
  b2.print();

  int m = 10;
  int n = 29;
  swap(m, n);
  double x = 0.5;
  double y = 50;
  swap(x, y);
  // swap(m, y);
  std::cout << m << ',' << n << std::endl;
  std::string s1{"first"};
  std::string s2{"second"};
  std::cout << std::movable<std::string> << std::endl;
  swap(s1, s2);
  std::cout << s1 << ',' << s2 << std::endl;
  Complex z1{1, 2};
  Complex z2{3, 4};
  swap(z1, z2);
  NoAssign a{};
  NoAssign b{};
  // 'NoAssign &NoAssign::operator =(const NoAssign &)':
  // attempting to reference a deleted function
  // swap(a, b);
  std::vector<double *> v = {new double[10], new double[20]};
  Widget<std::string> w;
  w.set("name");
  std::cout << w.show() << std::endl;
  {
    int m = 10;
    int n = 20;
    std::cout << add(m, n) << std::endl;
  }
  {
    double x = 0.5;
    double y = 50;
    std::cout << add(x, y) << std::endl;
  }
  /*std::cout << add(s1, s2) << std::endl;*/
  {
    std::vector<int> v = {1, 2, 3};
    foo(v);
    double x = 8;
    foo(x);
    std::string s{""};
    foo(s);
  }
}
