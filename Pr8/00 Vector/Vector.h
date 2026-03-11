#pragma once
template <std::size_t size>  // TODO: 11: 2-14 lines, what is it?
class Vector
{
  // TODO: 8: What is the vector, and which data type it can store?
 private:
  double _v[size]{};  // TODO: 9: what is the data structure?
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

// TODO: 10: add new vector3.h and move 41-45 lines to it. Why it doesn't work?
template <std::size_t size>  // TODO: 13: Remove this
class Vector;
template <>  // TODO: 12: what is it?
struct Vector<3>
{
 public:
  double _x{}, _y{}, _z{};
};