#pragma once
#include <iostream>
#include <numbers>
using namespace std::numbers;

class Complex
{
	// Insider
	friend Complex operator+(const Complex& a, const Complex& b)
	{
		return { a._re + b._re, a._im + b._im };
	}
	friend std::ostream& operator<<(std::ostream& os, const Complex& a)
	{
		return os << '(' << a._re << ',' << a._im << ')';
	}
private:
	double _re = 0;
	double _im = 0;
public:
	Complex(double re, double im) :_re(re), _im(im) {}
	Complex(double re) :_re(re) {}
	Complex(){};
	Complex operator+(this const Complex& a, const Complex& b)
	{
		return { a._re + b._re, a._im + b._im };
	}
	double re() const
	{
		return _re;
	}
	double im() const
	{
		return _im;
	}
};
Complex operator+(const Complex& a, const Complex& b)
{
	return { a.re() + b.re(), a.im() + b.im()};
}
// Rewrite operator* into class member
class TComplex
{
	// Insider
	friend std::ostream& operator<<(std::ostream& os, const TComplex& a)
	{
		return os << '(' << a._r << ',' << a._phi << ')';
	}
	friend TComplex operator*(const TComplex& a, const TComplex& b)
	{
		TComplex res={ a._r*b._r, a._phi+b._phi};
		res.normalisePhi();
		return res;
	}
private:
	double _r, _phi;
	double normalisePhi()
	{
		if (_phi < 0 || _phi >= 2 * pi)
		{
			_phi = std::abs(_phi);
			while (_phi > 2 * pi) _phi -= 2 * pi;
		}
		return _phi;
	}
public:
	struct BadRho {
		double _rho;
		BadRho(double r) :_rho(r) {};
	};
	
	TComplex(double r = 0, double phi = 0) :_r(r), _phi(phi) {
		if (r < 0) throw BadRho(r);
		normalisePhi();
	}
};