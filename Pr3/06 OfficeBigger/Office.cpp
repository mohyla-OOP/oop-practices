module;
#include <string>
#include <utility>

module office;

void pay_salary(Developer& d) {
    // інваріант: level >= 1
    d.salary += 1000 * d.level;
}
void pay_salary(Tester& t) {
    t.salary += t.automation ? 1500 : 1000;
}
void pay_salary(Accountant& a) {
    a.salary += 2000;
}
Developer hire_developer(std::string name, int level) {
    return Developer{ std::move(name), level, 0.0 };
}
void fire(Developer& d) {
    d.salary = 0.0;
}
void assign(Project& p, Developer& d) {
    p.budget -= d.salary;
}