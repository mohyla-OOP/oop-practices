#include "Complex.h"

Complex::Complex (double re, double im): _re(re), _im (im)
{
#ifndef NDEBUG
	cout<<"Complex number "<<*this<<" created"<<endl;
#endif
};

ostream& operator<<(ostream &os, const  Complex& a)
{
	os<<"("<<a.re()<<'+'<<a.im()<<"i)";
	return os;
}

Complex& Complex::operator= (const Complex& a)
{
	_re = a._re;
	_im = a._im;
	return *this;
}

Complex& Complex::operator+=(const Complex& b)
{
	_re += b._re;
	_im += b._im;
	return *this;
}

const Complex operator+(Complex a, const Complex& b)
{
	return a += b;;
}

Complex& Complex::operator-=(const Complex& b)
{
	_re -= b._re;
	_im -= b._im;
	return *this;
}

const Complex operator-(Complex a, const Complex& b)
{
	return a -= b;;
}

Complex& Complex::operator*=(const Complex& b)
{
	re() = re()*b.re()-im()*b.im();
	im() = re()*b.im()+im()*b.re();
	return *this;
}

const Complex  operator* (Complex a, const Complex& b)
{
	return a*=b;
}

bool operator== (const Complex& a, const Complex& b)
{
	return a.re()==b.re()&& a.im()==b.im();
}

bool operator!= (const Complex& a, const Complex& b)
{ 
	return !(a==b);
}

