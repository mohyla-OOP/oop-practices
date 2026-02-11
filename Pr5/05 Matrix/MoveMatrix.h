#pragma once
#pragma once
#include <iostream>
using namespace std;

class MoveMatrix
{
public:
	MoveMatrix(int m, int n) :_m(m), _n(n), _a(new double[n*m])
	{
		created += _n*_m;
		for (int i = 0; i < _m; ++i)
			for (int j = 0; j < _n; ++j)
				a(i, j) = double(i);
	}
	MoveMatrix(const MoveMatrix&);// = delete;
	MoveMatrix(MoveMatrix&&);
	~MoveMatrix()
	{
		if(_a!=0)
		{ 
			deleted += _m*_n;
			delete[] _a;
		}	
	}
	MoveMatrix& operator-=( const MoveMatrix&);
	const int m() const { return _m; }
	const int n() const { return _n; }
	double a(int i, int j) const
	{
		return _a[i*_n + j];
	}
	double& a(int i, int j)
	{
		return _a[i*_n + j];
	}
	static void epilog()
	{
		cout << "created=" << created << endl
			<< "copied =" << copied << endl
			<< "deleted=" << deleted << endl<<'\n';
	}
	static void prolog()
	{
		created = 0;
		copied = 0;
		deleted = 0;
	}
private:
	static int created;
	static int copied;
	static int deleted;
	int _m;
	int _n;
	double *_a;
};
MoveMatrix operator+(const MoveMatrix&, const MoveMatrix&);
const MoveMatrix operator-(const MoveMatrix&, const MoveMatrix&);
ostream& operator<<(ostream&, const MoveMatrix&);

