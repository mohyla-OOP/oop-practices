#include <iostream>
using namespace std;

#include "Vector_01.h"

Vector01::Vector01(int n) :_n(n),
_v(new double[_n] {})
{
	for (int i = 0; i < _n; i++)
		_v[i] = rand();
	return;
}

Vector01::~Vector01()
{
	delete[] _v;
	_v = nullptr;
	return;
}

bool operator==(const Vector01& u, const Vector01& v)
{
	bool res = true;
	if (u._n != v._n) 
		return false;

	for (int i = 0; i < u._n; i++)
		res = res && (v._v[i] == u._v[i]);
	return res;
}

bool operator!=(const Vector01& u, const Vector01& v)
{
	return !(u==v);
}
