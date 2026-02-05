#include "B.h"
#include "BB.h"


int main()
{
	A x;
	A::B y;
	x.f(y);
	y.f(1);
	B z;
	x.f(z);
	z.f(2);
	z=y;
	return 0;
}