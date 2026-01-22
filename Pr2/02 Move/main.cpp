#include <iostream>
//using namespace std;

#include "Vector.h"
#include "CopyVector.h"
#include "Swap.h"
#include "Allocator.h"
#include "Mover.h"

size_t Vector::_freeId = 0;
size_t CopyVector::_freeId = 0;
size_t counter = 0;

int main()
{	
	{		
		// Copy Semantics
		
		CopyVector u(10), v(10), w(10);
		counter = 0; 
		w = u + v;
		u = u + v + w;
		std::cout << "Copying:" << counter << std::endl;
	}
	{
		// Move Semantics
		
		Vector u(10), v(10), w(10);
		
		counter = 0;
		w = u + v;
		u = u + v + w;
		std::cout << "Moving:" << counter << std::endl;
		std::cout << v << std::endl;
		u = std::move(v);
		std::cout << v << std::endl;
		v = w;
		std::cout << v << std::endl;
		v = v;
		v = std::move(v);
		// My move from Mover.h
		v = move(v);
		std::cout << v << std::endl;
		const Vector cv(10);
		v = move(cv);
		std::cout << cv << std::endl;
	}
		// Controlled movement
	{
		CopyVector u(10), v(10);
		counter = 0;
		copyswap(u, v);
		std::cout << "Copying swap:" << counter << std::endl;
		counter = 0;
		moveswap(u, v);
		std::cout << "No moving swap:" << counter << std::endl;;
	}
	{
		Vector u(10), v(10);
		counter = 0;
		copyswap(u, v);
		std::cout << "Copying swap:" << counter << std::endl;
		counter = 0;
		moveswap(u, v);
		std::cout << "Moving swap:" << counter << std::endl;
	}
	
	return 0;
}