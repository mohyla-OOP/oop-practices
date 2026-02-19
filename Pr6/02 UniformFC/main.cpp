#include <iostream>
#include <fstream>
#include <functional>
#include "PTR.h"
#include "Lambda.h"
using namespace std;

#include "Complex.h"
#include "Foo.h"

//Home task: develop a Log
ofstream out("Output.txt");

int main()
{

	{
		// Transorm a method into a function
		Complex u1(1, 2);
		Complex u2(3, 4);

		using CFunc = Complex & (Complex&, const Complex&);
		//function<CFunc> op = &Complex::operator+=;
		
		std::function<CFunc> op = std::mem_fn(&Complex::operator+=);
		std::cout<<op(u1, u2)<<std::endl;
	}
	{
		// Joke
		using Func = void(const Foo&, int);
		function<Func> f_add_display = &Foo::print_add;
		const Foo foo(314159);
		f_add_display(foo, 1);
	}
	{
		Complex a{ 1,2 };
		Complex b{ 3,4 };

		using PMF = Complex & (Complex::*) (const Complex&);
		Complex& (Complex:: * pmf)(const Complex&) = &Complex::operator+=;

		//PMF pmf = &Complex::operator+=;
		struct HiddenAdapter {
			PMF pmf;
			Complex& operator()(Complex& a, const Complex& b) const {
				return (a.*pmf)(b);   // виклик PMF для об’єкта a
			}
		};

		HiddenAdapter f{ pmf };
		std::cout << f(a, b) << std::endl;

		std::function<Complex& (Complex&, const Complex&)> op =
			std::mem_fn(&Complex::operator+=);
		std::cout << op(a, b) << std::endl;
	}
	{
		Function<double> f(sqrt);
		cout << f(2) << endl;
	}
	{
		Complex a{ 1,2 };
		Complex b{ 3,4 };

		Adapter<Complex> plus_ass(&Complex::operator+=);
		cout<<plus_ass(a, b)<<endl;
		cout << Adapter<Complex>(&Complex::operator+=)(a, b) << endl;
		a.operator+=(b);
		a += b;
		cout<<std::invoke(&Complex::operator+=, a, b)<<endl;

		// Використання
		OpTable optable{ 
			{"+=", &Complex::operator+=},
			{"-=", &Complex::operator-=} 
		};
		std::cout<<apply_op(optable, "+=", a, b)<<std::endl;

		apply_op_generic(optable, "+=", a, b);
		apply_op_generic<OpTable, Complex>(optable, "+=", a, b);
		apply_op_generic_range<OpTable, Complex>(optable, "+=", a, b);
		apply(table, "+=", a, b);

	}
	
	return 0;
}