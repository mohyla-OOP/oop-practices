#pragma once
#include <iostream>
#include <utility>

struct Point2D {
    double x{};
    double y{};
};

class Triangle {
public:
    Triangle(Point2D a, Point2D b, Point2D c)
        : _a(a), _b(b), _c(c) {
    }

    Triangle& shift(const Point2D& d) {
        _a.x += d.x; _a.y += d.y;
        _b.x += d.x; _b.y += d.y;
        _c.x += d.x; _c.y += d.y;
        return *this;
    }

    //TODO: 1: check implementation of mirrorX
    //TODO: HW: implement mirrorY
    Triangle& mirrorX() {
        _a.y = -_a.y;
        _b.y = -_b.y;
        _c.y = -_c.y;
        return *this;
    }

    Triangle& scale(double s) {
        _a.x *= s; _a.y *= s;
        _b.x *= s; _b.y *= s;
        _c.x *= s; _c.y *= s;
        return *this;
    }

    Triangle& swapAB() {
        std::swap(_a, _b);
        //TODO: 2: Why return *this;?
        return *this;
    }

    void print() const {
        std::cout << "A(" << _a.x << "," << _a.y << ")\n";
        std::cout << "B(" << _b.x << "," << _b.y << ")\n";
        std::cout << "C(" << _c.x << "," << _c.y << ")\n\n";
    }

private:
    Point2D _a, _b, _c;
};

template<typename F>
void apply(Triangle& t, F f) {
    std::invoke(f, t);
}
