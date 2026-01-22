#pragma once
#include <typeinfo>
#include <iostream>

class Vector
{
private:
	size_t _n;
	double* _v;
	static size_t _freeId;
	const size_t _id;
public:
	Vector(size_t n);
	~Vector();
	Vector(const Vector& v);
	Vector(Vector&& v) noexcept;
	Vector& operator=(const Vector&)&;
	Vector& operator=(Vector&&)& noexcept;
	size_t size() const;
	double operator[](size_t)const;
	double& operator[](size_t);
	inline static size_t freeId()
	{
		return _freeId;
	}
};
Vector operator+(const Vector& u,	const Vector& v);
std::ostream& operator<<(std::ostream& os, const Vector& v);
