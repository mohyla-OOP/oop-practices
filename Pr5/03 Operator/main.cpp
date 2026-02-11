#include <iostream>
using namespace std;
#include <complex>
#include "Complex.h"
#include "Spaceship.h"
#include <vector>

int main()
{
	
	// Use spaceship operator for calendar dates
	{
		struct Point {
			auto operator<=>(const Point&) const = default;
			double _x;
			double _y;
		};

		Point a{ 1,2 };
		Point b{ 1,2 };
		cout << "a=" << '(' << a._x << ',' << a._y << ')' << endl;
		cout << "b=" << '(' << b._x << ',' << b._y << ')' << endl;
		cout << (a < b ? "a < b" : "not a < b") << endl;
		cout << (a > b ? "a > b" : "not a > b") << endl;
		cout << (a <= b ? "a <= b" : "not a <= b") << endl;
		cout << (a >= b ? "a >= b" : "not a >= b") << endl;
		cout << (a == b ? "a == b" : "not a == b") << endl;
		cout << (a != b ? "a != b" : "not a != b") << endl;
		cout << endl;

		// compare with strcmp
		auto res = a <=> b;
		cout << (res < 0 ? "a<b" : "not a<b") << endl << endl;
		cout << (res ==0 ? "a==b" : "not a==b") << endl << endl;
		cout << (res > 0 ? "a>b" : "not a>b") << endl << endl;
	}
	{
		Compare<string, int> a{ "Ivanenko",2 };
		Compare<string, int> b{ "Petrenko",1 };

		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		cout << (a < b ? "a < b" : "not a < b") << endl;
		cout << (a > b ? "a > b" : "not a > b") << endl;
		cout << (a <= b ? "a <= b" : "not a <= b") << endl;
		cout << (a >= b ? "a >= b" : "not a >= b") << endl;
		cout << (a == b ? "a == b" : "not a == b") << endl;
		cout << (a != b ? "a != b" : "not a != b") << endl;
		cout << endl;
	}
	{
		Compare<int, string> a{ 2, "Ivanenko" };
		Compare<int, string> b{ 1, "Petrenko" };

		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		cout << (a < b ? "a < b" : "not a < b") << endl;
		cout << (a > b ? "a > b" : "not a > b") << endl;
		cout << (a <= b ? "a <= b" : "not a <= b") << endl;
		cout << (a >= b ? "a >= b" : "not a >= b") << endl;
		cout << (a == b ? "a == b" : "not a == b") << endl;
		cout << (a != b ? "a != b" : "not a != b") << endl;
		cout << endl;
	}
	{
		CCompare<int, string> a{ 2, "Ivanenko" };
		CCompare<int, string> b{ 1, "Petrenko" };

		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		cout << (a < b ? "a < b" : "not a < b") << endl;
		cout << (a > b ? "a > b" : "not a > b") << endl;
		cout << (a <= b ? "a <= b" : "not a <= b") << endl;
		cout << (a >= b ? "a >= b" : "not a >= b") << endl;
		cout << (a == b ? "a == b" : "not a == b") << endl;
		cout << (a != b ? "a != b" : "not a != b") << endl;
		cout << endl;
	}
	{
		vector<int> v1{ 1, 6, 9 };
		vector<int> v2{ 1, 4, 9 };

		auto ans2 = v1 <=> v2;

		// If ans is less than zero
		if (ans2 < 0) {

			cout << "v1 < v2" << endl;
		}

		// If ans is equal to zero
		else if (ans2 == 0) {

			cout << "v1 == v2" << endl;
		}

		// If ans is greater than zero
		else if (ans2 > 0) {

			cout << "v1 > v2" << endl;
		}
	}

	{
		Compare<string, int> a{ "Ivanenko",2};
		Compare<string, int> b{ "Petrenko",1};

		// If ans is less than zero
		if (a<b) {

			cout << "a < b" << endl;
		}

		// If ans is equal to zero
		else if (a == b) {

			cout << "a == b" << endl;
		}

		// If ans is greater than zero
		else if (a > b) {

			cout << "a > b" << endl;
		}
	}
	{
		Compare<string, int> a{ "Ivanenko",2 };
		Compare<string, int> b{ "Petrenko",1 };
		auto ans = a <=> b;
		// If ans is less than zero
		if (ans<0) {

			cout << "a < b" << endl;
		}

		// If ans is equal to zero
		else if (ans==0) {

			cout << "a == b" << endl;
		}

		// If ans is greater than zero
		else if (ans > 0) {

			cout << "a > b" << endl;
		}
	}
}