#pragma once
#include <concepts>

#include "Iterator.h"

template <typename It>
concept MyIterator = requires(It it) {
  { *it };  // можна розіменувати
  { ++it } -> std::same_as<It &>;
  { it != it } -> std::convertible_to<bool>;
};

template <MyIterator It>
void my_sort(It begin, It end)
{
  for (It i = begin; i != end; ++i)
  {
    for (It j = i; j != end; ++j)
    {
      if (*j < *i)
      {
        auto tmp = *i;
        *i = *j;
        *j = tmp;
      }
    }
  }
}
