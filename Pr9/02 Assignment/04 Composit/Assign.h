#pragma once
#include <cassert>
#include <iostream>

class A
{
  int _x;
  int *_px;

 public:
  A(int x) : _x(x), _px(&_x) {}

  void dump(const char *name) const
  {
    std::cout << name << " x=" << _x << " p=" << _px << " &x=" << &_x << "\n";
    assert(_px == &_x);
  }
  A &operator=(const A &rhs)
  {
    _x = rhs._x;
    _px = &_x;
    assert(_px == &_x);
    return *this;
  }
};

class B
{
  int _y;
  int *_py;
  A _a;  // TODO: 1: what changed in the code in comparison to the previous project?
         //          Run the code
         //          No inheritance, but composition.
 public:
  B(int x, int y) : _y(x), _py(&_y), _a(y) {}

  void dump(const char *name) const
  {
    std::cout << name << " x=" << _y << " p=" << _py << " &x=" << &_y << "\n";
    assert(_py == &_y);
  }

  void dump() { return _a.dump("base"); }

  B &operator=(const B &rhs)
  {
    _a = rhs._a;
    _y = rhs._y;
    assert(_py == &_y);
    return *this;
  }
};
