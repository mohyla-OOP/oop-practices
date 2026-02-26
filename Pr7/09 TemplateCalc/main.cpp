#include <string>

#include "CC.h"
#include "String.h"
#include "UniCalc.h"

int main()
{
  ComplexCalc c(1, Complex(0, 1));

  cout << c.getA() << '+' << c.getX();
  cout << '=' << c.doOper(operator+) << endl;
  cout << c.getA() << endl;

  c.setX(2);
  cout << c.getA() << '*' << c.getX();
  cout << '=' << c.doOper(operator*) << endl;
  cout << c.getA() << endl << "==================" << endl;

  Calc<Complex> cc(1, Complex(0, 1));

  cout << cc.getA() << '+' << cc.getX();
  cout << '=' << cc.doOper(operator+) << endl;
  cout << cc.getA() << endl;

  cc.setX(2);
  cout << cc.getA() << '*' << cc.getX();
  cout << '=' << cc.doOper(operator*) << endl;
  cout << cc.getA() << endl << "==================" << endl;

  RefCalc<Complex> rc(1, Complex(0, 1));

  cout << rc.getA() << '+' << rc.getX();
  cout << '=' << rc.doOper(operator+) << endl;
  cout << rc.getA() << endl;

  rc.setX(2);
  cout << rc.getA() << '*' << rc.getX();
  cout << '=' << rc.doOper(operator*) << endl;
  cout << rc.getA() << endl << "==================" << endl;

  Calc<int> ci(1, 2);
  cout << ci.getA() << '+' << ci.getX();
  cout << '=' << ci.doOper(operator+) << endl;
  cout << rc.getA() << endl;

  ci.setX(2);
  cout << ci.getA() << '*' << ci.getX();
  cout << '=' << ci.doOper(operator*) << endl;
  cout << ci.getA() << endl << "==================" << endl;

  Calc<double> cr(1.5, 2.2);
  cout << cr.getA() << '+' << cr.getX();
  cout << '=' << cr.doOper(operator+) << endl;
  cout << cr.getA() << endl;

  cr.setX(2.5);
  cout << cr.getA() << '*' << cr.getX();
  cout << '=' << cr.doOper(operator*) << endl;
  cout << cr.getA() << endl << "==================" << endl;

  RefCalc<string> cs("I love ", "OOP");
  cout << cs.getA() << '+' << cs.getX();
  cout << '=' << cs.doOper(operator+) << endl;
  cout << cs.getA() << endl << "==================" << endl;

  RefCalc<String> css("I love, ", "too");
  cout << css.getA() << '+' << css.getX();
  cout << '=' << css.doOper(operator+) << endl;
  cout << css.getA() << endl << "==================" << endl;

  {
    cout << endl << "*** New level of generalization" << endl;
    UniCalc<Complex, Complex> cc(1, Complex(0, 1));

    cout << cc.getA() << '+' << cc.getX();
    cout << '=' << cc.doOper(operator+) << endl;
    cout << cc.getA() << endl;

    cc.setX(2);
    cout << cc.getA() << '*' << cc.getX();
    cout << '=' << cc.doOper(operator*) << endl;
    cout << cc.getA() << endl << "==================" << endl;

    UniCalc<Complex, RefWrapper<Complex> > rc(1, Complex(0, 1));

    cout << rc.getA() << '+' << rc.getX();
    cout << '=' << rc.doOper(operator+) << endl;
    cout << rc.getA() << endl;

    rc.setX(2);
    cout << rc.getA() << '*' << rc.getX();
    cout << '=' << rc.doOper(operator*) << endl;
    cout << rc.getA() << endl << "==================" << endl;

    UniCalc<int, Wrapper<int> > ci(1, 2);
    cout << ci.getA() << '+' << ci.getX();
    cout << '=' << ci.doOper(operator+) << endl;
    cout << rc.getA() << endl;

    ci.setX(2);
    cout << ci.getA() << '*' << ci.getX();
    cout << '=' << ci.doOper(operator*) << endl;
    cout << ci.getA() << endl << "==================" << endl;

    UniCalc<double, Wrapper<double> > cr(1.5, 2.2);
    cout << cr.getA() << '+' << cr.getX();
    cout << '=' << cr.doOper(operator+) << endl;
    cout << cr.getA() << endl;

    cr.setX(2.5);
    cout << cr.getA() << '*' << cr.getX();
    cout << '=' << cr.doOper(operator*) << endl;
    cout << cr.getA() << endl << "==================" << endl;

    UniCalc<string, RefWrapper<string> > cs("I love ", "OOP");
    cout << cs.getA() << '+' << cs.getX();
    cout << '=' << cs.doOper(operator+) << endl;
    cout << cs.getA() << endl << "==================" << endl;

    UniCalc<String, RefWrapper<String> > css("I love, ", "too");
    cout << css.getA() << '+' << css.getX();
    cout << '=' << css.doOper(operator+) << endl;
    cout << css.getA() << endl << "==================" << endl;
  }
  return 0;
}
