#pragma once
#include <iostream>
using namespace std;
class Foo
{
 private:
  int *_x;

 public:
  Foo(int x = 0) : _x(new int(x)) {}
  Foo(const Foo &f) : _x(new int(*f._x)) {}
  Foo &operator=(const Foo &f)
  {
    if (this != &f) *_x = *f._x;
    return *this;
  }
  ~Foo() { delete _x; }
  int x() const { return *_x; }
};
ostream &operator<<(ostream &os, const Foo &f) { return os << f.x(); }
