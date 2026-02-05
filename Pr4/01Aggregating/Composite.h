#pragma once
#include <type_traits>
class Component {
public:
	//TODO-HW: add audit for all constructions/desctructions, increment in constructor, make initialization for count, add showCount
	Component() {/*TODO: add debug print for constructor*/};
	//Component() :_a() {};
	Component(const Component& a) :_a(a._a) {/*TODO: add debug print for copy constructor*/}
	~Component() {/*TODO: add debug print for destructor*/}
private:
	int _a = 1;
	// static int _counter;
	// const int _id;
};

class Composite
{
private:
	Component _a;
public:
	Composite() :_a() {}
	// Семантика значень
	// порівняйте дві сигнатури конструкторів
	//Composite(const Component& a) :_a(a) {}
	Composite(const Component a) :_a(a) {}
	Composite(const Composite& a) :_a(a._a) {}
	Composite& operator=(const Composite& a) {
		_a = a._a;
		return *this;
	}
	//Composite(Composite&&) = delete;
};
Composite f()
{
	return Composite();
}
Composite g()
{
	Composite x;
	return x;
}

Composite h()
{
	return std::move(Composite());
}

class CopyOnly {
public:
	CopyOnly() = default;
	CopyOnly(const CopyOnly&) = default;
	CopyOnly& operator=(const CopyOnly&) = default;
	~CopyOnly() = default;
};

CopyOnly fCopyOnly()
{
	return CopyOnly();
}

//1.	Debug the call NoMove h(NoMove a)
//2.	Debug the call NoMove f(NoMove a)
class NoMove
{
private:
	int _k = 0;
public:
	NoMove(){}
	NoMove(const NoMove& a) :_k(a._k) {}
//3.	Unkomment next line and debug again
	//NoMove(NoMove&& a) :_k(a._k) {}
//4.	Unkomment next line and explain
    //NoMove(NoMove&& a) = delete;
};

NoMove f(NoMove a)
{
	NoMove b(a);
	return b;
}
NoMove g(const NoMove& a)
{
	return a;
}
NoMove h(NoMove a)
{
	return g(a);
}
