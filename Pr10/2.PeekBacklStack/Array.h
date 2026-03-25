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
  Array(int sz) : _size(sz)
  {
#ifdef _DEBUG_
    cout << "Constructor Array " << sz << endl;
#endif
    ia = new ArrayElem[_size];
    if (ia) return;
    throw BadArray();
  };
  Array(const Array &)
  {
    ia = new ArrayElem[_size];
    if (ia)
    {
      for (int i = 0; i < _size; i++) ia[i] = s.ia[i];
      return;
    }
    throw BadArray();
  };
  virtual ~Array()
  {
#ifdef _DEBUG_
    cout << "Destructor Array" << endl;
#endif
    delete[] ia;
  };

  virtual bool operator==(const Array &a) const
  {
    for (int i = 0; i < _size; i++)
      if (ia[i] != a.ia[i]) return false;
    return true;
  };
  virtual bool operator!=(const Array &a) const { return !(*this == a); };

  Array &operator=(const Array &a)
  {
    if (this == &a) return *this;
    delete[] ia;
    ia = new ArrayElem[_size];
    if (ia)
    {
      for (int i = 0; i < _size; i++) ia[i] = s.ia[i];
      return *this;
    }
    throw BadArray();
  };
  ArrayElem &operator[](int index)
  {
    if (index < 0 || index >= _size) throw BadArray();
    return ia[index];
  };
  const ArrayElem &operator[](int index) const
  {
    if (index < 0 || index >= _size) throw BadArray();
    return ia[index];
  };

  int size() const { return _size; };

 private:
  int _size;

 protected:
  ArrayElem *ia;
};

#endif