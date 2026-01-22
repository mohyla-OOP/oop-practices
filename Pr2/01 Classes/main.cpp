#include "Classes.h"
#include <iostream>
using namespace std;

int main()
{
// 0
	{
		NoConstruct nc;
		//cout << nc._c << endl;
		//cout << nc._i << endl;
	}
//1	
	cout<<"Starting the first block:"<<endl;
	{
		NoCopyNoAssignNoHeap v('a', 1);
		NoCopyNoAssignNoHeap * p = new NoCopyNoAssignNoHeap;
		NoCopyNoAssignNoHeap u=v;
		NoCopyNoAssignNoHeap w(v);
//		Default memberwise assingment
		u=w;
		delete p;

	}
//1a
	{
		NoCopyNoAssignNoHeapConst u('a', 1);
		NoCopyNoAssignNoHeapConst v;
//		The following assignment does not work
//		as memberwise assignment is not allowed
//		for a constant member
//		v=u;
	}

//2
	cout<<"Starting the second block:"<<endl;
	{
		NoCopyNoHeap v('b', 1);
		NoCopyNoHeap t('b', 2);

		NoCopyNoHeap u=v;
		NoCopyNoHeap w(v);
		u=w;

	}

//3
	cout<<"Starting the third block:"<<endl;
	{
		NoHeap v('c', 1);
		NoHeap t('c', 2);
		NoHeap u=v;
		NoHeap w(v);
		u=w;

	}

//4
	cout<<"Starting the forth block:"<<endl;
	{
		NoCopyNoAssignHeap x('d', 1, "d_First");
		NoCopyNoAssignHeap y('d', 2, "d_Second");
		NoCopyNoAssignHeap* z = new NoCopyNoAssignHeap('c', 3, "d_Third");
//		Direct destructor call is not allowed
//		as the object will be destroyed before
//		automatic destructor call at the block end
//		y.~NoCopyNoAssignHeap();
//		NoCopyNoAssignHeap z(x);
//		x=y;
		delete z;	
	}

//5
	cout<<"Starting the fifth block:"<<endl;
	{
		Heap u1('e',1,"e_First");
		Heap u2('e',2,"e_Second");
		Heap v;
		Heap w(u1);

		u1=u1;
		u1=v;
		w=u2;
		v=u2;
	}

	return 0;
}