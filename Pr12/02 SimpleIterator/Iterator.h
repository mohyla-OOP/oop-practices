#pragma once
#include <iostream>

template <typename T>
class Iterator
{
  T *_ptr = nullptr;

 public:
  using value_type = T;

  Iterator(T *p = nullptr) : _ptr(p) {}

  T &operator*() const { return *_ptr; }

  Iterator &operator++()
  {
    ++_ptr;
    return *this;
  }

  bool operator!=(const Iterator &other) const { return _ptr != other._ptr; }
};

template <typename It>
void sort(It begin, It end)
{
  for (It i = begin; i != end; ++i)
  {
    for (It j = i; j != end; ++j)
    {
      if (*j < *i)
      {
        auto tmp = *i;
        *i = *j;
        *j = tmp;
      }
    }
  }
}

template <typename It, typename Compare>
void sort(It begin, It end, Compare comp)
{
  for (It i = begin; i != end; ++i)
  {
    for (It j = i; j != end; ++j)
    {
      if (comp(*j, *i))
      {
        auto tmp = *i;
        *i = *j;
        *j = tmp;
      }
    }
  }
}
template <typename Container, typename Comparator>
void my_sort(Container &cont, Comparator comp)
{
  ::sort(begin(cont), end(cont), comp);

  for (auto x : cont) std::cout << x << " ";
  std::cout << "\n";
}

template <typename T, template <typename> class Container>
T *begin(Container<T> &a)
{
  return &a[0];
}

template <typename T, template <typename> class Container>
T *end(Container<T> &a)
{
  return &a[0] + a.size();
}
