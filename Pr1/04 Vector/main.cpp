#include "Vector_01.h"
#include "Vector_10.h"
#include "Vector.h"

int main()
{
	{
		Vector01 v1(10);
		Vector01 v2(9);
		Vector01 v3(10);
		cout << boolalpha;
		cout << (v1 == v2) << endl;
		cout << (v1 == v3) << endl;
	}
	{
		Vector10 v1(5);
		Vector10 v2(9);
		Vector10 v3(5);
		cout << boolalpha;
		cout << (v1 == v2) << endl;
		cout << (v1 == v3) << endl;
		cin >> v1;
		cin >> v3;
		cout << endl;
		cout << (v1 == v3) << endl;
;	}
	return 0;
}