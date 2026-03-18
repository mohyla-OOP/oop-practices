#pragma once
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
    // TODO: 4: set a breakpoint here, and trace the execution from main.cpp
    _x = rhs._x;
    assert(_px == &_x);
    return *this;
  }
};

// TODO: 1: Explain the declaration and definition of class B, how does it differ from the previous projects?
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
    // TODO: 4: set a breakpoint here, and trace the execution from main.cpp
    //  We're not making an assignment of base class, why, how to fix it? Check the next project.
    _y = rhs._y;
    assert(_py == &_y);
    return *this;
  }
};