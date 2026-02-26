#include <algorithm>
#include <initializer_list>
#include <iostream>

#include "Array.h"

int main()
{
  {
    Array<double> dar{1, 2, 3, 4};
    try
    {
      dar[100];
    }
    catch (const std::runtime_error &error)
    {
      std::cout << error.what() << std::endl;
    }
    std::cout << dar.size() << std::endl;
    dar.resize(2);
    std::cout << dar.size() << std::endl;
  }
  {
    Array<double[]> dar{1, 2, 3, 4, 7, 8};
    try
    {
      dar[100];
    }
    catch (const std::runtime_error &error)
    {
      std::cout << error.what() << std::endl;
    }
    std::cout << dar.size() << std::endl;
    dar.resize(2);
    std::cout << dar.size() << std::endl;
  }
}