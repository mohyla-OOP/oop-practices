#pragma once
#include <iostream>
using namespace std;
#include "AItor.h"

template <class T, class Container>
class Iterator : public AIterator<T>
{
 private:
  Container &_container;
  T *_begin;
  mutable T *_end;
  mutable T *_current;

 public:
  Iterator(Container &container) : _container(container), _begin(&_container[0]), _end(_begin + _container.size()), _current(_begin) {}
  Iterator(const Iterator &it) : _container(it._container), _begin(it._begin), _end(it._end), _current(it._current) {}
  Iterator &clone() { return *(new Iterator(*this)); }
  void begin()
  {
    _current = &_container[0];
    _end = _begin + _container.size();
  }
  const Iterator &operator++() const
  {
    ++_current;
    return *this;
  }
  bool end() const { return _current == _end; }
  const T &operator*() const { return *_current; }
  T &operator*() { return *_current; }
  virtual ~Iterator() {};
};

template <class T, class Container>
void sort(Iterator<T, Container> &i)
{
  for (i.begin(); !i.end(); ++i)
  {
    Iterator<T, Container> j(i);
    Iterator<T, Container> k(i);
    ++k;
    for (; !k.end(); ++k)
      if (*j < *k)
      {
        int tmp = *j;
        *j = *k;
        *k = tmp;
      }
  }
}
