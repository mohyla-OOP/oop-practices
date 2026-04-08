#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Array
{
 public:
  class BadArray;
  explicit Array(size_t size);
  Array();
  ~Array();
  T &operator[](size_t index);
  const T &operator[](size_t index) const;
  size_t size() const;
  void resize();

 private:
  size_t _size;
  T *_pT;
  bool operator==(const Array &) const;
  Array(const Array &);
  Array &operator=(const Array &);
};

template <typename T>
class Array<T>::BadArray
{
 private:
  string _reason;
  size_t _index;

 public:
  BadArray(string reason = "", size_t index = 0) : _reason(reason), _index(index) { return; };
  ~BadArray() {};
  ostream &diagnose(ostream &os) const
  {
    os << _reason << endl;
    if (_index != 0) os << ' ' << _index;
    os << endl;
    return;
  }
};
template <typename T>
ostream &operator<<(ostream &os, typename const Array<T>::BadArray &ba)
{
  return bs.diagnose(os);
}

template <typename T>
Array<T>::Array() : _size(0), _pT(nullptr)
{
}
template <typename T>
Array<T>::Array(size_t size) : _size(size), _pT(new T[_size])
{
}
template <typename T>
Array<T>::~Array()
{
  delete[] _pT;
}
template <typename T>
T &Array<T>::operator[](size_t index)
{
  if (index >= _size) throw BadArray("Bad index: ", index);
  return _pT[index];
}
template <typename T>
const T &Array<T>::operator[](size_t index) const
{
  if (index >= _size) throw BadArray("Bad index: ", index);
  return _pT[index];
}
template <typename T>
size_t Array<T>::size() const
{
  return _size;
}
template <typename T>
void Array<T>::resize()
{
  size_t new_size = _size * 2 + 1;
  T *new_array = new T[new_size];
  for (size_t i = 0; i < _size; ++i) new_array[i] = _pT[i];
  delete[] _pT;
  _size = new_size;
  _pT = new_array;
}

template <class T, size_t n>
class Array<T[n]>
{
 public:
  Array() {}
  ~Array() {}
  T &operator[](size_t index);
  const T &operator[](size_t index) const;
  size_t size() const { return n; };

 private:
  T _ar[n];
};

template <class T, size_t n>
T &Array<T[n]>::operator[](size_t index)
{
  return _ar[index];
}

template <class T, size_t n>
const T &Array<T[n]>::operator[](size_t index) const
{
  return _ar[index];
}

void isort(int a[], size_t size)
{
  for (int i = 0; i < size; ++i)
  {
    int j = i;
    for (int k = i + 1; k < size; ++k)
      if (a[j] < a[k])
      {
        int tmp = a[j];
        a[j] = a[k];
        a[k] = tmp;
      }
  }
}

void sort(int a[], size_t size)
{
  for (int *i = a; i < a + size - 1; ++i)
  {
    int *j = i;
    for (int *k = i + 1; k < a + size; ++k)
      if (*j < *k)
      {
        int tmp = *j;
        *j = *k;
        *k = tmp;
      }
  }
}
