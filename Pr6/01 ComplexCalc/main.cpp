// Compare Calc with ComplexCalc and choose a better solution

#include <functional>
#include <cassert>
#include <numbers>
#include "ComplexCalc.h"
#include "Calc.h"
#include "STLCalc.h"
#include <iostream>

using namespace std::numbers;
using std::cout;

int main()
{
	Calc c(1,2);
	cout << exe(c, &Calc::add) << endl;

	{
		Complex z1(1, 2), z2(3, 4);
		// Checking the correctness
		assert(((z1 += z2) -= z2) == z1);
	}
	
	ComplexCalc cc(1, Complex(0,1));

	cout<<cc.getA()<<'+'<<cc.getX();
	cout<<'='<<cc.doOper(&Complex::operator+=)<<endl;
	cout<<cc.getA()<< endl;
		cout << '=' << cc.doOper(&Complex::operator-=) << endl;
	cout << cc.getA() << endl;
	cc.setX(2);
	cout<<cc.getA()<<'*'<<cc.getX();
	cout<<'='<<cc.doOper(&Complex::operator*=)<<endl;
	cout<<cc.getA()<< endl;
	{
		Complex a (1, 2);
		Complex b (3, 4);
		Complex c(2);

		cout << apply_op("+=", a, b) << endl;
		cout << apply_op("*=", a, c) << endl;
	}
	
	STLCalc sc(1, SComplex(0, 1));

	cout << sc.getA() << '+' << sc.getX();
	cout << '=' << sc.doOper(&SComplex::operator+=) << endl;
	cout << sc.getA() << endl;
	cout << '=' << sc.doOper(&SComplex::operator-=) << endl;
	cout << sc.getA() << endl;

	{
		SComplex a(1, 2);
		SComplex b(3, 4);
		SComplex c(2);

		cout << apply_op("+=", a, b) << endl;
		cout << apply_op("*=", a, c) << endl;
		try
		{
			apply_op("/=", a, b);
		}
		catch (const std::runtime_error& er)
		{
			cerr << er.what() << endl;
		}
	}


	function< Complex& (ComplexCalc&, CPFR)> exe = &ComplexCalc::doOper;
	cout << exe(cc, &Complex::operator+=) << endl;
	cout << exe(cc, &Complex::operator-=) << endl;

	cout << sc.getA() << '+' << sc.getX();
	function<SComplex& (STLCalc&, CPtr)> execute = &STLCalc::doOper;
	cout << '=' << execute(sc, &SComplex::operator+=) << endl;

	return 0;
	
}
