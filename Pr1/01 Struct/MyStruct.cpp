#include "MyStruct.h"
#include <iostream>
using namespace std;

void create (MyFirstStruct &s)
{
	s._b=false;
	s._i=1;
	s._c='a';
	return;
}

void MySecondStruct::construct (MySecondStruct &s)
{
	s._b=false;
	s._i=1;
	s._c='a';
	return;
}

//Parameter s is not needed anymore
void MyThirdStruct::construct ()
{
	_b=false;
	_i=1;
	_c='a';
	return;
}

MyForthStruct::MyForthStruct()
{
	cout<<boolalpha;
	cout<<_b<<':'<<_i<<':'<<_c<< '.' << endl;
	_b=false;
	_i=1;
	_c='a';
	return;
}
	
MyFifthStruct::MyFifthStruct():	_b(false),_i(1),_c('a')
{
//	comme il faut
#ifndef NDEBUG
	cout<<boolalpha;
	cout<<_b<<':'<<_i<<':'<<_c<<endl;
#endif
	return;
}