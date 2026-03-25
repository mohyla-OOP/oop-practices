#pragma once
struct C
{
  virtual void f() {}
};
struct B : public C
{
  void f() {}
};
struct A : public B
{
  void f() {}
};
