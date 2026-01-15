#include <iostream>
using namespace std;

#include "Vector_10.h"

Vector10::Vector10(int n) : _n(n),
_v(new double[_n] {})
{
	for (int i = 0; i < _n; i++)
		_v[i] = rand();
	return;
}

Vector10::~Vector10()
{
	delete[] _v;
	_v = nullptr;
	return;
}

bool Vector10::operator==(const Vector10& u) const
{
	bool res = true;
	if (_n != u._n)
		return false;

	for (int i = 0; i < size(); i++)
		res = res && (_v[i] == u._v[i]);
	return res;
}

bool Vector10::operator!=(const Vector10& u) const
{
	return !(*this == u);
}

ostream& operator<<(ostream& os, const Vector10& u)
{
	char ch = '(';
	for (int i = 0; i < u._n; i++)
	{
		os << ch << u._v[i];
		ch = ',';
	}
	os << ')' << endl;

	return os;
}

istream& operator>>(istream& is, Vector10& u)
{
	cout << u._n << ':' << endl;
	for (int i = 0; i < u._n; i++)
	{
		cout << i << ':';
		is >> u._v[i];
	}
	return is;
}
