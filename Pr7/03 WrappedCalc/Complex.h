#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>

#include <iostream>
using namespace std;

template <class Type>
Type power(const Type &base, unsigned int factor)
{
  Type y = 1;
  for (unsigned int i = 0; i < factor; ++i) y = y * base;
  return y;
}

template <class Type>
const Type power1(const Type &base, unsigned int factor)
{
  Type y = 1;
  for (unsigned int i = 0; i < factor; ++i) y = y * base;
  return y;
}

// template <class T>
// class Type{
//	T& Type<T>::operator=(const T&)&;
// };

class Complex
{
 private:
  double _re, _im;

 public:
  Complex(double re = 0, double im = 0);
  Complex(const Complex &z) : _re(z._re), _im(z._im) {};
  ~Complex() {};

  double re() const { return _re; }
  double im() const { return _im; }

  double &re() { return _re; }
  double &im() { return _im; }

  double mod() const { return sqrt(_re * _re + _im * _im); }
  double arg() const { return atan2(_im, _re); }

  const Complex &conj()
  {
    _im = -_im;
    return *this;
  }

  Complex &operator=(const Complex &) &;
};

ostream &operator<<(ostream &, const Complex &);
istream &operator>>(istream &, Complex &);

Complex &operator+=(Complex &a, const Complex &b);
Complex &operator-=(Complex &a, const Complex &b);
Complex &operator*=(Complex &a, const Complex &b);
Complex &operator/=(Complex &a, const Complex &b);

const Complex operator+(const Complex &, const Complex &);
const Complex operator-(const Complex &, const Complex &);
const Complex operator*(const Complex &, const Complex &);
const Complex operator/(const Complex &, const Complex &);

bool operator==(const Complex &, const Complex &);
bool operator!=(const Complex &, const Complex &);

typedef const Complex (*const CPFR)(Complex, const Complex &);
typedef const Complex (*PFR)(Complex, const Complex &);

#endif