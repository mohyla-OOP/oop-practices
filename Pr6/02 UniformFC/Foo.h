#pragma once
#pragma once
#include <functional>
#include <iostream>
struct Foo
{
    Foo(int num) : num_(num) {}
    void print_add(int i) const {
        std::cout << num_ + i << '\n';
    }
    int num_;
};
