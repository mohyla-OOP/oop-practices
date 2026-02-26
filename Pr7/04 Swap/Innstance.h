#pragma once

template <typename T>
class SafeValue
{
  T _value;

 public:
  explicit SafeValue(T v) : _value(std::move(v)) {}

  const T &get() const { return _value; }

  void set(T v) { _value = std::move(v); }

  void swap(SafeValue &other)
  {
    using std::swap;
    swap(_value, other._value);
  }
};
