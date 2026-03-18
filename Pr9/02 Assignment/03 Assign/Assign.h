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

class B : public A
{
  int _y;
  int *_py;

 public:
  B(int x, int y) : _y(x), _py(&_y), A(y) {}

  void dump(const char *name) const
  {
    std::cout << name << " x=" << _y << " p=" << _py << " &x=" << &_y << "\n";
    assert(_py == &_y);
  }

  B &operator=(const B &rhs)
  {
    // TODO: 1: what changed here in comparison with the previous project?
    //          set a breakpoint, run the code and trace it
    A::operator=(rhs);
    _y = rhs._y;
    assert(_py == &_y);
    return *this;
  }
};