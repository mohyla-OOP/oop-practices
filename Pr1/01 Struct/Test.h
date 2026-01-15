#pragma once
//https://www.onlinegdb.com/
struct Test
{
	int (*f)(int k);
};

int g(int k) { return k; }

int test()
{
	Test test;
	test.f = &g;
	return (*test.f)(1);
}
