import office;
#include <iostream>

int main()
{
	Developer a{ "Ivan", 3 };
	Tester b{ "Anna", true };
	Accountant c{ "Olga" };
	Project pr{ "XO", 100'000 };

	pay_salary(a);
	std::cout << a.salary << std::endl;
}
