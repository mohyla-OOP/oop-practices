#include <map>
#include <functional>
#include "Complex.h"

class ComplexCalc 
{
private:
// Accumulator
	Complex _a;
// Register
	Complex _x;
public:
	ComplexCalc (const Complex& a =0,
			const Complex& x=0): _a(a),_x(x){};
	const Complex& getA() const {return _a; }
	const Complex& getX() const {return _x; }
	void setA (const Complex& a ) { _a = a; }
	void setX (const Complex& x ) { _x = x; }
	Complex& doOper(CPFR op) {return (_a.*op)(_x);}
};

struct Operation {
	const char* name;
	Complex& (Complex::* method)(const Complex&);
};

Operation ops[] = {
	{"+=", &Complex::operator+=},
	{"-=", &Complex::operator-=},
};

using PMF = Complex & (Complex::*)(const Complex&);

const std::map<std::string, PMF> optable = {
	{ "+=", &Complex::operator+= },
	{ "-=", &Complex::operator-= },
	{ "*=", &Complex::operator*= }
};
#include <map>
#include <string>
#include <functional>   // std::invoke

using PMF = Complex & (Complex::*)(const Complex&);   // селектор методу

// Ключ = ім’я операції, Значення = селектор


// Застосувати операцію за ім’ям до a з аргументом b
Complex& apply_op(const std::string& opname, Complex& a, const Complex& b) {
	if (auto it = optable.find(opname); it != optable.end())
		return (a.*it->second)(b);
		//return std::invoke(it->second, a, b);   
	throw std::runtime_error("Unknown operation: " + opname);
}
