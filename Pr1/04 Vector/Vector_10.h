#include <iostream>
using namespace std;

//****************************************************
//
//	Version 1.0
//	Develop a selector and a modifier for the class Vector10
//
//****************************************************

class Vector10
{
// the door opened
friend ostream& operator<<(ostream&, const Vector10&);
friend istream& operator>>(istream&, Vector10&);
// class invariant _v!=nullptr
private:
	int _n;
	double * _v;
public:
	Vector10(int);
	~Vector10();
	int size() const { return _n;}
	
	bool operator==(const Vector10&) const;
	bool operator!=(const Vector10&) const;

};
