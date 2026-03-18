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
    assert(_px == &_x);
    return *this;
  }
};
