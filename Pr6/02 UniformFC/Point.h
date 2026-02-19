#pragma once
#include <iostream>
using namespace std;

// Plain point
struct Point
{
	double _x;
	double _y;
};

// Point particle
// Define mass as a function depending on coordinats of the MPoint mass(x,y)
// Develop mass center for 3D points

struct MPoint
{ 
	using Coord=  double Point::* ;
	using ConstCoord = const double  Point::*;
	Point _p;
	double _mass = 1;
};

inline double select
  (const MPoint& u, const MPoint::ConstCoord coord)
{
   	return u._p.*coord;
}
inline void modify
   (MPoint& u, MPoint::Coord coord, double a)
{
   	u._p.*coord=a;
	return; 
}
// Single coordinate in the center of mass 
double centre(const MPoint p[], const size_t n, MPoint::ConstCoord coord)
{
	double moment(0), sum(0);
	for (size_t i=0;i<n;++i) {
		moment+=p[i]._mass*p[i]._p.*coord;
		sum+=p[i]._mass;
	}
	return moment/sum;
}
// Center of mass
Point centre(const MPoint p[], const size_t n)
{
	return
	{
		centre(p, n, &Point::_x),
		centre(p, n, &Point::_y)
	};
}

ostream& operator<<(ostream& os, const Point& a)
{
	return os << '(' << a._x << ',' << a._y << ')';
}




