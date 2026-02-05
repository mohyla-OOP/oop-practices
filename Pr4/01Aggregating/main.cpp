#include <iostream>
#include "Composite.h"
#include "Aggregate.h"
//Supplay Aggregee with id and monitor creating and deleting
int main()
{
	{
		std::cout << "*** Try Composite ***\n";
		Component a;
		Composite v(a);
		Composite x;
		Composite y(x);
		x = y;
		Composite z(f());
		y = f();
		Composite u(g());
		y = g();
		Composite w(h());
		y = h();
	}
	{
		//Pointer etude
		Aggregee* p = nullptr;
		Aggregee* q = new Aggregee;
		// Пани на двох одні штани
		Aggregee* sq = q;
		delete p;
		delete q;
		//delete sq;
	}
	{
		std::cout << "*** Try Unique Ptr ***\n";
		//Unique Pointer etude
		std::unique_ptr<Aggregee> p = nullptr;
		auto  q = std::make_unique<Aggregee>();
		auto  qq = std::make_unique<Aggregee>(Aggregee());
		std::unique_ptr<Aggregee> s(std::move(q));
	}
	{
		CopyOnly y(fCopyOnly());
		y = fCopyOnly();
	}
	
	{
		std::cout << "*** Try Aggregate ***\n";
		Aggregate x;
		Aggregee a;
		Aggregate v(a);
		//Aggregate s(&a);
		Aggregate y(x);
		x = y;
		Aggregate z(af());
		y = af();
		Aggregate u(ag());
		y = ag();
		Aggregate w(ah());
		y = ah();
	}
	{
		std::cout << "*** Try AggregateUnique ***\n";
		AggregateUnique x;
		Aggregee a;
		AggregateUnique v(a);
		AggregateUnique y(x);
		x = v;
		y = std::move(x);
		AggregateUnique z(&a);
	}
	{
		//MoveOnly x;
		// attempting to reference a deleted function
		//MoveOnly y(x);
		//y = x;
		MoveOnly y(fMoveOnly());
		y = fMoveOnly();
	}

	{
		NoMove a;
		h(a);
		f(a);
	}
	return 0;
}