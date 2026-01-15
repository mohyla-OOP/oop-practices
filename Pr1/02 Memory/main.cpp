#include "Memory.h"
#include <iostream>
using namespace std;

int main()
{
	char * dangling =nullptr;
	{
		Memory1 s("I have no destructor");
		dangling = s._s;
	}
	cout<<dangling<<" - Allthough s does not exit anymore"<<endl;
	{
		Memory2 s("I have a destructor");
		dangling = s._s;
	}
	cout <<static_cast<unsigned int>(*dangling) << " dangling is undefined: "<< dangling << endl;
	int* dangling1 = nullptr;
	{
		Memory3 s(5);
		dangling1 = s._s;
	}
	for (size_t i = 0; i < 5; ++i)
		cout << dangling1[i] << ' ';
	cout << endl;
	cout << dangling1 << " dangling is undefined" << endl;
	return 0;
}