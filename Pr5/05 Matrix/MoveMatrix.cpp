#include "MoveMatrix.h"

int MoveMatrix::created = 0;
int MoveMatrix::copied = 0;
int MoveMatrix::deleted = 0;

MoveMatrix::MoveMatrix(const MoveMatrix& a) : _m(a._m), _n(a._n), _a(new double[_m * _n])
{
	copied += _m * _n;
	for (int i = 0; i < _n * _m; ++i)
		_a[i] = a._a[i];
}

MoveMatrix::MoveMatrix(MoveMatrix&& a) : _m(a._m), _n(a._n), _a(a._a)
{
	a._a = nullptr;
}

MoveMatrix operator+(const MoveMatrix& a, const MoveMatrix& b)
{
	MoveMatrix res(a.m(), a.n());
	for (int i = 0; i < a.m(); ++i)
		for (int j = 0; j < a.n(); ++j)
			res.a(i, j) = a.a(i, j) + b.a(i, j);
	return res;
}
const MoveMatrix operator-(const MoveMatrix& a, const MoveMatrix& b)
{
	MoveMatrix res(a);
	res -= b;
	return res;
}

MoveMatrix& MoveMatrix::operator-=(const MoveMatrix& a)
{
	for (int i = 0; i < m(); ++i)
		for (int j = 0; j < n(); ++j)
			this->a(i, j) -= a.a(i, j);
	return *this;
}
ostream& operator<<(ostream& os, const MoveMatrix& a)
{
	for (int i = 0; i < a.m(); ++i)
	{
		for (int j = 0; j < a.n(); ++j)
			os << a.a(i, j) << ' ';
		os << endl;
	}

	return os;
}