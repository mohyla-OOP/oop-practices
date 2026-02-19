// Remove const from returned types

// Complex numbers
// in cartesian (algebraic) form
#ifndef _Complex_
#define _Complex_

#include <iostream>

class Complex
{
private:
	double _re, _im;

public:
	using  Coord = double Complex::*;
	using ConstCoord = const double Complex::*  ;

	Complex (double re=0, double im=0);
	Complex (const Complex&);
	~Complex();

	Complex& operator= (const Complex&);

	inline double select(ConstCoord u) const;
	inline void modify(Coord u, double a);
	
	double& re();
	double& im();

	double re() const;
	double im() const;

	static Coord getre()
	{
		return &Complex::_re;
	}

	static Coord getim()
	{
		return &Complex::_im;
	}
	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const Complex&);
};

double Complex::select(ConstCoord u) const
{
	return this->*u;
}
void Complex::modify(Coord u, double a)
{
	this->*u=a;
}

const Complex  operator+ (const Complex&, const Complex&);
const Complex  operator- (const Complex&, const Complex&);

// TBD
const Complex  power(const Complex&, unsigned int);

bool operator== (const Complex&, const Complex&);
bool operator!= (const Complex&, const Complex&);

std::ostream & operator<<(std::ostream &, const Complex &);
std::istream & operator>>(std::istream &, Complex &);

template<typename T>
class Function
{
private:
	T(*_f)(T);
public:
	Function(T(*f)(T)) :_f(f) {}
	T operator()(T x)
	{
		return _f(x);
	}
};

template<typename T>
class Adapter
{
	T& (T::* _pmf)(const T&);
public:
	Adapter(T& (T::* pmf)(const T&)) :_pmf(pmf) {}
	T& operator()(T& a, const T& b)
	{
		return (a.*_pmf)(b);
	}
};

#endif