#pragma once
template <typename T>
void swap(T &a, T &b)
{
  T tmp = a;
  a = b;
  b = tmp;
}

namespace Dynamic
{
  template <typename T>
  class Array
  {
   private:
    std::size_t _n;
    T *_v;

   public:
    explicit Array(std::size_t n) : _n(n), _v(new T[_n]{}) {}
    ~Array() { delete[] _v; };
    int size() const { return _n; }
    T operator[](std::size_t i) const { return _v[i]; }
    T &operator[](std::size_t i) { return _v[i]; }
    void resize(std::size_t k)
    {
      Array<T> tmp(_n * k);
      for (std::size_t i = 0; i < _n; ++i) tmp._v[i] = _v[i];
      std::swap(_v, tmp._v);
      std::swap(_n, tmp._n);
    }
  };
}  // namespace Dynamic
