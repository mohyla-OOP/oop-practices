module;

module office;

Employee::Employee(double salary) : salary_(salary) {}
double Employee::salary() const { return salary_; }
void Employee::set_salary(double s) { salary_ = s; }

void promote(Employee& e, double delta) {
    e.set_salary(e.salary() + delta);  // є friend-доступ до закритого set_salary
}