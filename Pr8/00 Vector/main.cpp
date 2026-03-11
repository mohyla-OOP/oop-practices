#include <array>
#include <complex>
#include <iostream>
#include <vector>

#include "Array.h"
#include "Vector.h"

struct Foo
{
  Foo(int k = 0) : _k(k) {}
  // TODO: 1: remove default value for k and compile
  // TODO: 2: assign default value 0 in definition of k
  // TODO: 3: add new Foo()=default constructor
  int _k;
};

int main()
{
  Array<10, Foo> ar;
  // TODO: 4: add console output of ar[0] and compile
  // TODO: 5: how to get the underlying value of ar[0] and print it? Check the implementation of operator[] in Array class
  // TODO: 7: why the printed value with default constructor is so strange?
  //          What should we do fix it? We should provide proper initialization for default constructor
  Vector<10> u;
  Vector<10> v;
  // u* v;
  // u = v;
  Array<5, Foo> foo;
  Array<10> a;
  Array<10> b;
  Array<5, int> c;

  Array<10, std::complex<double>> z1;
  Array<10, std::complex<double>> z2;

  std::array<double, 10> x;
  std::array<std::complex<double>, 10> y;

  Array<3, double> a3;
  std::cout << '(' << a3._x << ',' << a3._y << ',' << a3._z << ')' << std::endl;
  {
    Array<3, float> a3;
    std::cout << '(' << a3._x << ',' << a3._y << ',' << a3._z << ')' << std::endl;
  }
  {
    std::array<double, 3> b3;
    std::array<float, 3> c3;
  }
  {
    double x[10]{};
    int n = 100;
    double *a = new double[n]{};
    Array<20, double> ar;
    std::array<double, 30> sar;
    std::vector<double> v;
  }
}