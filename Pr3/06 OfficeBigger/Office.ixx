module;
#include <string>

export module office;

export struct Developer {
    std::string name;
    int level;          // 1..5
    double salary;
};

export struct Tester {
    std::string name;
    bool automation;
    double salary;
};

export struct Accountant {
    std::string name;
    double salary;
};

export struct Project {
    std::string title;
    double budget;
};

export void pay_salary(Developer& d);

export void pay_salary(Tester& t);

export void pay_salary(Accountant& a);

export Developer hire_developer(std::string name, int level);

export void fire(Developer& d);

export void assign(Project& p, Developer& d);