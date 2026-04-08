#include <iostream>
#include <string>
#include <vector>

#include "Array.h"
#include "Concept.h"
#include "Iterator.h"
#include "Sequence.h"

int main()
{
  const std::size_t n = 10;
  {
    int arr[n] = {};

    Iterator<int> begin(arr);
    Iterator<int> end(arr + n);

    for (auto it = begin; it != end; ++it)
    {
      std::cout << *it << " ";
    }
    std::cout << std::endl;

    auto it = begin;
    while (it != end)
    {
      *it = rand() % 100;  // наповнення
      ++it;
    }

    sort(begin, end);
    for (auto it = begin; it != end; ++it)
    {
      std::cout << *it << " ";
    }
    std::cout << std::endl;

    sort(begin, end, [](auto a, auto b) { return a > b; });
    for (auto it = begin; it != end; ++it)
    {
      std::cout << *it << " ";
    }
    std::cout << std::endl;

    my_sort(begin, end);
    for (auto it = begin; it != end; ++it)
    {
      std::cout << *it << " ";
    }
    std::cout << "\n---------------" << std::endl;
  }
  /*int x = 5;
  my_sort(x, x);*/
  {
    std::vector<int> a(n);
    std::generate(a.begin(), a.end(), [] { return rand() % 100; });
    ::sort(a.begin(), a.end());
    for (auto x : a)
    {
      std::cout << x << ' ';
    }
    std::cout << "\n-------------" << std::endl;
  }
  {
    std::vector<std::string> s = {"aa", "bb", "ab", "bcde", "bxy"};
    ::sort(s.begin(), s.end());
    for (auto x : s)
    {
      std::cout << x << ' ';
    }
    std::cout << "\n-------------" << std::endl;
  }
  {
    Array<double> a(n);
    std::generate(a.begin(), a.end(), [] { return 2 * rand() % 100; });
    ::sort(a.begin(), a.end());
    for (auto x : a)
    {
      std::cout << x << ' ';
    }
    std::cout << "\n-------------" << std::endl;
  }
  {
    Array<std::string> a = {"00", "aa", "bb", "ab", "bcde", "bxy"};
    Iterator<std::string> begin = a.begin();
    Iterator<std::string> end = a.end();
    ::sort(begin, end);
    for (auto x : a)
    {
      std::cout << x << ' ';
    }
    std::cout << "\n-------------" << std::endl;
  }
  {
    Sequence<double> a = {34, 25, 978, 245, 8765, 45787};
    sort(begin(a), end(a));
    for (auto x : a)
    {
      std::cout << x << ' ';
    }
    std::cout << "\n-------------" << std::endl;
  }
  {
    Array<std::string> a = {"tra_ta-ta", "abracadabra", "bb", "ab", "bcde", "bxy"};
    my_sort(a, [](auto a, auto b) { return a > b; });
    std::cout << "\n-------------" << std::endl;
  }
}
