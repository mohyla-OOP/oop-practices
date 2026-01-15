#include <iostream>
using namespace std;

//****************************************************
//
//	Version 0.1
//	All attributes are public and thus accessible
//
//****************************************************

//Realize operator<< and operator>>

struct Vector01
{
	int _n;
	double * _v;

	Vector01(int n);
	~Vector01();

};

	bool operator==(const Vector01&, const Vector01&);
	bool operator!=(const Vector01&, const Vector01&);
	ostream& operator<<(ostream&, const Vector01&);
	istream& operator>>(istream&, Vector01&);

	


