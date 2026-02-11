#include "Matrix.h"
#include "CopyMatrix.h"
#include "MoveMatrix.h"

#include <complex>
#include <string>

int main()
{
	Matrix a(3, 4), b(3, 4);
	cout << a<< '\n' << b << '\n';
	Matrix c (a + b);
	cout << c << '\n';
	cout << a + b + c << endl << '\n';

	{
		CopyMatrix a(100, 200), b(100, 200);
		CopyMatrix c(100, 200);
		a - b - c;
	}
	CopyMatrix::epilog();
	CopyMatrix::prolog();
	{
		CopyMatrix a(100, 200), b(100, 200);
		CopyMatrix c(100, 200);
		a + b + c;
	}
	CopyMatrix::epilog();
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