#ifndef _CLASSES_H
#define _CLASSES_H
//#include  <cstdint>
#include <bitset>
#include <iostream>
using namespace std;

struct NoConstruct
{
	char _c;
	int _i;
public:
	~NoConstruct()
	{
		cout << "No proper values have been initialised:" << hex << (int)(byte(_c)) << ':' << _i << endl;
		cout << "Bit sets: " << bitset<8>(_c) << ':' << bitset<32>(_i) << endl;
		int* pint = new int;
		cout << hex << *pint << endl;
		cout << bitset<32>(*pint) << endl
			<< bitset<32>(_i) << endl;
	}
};


//The class contains neither copy constructor nor assignment
class NoCopyNoAssignNoHeap
{
	char _c;
	int _i;

public:
	NoCopyNoAssignNoHeap();
	NoCopyNoAssignNoHeap(char c, int i);
	~NoCopyNoAssignNoHeap();
};

//The class contains neither copy constructor nor assignment
//but a constant class member
class NoCopyNoAssignNoHeapConst
{
	const char _c;
	int _i;

public:
	NoCopyNoAssignNoHeapConst();
	NoCopyNoAssignNoHeapConst(char c, int i);
	~NoCopyNoAssignNoHeapConst();
};

//The class contains assignment but copy constructor 
class NoCopyNoHeap
{
	const char _c;
	int _i;

public:
	NoCopyNoHeap(char c, int i);
	NoCopyNoHeap& operator=(const NoCopyNoHeap&);
	~NoCopyNoHeap();
};

//The class contains both assignment and copy constructor 
class NoHeap
{
	const char _c;
	int _i;

public:
	NoHeap(char c, int i);
	NoHeap(const NoHeap&);
	NoHeap& operator=(const NoHeap&);
	~NoHeap();
};

//The class contains neither copy constructor nor assignment
//but a member located in the heap
class NoCopyNoAssignHeap
{
	const char _c;
	int _i;
	char* _t;
public:
	NoCopyNoAssignHeap(char c, int i, const char* t);
	~NoCopyNoAssignHeap();
};

//The class contains both assignment and copy constructor
//and a member located in the heap
class Heap
{
	const char _c;
	int _i;
	char* _t;
public:
	Heap();
	Heap(char c, int i, const char* t);
	Heap(const Heap&);
	Heap& operator=(const Heap&);
	~Heap();
};
#endif