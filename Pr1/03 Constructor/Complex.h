#pragma once

//Develop operator<< for classes complex

class Complex
{
private:
	double _re, _im;
public:
	Complex(double re, double im) :_re(re), _im(im) {}
	Complex(double re) :Complex(re, 0) {}
	Complex() :Complex(0, 0) {};
};
class TComplex
{
private:
	double _r, _phi;
public:
	TComplex(double r = 0, double phi = 0) :_r(r), _phi(phi) {}
};
