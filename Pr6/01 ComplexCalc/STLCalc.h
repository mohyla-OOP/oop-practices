#pragma once
#include <complex>

using SComplex = std::complex<double>;
using CPtr = SComplex &
(SComplex::* const) (const SComplex&);

class STLCalc
{
private:
	SComplex _a, _x;
public:
	STLCalc(const SComplex& a = 0,
		const SComplex& x = 0) : _a(a), _x(x) {};
	const SComplex& getA() const { return _a; }
	const SComplex& getX() const { return _x; }
	void setA(const SComplex& a) { _a = a; }
	void setX(const SComplex& x) { _x = x; }
	SComplex& doOper(CPtr op) { return (_a.*op)(_x); }
};

using SPMF = SComplex & (SComplex::*)(const SComplex&);   // селектор методу


const std::map<std::string, SPMF> optableSTL = {
	{ "+=", &SComplex::operator+= },
	{ "-=", &SComplex::operator-= },
	{ "*=", &SComplex::operator*= }
};
#include <map>
#include <string>

// Застосувати операцію за ім’ям до a з аргументом b
SComplex& apply_op(const std::string& opname, SComplex& a, const SComplex& b) {
	if (auto it = optableSTL.find(opname); it != optableSTL.end())
		return (a.*it->second)(b);
	//return std::invoke(it->second, a, b);   
	throw std::runtime_error("Unknown operation: " + opname);
}

