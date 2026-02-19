#pragma once
#include <vector>
#include <functional>
#include "Complex.h"

struct SomeUniqueCompilerGeneratedType {
    Complex& operator()(Complex&, const Complex&) const;
};


using Op = Complex & (Complex&, const Complex&);

std::vector<std::pair<std::string, std::function<Op>>> table = {
    { "+=", [](auto& a, auto const& b) -> Complex& { return a += b; } },
    { "-=", [](auto& a, auto const& b) -> Complex& { return a -= b; } },
    { "*=", [](auto& a, auto const& b) -> Complex& { return a *= b; } },
    { "/=", [](auto& a, auto const& b) -> Complex& { return a /= b; } }
};


template<class T>
T& apply(const auto& table,
    std::string_view name,
    T& a,
    const T& b)
{
    auto it = std::ranges::find_if(table,
        [&](auto const& e) { return e.first == name; });

    if (it == table.end())
        throw std::runtime_error("Unknown op");

    return it->second(a, b);
}
