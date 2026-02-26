#pragma once
// TODO: 6: check the policy, what is it doing
template <typename T>
struct NoDeletePolicy
{
  static void doDelete(const T &) {}
};

template <typename T>
struct PtrDeletePolicy
{
  static void doDelete(T &ptr)
  {
    delete ptr;
    ptr = 0;
  }
};

template <typename T>
struct ArrayDeletePolicy
{
  static void doDelete(T &ptr)
  {
    delete[] ptr;
    ptr = 0;
  }
};
