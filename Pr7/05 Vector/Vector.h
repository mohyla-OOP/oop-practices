#pragma once
template <std::size_t size>
class Vector
{
 private:
  double _v[size]{};

 public:
  explicit Vector() {}
  ~Vector() {};
  Vector &operator=(const Vector &);
  double operator[](int) const;
  double &operator[](int);
  Vector &operator+=(const Vector &);
};

template <std::size_t size>
Vector<size> operator+(const Vector<size> &, const Vector<size> &);
template <std::size_t size>
double operator*(const Vector<size> &u, const Vector<size> &v)
{
  double res = 0;
  for (int i = 0; i < size; i++) res += u[i] * v[i];
  return res;
}
template <std::size_t size>
Vector<size> &Vector<size>::operator=(const Vector<size> &vec)
{
  //	Чи потрібна тепер ця перевірка?
  //	if (this==&vec)
  //		return *this;
  for (int i = 0; i < size; i++) _v[i] = vec._v[i];
  return *this;
}

template <std::size_t size>
class Vector;
template <>
struct Vector<3>
{
 public:
  double _x{}, _y{}, _z{};
};