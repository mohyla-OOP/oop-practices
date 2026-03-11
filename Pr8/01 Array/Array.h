#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <string>

struct BadIndex
{
  std::size_t i;
  std::string reason;

  BadIndex(std::size_t ii, std::string r = "bad index") : i(ii), reason(r) {}
};

inline std::ostream &operator<<(std::ostream &os, const BadIndex &e) { return os << e.reason << ": " << e.i; }

template <class T>
class Array
{
  std::size_t n{};
  T *v{};

 public:
  Array() = default;

  explicit Array(std::size_t m) : n(m), v(new T[m]{})
  {  // TODO: 4: remove default initialization here, restart and check the console output
  }

  Array(std::initializer_list<T> init) : Array(init.size()) { std::copy(init.begin(), init.end(), v); }

  ~Array() { delete[] v; }

  Array(const Array &a) : Array(a.n) { std::copy(a.v, a.v + n, v); }

  Array(Array &&a) noexcept : n(a.n), v(a.v)
  {
    a.n = 0;
    a.v = nullptr;
  }

  Array &operator=(Array a)  // copy-swap trick
  {
    std::swap(n, a.n);
    std::swap(v, a.v);
    return *this;
  }

  std::size_t size() const { return n; }

  T &operator[](std::size_t i)
  {
    if (i >= n) throw BadIndex(i);
    return v[i];
  }

  const T &operator[](std::size_t i) const
  {
    if (i >= n) throw BadIndex(i);
    return v[i];
  }

  T *begin() { return v; }
  T *end() { return v + n; }

  const T *begin() const { return v; }
  const T *end() const { return v + n; }

  void resize(std::size_t m)
  {
    Array tmp(m);

    std::size_t k = std::min(n, m);

    for (std::size_t i = 0; i < k; ++i) tmp.v[i] = v[i];

    std::swap(n, tmp.n);
    std::swap(v, tmp.v);
  }
};
template <class T>
std::ostream &operator<<(std::ostream &os, const Array<T> &s)
{
  os << '(';
  for (std::size_t i = 0; i < s.size() - 1; ++i) os << s[i] << ',';
  return os << s[s.size() - 1] << ')';
}
