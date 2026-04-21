#include <complex>
#include <fstream>

#include "Template.h"

std::ofstream os("out.txt");

int main(int argc, char *argv[])
{
  auto s = sum(-7, 3.7f, 9u, -2.6);
  std::cout << "s is " << s << " and its type is " << typeid(s).name() << '\n';

  auto s2 = sum(-7, 3.7f, 9u, -42.6);
  std::cout << "s2 is " << s2 << " and its type is " << typeid(s2).name() << '\n';

  auto m = minimum(-7, 3.7f, 9u, -2.6);
  std::cout << "m is " << m << " and its type is " << typeid(m).name() << '\n';
  os << "m1 =" << m << ':' << typeid(m).name() << '\n';

  auto m1 = my_minimum(-7, 3.7f, 9u, -2.6);
  std::cout << "m1 is " << m1 << " and its type is " << typeid(m1).name() << '\n';

  auto m2 = minimum(-7, 3.7f, 9u, -42.6L);
  std::cout << "m2 is " << m2 << " and its type is " << typeid(m2).name() << '\n';
  os << "m21 =" << m2 << ':' << typeid(m2).name() << '\n';

  auto ss = sum(-7, 3.7f);
  std::cout << "ss is " << ss << " and its type is " << typeid(ss).name() << '\n';
  os << "ss =" << ss << ':' << typeid(ss).name() << '\n';

  auto sss = sum(-7, 3.7f, 9u, -2.6);
  std::cout << "s is " << s << " and its type is " << typeid(s).name() << '\n';
  os << "s  =" << s << ':' << typeid(s).name() << '\n';

  auto ss2 = sum(-7, 3.7f, 9u, -42.6);
  std::cout << "s2 is " << s2 << " and its type is " << typeid(s2).name() << '\n';
  os << "s2 =" << s2 << ':' << typeid(s2).name() << '\n';

  auto s4 = sum('a', (-1), 1u);
  std::cout << "s4 is " << s4 << " and its type is " << typeid(s4).name() << '\n';
  os << "s4 =" << s4 << ':' << typeid(s4).name() << '\n';
  {
    auto s4 = sum('a', true);
    std::cout << "s4 is " << s4 << " and its type is " << typeid(s4).name() << '\n';
    os << "s4 =" << s4 << ':' << typeid(s4).name() << '\n';
    std::cout << sizeof(bool) << std::endl;
  }
  std::cout << min_magnitude(1, -10) << std::endl;
  // std::cout << min_magnitude(1u, -10) << std::endl;
  std::cout << min_magnitude(2.0, -10.) << std::endl;
  std::cout << min_magnitude(std::complex<double>(1, 1), std::complex<double>(2, 2)) << std::endl;

  std::cout << Count<int, int, double>::_value << std::endl;
  std::cout << Count<int, std::string, char, int, int, float, unsigned int, bool>::_value << std::endl;

  std::cout << count_ints<int, int, double>() << std::endl;
  std::cout << count_ints<int, std::string, char, int, int, float, unsigned int, bool>() << std::endl;

  std::cout << count<int, int, double>() << std::endl;
  std::cout << count<int, std::string, char, int, int, float, unsigned int, bool>() << std::endl;

  {
    int k = 2;
    int &rk = k;
    std::cout << &k << ',' << &(k) << ',' << &rk << std::endl;
  }

  return 0;
}
