#include <vector>

#include "Types.h"

int main()
{
  std::cout << info<decltype(bool() ? std::complex<double>() : float())>() << std::endl;
  // No object created
  std::cout << sizeof(std::vector<int>().size()) << std::endl;

  int k = 2;
  int l = 3;
  double x = 3.14;
  std::cout << info<decltype(true ? k : x)>() << std::endl;
  std::cout << info<decltype(false ? k : l)>() << std::endl;

  std::cout << info<decltype(bool() ? k : x)>() << std::endl;
  std::cout << info<decltype(bool() ? int{} : double{})>() << std::endl;

  std::cout << info<my_common_type<double, std::complex<double>>::type>() << std::endl;
  std::cout << info<my_common_type<std::string, char *>::type>() << std::endl;
  // std::cout << info < my_common_type<std::string, char>::type >() << std::endl;

  std::cout << info<decltype(true ? int{} : char{})>() << std::endl;
  std::cout << info<my_common_plus_type<std::string, char>::type>() << std::endl;

  {
    double x = 2;
    double &rx = x;
    double &&rrx = 3;
    const double cx = x;

    std::cout << my_info<decltype(x)>() << std::endl;
    std::cout << my_info<decltype(rx)>() << std::endl;
    std::cout << my_info<decltype(rrx)>() << std::endl;
    std::cout << my_info<decltype(cx)>() << std::endl;

    std::cout << my_info<decltype((x))>() << std::endl;
    std::cout << my_info<decltype((cx))>() << std::endl;

    x = 10;
    (x) = 20;
    std::cout << x << std::endl;

    std::cout << my_info<decltype((1 + 2))>() << std::endl;
    std::cout << my_info<decltype(std::declval<double>() + std::declval<std::complex<double>>())>() << std::endl;
    std::cout << my_info<decltype((std::declval<double>() + std::declval<std::complex<double>>()))>() << std::endl;
  }
  {
    int x = 10;
    int &rx = x;
    (x);
    auto &r = f();  // r out of memory
    r = 10;         // UB
    std::cout << r << std::endl;
    g();                     // g() reload stack
    std::cout << r << '\n';  //  UB
  }
}