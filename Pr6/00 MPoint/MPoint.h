#pragma once
#include <iostream>
#include <vector>
// TODO: 1: read
// Mass center of a system of point particles
// // Define mass as a function depending on coordinats of the MPoint mass(x,y)
// Develop mass center for 3D points

struct AMPoint {
	double _point[2];
	double _mass =1;
};

// Plain point
struct Point
{
	double _x;
	double _y;
};

// A function for coordinate #k
double centre(const std::vector<AMPoint> p, const int n, const int k)
{
	double moment(0), sum(0);
	for (size_t i = 0; i < n; ++i) {
		moment += p[i]._mass * p[i]._point[k];
		sum += p[i]._mass;
	}
	return moment / sum;
}

// Center of mass
Point centre(const std::vector<AMPoint> p)
{
	int n = p.size();
	return Point
	{
		centre(p, n, 0),
		centre(p, n, 1)
	};
}

// Point particle

struct MPoint
{
	// Pointer to member of Point
	using Coord = double Point::*;
	using ConstCoord = const double  Point::*;
	Point _p;
	double _mass = 1;
};
// Selector of a coordinate
inline double select
(const MPoint& u, const MPoint::ConstCoord coord)
{
	return u._p.*coord;
}

// Single function for any coordinate
double centre(const std::vector<MPoint> p, const int n, MPoint::ConstCoord coord)
{
	double moment(0), sum(0);
	for (size_t i = 0; i < n; ++i) {
		moment += p[i]._mass * p[i]._p.*coord;
		sum += p[i]._mass;
	}
	return moment / sum;
}
// Center of mass
Point centre(const std::vector<MPoint> p)
{
	int n = p.size();
	return
	{
		centre(p, n, &Point::_x),
		centre(p, n, &Point::_y)
	};
}

std::ostream& operator<<(std::ostream& os, const Point& a)
{
	return os << '(' << a._x << ',' << a._y << ')';
}


