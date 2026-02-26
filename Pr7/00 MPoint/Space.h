// Space with any number of axis
#pragma once
template <typename... P>
struct R;

template <typename T, typename... P>
struct R<T, P...>
{
  T _x{};
  R<P...> _y{};
};

template <>
struct R<>
{
};

template <typename T, typename... P>
using Coord = T R<T, P...>::*;

template <typename T, typename... P>
static T select(R<T, P...> &a, Coord<T, P...> coord)
{
  return a.*coord;
}

template <typename T, typename... P>
R<P...> &down(R<T, P...> &a)
{
  return a._y;
}

template <typename T>
R<> &down(R<T> &a)
{
  return {};
}

template <typename T, typename... P>
struct PointParticle
{
  R<T, P...> _point;
  double _mass;
};

template <int n, typename T, typename... P>
double center(PointParticle<T, P...> a[n], Coord<T, P...> coord)
{
  double moment = 0;
  double sum = 0;
  for (int i = 0; i < n; ++i)
  {
    moment += a[i]._point.*coord * a[i]._mass;
    sum += a[i]._mass;
  }
  return moment / sum;
}

template <int n, typename T, typename... P>
R<T, P...> center(PointParticle<T, P...> a[n])
{
  R<T, P...> centre = { center(a[n], &_a) }
}
