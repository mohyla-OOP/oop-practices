#include "Complex.h"
#include "TComplex.h"

std::ostream& operator<<(std::ostream &os, const  Complex& a)
{
	os<<"("<<a._re<<'+'<<a._im<<"i)";
	return os;
}

Complex:: Complex(const TComplex& a) 
{
	_re = a.rho() * std::cos(a.phi());
	_im = a.rho() * std::sin(a.phi());

}

Complex& Complex::operator+=(const Complex& b)
{
	_re += b._re;
	_im += b._im;
	return *this;
}

Complex& Complex::operator-=(this Complex& a, const Complex& b)
{
	a._re -= b._re;
	a._im -= b._im;
	return a;
}


Complex& Complex::operator*=(const Complex& a)
{
	return *this=(*this)*a;
}

bool operator== (const Complex& a, const Complex& b)
{
	return a._re == b._re && a._im == b._im;
}

bool operator!= (const Complex& a, const Complex& b)
{ 
	return !(a==b);
}

