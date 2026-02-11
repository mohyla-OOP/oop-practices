#include "Matrix.h"

Matrix::Matrix(const Matrix& a): _m(a._m),_n(a._n),_a(new double[_m*_n])
{
	for (int i = 0; i < _n*_m; ++i)
		_a[i] = a._a[i];
}
Matrix::Matrix(Matrix&& a) : _m(a._m), _n(a._n), _a(a._a)
{
	a._a = nullptr;
}
Matrix operator+(const Matrix& a, const Matrix& b)
{
	Matrix res(a.m(), a.n());
	for (int i = 0; i < a.m(); ++i)
		for (int j = 0; j < a.n(); ++j)
			res(i, j) = a(i, j) + b(i, j);
	return res;
}
ostream& operator<<(ostream& os, const Matrix& a)
{
	for (int i = 0; i < a.m(); ++i)
	{ 
		for (int j = 0; j < a.n(); ++j)
			os << a(i, j)<<' ';
		os << endl;
	}

	return os;
}