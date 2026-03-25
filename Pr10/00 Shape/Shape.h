#pragma once
#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
struct Point
{
  Point(double x = 0, double y = 0) : _x(x), _y(y) {}
  double _x;
  double _y;
};

class Shape
{
 public:
  // Shape() = default;
  virtual void whatAmI() = 0;
  //	virtual ~Shape() = default;
};
void Shape::whatAmI() { cout << "I don't know what I am!\n"; }

class Rectangle : public Shape
{
 public:
  void whatAmI() override { cout << "I'm a rectangle!\n"; }
  ~Rectangle() { std::cout << "Nothing to delete" << std::endl; }

 private:
  std::vector<Point> _vericese{Point(1, 0), Point(0, 1), Point(1, 1)};
};

class Triangle : public Shape
{
 public:
  void whatAmI() override { cout << "I'm a triangle!\n"; }
  ~Triangle()
  {
    std::cout << "Deleting _verices" << std::endl;
    delete[] _vertices;
  }

 private:
  Point *_vertices = new Point[3]{Point(0, 0), Point(1, 0), Point(0, 1)};
};

class RightTriangle : public Triangle
{
 public:
  void whatAmI() override final { cout << "I'm a right triangle!\n"; }
};

class AcuteTriangle : public Triangle
{
 public:
  void whatAmI() override final { cout << "I'm an acute triangle!\n"; }
};

class ObtuseTriangle : public Triangle
{
 public:
  void whatAmI() override final { cout << "I'm an obtuse triangle!\n"; }
};