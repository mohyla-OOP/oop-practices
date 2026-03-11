#include <array>
#include <iostream>
#include <string>
using namespace std;
#include <fstream>

#include "Array.h"
#include "Complex.h"
#include "Sequence.h"

ofstream out("out.txt");

int main()
{
  {
    std::array<double, 0> a;
    // std::cout << a[0] << std::endl;
    // double b[0];
    double *p = new double[0];
    std::cout << p << ',' << p[0] << std::endl;
  }
  {
    Array<double> a(7);
    double x = 10, y = 20, z = 3;
    a[0] = a[1] = x;
    a[2] = y;
    a[3] = z;
    for (size_t i = 0; i < a.size(); ++i) std::cout << a[i] << ' ';
    std::cout << std::endl;
  }
  {
    Array<int> a{1, 2, 3, 4};
    std::cout << a << std::endl;
    int &k = a[1];
    std::cout << k << std::endl;
    a.resize(5);
    std::cout << a << std::endl;
    std::cout << std::hex << k << std::endl;
  }
  {
    Sequence<int> si{1, 2, 3, 4, 5};  // TODO: 1: set a breakpoint here and trace the calls, explain where we will be
    std::cout << si << std::endl;
    si.append('a').append('b').append('c');
    std::cout << si << std::endl;
  }
  {
    Sequence<char> seq(2);
    seq.append('a').append('b').append('c');
    std::cout << seq << std::endl;
    seq.append('A').append('B').append('C');
    std::cout << seq << std::endl;
  }
  {
    Array<Complex> carr(5);
    std::cout << carr << std::endl;
  }
  {
    Sequence<Complex> comseq(5);
    std::cout << comseq << std::endl;
    comseq.append('a').append('b').append('c');
    std::cout << comseq << std::endl;
  }
  return 0;
}