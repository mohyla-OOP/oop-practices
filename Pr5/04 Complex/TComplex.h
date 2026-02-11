#pragma once
#include <iostream>

class Complex;
class TComplex
{
	friend std::ostream& operator<<(std::ostream& os, const  TComplex& a)
	{
		os << "(" << a._r << '+' << a._phi << "i)";
		return os;
	}
private:
	double _r;
	double _phi;
public:
	TComplex(double r = 0, double phi = 0) :_r(r), _phi(phi){}
	//TComplex& operator=(const TComplex&)&;
	TComplex(const Complex& a);
	//operator Complex() const;
	TComplex& operator+=(const TComplex&);
	TComplex& operator-=(const TComplex&);
	TComplex& operator*=(const TComplex&);
	TComplex& operator/=(const TComplex&);
	double rho() const
	{
		return _r;
	}
	double phi() const
	{
		return _phi;
	}
};

inline TComplex operator*(const TComplex a, const TComplex& b)
{
	TComplex tmp(a);
	return tmp *= b;
}

