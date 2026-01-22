#include "CopyVector.h"
#include "Allocator.h"

CopyVector::CopyVector(size_t n) : _n(n), _v(new double[_n]), _id(++_freeId)
{
#ifdef CALCULATE
	++counter;
#endif
	for (size_t k = 0; k < _n; ++k)
		_v[k] = k;
}
CopyVector::~CopyVector()
{
	delete[] _v;
	_v = nullptr;
}
CopyVector::CopyVector(const CopyVector& v) : _n(v._n), _v(new double[_n]), _id(++_freeId)
{
#ifdef CALCULATE
	++counter;
#endif
	for (size_t k = 0; k < _n; ++k)
		_v[k] = v._v[k];
}

size_t CopyVector::size() const
{
	return _n;
}
CopyVector& CopyVector::operator=(const CopyVector& v)&
{
	if (&v == this)
		return *this;
	delete[] _v;
#ifdef CALCULATE
	++counter;
#endif
	_n = v._n;
	_v = new double[_n];
	for (int i = 0; i < _n; ++i)
		_v[i] = v._v[i];

	return *this;
}

double CopyVector::operator[](size_t k) const
{
	return _v[k];
}

double& CopyVector::operator[](size_t k)
{
	return _v[k];
}

CopyVector operator+(const CopyVector& u,const CopyVector& v) {
	CopyVector w(u.size());
	for (int i = 0; i < w.size(); ++i)
		w[i] = u[i] + v[i];
	return w;
}
