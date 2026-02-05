#include "Triangle.h"
#include <cassert>
#include <iostream>
using namespace std;


int Triangle::_call=0;
ofstream Triangle::out("Triangle.txt");

void Triangle::assignSegment(const SidePtr side, 
				   const Triangle & s)
{
	if ((*this).*side == 0)
	{
		if (s.*side == 0)
			;
		else
			(*this).*side = new Segment(*(s.*side));
	}
	else
	{
		if (s.*side == 0)
		{
			delete ((*this).*side);
			(*this).*side = 0;
		}
		else
			*((*this).*side) = *(s.*side);
	}
	return;
}

Triangle::Triangle(const double x1, const double y1,
		const double x2, const double y2,
		const double x3, const double y3):
		_a(x1, y1), _b(x2, y2), _c(x3, y3),
		_ab(0), _bc(0), _ca(0)
{
	++_call;
	assert (area()!=0);
	return;
}

Triangle::Triangle(const Point& a, const Point& b, const Point &c):
		_a(a), _b(b), _c(c),
		_ab(0), _bc(0), _ca(0)
{
	++_call;
	assert(area()!=0);
	return;
}

Triangle::Triangle (const Triangle& t, const bool full):
		_a(t._a), _b(t._b), _c(t._c),
		_ab(0), _bc(0), _ca(0)
{
	++_call;
	if (full)
	{
		assignSegment(&Triangle::_ab, t);
		assignSegment(&Triangle::_bc, t);
		assignSegment(&Triangle::_ca, t);
	}
	return;
};
Triangle::~Triangle()
{
	++_call;
	if (_ab!=0) delete _ab;
	if (_bc!=0) delete _bc;
	if (_ca!=0) delete _ca;
	return;
};

Triangle& Triangle::operator= (const Triangle& t)
{
	++_call;
	_a=t._a;
	_b=t._b;
	_c=t._c;
	if (_ab!=0) delete _ab;
	if (_bc!=0) delete _bc;
	if (_ca!=0) delete _ca;
	_ab=_bc=_ca=0;

	return *this;
}

Triangle& Triangle::assign (const Triangle& t)
{
	++_call;
	_a=t._a;
	_b=t._b;
	_c=t._c;

	assignSegment(&Triangle::_ab, t);
	assignSegment(&Triangle::_bc, t);
	assignSegment(&Triangle::_ca, t);

	return *this;
}
double Triangle::perimeter() const
{
	++_call;
	return length_a()+length_b()+length_c();
}

double Triangle::area() const
{
	++_call;
	return 0.5*length_a()*side_a().distance(apexA());
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

const Segment& Triangle::side_a() const
{
	++_call;
	if (_bc==0) 
		_bc= new Segment(_b, _c);
	return *_bc;
}
const Segment& Triangle::side_b() const
{
	++_call;
	if (_ca==0)
		_ca=new Segment(_c, _a);
	return *_ca;
}
const Segment& Triangle::side_c() const
{
	++_call;
	if (_ab==0)
		_ab=new Segment(_a, _b);
	return *_ab;
}

double Triangle::length_a() const
{
	++_call;
	return side_a().length();
}

double Triangle::length_b() const
{
	return side_b().length();
}

double Triangle::length_c() const
{
	++_call;
	return side_c().length();
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