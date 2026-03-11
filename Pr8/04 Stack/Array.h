#pragma once
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <string>

// ============================================================
//  Array<T> -- fixed-size array over a raw pointer
//  Invariant: _v points to an array of exactly _n elements
// ============================================================
template <typename T>
class Array
{
 public:
  explicit Array(std::size_t n = 0) : _n(n), _v(n ? new T[n]{} : nullptr) {}

  Array(std::initializer_list<T> il) : _n(il.size()), _v(new T[il.size()]) { std::copy(il.begin(), il.end(), _v); }

  ~Array() { delete[] _v; }

  // copy disabled until properly implemented
  Array(const Array &) = delete;
  Array &operator=(const Array &) = delete;

  std::size_t size() const { return _n; }

  T &operator[](std::size_t i)
  {
    if (i >= _n) throw std::runtime_error("Array: index out of range: " + std::to_string(i));
    return _v[i];
  }
  const T &operator[](std::size_t i) const
  {
    if (i >= _n) throw std::runtime_error("Array: index out of range: " + std::to_string(i));
    return _v[i];
  }

  // Resize -- only growing is allowed
  void resize(std::size_t m)
  {
    assert(m >= _n);
    T *tmp = new T[m]{};
    for (std::size_t i = 0; i < _n; ++i) tmp[i] = _v[i];
    delete[] _v;
    _v = tmp;
    _n = m;
  }

 private:
  std::size_t _n;
  T *_v;
};
