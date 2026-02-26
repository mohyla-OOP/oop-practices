#ifndef _Array_h
#define _Array_h

#define _DEBUG_

template <class ArrayElem>
class Array
{
 public:
  class BadArray
  {
  };
  Array(int sz);
  Array(const Array &);
  ~Array();
  Array &operator=(const Array &a);
  ArrayElem &operator[](int index);
  const ArrayElem &operator[](int index) const;
  int size() const;

 private:
  int _size;
  ArrayElem *ia;
};
template <class Elem>
bool operator==(const Array<Elem> &, const Array<Elem> &);
template <class Elem>
bool operator!=(const Array<Elem> &, const Array<Elem> &);
#endif