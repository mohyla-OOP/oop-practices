#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include <iostream>
using namespace std;
#include "Point.h"
#include "Segment.h"

class Triangle
{
	typedef Segment* Triangle::*SidePtr;

private:
	static ofstream out;
	static int _call;
	Point _a, _b, _c;
	mutable Segment *_ab, *_bc, *_ca;

	void assignSegment(const SidePtr, const Triangle &);

public:
	Triangle(const double x1=0, const double y1=0,
		const double x2=1, const double y2=0,
		const double x3=0, const double y3=1);
	Triangle(const Point &a, const Point& b, const Point& c);
	Triangle (const Triangle&, const bool full=false);
	~Triangle();
	Triangle& operator= (const Triangle&);

	Triangle& assign (const Triangle&);
	double perimeter() const;
	double area() const;

	const Point& apexA() const;
	const Point& apexB() const;
	const Point& apexC() const;

	const Segment& side_a() const;
	const Segment& side_b() const;
	const Segment& side_c() const;
	
	double length_a() const;
	double length_b() const;
	double length_c() const;

	static int epilog();
	ostream& show (ostream & os) const;
};

ostream& operator<<(ostream &, const Triangle &);
#endif
