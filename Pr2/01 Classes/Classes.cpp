#include "Classes.h"
#include <string.h>
#include <iostream>
using namespace std;

NoCopyNoAssignNoHeap::NoCopyNoAssignNoHeap(char c, int i): _c(c), _i(i)
{
	cout<<"NoCopyNoAssignNoHeap created ("<<this<<':'<<_c<<','<<_i<<','<<')'<<endl;
}

NoCopyNoAssignNoHeap::NoCopyNoAssignNoHeap(): _c('?'), _i(0)
{
	cout<<"NoCopyNoAssignNoHeap created ("<<this<<':'<<_c<<','<<_i<<','<<')'<<endl;
}

NoCopyNoAssignNoHeap::~NoCopyNoAssignNoHeap()
{
	cout<<"NoCopyNoAssignNoHeap deleted ("<<this<<':'<<_c<<','<<_i<<','<<')'<<endl;
}

NoCopyNoAssignNoHeapConst::NoCopyNoAssignNoHeapConst(char c, int i): _c(c), _i(i)
{
	cout<<"NoCopyNoAssignNoHeapConst created ("<<this<<':'<<_c<<','<<_i<<','<<')'<<endl;
};

NoCopyNoAssignNoHeapConst::NoCopyNoAssignNoHeapConst(): _c('?'), _i(0)
{
	cout<<"NoCopyNoAssignNoHeapConst created ("<<this<<':'<<_c<<','<<_i<<','<<')'<<endl;
};

NoCopyNoAssignNoHeapConst::~NoCopyNoAssignNoHeapConst()
{
	cout<<"NoCopyNoAssignNoHeapConst deleted ("<<this<<':'<<_c<<','<<_i<<','<<')'<<endl;
}

NoCopyNoHeap::NoCopyNoHeap(char c, int i):_c(c),_i(i)
{	
	cout<<"NoCopyNoHeap created ("<<this<<':'<<_c<<','<<_i<<','<<')'<<endl;
};

NoCopyNoHeap::~NoCopyNoHeap()
{
	cout<<"NoCopyNoHeap deleted ("<<this<<':'<<_c<<','<<_i<<','<<')'<<endl;
}

NoCopyNoHeap& NoCopyNoHeap::operator=(const NoCopyNoHeap& t)
{
	cout<<"Assignment "<<this<<'='<<&t<<": "<<endl;
	if (this != &t)
	{
//	_c=t._c;
	_i=t._i;
	}
	return *this;
}

NoHeap::NoHeap(char c, int i):_c(c),_i(i)
{	
	cout<<"NoHeap created ("<<this<<':'<<_c<<','<<_i<<','<<')'<<endl;
};

NoHeap::NoHeap(const NoHeap& t):_c(t._c),_i(t._i)
{	
	cout<<"NoHeap created ("<<this<<':'<<_c<<','<<_i<<','<<')'<<endl;
};

NoHeap::~NoHeap()
{
	cout<<"NoCopyNoHeap deleted ("<<this<<':'<<_c<<','<<_i<<','<<')'<<endl;
}

NoHeap& NoHeap::operator=(const NoHeap& t)
{
	cout<<"Assignment "<<this<<'='<<&t<<": "<<endl;
	if (this != &t)
	{
//	_c=t._c;
	_i=t._i;
	}
	return *this;
}

NoCopyNoAssignHeap::NoCopyNoAssignHeap(char c, int i, const char* t): _c(c), _i(i)
{
	_t = new char [strlen(t)+1];
	strcpy(_t, t);
	cout<<"NoCopyNoAssignHeap created ("<<this<<':'<<_c<<','<<_i<<','<<_t<<')'<<endl;
};

NoCopyNoAssignHeap::~NoCopyNoAssignHeap()
{
	cout<<"NoCopyNoAssignHeap deleted ("<<this<<':'<<_c<<','<<_i<<','<<_t<<')'<<endl;
	delete [] _t;
}

Heap::Heap(): _c('?'), _i(0)
{
	_t = new char[1];
	*_t='\0';
	cout<<"Heap created ("<<this<<':'<<_c<<','<<_i<<','<<_t<<')'<<endl;
}

Heap::Heap(char c, int i, const char* t): _c(c), _i(i)
{
	_t = new char [strlen(t)+1];
	strcpy(_t, t);
	cout<<"Heap created ("<<this<<':'<<_c<<','<<_i<<','<<_t<<')'<<endl;
};

Heap::Heap(const Heap& t): _c(t._c), _i(t._i)
{
	_t = new char [strlen(t._t)+1];
	strcpy(_t, t._t);
	cout<<"Heap created ("<<this<<':'<<_c<<','<<_i<<','<<_t<<')'<<endl;
}

Heap& Heap::operator=(const Heap& t)
{
	cout<<"Assignment "<<this<<'='<<&t<<": "<<endl;
	if (this != &t)
	{
//	_c=t._c;
	_i=t._i;
	delete [] _t;
	_t = new char [strlen(t._t)+1];
	strcpy(_t, t._t);
	}
	return *this;
}

Heap::~Heap()
{
	cout<<"Heap deleted ("<<this<<':'<<_c<<','<<_i<<','<<_t<<')'<<endl;
	delete [] _t;
}
