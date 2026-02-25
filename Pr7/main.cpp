
////lib / contmove.cpp
////
////The following code example is taken from the book
////C++ Move Semantics - The Complete Guide by Nicolai M.Josuttis, Leanpub, 2020
////The code is licensed under a Creative Commons Attribution 4.0 International License.Creative Commons License
//// raw code

#include <algorithm>
#include <array>
#include <chrono>
#include <cstdlib>  // for std::atoi()
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
std::ofstream resos("results.txt");
template <int numElems, typename T>
void test(int numLoops, const T &initialVal)
{
  // initialize durations:
  using millisecondsDouble = std::chrono::duration<double, std::milli>;
  millisecondsDouble arrCopy{0}, arrMove{0}, vecCopy{0}, vecMove{0};

  // declare source objects:
  std::array<T, numElems> arr;
  std::vector<T> vec;

  // loop several times over:
  for (int i = 0; i < numLoops; ++i)
  {
    // (re-)initialize source objects:
    std::fill(arr.begin(), arr.end(), initialVal);
    vec.resize(numElems);
    std::fill(vec.begin(), vec.end(), initialVal);

    // measure copy and move for arrays:
    auto t0 = std::chrono::steady_clock::now();
    auto arr1{arr};  // copies all elements/values
    auto t1 = std::chrono::steady_clock::now();
    auto arr2{std::move(arr)};  // moves all elements/values
    auto t2 = std::chrono::steady_clock::now();
    arrCopy += t1 - t0;
    arrMove += t2 - t1;

    // measure copy and move for vectors:
    auto t3 = std::chrono::steady_clock::now();
    auto vec1{vec};  // copies all elements/values
    auto t4 = std::chrono::steady_clock::now();
    auto vec2{std::move(vec)};  // moves elements/values as a whole
    auto t5 = std::chrono::steady_clock::now();
    vecCopy += t4 - t3;
    vecMove += t5 - t4;

    // disable warning about destinations never used:
    if (arr1[0] != arr2[0]) std::cout << "oops" << '\n';
    if (vec1[0] != vec2[0]) std::cout << "oops" << '\n';
  }

  // print measured durations:
  std::cout << " array copy:  " << arrCopy.count() << '\n';
  std::cout << "       move:  " << arrMove.count() << '\n';
  std::cout << " vector copy: " << vecCopy.count() << '\n';
  std::cout << "        move: " << vecMove.count() << '\n';

  resos << " array copy:  " << arrCopy.count() << '\n';
  resos << "       move:  " << arrMove.count() << '\n';
  resos << " vector copy: " << vecCopy.count() << '\n';
  resos << "        move: " << vecMove.count() << '\n';
}

std::list<std::string> createAndInsert(std::list<std::string> *plist)
{
  std::list<std::string> coll;
  coll.push_back(std::string("first"));
  coll.push_back(std::string("second"));
  coll.push_back(std::string("third"));
  plist = &coll;

  return std::move(coll);  // move constructor if not optimized away
}

int main(int argc, char **argv)
{
  std::list<std::string> *plist = nullptr;
  // Standard containers
  std::list<std::string> list;
  list = createAndInsert(plist);
  for (std::string s : list)
  {
    std::cout << s << ' ' << std::endl;
    resos << s << ' ' << std::endl;
  }
  plist = &list;
  std::list<std::string> list1 = std::move(list);

  std::array<std::string, 3> arr{"first", "second", "third"};
  std::array<std::string, 3> arr1{"first1", "second1", "third1"};
  arr1 = std::move(arr);
  for (std::string s : arr)
  {
    std::cout << s << ' ' << std::endl;
    resos << s << ' ' << std::endl;
  }

  std::array<double, 3> darr{1, 2, 3};
  std::array<double, 3> darr1{4, 5, 6};
  darr1 = std::move(darr);
  for (double s : darr)
  {
    std::cout << s << ' ' << std::endl;
    resos << s << ' ' << std::endl;
  }
  int numLoops = 1'000;
  if (argc > 1)
  {
    numLoops = std::atoi(argv[1]);
  }

  std::cout << "double:\n";
  test<10'000>(numLoops, 42.7);

  std::cout << "short string:\n";
  test<1'000>(numLoops, std::string{"short"});

  std::cout << "long string:\n";
  test<1'000>(numLoops, std::string{"a very long string to avoid small string optimization"});
}
