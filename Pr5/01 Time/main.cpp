#include <iostream>
using namespace std;
#include "Time.h"

int main()
{
	Time t1(1, 2, 3);
	Time t2(4, 5, 6);
	cout << t1 << endl;
	cout << t2 << endl;
	t1 + t2;
	t1 + 10;
	10 + t1;
	10 * t1;
	cout << t1 + t2 << endl;
	cout << Time(t1 + t2) << endl;
	return 0;
}
