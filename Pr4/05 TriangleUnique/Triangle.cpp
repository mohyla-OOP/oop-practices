#include "Triangle.h"
#include <ostream>

std::ofstream Triangle::out_("Triangle.txt");
int Triangle::call_count_ = 0;

Triangle::Triangle(double x1, double y1,
    double x2, double y2,
    double x3, double y3)
    : a_(x1, y1), b_(x2, y2), c_(x3, y3),
    ab_(nullptr), bc_(nullptr), ca_(nullptr)
{
    ++call_count_;
    // Same style as your original: assert non-degenerate after construction
    assert(area() != 0.0); // uses lazy sides underneath
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
    : a_(a), b_(b), c_(c),
    ab_(nullptr), bc_(nullptr), ca_(nullptr)
{
    ++call_count_;
 }

// Copy-construct: copy vertices; do not copy the side caches (lazy rebuild)
Triangle::Triangle(const Triangle& rhs)
    : a_(rhs.a_), b_(rhs.b_), c_(rhs.c_),
    ab_(nullptr), bc_(nullptr), ca_(nullptr)
{
    ++call_count_;
}

// Sides (lazy, with unique_ptr)
const Segment& Triangle::side_a() const {
    ++call_count_;
    if (!bc_) bc_ = std::make_unique<Segment>(b_, c_);
    return *bc_;
}
const Segment& Triangle::side_b() const {
    ++call_count_;
    if (!ca_) ca_ = std::make_unique<Segment>(c_, a_);
    return *ca_;
}
const Segment& Triangle::side_c() const {
    ++call_count_;
    if (!ab_) ab_ = std::make_unique<Segment>(a_, b_);
    return *ab_;
}

// Measures
double Triangle::length_a() const { ++call_count_; return side_a().length(); }
double Triangle::length_b() const { ++call_count_; return side_b().length(); }
double Triangle::length_c() const { ++call_count_; return side_c().length(); }

double Triangle::perimeter() const {
    ++call_count_;
    return length_a() + length_b() + length_c();
}

double Triangle::area() const {
    ++call_count_;
    // Keep your original style: 0.5 * |BC| * distance(A, BC)
    return 0.5 * length_a() * side_a().distance(apexA());
}

// I/O
std::ostream& Triangle::show(std::ostream& os) const {
    os << "Triangle: " << apexA() << apexB() << apexC() << '\n';
    os << side_a();
    os << side_b();
    os << side_c();
    os << "perimeter " << perimeter() << '\n';
    os << "area " << area() << "\n\n";
    return os;
}
int Triangle::epilog() {
    out_ << "N calls " << call_count_ << '\n';
    return call_count_;
}
std::ostream& operator<<(std::ostream& os, const Triangle& t) {
    return t.show(os);
}