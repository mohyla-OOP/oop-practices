module;

export module office;

export class Employee {
    friend void promote(Employee& e, double delta);
public:
    explicit Employee(double salary);
    double salary() const;
private:
    double salary_;
    void set_salary(double s); // лишається закритим
};

// утиліта, якій дозволено міняти зарплату (через friendship)
export void promote(Employee& e, double delta);