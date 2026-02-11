#include "CopyMatrix.h"

int CopyMatrix::created=0;
int CopyMatrix::copied=0;
int CopyMatrix::deleted=0;

CopyMatrix::CopyMatrix(const CopyMatrix& a) : _m(a._m), _n(a._n), _a(new double[_m*_n])
{
	copied+=_m*_n;
	for (int i = 0; i < _n*_m; ++i)
		_a[i] = a._a[i];
}

CopyMatrix operator+(const CopyMatrix& a, const CopyMatrix& b)
{
	CopyMatrix res(a.m(), a.n());
	for (int i = 0; i < a.m(); ++i)
		for (int j = 0; j < a.n(); ++j)
			res.a(i, j) = a.a(i, j) + b.a(i, j);
	return res;
}
CopyMatrix operator-(const CopyMatrix a, const CopyMatrix b)
{
	CopyMatrix res(a.m(), a.n());
	for (int i = 0; i < a.m(); ++i)
		for (int j = 0; j < a.n(); ++j)
			res.a(i, j) = a.a(i, j) - b.a(i, j);
	return res;
}
ostream& operator<<(ostream& os, const CopyMatrix& a)
{
	for (int i = 0; i < a.m(); ++i)
	{
		for (int j = 0; j < a.n(); ++j)
			os << a.a(i, j) << ' ';
		os << endl;
	}

	return os;
}