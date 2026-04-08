#pragma once

template <class T>
class AIterator
{
 public:
  virtual AIterator &clone() = 0;
  virtual void begin() = 0;
  virtual const AIterator &operator++() const = 0;
  virtual bool end() const = 0;
  virtual const T &operator*() const = 0;
  // virtual T& operator*() = 0;
  virtual ~AIterator() {};
};

template <class T>
ostream &operator<<(ostream &os, AIterator<T> &itor)
{
  while (!itor.end())
  {
    os << *itor << ' ';
    ++itor;
  }
  return os << endl;
}

template <class T>
bool find(const T &elem, AIterator<T> &itor)
{
  while (!itor.end())
  {
    if (*itor == elem) return true;
    ++itor;
  }
  return false;
}
template <class T, typename Func>
bool find(AIterator<T> &itor, Func f)
{
  while (!itor.end())
  {
    if (f(*itor)) return true;
    ++itor;
  }
  return false;
}

template <class T, typename Func>
bool find(AIterator<T> &itor, Func f, const T &x)
{
  while (!itor.end())
  {
    if (f(*itor, x)) return true;
    ++itor;
  }
  return false;
}

template <class T>
void asort(AIterator<T> &i)
{
  AIterator<T> &show = i.clone();
  for (i.begin(); !i.end(); ++i)
  {
    AIterator<T> &j = i.clone();
    AIterator<T> &k = i.clone();
    ++k;
    for (; !k.end(); ++k)
      if (*j < *k)
      {
        T tmp = *j;
        *j = *k;
        *k = tmp;
      }
    delete &j;
    delete &k;
  }
}
