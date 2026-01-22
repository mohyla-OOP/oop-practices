#pragma once
#define CALCULATE
extern size_t counter;

template<typename T>
T* allocate(T*& ptr, size_t n)
{
	++counter;
	return ptr = new T[n];
} 

template<typename T>
void remover(T*& ptr)
{
	delete []ptr;
}
