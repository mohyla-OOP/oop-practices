#include "Point.h"
#include "Segment.h"
#include "Triangle.h"
#include <cassert>
#include <cmath>

int Triangle::_call=0;
ofstream Triangle::out("Triangle.txt");

Triangle::Triangle(const double x1, const double y1,
		const double x2, const double y2,
		const double x3, const double y3):
		_a(x1, y1), _b(x2, y2), _c(x3, y3)
{
	++_call;
	assert (area()!=0);
	return;
}

Triangle::Triangle(const Point& a, const Point& b, const Point &c):
		_a(a), _b(b), _c(c)
{
	++_call;
	cout << area() << endl;
	assert (area()>0);
	return;
}

Triangle::Triangle (const Triangle& t):
			_a(t._a), _b(t._b), _c(t._c)
{
	++_call;
	return;
};
Triangle::~Triangle()
{
	++_call;
	return;
};
Triangle& Triangle::operator= (const Triangle& t)
{
	++_call;
	_a=t._a;
	_b=t._b;
	_c=t._c;
	return *this;
}

double Triangle::perimeter() const
{
	++_call;
	return side_a().length()+side_b().length()+side_c().length();
}


double Triangle::area() const
{
	++_call;
	double a = side_a().length();
	double b = side_b().length();
	double c = side_c().length();
	double p = (a + b + c)*0.5;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

const Point& Triangle::apexA() const
{
	++_call;
	return _a;
}
const Point& Triangle::apexB() const
{
	++_call;
	return _b;
}
const Point& Triangle::apexC() const
{
	++_call;
	return _c;
}

const Segment Triangle::side_a() const
{
	++_call;
	return Segment(_b, _c);
}
const Segment Triangle::side_b() const
{
	return Segment(_c, _a);
}
const Segment Triangle::side_c() const
{
	++_call;
	return Segment(_a, _b);
}

ostream& Triangle::show (ostream & os) const
{
	os<<"Triangle: "<<apexA()<<apexB()<<apexC()<<endl;
	os<<side_a();
	os<<side_b();
	os<<side_c();
	os<<"perimeter "<<perimeter()<<endl;
	os<<"area      "<<area()<<endl<<endl;
	return os;
}
int Triangle::epilog()
{
	out<<"N calls "<<_call<<endl;
	return _call;
}

ostream& operator<<(ostream & os, const Triangle & t)
{	
	return t.show(os);
}