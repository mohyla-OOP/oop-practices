#include "MoveMatrix.h"

#include <complex>
#include <string>

int main()
{
	MoveMatrix::prolog();
	{
		MoveMatrix a(100, 200), b(100, 200);
		MoveMatrix c(100, 200);
		a + b + c;
	}
	MoveMatrix::epilog();
	MoveMatrix::prolog();
	{
		MoveMatrix a(100, 200), b(100, 200);
		MoveMatrix c(100, 200);
		a - b - c;
	}
	MoveMatrix::epilog();
	return 0;
}