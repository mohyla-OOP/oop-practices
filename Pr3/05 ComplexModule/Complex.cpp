module;
#include <ostream>
#include <numbers>
#include <cmath>

module MComplex;

using namespace std::numbers;

// ?????? — ?? ?????? C++.
// ??? ??????????? ?? ????????????: import <cmath>;

Complex operator+(const Complex& a, const Complex& b)
{
	return { a._re + b._re, a._im + b._im };
}
std::ostream& operator<<(std::ostream& os, const Complex& a)
{
	return os << '(' << a._re << ',' << a._im << ')';
}

TComplex operator*(const TComplex& a, const TComplex& b)
{
	TComplex res = { a._r * b._r, a._phi + b._phi };
	res._phi = normalisePhi(res._phi);
	return res;
}
std::ostream& operator<<(std::ostream& os, const TComplex& a)
{
	return os << '(' << a._r << ',' << a._phi << ')';
}
double normalisePhi(double phi)
{
	if (phi < 0 || phi >= 2 * pi)
	{
		phi = std::abs(phi);
		while (phi > 2 * pi) phi -= 2 * pi;
	}
	return phi;
}