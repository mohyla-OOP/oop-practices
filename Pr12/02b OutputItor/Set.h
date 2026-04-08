#pragma once
#include "AItor.h"
#include "Itor.h"
#include "OutItor.h"
#include "Sequence.h"

template <class T>
class ASet
{
 public:
  virtual ASet &add(const T &x) = 0;
  virtual const T &operator[](size_t index) const = 0;
  virtual size_t size() const = 0;
  virtual ~ASet() {};
};

template <class T>
class Set : public ASet<T>
{
 private:
  Sequence<T> *_seq;

 public:
  Set(size_t n) : _seq(new Sequence<T>) {}
  Set &add(const T &x)
  {
    if (_seq->size() == 0)
    {
      _seq->append(x);
      return *this;
    }
    Iterator<T, Sequence<T>> itor(*_seq);
    if (!find(itor, x)) _seq->append(x);
    return *this;
  }

  const T &operator[](size_t index) const { return (*_seq)[index]; }

  size_t size() const { return _seq->size(); }
};

template <class T>
class MultiSet : public ASet<T>
{
 private:
  Sequence<T> *_seq;

 public:
  MultiSet(size_t n) : _seq(new Sequence<T>) {}

  MultiSet &add(const T &x)
  {
    _seq->append(x);
    return *this;
  }
  T &operator[](size_t index) { return (*_seq)[index]; }
  const T &operator[](size_t index) const { return (*_seq)[index]; }

  size_t size() const { return _seq->size(); }
};
