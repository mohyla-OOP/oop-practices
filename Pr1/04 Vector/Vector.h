#pragma once
#include <iostream>
using namespace std;

//****************************************************
//
//	Version 2.0
//	Develop selector-modifier for the class Vector
//
//****************************************************

// Develop Vector.cpp;
// Suggest realisation for the code:
// Vector a(10); Vector b=a;
// Vector c(20); c=a;

class Vector
{
private:
	int _n;
	double* _v;
public:
	Vector(int);
	~Vector();
	int size() const { return _n; }
	double operator[](int i);
	const double operator[] (int i) const;
};

	bool operator==(const Vector&, const Vector&);
	bool operator!=(const Vector&, const Vector&);

	ostream& operator<<(ostream&, const Vector&);
	istream& operator>>(istream&, Vector&);
