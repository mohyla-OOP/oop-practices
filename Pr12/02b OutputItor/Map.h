#pragma once
using namespace std;
// #include "Set.h"
#include "AItor.h"
#include "Itor.h"
#include "Sequence.h"

template <class T, class U>
struct Pair
{
  T _t;
  U _u;
  Pair(T t = T(), U u = T()) : _t(t), _u(u) {}
};
template <class T, class U>
ostream &operator<<(ostream &os, const Pair<T, U> &pair)
{
  return os << '(' << pair._t << ',' << pair._u << ')';
}

template <class T, class U>
bool operator<(const Pair<T, U> &a, const Pair<T, U> &b)
{
  return a._t < b._t;
}

template <class T, class U>
bool operator==(const Pair<T, U> &a, const Pair<T, U> &b)
{
  return a._t == b._t;
}

template <class T, class U>
class Map
{
 private:
  Sequence<Pair<T, U>> *_seq;

 public:
  Map(size_t n) : _seq(new Sequence<Pair<T, U>>) {}
  Map &add(const Pair<T, U> &pair)
  {
    if (_seq->size() == 0)
    {
      _seq->append(pair);
      return *this;
    };
    Iterator<Pair<T, U>, Map<T, U>> itor(*this);
    if (find(itor, pair))
      (*itor)._u = pair._u;
    else
      _seq->append(pair);
    return *this;
  }
  Pair<T, U> &operator[](size_t index) { return (*_seq)[index]; }
  const Pair<T, U> &operator[](size_t index) const { return (*_seq)[index]; }

  size_t size() const { return _seq->size(); }
};
#pragma once
