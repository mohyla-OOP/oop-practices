#pragma once
#include <cassert>
#include <iostream>

class A
{
  int _x;
  int *_px;

 public:
  A(int x) : _x(x), _px(&_x) {}  // TODO: 1: explain the constructor, explain what are we initializing here

  void dump(const char *name) const
  {
    std::cout << name << " x=" << _x << " p=" << _px << " &x=" << &_x << "\n";
    assert(_px == &_x);  // TODO: 3: check the console, explain the assert, what does it check?
                         //          hint: check what happens after assignment in main
  }
};