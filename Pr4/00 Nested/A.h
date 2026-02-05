#pragma once

class B;
class A
{
private:
	B* p;
	::B* q;
public:
	class B;
	B& f(B& x)
	{
		return x;
	}
	::B& f(::B& x)
	{
		return x;
	}
};
