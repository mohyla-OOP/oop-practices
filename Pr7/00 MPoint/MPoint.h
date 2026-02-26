#pragma once
#include <map>
#include <vector>

#include "Array.h"

// TODO: 4: which template will be used here?
struct MPointNew
{
  double _mass;
  Array<3, double> _point;
};
using AP = double(Array<3, double>::*);

// Single function for any coordinate
double centre(const std::vector<MPointNew> p, const int n, double Array<3, double>::*coord)
{
  double moment(0), sum(0);
  for (size_t i = 0; i < n; ++i)
  {
    moment += p[i]._mass * p[i]._point.*coord;
    sum += p[i]._mass;
  }
  return moment / sum;
}
// Center of mass
Array<3, double> centre(const std::vector<MPointNew> p)
{
  int n = p.size();
  return {centre(p, n, &Array<3, double>::_x), centre(p, n, &Array<3, double>::_y), centre(p, n, &Array<3, double>::_z)};
}

struct MPoint
{
  double _mass = 1;
  double _x = 1;
  double _y = 1;
  double _z = 1;
};

struct MPoint4
{
  double _x = 1;
  double _y = 1;
  double _z = 1;
  double _t = 1;
  double _mass = 1;
  MPoint4(double x, double y, double z, double t, double mass = 1) : _x(x), _y(y), _z(z), _t(t), _mass(mass) {}
  MPoint4() {}
};

template <class T>
double center(const T ap[], const int size, double T::*coord)
{
  double moment = 0;
  double sumMass = 0;
  double mass = 0;
  for (int i = 0; i < size; ++i)
  {
    mass = ap[i]._mass;
    moment += mass * ap[i].*coord;
    sumMass += mass;
  }
  return moment / sumMass;
}

class CPoint
{
 private:
  double _x = 1;
  double _y = 1;
  double _z = 1;
  double _mass = 1;

 public:
  using Coord = const double CPoint::*;

  CPoint(double x, double y, double z, double mass) : _x(x), _y(y), _z(z), _mass(mass) {}
  CPoint() {}
  static Coord x() { return &CPoint::_x; }
  static Coord y() { return &CPoint::_y; }
  static Coord z() { return &CPoint::_z; }
  double mass() const { return _mass; }
};

class CPoint4
{
 private:
  double _x = 1;
  double _y = 1;
  double _z = 1;
  double _t = 1;
  double _mass = 1;

 public:
  using Coord = const double CPoint4::*;

  CPoint4(double x, double y, double z, double t, double mass) : _x(x), _y(y), _z(z), _t(t), _mass(mass) {}
  CPoint4() {}
  static Coord x() { return &CPoint4::_x; }
  static Coord y() { return &CPoint4::_y; }
  static Coord z() { return &CPoint4::_z; }
  static Coord t() { return &CPoint4::_t; }
  double mass() const { return _mass; }
};

template <class T>
double center(const T ap[], const int size, typename T::Coord coord())
// Details concerning typename T::Coord in the Lecture 13, slides 6-8
{
  double moment = 0;
  double sumMass = 0;
  double mass = 0;
  for (int i = 0; i < size; ++i)
  {
    mass = ap[i].mass();
    moment += mass * ap[i].*coord();
    sumMass += mass;
  }
  return moment / sumMass;
}
