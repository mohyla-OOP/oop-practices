#include "A.h"
#include "Container.h"
#include "Shape.h"

int main()
{
  Shape *s1 = new Rectangle;
  Shape *s2 = new Triangle;
  // Shape* s3 = new Shape;
  Shape *s4 = new RightTriangle;
  Shape *s5 = new AcuteTriangle;
  Shape *s6 = new ObtuseTriangle;

  s1->whatAmI();
  s1->Shape::whatAmI();
  s2->whatAmI();
  // s3->whatAmI();
  s4->whatAmI();
  s5->whatAmI();
  s6->whatAmI();

  C *z = new A;
  z->f();  // A::f()

  z = new B;
  z->f();  // B::f()

  {
    Shape *shape = new Triangle;
    delete shape;
  }
  {
    Shape *shape = new Rectangle;
    delete shape;
  }

  {
    VectorContainer<int> v;
    useContainer(v);
    SetContainer<int> s;
    useContainer(s);
    GostakContainer<char> gc;
    useContainer(gc);
    /*gc.add('a');
    gc.print();*/
  }
}
