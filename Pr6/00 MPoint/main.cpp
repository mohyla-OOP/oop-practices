#include "MPoint.h"

int main()
{
	MPoint u = { 1,2 }, v = { 3,4 };

	MPoint::ConstCoord cpx = &Point::_x;
	MPoint::ConstCoord cpy = &Point::_y;

	MPoint::Coord px = &Point::_x;
	MPoint::Coord py = &Point::_y;

	std::cout << "u._x=" << select(u, &Point::_x) << std::endl;
	std::cout << "v._y=" << select(v, &Point::_y) << std::endl;

	//TODO: 2: Why different initialization of MPoint and AMPoint?
	std::vector<MPoint> a = { {1,2,3},{2,4,5},{3,1,8} };
	std::cout << centre(a) << std::endl;

	std::vector<AMPoint> b = { {{1,2},3},{{2,4},5},{{3,1},8} };
	std::cout << centre(b) << std::endl;

}