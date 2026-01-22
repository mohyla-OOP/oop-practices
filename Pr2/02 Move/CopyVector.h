#pragma once
class CopyVector
{
private:
	size_t _n;
	double* _v;
	static size_t _freeId;
	const size_t _id;
public:
	CopyVector(size_t n);
	~CopyVector();
	CopyVector(const CopyVector& v);

	// Incidental addon: ref-qualified assignment 
	CopyVector& operator=(const CopyVector&)&;
	
	size_t size() const;
	double operator[](size_t)const;
	double& operator[](size_t);
	inline static size_t freeId()
	{
		return _freeId;
	}
};
CopyVector operator+(const CopyVector& u, const CopyVector& v);
