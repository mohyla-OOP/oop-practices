#pragma once
#include <iostream>
#include <string>

#include "Array.h"
using namespace std;

template <class T>
class Sequence
{
 public:
  class BadSeq;
  Sequence() : _size(0), _capacity(_size), _sArr(new Array<T>()) {}
  ~Sequence() { delete _sArr; }
  Sequence &append(const T &elem);
  const T &operator[](size_t index) const { return (*_sArr)[index]; }
  T &operator[](size_t index) { return (*_sArr)[index]; }
  size_t capacity() const { return _capacity; }
  size_t size() const { return _size; }
  bool empty() const { return _size == 0; }
  void clear() { _size = 0; }
  Sequence &insert(const T &elem, size_t index);
  Sequence &remove(size_t index);

 private:
  size_t _size;
  size_t _capacity;
  Array<T> *_sArr;
  Sequence(const Sequence &) = delete;
  Sequence &operator=(const Sequence &) = delete;
};

template <class T>
class Sequence<T>::BadSeq
{
 private:
  string _error;
  size_t _index;

 public:
  BadSeq(string error) : _error(error), _index(index) {};
  void diagnose()
  {
    cerr << _error << endl;
    return;
  }
};

template <class T>
Sequence<T> &Sequence<T>::append(const T &elem)
{
  if (_size == _capacity)
  {
    _sArr->resize();
    _capacity = _capacity * 2 + 1;
  }
  (*_sArr)[_size++] = elem;
  return *this;
}
template <class T>
ostream &operator<<(ostream &os, const Sequence<T> &s)
{
  os << '[';
  for (size_t i = 0; i < s.size(); ++i) os << s[i] << ' ';
  return os << ']';
}
