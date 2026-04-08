#include <algorithm>
#include <iostream>
#include <list>
#include <ranges>
#include <vector>

// ----------------------------
// Task 1: Basic iterator usage
// ----------------------------
void task1()
{
  std::vector<int> v = {1, 2, 3, 4, 5};

  for (auto it = v.begin(); it != v.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

// ---------------------------------------
// Task 2: const_iterator with const vector
// ---------------------------------------
void print_const(const std::vector<int> &v)
{
  for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

// ---------------------------------------
// Task 3: Iterator invalidation (fixed)
// ---------------------------------------
void task3()
{
  std::vector<int> v = {1, 2, 3, 4, 5};

  for (auto it = v.begin(); it != v.end();)
  {
    if (*it % 2 == 0)
    {
      it = v.erase(it);
    }
    else
    {
      ++it;
    }
  }

  for (auto x : v) std::cout << x << " ";
  std::cout << std::endl;
}

// ---------------------------------------
// Task 4: remove_if + erase idiom
// ---------------------------------------
void task4()
{
  std::vector<int> v = {1, 2, 3, 4, 5};

  v.erase(std::remove_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; }), v.end());

  for (auto x : v) std::cout << x << " ";
  std::cout << std::endl;
}

// ---------------------------------------
// Task 5: Generic algorithm with iterators
// ---------------------------------------
template <typename It>
void my_print(It begin, It end)
{
  for (It it = begin; it != end; ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void task5()
{
  std::list<int> l = {1, 2, 3};
  std::vector<int> v = {4, 5, 6};

  my_print(l.begin(), l.end());
  my_print(v.begin(), v.end());
}

// ---------------------------------------
// Bonus: ranges
// ---------------------------------------
void bonus()
{
  std::vector<int> v = {1, 2, 3, 4, 5};

  std::ranges::for_each(v, [](int x) { std::cout << x << " "; });
  std::cout << std::endl;
}

// ---------------------------------------
// main
// ---------------------------------------
int main()
{
  task1();

  std::vector<int> v = {10, 20, 30};
  print_const(v);

  task3();
  task4();
  task5();
  bonus();

  return 0;
}
