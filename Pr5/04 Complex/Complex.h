// Modify the first parameter in operations

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>
class TComplex;
class  Complex
{
	friend std::ostream& operator<<(std::ostream&, const Complex&);
	friend std::istream& operator>>(std::istream&, Complex&);
	friend bool operator== (const Complex&, const Complex&);
	friend bool operator!= (const Complex&, const Complex&);
private:
	double _re = 0, _im = 0;

public:
	Complex(double re = 0, double im = 0) :_re(re), _im(im) {}
	//Complex& operator=(const Complex&)&;
	Complex(const TComplex&);
	Complex& operator+=(const Complex&);
	Complex& operator-=(this Complex&, const Complex&);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const Complex&);

	Complex operator- (this const Complex& a, const Complex& b)
	{
		Complex tmp(a);
		return tmp += b;
	}
	
	double re() const { return _re;}
	double im() const { return _im;}

	double& re(){ return _re;}
	double& im(){ return _im;}

	double mod() const { return std::hypot(_re,_im);}
	double arg() const { return std::atan2(_im, _re); }

	const Complex& conj() { _im=-_im; return *this;}
};

inline Complex operator+ (const Complex& a, const Complex& b)
{
	Complex tmp(a);
	return tmp += b;
}


#endif