
#ifndef _EMPLOYER_H_
#define _EMPLOYER_H_
// Home task: void Employer::fire(const int i)
#include "Accountant.h"

class Person;
class Position;
class Employee;

class Employer
{
	friend void Accountant::payroll(const Employee &) const;
	friend void Accountant::payroll() const;
private:
	struct Staff
	{
		Employee * _pemployee;
		bool _free;
	};
	Accountant * _accountant;
	const Person & _me;

	int _volume;
	// pimpl
	Staff * _office;

	Employer& operator=(const Employer&) = delete;
	Employer(const Employer&) = delete;

public:
	Employer(const Person & employer, const int volume, const Person & accountant);
	~Employer();
	const Accountant & myAccountant();
	void hire(const Person &, const Position &);
	Staff& getPosition(int i);
	bool free(int i) const;
	const Employee& _pemployee(int i) const;
	void fire(const int);
	void pay() const;
};

#endif
