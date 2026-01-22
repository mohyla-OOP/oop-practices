#include <iostream>
#include <complex>
#include "C.h"
#include "Point.h"
int Point::_freeID = 0;
int main()
{
	{
		std::complex<double> u(1, 2);
		std::complex<double> v(3,4);
		std::complex<double> w;
		std::cout<<(u + v = w)<<std::endl;
	}
	CPoint a;
	double* p = &a._x;
	double* q = &a._y;
	/*std::cout << a._x << ',' << a._y << std::endl;*/
	std::cout << std::hex << *p << ',' << *q << std::endl;
	std::cout << std::hex<<(std::int64_t)*p << ',' << (std::int64_t)*q << std::endl;
	CPoint b{ 1,2 };
	std::cout << b._x << ',' << b._y << std::endl;
	CPoint c(b);
	std::cout << c._x << ',' << c._y << std::endl;
	c._x = 10;
	b = c;
	std::cout << b._x << ',' << b._y << std::endl;
	{
		Point2003 a;
		std::cout << a._x << ',' << a._y << std::endl;
		Point2003 b(1, 2);
		std::cout << b._x << ',' << b._y << std::endl;
		Point2003 c{ 3,4 };
		std::cout << c._x << ',' << c._y << std::endl;
		Point2003 d(b);
		std::cout << d._x << ',' << d._y << std::endl;
		Point2003 h = c;
		std::cout << h._x << ',' << h._y << std::endl;
		a = d;
		std::cout << a._x << ',' << a._y << std::endl;
	}
	{
		Point2011 a;
		std::cout << a._x << ',' << a._y << std::endl;
		//Point2011 b(1, 2);
		Point2011 c{ 3,4 };
		std::cout << c._x << ',' << c._y << std::endl;
		Point2011 d(c);
		std::cout << d._x << ',' << d._y << std::endl;
		Point2011 h = c;
		std::cout << h._x << ',' << h._y << std::endl;
		a = d;
		std::cout << a._x << ',' << a._y << std::endl;
	}
	{
		Point2011a a;
		std::cout << a._x << ',' << a._y << std::endl;
		//Point2011a b(1, 2);
		//Point2011a c{ 3,4 };
		std::cout << c._x << ',' << c._y << std::endl;
		Point2011a d(a);
		std::cout << d._x << ',' << d._y << std::endl;
		Point2011a h = a;
		std::cout << h._x << ',' << h._y << std::endl;
		a = d;
		std::cout << a._x << ',' << a._y << std::endl;
	}
	{
		Point a;
		Point b(1, 2);
		Point c(b);
		//a = b;
	}
}