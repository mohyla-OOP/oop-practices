#include "Memory.h"
#include <iostream>
using namespace std;

Memory1::Memory1(const char * const s):_s(new char[strlen(s)+1])
{
	cout<<"Parameter s="<<s << endl;
	cout<<"Attribute before initialisation "<<_s << endl;
	for(size_t i=0; i<=strlen(s); ++i)
		_s[i]=s[i];
	cout<< "Attribute after initialisation " << _s<<endl;
	return;
}

//todo home: use while(++target=++source); for copying 

Memory2::Memory2(const char * const s):_s(new char[strlen(s)+1])
{
	for(size_t i=0; i<=strlen(s); ++i)
		_s[i]=s[i];
#ifndef NDEBUG
	cout<<_s<<endl;
#endif
	return;
}

Memory2::~Memory2()
{
	delete []_s;
	cout << "Here is my delete!" <<_s<<endl;
	_s=nullptr;
	//cout<<"Here is my delete!"<</*_s<<*/endl;
}

Memory3::Memory3(const int n) :_s(new int[n] {})
{
	for (size_t i = 0; i <n; ++i)
		_s[i] = i+1;
#ifndef NDEBUG
	cout << "Where is your delete? " << ':';
	for (size_t i = 0; i < n; ++i)
		cout << _s[i] << ' ';
		cout << endl;
#endif
	return;
}

Memory3::~Memory3()
{
	delete[]_s;
	_s = nullptr;
	cout << "Here is my delete! " << _s<< endl;
}