#include <iostream>
using namespace std;
// 1.Use IndexedVarVector operator+(const IndexedVarVector&,const IndexedVarVector&);
// instead of const IndexedVarVector operator+(const IndexedVarVector&,const IndexedVarVector&);
// 2. Define move assignment
// 3. Develope corresponding tests
class IndexedVarVector
{
private:
	size_t _n;
	double * _v;
public:

//	explicit IndexedVarVector(size_t n=10);
	IndexedVarVector(size_t n=10);
	IndexedVarVector(const IndexedVarVector&);
	IndexedVarVector(IndexedVarVector&&);
	~IndexedVarVector();
	size_t size() const { return _n;}
	IndexedVarVector& operator=(const IndexedVarVector&)&;
	IndexedVarVector& operator=(IndexedVarVector&&) = default;
	double operator[](size_t) const;
	double& operator[](size_t);
};

	ostream& operator<<(ostream&, const IndexedVarVector&);
	void fill(IndexedVarVector& v);
	bool operator==(const IndexedVarVector&, const IndexedVarVector&);
	bool operator!=(const IndexedVarVector&, const IndexedVarVector&);
	double operator*(const IndexedVarVector&,const IndexedVarVector&);

	IndexedVarVector operator*(double, const IndexedVarVector&);
	IndexedVarVector operator*( const IndexedVarVector&, double);
	IndexedVarVector operator+(const IndexedVarVector&,const IndexedVarVector&);
