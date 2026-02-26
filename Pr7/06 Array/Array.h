#pragma once
#include <atomic>
#include <memory>
#include <stdexcept>
#include <string>

// Complete and test

template <typename T>
class Array
{
 private:
  std::size_t _n;
  T *_v;

 public:
  explicit Array(std::size_t n) : _n(n), _v(new T[_n]{}) {}

  Array(std::initializer_list<T> init) : _v(new T[init.size()]), _n(static_cast<std::size_t>(init.size()))
  {
    std::copy(init.begin(), init.end(), _v);
  }

  ~Array() { delete[] _v; };
  std::size_t size() const { return _n; }
  T operator[](std::size_t i) const
  {
    if (i > _n) throw std::runtime_error("index: " + std::to_string(i));
    return _v[i];
  }
  T &operator[](std::size_t i)
  {
    if (i > _n) throw std::runtime_error("index: " + std::to_string(i));
    return _v[i];
  }
  void resize(std::size_t k)
  {
    Array<T> tmp(_n * k);
    for (std::size_t i = 0; i < _n; ++i) tmp._v[i] = _v[i];
    std::swap(_v, tmp._v);
    std::swap(_n, tmp._n);
  }
};

template <typename T>
class Array<T[]>
{
 private:
  std::unique_ptr<T[]> _v;
  std::size_t _n = 0;

 public:
  Array() = default;

  explicit Array(std::size_t n) : _v(std::make_unique<T[]>(n)), _n(n) {}

  // ⭐ конструктор зі списку ініціалізації
  Array(std::initializer_list<T> il) : _v(std::make_unique<T[]>(il.size())), _n(il.size()) { std::copy(il.begin(), il.end(), _v.get()); }

  std::size_t size() const { return _n; }

  T &operator[](std::size_t i)
  {
    if (i > _n) throw std::runtime_error("index: " + std::to_string(i));
    return _v[i];
  }
  const T &operator[](std::size_t i) const
  {
    if (i > _n) throw std::runtime_error("index: " + std::to_string(i));
    return _v[i];
  }
  void resize(std::size_t k)
  {
    Array tmp(_n * k);
    for (std::size_t i = 0; i < _n; ++i) tmp._v[i] = _v[i];

    std::swap(_v, tmp._v);
    std::swap(_n, tmp._n);
  }
};
