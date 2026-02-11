// Provide complete testing
#include <cassert>
#include "Complex.h"
#include "TComplex.h"
#include <numbers>
using namespace std::numbers;

int main()
{
	Complex a { 1, 2 };
	Complex b { 3, 4 };
	TComplex t1(1, pi/4);
	TComplex t2(2, pi / 4);

	std::cout << (a += b) << std::endl;
	std::cout << (a -= b) << std::endl;
	std::cout << (a *= b) << std::endl;

	std::cout << (t1 *= t2) << std::endl;
	std::cout << (t1 *= t2) << std::endl;
	t1 + t2;
	t1 + a;
	a* t1;
	//t1 - t2;

	return 0;
}
