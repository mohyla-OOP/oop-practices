#pragma once

template <class T>
class AOutIterator
{
 public:
  virtual void begin() const = 0;
  virtual const AOutIterator &operator++() const = 0;
  virtual bool end() const = 0;
  virtual const T &operator*() const = 0;
  virtual ~AOutIterator() {};
};

template <class T>
ostream &operator<<(ostream &os, const AOutIterator<T> &itor)
{
  while (!itor.end())
  {
    os << *itor << ' ';
    ++itor;
  }
  return os << endl;
}
template <class T>
bool find(AOutIterator<T> &itor, const T &elem)
{
  while (!itor.end())
  {
    if (*itor == elem) return true;
    ++itor;
  }
  return false;
}
template <class T, typename Func>
bool find(AOutIterator<T> &itor, Func f)
{
  while (!itor.end())
  {
    if (f(*itor)) return true;
    ++itor;
  }
  return false;
}

template <class T, typename Func>
bool find(AOutIterator<T> &itor, Func f, const T &x)
{
  while (!itor.end())
  {
    if (f(*itor, x)) return true;
    ++itor;
  }
  return false;
}
