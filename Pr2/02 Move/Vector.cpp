#include "Vector.h"
#include "Allocator.h"
#include <cassert>

Vector::Vector(size_t n) : _n(n), _v(new double[_n]), _id(++_freeId)
{
#ifdef CALCULATE
	++counter;
#endif
	
	for (size_t k = 0 ; k < _n; ++k)
		_v[k] = k+_id;
}
Vector::~Vector()
{
	delete[] _v;
	_v = nullptr;
}
Vector::Vector(const Vector& v) : _n(v._n), _v(new double[_n]), _id(++_freeId)
{
#ifdef CALCULATE
	++counter;
#endif
	for (size_t k = 0; k < _n; ++k)
		_v[k] = v._v[k];
}
Vector::Vector(Vector&& v) noexcept : _n(v._n), _v(v._v), _id(++_freeId) 
{
	v._n = 0;
	v._v = nullptr;
}
size_t Vector::size() const
{
	return _n;
}
Vector& Vector::operator=(const Vector& v)&
{
	assert(std::is_lvalue_reference<decltype(v)>::value);
	if (&v == this)
		return *this;
	delete[] _v;
	
#ifdef CALCULATE
	++counter;
#endif
	_n = v._n;
	_v = new double[_n];
	
	for(int i=0;i<_n;++i)
		_v[i] = v._v[i];
	
	return *this;
}
Vector& Vector::operator=(Vector&& v)& noexcept
{
	assert(std::is_rvalue_reference<decltype(v)>::value);
	// Is there any sence in moving v to v?
	// But allowed is averything
	// which is not forbidden
	if (&v == this)
		return *this;
	delete[] _v;
	_n = v._n;
	_v = v._v;
	
	v._n = 0;
	v._v = nullptr;
	return *this;
}
double Vector::operator[](size_t k) const
{
	return _v[k];
}

double& Vector::operator[](size_t k)
{
	return _v[k];
}

Vector operator+(const Vector& u, const Vector& v) {
	Vector w(u.size());
	for (int i = 0; i <w.size(); ++i)
		w[i] = u[i] + v[i];
	return w;
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	std::cout << '(';
	for (int k = 0; k < v.size(); ++k)
		std::cout << v[k] << ' ';
	std::cout << ')';
	return os;
}
