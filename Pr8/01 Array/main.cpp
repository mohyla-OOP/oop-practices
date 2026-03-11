#include <algorithm>
#include <complex>
#include <initializer_list>
#include <iostream>
#include <vector>

#include "Array.h"

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
  for (T x : v) os << x << ' ';
  return os;
}

// TODO: 2: what is it?
struct Foo
{
  Foo(int k = 0) : _k(k) {}
  int _k;
};

int main()
{
  {
    Array<Foo> a(7);
    // TODO: 6: create vector of Foo;
    // TODO: 7: make reserve
    // TODO: 8: resize calls, explain why fails? What makes resize?
    // TODO: 9: push_back Foo(1) and Foo(), why first works and second not?
    // TODO: 10: remove constructor Foo(int), explain what happens
    // TODO: 11: print capacity and size to console
    // TODO: 12: make resize to 5, push_back Foo(1), print capacity and size
  }
  {
    Array<double> a(7);
    double x = 10, y = 20, z = 3;
    a[0] = a[1] = x;
    a[2] = y;
    a[3] = z;
    for (int i = 0; i < a.size(); ++i) std::cout << a[i] << std::endl;

  }  // TODO: 3: set a breakpoint here, check the console and explain the output, what are the ZEROES?
  {
    std::vector<std::complex<double>> v;
    std::cout /*<< "vector:"*/ << v << /* " end" <<*/ std::endl;
    v.reserve(5);
    std::cout /*<< "vector:"*/ << v << /* " end" <<*/ std::endl;
    v.resize(10);
    std::cout /*<< "vector:"*/ << v << /* " end" <<*/ std::endl;
  }  // TODO: 5: set a breakpoint here, check the console and explain the output, why GAP?
  {
    Array<std::complex<double>> dar(5);
    try
    {
      // TODO: 1: set a breakpoint here and trace the further exception throwing
      dar[100];
    }

    catch (const BadIndex &error)
    {
      std::cout << error << std::endl;
    }
    for (int i = 0; i < dar.size(); ++i) std::cout << dar[i] << ' ' << std::endl;
    std::cout << dar.size() << std::endl;
    dar[1] = std::complex<double>(1, 2);
    std::complex<double> &c = dar[1];
    // std::complex<double> c = dar[1]; //TODO: 14: uncomment this line and comment the previous one, run and check
    // std::complex<double>* p = &dar[1]; //TODO: 15: uncomment this line
    // std::cout << p << std::endl; //TODO: 15: uncomment this line
    dar.resize(10);  // TODO: 13: set a breakpoint here, explain the console output
    std::cout << dar.size() << std::endl;
    std::cout << dar << std::endl;
    // invalidation
    std::cout << c << std::endl;
    // std::cout << *p << std::endl; //TODO: 15: uncomment this line
    // std::cout << p << std::endl; //TODO: 15: uncomment this line
    // std::cout << &dar[1] << std::endl; //TODO: 15: uncomment this line

    // When we work with containers which change their size, we should be careful with
    // references and pointers to their elements, because they can be invalidated by resize()
    // and push_back() operations. In case of vector, if the new size is greater than the current capacity,
    // the container will allocate a new memory block, copy the existing elements to it and deallocate the old one.
    // In case of our Array class, we always allocate a new memory block and copy the existing elements to it, so all references and pointers to its
    // elements will be invalidated after resize().

    Array<int> a{1, 2, 3, 4};  // TODO: 16: trace the constructor calls here

    for (auto x : a) std::cout << x << " ";

    std::cout << "\n";

    try
    {
      std::cout << a[10];
    }
    catch (const BadIndex &e)
    {
      std::cout << e << std::endl;
    }
    {
      Array<int> a{1, 2, 3};

      int *p = &a[0];

      a.resize(100);

      std::cout << *p << '.' << std::endl;

      for (auto &x : a)
      {
        std::cout << std::hex << x << ',';
        a.resize(100);
      }
      std::cout << "that is all" << std::endl;
    }
  }
}