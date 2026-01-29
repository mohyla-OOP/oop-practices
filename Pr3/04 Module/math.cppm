// Module math C++20
// Definition

module;
#include <cmath>

export module math;

export bool is_prime(long i);

long max_check(long i) { return std::sqrt(i) + 1; }

bool is_prime(long i)
{
    if (i == 1)
        return false;
    if (i % 2 == 0)
        return i == 2;
    for (long j = 3; j < max_check(i); j += 2)
        if (i % j == 0)
            return false;
    return true;
}
