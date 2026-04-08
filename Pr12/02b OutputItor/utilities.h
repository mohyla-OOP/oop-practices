#pragma once
#include <iostream>
using namespace std;

template <class T, template <typename> class Itor>
ostream &operator<<(ostream &os, const Itor<T> &itor)
{
  while (!itor.end())
  {
    os << *itor << ' ';
    ++itor;
  }
  return os << endl;
}

template <class T, template <typename> class Itor>
bool find(Itor<T> &itor, const T &elem)
{
  while (!itor.end())
  {
    if (*itor == elem) return true;
    ++itor;
  }
  return false;
}

template <class T, typename Func, template <typename> class Itor>
bool find(Itor<T> &itor, Func f)
{
  while (!itor.end())
  {
    if (f(*itor)) return true;
    ++itor;
  }
  return false;
}

template <class T, typename Func, template <typename> class Itor>
bool find(Itor<T> &itor, Func f, const T &x)
{
  while (!itor.end())
  {
    if (f(*itor, x)) return true;
    ++itor;
  }
  return false;
}