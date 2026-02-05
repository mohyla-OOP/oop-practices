#include "A.h"

class B
{
public:
	B(){};
	B(const A::B&){};
	void f(double x)
	{
		x=x;
	}
	B& operator=(const B&)
	{
		return *this;
	}
};