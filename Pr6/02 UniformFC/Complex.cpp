#include <iostream>
using namespace std;

#define _USE_MATH_DEFINES

#include "Complex.h"
#include <math.h>

Complex::Complex(double re, double im): _re(re), _im(im) 
{
	return;
}

Complex::Complex(const Complex &c): _re(c.re()), _im(c.im()) 
{
	return;
}

Complex::~Complex()
{
	return;
}

Complex & Complex::operator = (const Complex &c)
{
	re() = c.re();
	im() = c.im();
	return *this;
}
	
double & Complex::re()
{
	return _re;
}
double & Complex::im()
{
	return _im;
}

double Complex::re() const
{
	return _re;
}
double Complex::im() const
{
	return _im;
}

Complex& Complex::operator += (const Complex& b)
{
	re() += b.re();
	im() += b.im();
	return *this;
}

Complex& Complex::operator -= (const Complex &b)
{
	re() -= b.re();
	im() -= b.im();
	return *this;
}

Complex& Complex:: operator *= (const Complex &b)
{
	double re(_re * b._re - _im * b._im);
	double im(_im * b._re + _re * b._im);
	_re = re;
	_im = im;
	return *this;
}
Complex& Complex::  operator /= (const Complex &b)
{
	//TBD
	return *this;
}

const Complex  operator + (const Complex &a, const Complex &b)
{
	Complex res(a);
	res += b;
	return res;
}
const Complex  operator - (const Complex &a, const Complex &b)
{
	Complex res(a);
	res -= b;
	return res;
}

const Complex operator * (const Complex &a, const Complex &b)
{
	Complex res(a);
	res *= b;
	return res;
}
const Complex operator / (const Complex &a, const Complex &b)
{
	Complex res(a);
	res /= b;
	return res;
}


bool operator == (const Complex &a, const Complex &b)
{
	return (a.re() == b.re()) && (a.im() == b.im());
}

bool operator != (const Complex &a, const Complex &b)
{
	return !(a == b);
}

ostream & operator << (ostream &os, const Complex &a)
{
	os << a.re() << "+i" << a.im();
	return os;
}

istream & operator >> (istream &is, Complex &a)
{
	is >> a.re();
	is >> a.im();
	return is;
}
