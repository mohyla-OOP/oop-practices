#include <iostream>
using namespace std;

typedef unsigned int RegisterArray[4];

unsigned int cycleShiftLeft (
         RegisterArray c,
		 unsigned int register_no,
         unsigned int n)
{
    return c[register_no] = (c[register_no] >> (32-n))|(c[register_no]<<n);
}

ostream& operator<<(ostream& os, const RegisterArray c)
{
	return os<<c[0]<<':'<<c[1]<<':'<<c[2]<<':'<<c[3]<<endl;
}

struct RegisterPile  {
	unsigned int _a;
    unsigned int _b;
	unsigned int _c;
	unsigned int _d;
};


typedef unsigned int RegisterPile ::*Register;
Register reg_a = & RegisterPile ::_a;
Register reg_b = & RegisterPile ::_b;
Register reg_c = & RegisterPile ::_c;
Register reg_d = & RegisterPile ::_d;

unsigned int cycleShiftLeft (
         RegisterPile& c,
		 Register& regPtr,
         unsigned int n)
{		
    return c.*regPtr = (c.*regPtr >> (32-n))|(c.*regPtr<<n);
}

void cycleShiftLeft (
         RegisterPile* c,
		 size_t number,
		 Register& regPtr,
         unsigned int n)
{
	for(size_t i=0; i<number; i++)
		c[i].*regPtr = cycleShiftLeft(c[i], regPtr, n);
    return;
}

ostream& operator<<(ostream& os, const RegisterPile& c)
{
	return os<<c._a<<':'<<c._b<<':'<<c._c<<':'<<c._d<<endl;
}

class HiddenRegisterPile  {
private:
	unsigned int _a;
    unsigned int _b;
	unsigned int _c;
	unsigned int _d;
public:
	//typedef unsigned int HiddenRegisterPile ::*Register;
	using Register = unsigned int HiddenRegisterPile ::* ;

	typedef const unsigned int HiddenRegisterPile ::*ConstRegister;
	
	HiddenRegisterPile(unsigned int a = 0xFFFFFF11,
					   unsigned int b = 0xEEEEEE11, 
					   unsigned int c = 0xDDDDDD11, 
					   unsigned int d = 0xCCCCCC11):_a(a),_b(b),_c(c),_d(d) {}
	static Register reg_a()
	{
		return &HiddenRegisterPile::_a;
	}
	static Register reg_b()
	{
		return &HiddenRegisterPile::_b;
	}
	static Register reg_c()
	{
		return &HiddenRegisterPile::_c;
	}
	static Register reg_d()
	{
		return &HiddenRegisterPile::_d;
	}
	ostream& show(ostream& os) const
	{
		return os<<'('<<_a<<','<<_b<<','<<_c<<','<<_d<<')'<<endl;
	}
};
unsigned int cycleShiftLeft (
         HiddenRegisterPile& c,
		 HiddenRegisterPile::Register regPtr(),
         unsigned int n)
{
    return c.*regPtr() = (c.*regPtr() >> (32-n))|(c.*regPtr()<<n);
}
