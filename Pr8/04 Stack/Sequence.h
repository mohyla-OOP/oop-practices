#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

#include "Array.h"

// ============================================================
//  Sequence<T> -- variable-size sequence built on top of Array<T>
//  Invariant: _size <= _capacity, valid elements in [0, _size)
//
//  Key distinction:
//    Array    -- always fully populated (_size == _capacity)
//    Sequence -- partially populated    (_size <= _capacity)
// ============================================================
template <typename T>
class Sequence
{
 public:
  // ---- Exception ----
  class BadSeq
  {
   public:
    BadSeq(std::size_t index, const std::string &error = "unknown") : _error(error), _index(index) {}
    void diagnose() const { std::cerr << "Sequence error [" << _error << "] at index: " << _index << '\n'; }

   private:
    std::string _error;
    std::size_t _index;
  };

  // ---- Constructors / destructor ----
  explicit Sequence(std::size_t capacity = 0) : _size(0), _capacity(capacity), _a(new Array<T>(capacity)) {}

  Sequence(std::initializer_list<T> il) : _size(il.size()), _capacity(il.size()), _a(new Array<T>(il)) {}

  ~Sequence() { delete _a; }

  Sequence(const Sequence &) = delete;
  Sequence &operator=(const Sequence &) = delete;

  // ---- Element access ----
  T &operator[](std::size_t i)
  {
    if (i >= _size) throw BadSeq(i, "index out of range");
    return (*_a)[i];
  }
  const T &operator[](std::size_t i) const
  {
    if (i >= _size) throw BadSeq(i, "index out of range");
    return (*_a)[i];
  }

  T &back()
  {
    if (_size == 0) throw BadSeq(0, "back on empty sequence");
    return (*_a)[_size - 1];
  }
  const T &back() const
  {
    if (_size == 0) throw BadSeq(0, "back on empty sequence");
    return (*_a)[_size - 1];
  }

  // ---- State ----
  std::size_t size() const { return _size; }
  std::size_t capacity() const { return _capacity; }
  bool empty() const { return _size == 0; }
  void clear() { _size = 0; }

  // ---- Modification ----
  Sequence &append(const T &elem)
  {
    _grow_if_needed();
    (*_a)[_size++] = elem;
    return *this;
  }

  // Alias for Stack compatibility
  Sequence &push_back(const T &x) { return append(x); }

  Sequence &pop_back()
  {
    if (_size == 0) throw BadSeq(0, "pop_back on empty sequence");
    --_size;
    return *this;
  }

  Sequence &insert(const T &elem, std::size_t index)
  {
    if (index > _size) throw BadSeq(index, "insert out of range");
    _grow_if_needed();
    for (std::size_t i = _size; i > index; --i) (*_a)[i] = (*_a)[i - 1];
    (*_a)[index] = elem;
    ++_size;
    return *this;
  }

  Sequence &remove(std::size_t index)
  {
    if (index >= _size) throw BadSeq(index, "remove out of range");
    for (std::size_t i = index; i < _size - 1; ++i) (*_a)[i] = (*_a)[i + 1];
    --_size;
    return *this;
  }

 private:
  std::size_t _size;
  std::size_t _capacity;
  Array<T> *_a;

  void _grow_if_needed()
  {
    if (_size == _capacity)
    {
      std::size_t new_cap = _capacity == 0 ? 1 : _capacity * 2;
      _a->resize(new_cap);
      _capacity = new_cap;
    }
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Sequence<T> &s)
{
  if (s.size() == 0) return os << "()";
  os << '(';
  for (std::size_t i = 0; i < s.size() - 1; ++i) os << s[i] << ", ";
  return os << s[s.size() - 1] << ')';
}
