#pragma once
#include <iostream>
using namespace std;

class Matrix
{
public:
	Matrix(int m, int n) :_m(m), _n(n), _a(new double[n*m]) 
	{
		for (int i = 0; i < _m; ++i)
			for (int j = 0; j < _n; ++j)
				(*this)(i, j) = double(i);
	}
	Matrix(const Matrix&);
	Matrix(Matrix&&);
	~Matrix()
	{
		delete[] _a;
	}
	const int m() const { return _m; }
	const int n() const { return _n; }
	double operator()(int i, int j) const
	{
		return _a[i*_n + j];
	}
	double& operator()(int i, int j)
	{
		return _a[i*_n + j];
	}
private:
	int _m;
	int _n;
	double *_a;
};
Matrix operator+(const Matrix&, const Matrix&);
ostream& operator<<(ostream&, const Matrix&);