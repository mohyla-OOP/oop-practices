#ifndef TRIANGLE_UNIQUE_H
#define TRIANGLE_UNIQUE_H

#include <iosfwd>
#include <memory>   // std::unique_ptr
#include <fstream>
#include <cassert>

#include "Point.h"
#include "Segment.h"

class Triangle {
private:
    static std::ofstream out_;
    static int call_count_;

    // Source of truth: vertices only
    Point a_, b_, c_;

    // Lazy-owned sides: exclusive ownership, nullable by design
    // Mapping preserved like in your original:
    //   side_a() -> _bc (Segment{b,c})
    //   side_b() -> _ca (Segment{c,a})
    //   side_c() -> _ab (Segment{a,b})
    mutable std::unique_ptr<Segment> ab_; // used by side_c()
    mutable std::unique_ptr<Segment> bc_; // used by side_a()
    mutable std::unique_ptr<Segment> ca_; // used by side_b()

public:
    Triangle(double x1 = 0, double y1 = 0,
        double x2 = 1, double y2 = 0,
        double x3 = 0, double y3 = 1);

    Triangle(const Point& a, const Point& b, const Point& c);

    // Copy ctor: copy vertices; sides are rebuilt lazily when needed
    Triangle(const Triangle&);

    // Rule of Zero: defaulted dtor/copy-assign/moves
    ~Triangle() = default;
    Triangle& operator=(const Triangle&) = default;

    // Same “assign” facade as in your codebase, delegates to operator=
   // Triangle& assign(const Triangle& rhs) { ++call_count_; *this = rhs; return *this; }

    // Accessors
    const Point& apexA() const { ++call_count_; return a_; }
    const Point& apexB() const { ++call_count_; return b_; }
    const Point& apexC() const { ++call_count_; return c_; }

    // Sides – return by reference; build lazily if needed (no new/delete)
    const Segment& side_a() const;
    const Segment& side_b() const;
    const Segment& side_c() const;

    // Measures
    double length_a() const;
    double length_b() const;
    double length_c() const;

    double perimeter() const;
    double area() const;

    std::ostream& show(std::ostream& os) const;
    static int epilog();
};

std::ostream& operator<<(std::ostream& os, const Triangle& t);

#endif // TRIANGLE_UNIQUE_H