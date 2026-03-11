#pragma once
#include <iostream>
#include <string>

#include "Array.h"

template <class T>
class Sequence
{
 public:
  class BadSeq;
  Sequence(size_t size = 0) : _size(0), _capacity(size), _a(new Array<T>(size)) {}
  Sequence(std::initializer_list<T> init) : _a(new Array<T>(init)), _size(_a->size()), _capacity(_size) {}
  ~Sequence() { delete _a; }
  Sequence &append(const T &elem);
  const T &operator[](size_t index) const { return (*_a)[index]; }
  T &operator[](size_t index) { return (*_a)[index]; }
  size_t capacity() const { return _capacity; }
  size_t size() const { return _size; }
  bool empty() const { return _size == 0; }
  void clear() { _size = 0; }
  Sequence &insert(const T &elem, size_t index);
  Sequence &remove(size_t index);

 private:
  Array<T> *_a;
  size_t _size;
  size_t _capacity;

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
  BadSeq(std::size_t index, string error = "unknown") : _error(error), _index(index) {};
  void diagnose()
  {
    std::cerr << _error << ':' << _index << std::endl;
    return;
  }
};

template <class T>
Sequence<T> &Sequence<T>::append(const T &elem)
{
  std::size_t k = _size;
  if (_size == _capacity)
  {
    _capacity += _size;
    _a->resize(_capacity);
  }
  (*_a)[k++] = elem;
  ++_size;
  return *this;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const Sequence<T> &s)
{
  if (s.size() == 0) return os;
  os << '(';
  for (std::size_t i = 0; i < s.size() - 1; ++i) os << s[i] << ',';
  return os << s[s.size() - 1] << ')';
}
