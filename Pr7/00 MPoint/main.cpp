#include <iostream>
using namespace std;
#include "MPoint.h"
// test the new function
// Add one more dimension in material particles

int main()
{
  const int n = 100;

  // TODO: 3: what is it? what is MPointNew? Explain how initialization is going on?
  vector<MPointNew> v = {{1, {1, 2, 3}}, {2, {3, 4, 5}}, {1, {2, 1, 4}}};
  Array<3, double> cent = centre(v);
  cout << '(' << cent._x << ';' << cent._y << ';' << cent._z << ')' << endl;

  // TODO: 5: what is it? what type of array is used? what is the MPoint?
  MPoint mar[] = {{1, 1, 2, 3}, {2, 3, 4, 5}, {1, 2, 1, 4}};
  // TODO: 6: check center funciton, what is the las parameter? what is &MPoint::_x
  cout << center(mar, 3, &MPoint::_x) << ';' << center(mar, 3, &MPoint::_y) << ';' << center(mar, 3, &MPoint::_z) << endl;

  // TODO: HW: make specialization of Array<4, double> instead of MPoint4
  MPoint4 mar4[n];
  cout << center(mar4, n, &MPoint4::_x) << ';' << center(mar4, n, &MPoint4::_y) << ';' << center(mar4, n, &MPoint4::_z) << ';'
       << center(mar4, n, &MPoint4::_t) << endl;

  CPoint car[n];
  cout << center(car, n, &CPoint::x) << ';' << center(car, n, &CPoint::y) << ';' << center(car, n, &CPoint::z) << endl;

  CPoint4 car4[n];
  cout << center(car4, n, &CPoint4::x) << ';' << center(car4, n, &CPoint4::y) << ';' << center(car4, n, &CPoint4::z) << ';'
       << center(car4, n, &CPoint4::t) << endl;

  return 0;
}