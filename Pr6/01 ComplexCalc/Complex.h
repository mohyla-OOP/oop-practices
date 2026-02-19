// Modify the first parameter in operations

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>
using namespace std;

class  Complex
{
private:
	double _re, _im;

public:
	Complex (double re=0, double im=0);
	Complex (const Complex & z): _re(z._re), _im (z._im) {};
	~Complex(){};

	double re() const { return _re;}
	double im() const { return _im;}
	
	double& re(){ return _re;}
	double& im(){ return _im;}

	Complex& operator+=(const Complex& b);
	Complex& operator-=(const Complex& b);
	Complex& operator*=(const Complex& b);
	Complex& operator/=(const Complex& b);

	double mod() const { return hypot(_re,_im);}
	double arg() const { return atan2(_im, _re); }

	const Complex& conj() { _im=-_im; return *this;}

	Complex& operator= (const Complex&);
};

	ostream& operator<<(ostream &, const Complex &);
	istream& operator>>(istream &, Complex&);

	

	const Complex  operator+ (Complex, const Complex&);
	const Complex  operator- (Complex, const Complex&);
	const Complex  operator* (Complex, const Complex&);
	const Complex  operator/ (Complex, const Complex&);

	bool operator== (const Complex&, const Complex&);
	bool operator!= (const Complex&, const Complex&);

	using CPFR = Complex& (Complex::* const) (const Complex&);
	using PFR = Complex & (Complex::*) (const Complex&);

#endif