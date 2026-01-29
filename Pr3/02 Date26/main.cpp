#include <iostream>
#include <cassert>
#include "date.h"

int main() {
    //Поточна дата
    std::cout << Date() << std::endl;

    // Базові конструкти
    Date a(2024, Month::feb, 28);
    std::cout << "a = " << a << "\n"; // 2024-02-28

    // Наступний день (високосний рік)
    Date b = a.next_day();
    std::cout << "b = " << b << "\n"; // 2024-02-29
    assert(b == Date(2024, Month::feb, 29));

    // Попередній день (високосний рік)
    Date c(2024, Month::mar, 1);
    b = c.prev_day();
    std::cout << "b = " << b << "\n"; // 2024-02-29
    assert(b == Date(2024, Month::feb, 29));


    // Перехід через кінець місяця і року
    c=Date(2000, 12, 31);
    c.add_days(1);
    std::cout << "c = " << c << "\n"; // 2001-01-01
    assert(c == Date(2001, 1, 1));

    // Віднімання днів
    Date d(2025, 3, 1);
    d.add_days(-1);
    std::cout << "d = " << d << "\n"; // 2025-02-28 (2025 не високосний)
    assert(d == Date(2025, 2, 28));

    // Парсинг
    Date e = parse_yyy_ymm_dd("1999-11-30");
    std::cout << "e = " << e << "\n"; // 1999-11-30
    assert(e == Date(1999, 11, 30));

    // Перевірка порівнянь
    assert(Date(2020, 1, 1) < Date(2020, 1, 2));
    assert(Date(2019, 12, 31) < Date(2020, 1, 1));
    assert(Date(2020, 3, 1) > Date(2020, 2, 29));

    std::cout << "All basic tests passed.\n";
    return 0;
}
