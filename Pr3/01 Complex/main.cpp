#include "Complex.h"

int main()
{
	Complex a(1, 2); 
	Complex b(3, 4);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << a+b << std::endl;

	try {
		TComplex(-1, -pi);
	}
	catch(TComplex::BadRho& x)
	{
		std::cerr << x._rho << " negative" << std::endl;
	}
	TComplex t1(2, 0);
	TComplex t2(5, 0);
	std::cout << t1 * t2 << std::endl;
	TComplex t3(1, pi / 4);
	TComplex t4(2, pi / 4);
	std::cout << pi/2<<':'<<t3 * t4 << std::endl;
}