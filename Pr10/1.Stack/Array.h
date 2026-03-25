#ifndef _Array_h
#define _Array_h

template <class Elem>
class Array
{
 public:
  class BadArray
  {
   public:
    BadArray(size_t index) : _index(index) {};

   private:
    size_t _index;
  };
  Array(int sz) : _size(sz), _ar(new Elem[_size])
  {
#ifndef NDEBUG_
    cout << "Constructor Array " << sz << endl;
#endif
  };
  Array(const Array &) = delete;
  Array &operator=(const Array &a) = delete;
  virtual ~Array()
  {
#ifndef NDEBUG_
    cout << "Destructor Array" << endl;
#endif
    delete[] _ar;
  };
  Elem &operator[](int index)
  {
    if (index >= _size) throw BadArray(index);
    return _ar[index];
  }
  const Elem &operator[](int index) const
  {
    if (index >= _size) throw BadArray(index);
    return _ar[index];
  }
  int size() const { return _size; }

 private:
  int _size;
  // protected:
  Elem *_ar;
};

#endif