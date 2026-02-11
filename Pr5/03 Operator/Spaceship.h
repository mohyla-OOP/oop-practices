#pragma once
#include <iostream>
using namespace std;
// Default comparisons
template<class T1, class T2>
struct Compare {
    T1 _x1;
    T2 _x2;
    auto operator<=>(const Compare&) const = default;
};
template<class T1, class T2>
ostream& operator<<(ostream& os, const Compare<T1, T2>& a)
{
   return os << '(' << a._x1 << ',' << a._x2 << ')';
}
template<class T1, class T2>
class CCompare {
    T1 _x1;
    T2 _x2;
    friend auto operator<=>(const CCompare&, const CCompare&) = default;
public:
    CCompare(const T1& x1, const T2& x2) :_x1(x1), _x2(x2) {}
    const T1& x1() const { return _x1; }
    const T2& x2() const { return _x2; }
};
template<class T1, class T2>
ostream& operator<<(ostream& os, const CCompare<T1, T2>& a)
{
    return os << '(' << a.x1() << ',' << a.x2() << ')';
}
