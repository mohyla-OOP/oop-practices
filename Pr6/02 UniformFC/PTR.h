#pragma once
#include <map>
#include <string>
#include "Complex.h"

using PMF = Complex & (Complex::*)(const Complex&);
using OpTable = std::map<std::string, PMF>;

Complex& apply_op(const OpTable& table,
    const std::string& opname,
    Complex& a, const Complex& b)
{
    if (auto it = table.find(opname); it != table.end())
        return std::invoke(it->second, a, b);
    throw std::runtime_error("Unknown operation: " + opname);
}

template<class Table>
Complex& apply_op_generic(const Table& table,
    const std::string& opname,
    Complex& a, const Complex& b)
{
    if (auto it = table.find(opname); it != table.end())
        return std::invoke(it->second, a, b);
    throw std::runtime_error("Unknown operation: " + opname);
}

template<class Table, class T>
T& apply_op_generic(const Table& table,
    const std::string& opname,
    T& a, const T& b)
{
    if (auto it = table.find(opname); it != table.end())
        return std::invoke(it->second, a, b);
    throw std::runtime_error("Unknown operation: " + opname);
}

template<class Table, class T>
T& apply_op_generic_range(const Table& table,
    std::string_view opname,
    T& a,
    const T& b)
{
    auto it = std::ranges::find_if(table,
        [&](auto const& e) { return e.first == opname; });

    if (it != table.end())
        return std::invoke(it->second, a, b);

    throw std::runtime_error("Unknown operation");
}


