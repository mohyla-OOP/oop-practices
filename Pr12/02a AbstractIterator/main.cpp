#include <iostream>
#include <string>
using namespace std;
#include "AItor.h"
#include "Array.h"
#include "Complex.h"
#include "Itor.h"
#include "Sequence.h"

bool positive(double x) { return x > 0; }

int main()
{
  const int n = 10;
  {
    int a[n];
    for (size_t i = 0; i < n; ++i) a[i] = rand();
    for (size_t i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << endl;
    // Compare with a project 04 Concept
    isort(a, n);
    for (size_t i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << endl;
  }
  {
    Array<int> a(n);
    for (size_t i = 0; i < n; ++i) a[i] = rand();
    Iterator<int, Array<int>> itor(a);
    while (!itor.end())
    {
      cout << *itor << ' ';
      ++itor;
    }
    cout << itor << endl;
    itor.begin();
    sort(itor);
    itor.begin();
    cout << itor << endl;
  }
  {
    const size_t n = 10;
    Array<double[n]> a;
    double x = -10, y = 20, z = 3;
    a[0] = a[1] = x;
    a[2] = y;
    a[3] = z;
    for (size_t i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << endl;
    Iterator<double, Array<double[n]>> itor(a);
    itor.begin();
    cout << itor << endl;
    itor.begin();
    bool res = find(itor, positive);
    cout << *itor << endl;
    itor.begin();
    find(itor, [](double x, double y) { return x < y; }, 100.0);
    itor.begin();
    find(itor, [](auto x, auto y) { return x >= y; }, 100.0);
  }
  {
    Array<double> a(7);
    double x = 10, y = 20, z = 3;
    a[0] = a[1] = x;
    a[2] = y;
    a[3] = z;
    for (size_t i = 0; i < a.size(); ++i) cout << a[i] << ' ';
    cout << endl;

    Iterator<double, Array<double>> itor(a);
    itor.begin();
    while (!itor.end())
    {
      *itor = *itor * 2;
      ++itor;
    }
    itor.begin();
    cout << itor << endl;
  }
  {
    Sequence<char> seq(20);
    seq.append('a').append('b').append('c');
    Iterator<char, Sequence<char>> itor(seq);
    itor.begin();
    while (!itor.end())
    {
      *itor = ++*itor;
      ++itor;
    }
    cout << itor << endl;
    seq.append('A').append('B').append('C');
    itor.begin();
    cout << itor << endl;
  }
  {
    Array<Complex> carr(5);
    for (size_t i = 0; i < carr.size(); ++i) cout << carr[i] << ' ';
    cout << endl;

    Iterator<Complex, Array<Complex>> itor(carr);
    itor.begin();
    int x = 2;
    while (!itor.end())
    {
      *itor = *itor + x++ * Complex(1, 1);
      ++itor;
    }
    cout << itor << endl;
    for (size_t i = 0; i < carr.size(); ++i) cout << carr[i] << ' ';
    cout << endl;
  }
  {
    Sequence<Complex> comseq(100);
    for (size_t i = 0; i < comseq.size(); ++i) cout << comseq[i] << ' ';
    cout << endl;
    Iterator<Complex, Sequence<Complex>> itor(comseq);
    comseq.append(Complex(1, 1)).append(Complex(2, 2)).append(Complex(3, 3));
    itor.begin();
    cout << itor << endl;
    itor.begin();
    while (!itor.end())
    {
      cout << *itor << ' ';
      ++itor;
    }
    cout << endl;
    for (size_t i = 0; i < comseq.size(); ++i) cout << comseq[i] << ' ';
    cout << endl;
    comseq.append(Complex(4, 4)).append(Complex(3, 3)).append(Complex(6, 6));
    itor.begin();
    cout << itor << endl;
    itor.begin();
    bool found = find(Complex(3, 3), itor);
    Iterator<Complex, Sequence<Complex>> foundItor(itor);
    cout << foundItor;
    ++itor;
    found = find(Complex(3, 3), itor);
    cout << itor;
  }
  {
    Sequence<string> s(100);
  }
  return 0;
}