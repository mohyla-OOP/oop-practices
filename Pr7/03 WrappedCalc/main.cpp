#include <complex>

#include "TemplateCalc.H"
// Compare calculators and their wrappers with the previous project

int main()
{
  Calc<Complex> cc(1, Complex(0, 1));

  cout << cc.getA() << '+' << cc.getX();
  cout << '=' << cc.doOper(operator+) << endl;
  cout << cc.getA() << endl;

  cc.setX(2);
  cout << cc.getA() << '*' << cc.getX();
  cout << '=' << cc.doOper(operator*) << endl;
  cout << cc.getA() << endl;

  Calc<int> ci(1, 2);
  cout << ci.getA() << '+' << ci.getX();
  cout << '=' << ci.doOper(operator+) << endl;
  cout << ci.getA() << endl;

  ci.setX(2);
  cout << ci.getA() << '*' << ci.getX();
  cout << '=' << ci.doOper(operator*) << endl;
  cout << ci.getA() << endl;

  Calc<double> cr(1.5, 2.2);
  cout << cr.getA() << '+' << cr.getX();
  cout << '=' << cr.doOper(operator+) << endl;
  cout << cr.getA() << endl;

  cr.setX(2.5);
  cout << cr.getA() << '*' << cr.getX();
  cout << '=' << cr.doOper(operator*) << endl;
  cout << cr.getA() << endl;

  using StepComp = complex<double>;
  Calc<StepComp> stcalc{StepComp(1, 1), StepComp(2, 2)};
  cout << stcalc.getA() << '+' << stcalc.getX();
  cout << '=' << stcalc.doOper(operator+) << endl;
  cout << stcalc.getA() << endl;

  // Apropos
  {
    Complex z(2, 0);
    StepComp s(2, 0);
    // power(z, 10) = 2;
    cout << power(z, 10) << endl;
    cout << (power(s, 10) = 2) << endl;
    /*power1(z, 10) = 2;
    cout << (power1(s, 10) = 2) << endl;*/
    // But drop the other shoe!
    power(z, 10) += 10;
  }

  return 0;
}
