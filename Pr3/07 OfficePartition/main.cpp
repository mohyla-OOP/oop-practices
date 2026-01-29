import office;
#include <iostream>

int main() {
    Employee John{ 1000 };
    std::cout << John.salary() << '\n';
    promote(John, 200);
    std::cout << John.salary() << '\n';
    Employee Ivan{2000 };
    std::cout << Ivan.salary() << '\n';
    // Ivan.salary(3000);
    promote(Ivan, 250);
    std::cout << Ivan.salary() << '\n';

}
