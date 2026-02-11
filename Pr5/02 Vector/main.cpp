#include <iostream>
using namespace std;
#include "Vector.h"
#include "IndexedVector.h"
#include "IndexedVarVector.h"
#include <complex>
// Check move assignment
int main()
{
	
	{
		WrappedVector a, b;
		cout<<a<<a*10<<endl;
		//10 * a;
		cout<<a+b<<endl;
		cout<<a*b<<endl;
		WrappedVector c(a);
		cout<<boolalpha<<(a==b)<<endl;
		cout<<(a==c)<<endl;
	}
	{
		vector<double> u, v;
		cout << boolalpha << (u == v) << endl;
		//cout << u.operator== (v) << endl;
		IndexedWrappedVector a, b;
		cout<<a<<a*10<<10*a<<endl;
		cout<<a+b<<endl;
		cout<<a*b<<endl;
		IndexedWrappedVector c(a);
		cout<<boolalpha<<(a==b)<<endl;
		cout<<(a==c)<<endl;
	}
	{
		IndexedVarVector a, b;
		cout<<a<<a*10<<10*a<<endl;
		cout<<a+b<<endl;
		cout<<a*b<<endl;
		IndexedVarVector c(a);
		cout<<boolalpha<<(a==b)<<endl;
		cout<<(a==c)<<endl;
		a = std::move(b);
		cout << b << endl;
	}
	return 0;
}
