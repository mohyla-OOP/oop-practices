#pragma once
template<class T>
void copyswap(T& a, T& b)
{
    T tmp(a);   // two copies of a
    a = b;      // two copies of b
    b = tmp;    // two copies of a
}
template<class T>
void moveswap(T& a, T& b)
{
    T tmp = std::move(a);   // single copy of a
    a = std::move(b);       // single copy of b
    b = std::move(tmp);     // single copy of a
}
