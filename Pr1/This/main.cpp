#include <cmath>
#include <iostream>

#if 1
struct Point { 
    double _x=0, _y=0;
  
    double dist(Point other) const {
        return hypot(_x - other._x, _y - other._y);
    }
};

double dist(Point a, Point b) {
    return hypot(a._x - b._x, a._y - b._y);
}
int main() {
    Point u, v;
    auto d = dist(u, v);
    d = u.dist(v);
}
#endif
#if 0
struct Point {
    double _x = 0, _y = 0;

    double dist(this Point& a, Point& b) {
        return hypot(a._x - b._x, a._y - b._y);
    }
    inline double& x(this Point& self )
        { return self._x; }
};
int main() {
    Point u{ 0,3 }, v{ 4,0 };
    auto d = u.dist(v);
    std::cout << d << std::endl;
}
#endif
