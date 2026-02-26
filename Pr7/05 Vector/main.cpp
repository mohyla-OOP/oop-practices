#include <array>
#include <complex>
#include <iostream>
#include <vector>

#include "Array.h"
#include "DynamicArray.h"
#include "Vector.h"

int main()
{
  Vector<10> u;
  Vector<10> v;
  // u* v;
  // u = v;
  Array<10> a;
  Array<10> b;
  Array<5, int> c;
  Dynamic::Array<double> d(10);

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
    Dynamic::Array<double> bar(100);
    std::vector<double> v;
  }
  {
    Dynamic::Array<double> dar(5);
    std::cout << dar.size() << std::endl;
    dar.resize(2);
    std::cout << dar.size() << std::endl;
  }
}