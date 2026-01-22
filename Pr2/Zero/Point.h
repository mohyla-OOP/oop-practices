#pragma once
struct Point2003
{
	double _x;
	double _y;
	Point2003(double x=0, double y=0) :_x(x), _y(y) {}
	Point2003(const Point2003& a) :_x(a._x), _y(a._y) {}
};
struct Point2011
{
	double _x = 0;
	double _y = 0;
};
struct Point2011a
{
	double _x = 0;
	double _y = 0;
	Point2011a() = default;
	Point2011a(const Point2011a& a) = default;
};

class Point {
	static int _freeID;	//Вільний ID в класі
	const int _pointID;	//Власний ID об'єкту
	double _x;
	double _y;
public:
	Point(double x = 0, double y = 0) :_x(x), _y(y), _pointID(++_freeID) {}
	Point(const Point& a) :_x(a._x), _y(a._y), _pointID(++_freeID) {}
	//~Point();
	double& x();
	double x() const;
	double& y();
	double y() const;
};

