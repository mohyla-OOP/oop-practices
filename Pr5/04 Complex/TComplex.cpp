#include "TComplex.h"
#include "Complex.h"

TComplex::TComplex(const Complex& a)
{
	_r = a.mod();
	_phi = a.arg();;
}

TComplex& TComplex::operator+=(const TComplex& a)
{
	return *this = (*this) + a;
}

TComplex& TComplex::operator*=(const TComplex& a)
{
	_r *= a._r;
	_phi += a._phi;
	return *this;
}

