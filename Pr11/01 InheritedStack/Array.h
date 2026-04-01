#pragma once
template <class Elem>
class Array
{
 public:
  class BadArray;
  Array(size_t sz);
  Array(const Array &) = delete;
  Array &operator=(const Array &a) = delete;
  virtual ~Array();

  Elem &operator[](size_t index);
  const Elem &operator[](size_t index) const;
  size_t size() const;

 private:
  size_t _size;
  Elem *_ar;
};

template <class Elem>
class Array<Elem>::BadArray
{
 public:
  BadArray(size_t index) : _index(index) {};

 private:
  size_t _index;
};

template <class Elem>
Array<Elem>::Array(size_t sz) : _size(sz), _ar(new Elem[_size])
{
#ifndef NDEBUG_
  std::cout << "Constructor Array " << sz << std::endl;
#endif
};
template <class Elem>
Array<Elem>::~Array()
{
#ifndef NDEBUG_
  std::cout << "Destructor Array" << std::endl;
#endif
  delete[] _ar;
};
template <class Elem>
Elem &Array<Elem>::operator[](size_t index)
{
  if (index >= _size) throw BadArray(index);
  return _ar[index];
}
template <class Elem>
const Elem &Array<Elem>::operator[](size_t index) const
{
  if (index >= _size) throw BadArray(index);
  return _ar[index];
}
template <class Elem>
size_t Array<Elem>::size() const
{
  return _size;
}
