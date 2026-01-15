#include "MyStruct.h"
#include <iostream>
using namespace std;
#include "Test.h"

int main()
{
	cout << test() << endl;
	//case 1:
		MyFirstStruct s/*{ true,0,'a' }*/;
		cout<<boolalpha;
		//cout<<s._b<<':'<<s._i<<':'<<s._c<<endl;
		int* si = &s._i;
		cout << s._b << ':' << *si << ':' << s._c << '.' << endl;
		create(s);
		cout<<s._b<<':'<<s._i<<':'<<s._c<<endl;
		
	//case 2:
		MySecondStruct s2;
		cout<<boolalpha;
		//cout<<s2._b<<':'<<s2._i<<':'<<s2._c<<endl;
		si = &s2._i;
		cout << s2._b << ':' << *si << ':' << s2._c << '.'<<endl;
		MySecondStruct::construct(s2);
		cout<<s2._b<<':'<<s2._i<<':'<<s2._c<<endl;
		
	//case 3:
		MyThirdStruct s3;
		cout<<boolalpha;
		//cout<<s3._b<<':'<<s3._i<<':'<<s3._c<<endl;
		si = &s3._i;
		cout << s3._b << ':' << *si << ':' << s3._c << '.' << endl;
		s3.construct();
		cout<<s3._b<<':'<<s3._i<<':'<<s3._c<<endl;
	
	//case 4:
		{
		MyForthStruct s4;
		cout<<boolalpha;
		cout<<s4._b<<':'<<s4._i<<':'<<s4._c<< endl;
//		explicit call is not needed anymore
		}
	//case 5:
		{
		MyFifthStruct s5;
//		testing output is integrated into DEBUG mode		
//		cout<<s4._b<<':'<<s4._i<<':'<<s4._c<<endl;
		}

	return 0;
}
