#include "Point.h"
#include "Segment.h"
#include "Triangle.h"

#include <iostream>
using namespace std;

ofstream out("Main.txt");

// The project for Refactoring with Triangle::Segment
int main()
{ 
	Point u, v(0,3), w (4);

	out<<"Triangle composing apices and vertices======"<<endl;
	Triangle ABC(u, v, w);
	out<<"ABC "<<ABC;

	Triangle a, b(2,0,2,2,0,2), c(b,true);
	out<<"a "<<a;

	out<<"b "<<b;

	out<<"c "<<c;

	c.assign(ABC); //c=ABC;
	out<<"new value of c "<<c;

	out<<"Triangles "<<Triangle::epilog()<<endl;
	out<<"Segments  "<<Segment::epilog()<<endl;
	out<<"Points    "<<Point::epilog()<<endl;
	
	
	//59 of points; 22 of segments

	return 0;
}
