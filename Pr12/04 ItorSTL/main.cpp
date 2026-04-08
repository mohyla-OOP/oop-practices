#include <iostream>
using std::cout;
using std::endl;
#include <complex>
#include <list>
#include <vector>

int main()
{
  {
    double vec[]{1, 2, 3, 4, 5};
    cout << "C-array can be traversed with implicit iterator:" << endl;
    for (const auto &el : vec)
    {
      cout << el << " ";
    }
    cout << endl;
  }
  {
    std::vector<int> vec(/*std::initializer_list<int> */ {1, 2, 3, 4, 5});
    cout << "std::vector can be traversed with implicit iterator:" << endl;
    for (const auto &el : vec)
    {
      cout << el << " ";
    }
    cout << endl;
  }
  {
    std::vector<int> vec(/*std::initializer_list<int> */ {1, 2, 3, 4, 5});
    cout << "std::vector can be processed with implicit input-output iterator:" << endl;
    for (auto &el : vec)
    {
      cout << ++el << " ";
    }
    cout << endl;
  }
  {
    std::vector<int> vec({1, 2, 3, 4, 5});
    cout << "individual iterator:" << endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
      cout << ++*it << " ";
    }
    cout << endl;
  }
  {
    std::vector<std::complex<double>> vec({1, 2, 3, 4, 5});
    cout << "std::vector<std::complex<double> traversed" << endl;
    for (const auto &el : vec)
    {
      cout << el << " ";
    }
    cout << endl;
  }
  {
    std::vector<std::complex<double>> vec({1, 2, 3, 4, 5});
    cout << "std::vector<std::complex<double> processed" << endl;
    for (auto &el : vec)
    {
      cout << (el = std::complex<double>(0, real(el))) << " ";
    }
    cout << endl;
  }
  {
    std::complex<double> vec[]{1, 2, 3, 4, 5};
    cout << "C-array of complex can also be traversed with implicit iterator:" << endl;
    for (const auto &el : vec)
    {
      cout << el << " ";
    }
    cout << endl;
  }
  {
    std::vector<int> vec({1, 2, 3, 4, 5});
    cout << "individual iterator:" << endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
      cout << *it << " ";
    }
    cout << endl;
  }
  {
    std::vector<std::complex<double>> vec({1, 2, 3, 4, 5});
    for (std::vector<std::complex<double>>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
      cout << *it << " ";
    }
    cout << endl;
  }
  {
    std::vector<int> vec({1, 2, 3, 4, 5});
    cout << "Reverse iterator:" << endl;
    for (std::vector<int>::reverse_iterator rIt = vec.rbegin(); rIt != vec.rend(); ++rIt)
    {
      cout << *rIt << " ";
    }
    cout << endl;
  }
  {
    std::list<std::string> li{"one", "two", "three"};
    cout << "List values: " << endl;
    for (const auto &el : li)
    {
      std::cout << el << " ";
    }
    cout << endl;
  }
  {
    std::list<std::string> li{"one", "two", "three"};
    cout << "List Reverse iterator : " << endl;
    ;
    for (std::list<std::string>::reverse_iterator rIt = li.rbegin(); rIt != li.rend(); ++rIt)
    {
      cout << *rIt << " ";
    }
    cout << endl;
  }
  {
    std::list<std::string> li{"one", "two", "three"};
    std::vector<std::string> vec(std::make_move_iterator(li.begin()), std::make_move_iterator(li.end()));
    cout << "Moved list to vector " << endl;
    for (const auto &el : vec)
    {
      cout << el << " ";
    }
    cout << endl;
    cout << "List values: empty" << std::endl;
    for (const auto &el : li)
    {
      cout << el << " ";
    }
    cout << endl;
  }
}
