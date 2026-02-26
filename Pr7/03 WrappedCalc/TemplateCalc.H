#include "Complex.h"
#include "Wrapper.h"

template <typename Arithm>
class Calc
{
  Arithm _a, _x;

 public:
  Calc(const Arithm &a = 0, const Arithm &x = 0) : _a(a), _x(x) {};
  const Arithm &getA() const { return _a; }
  const Arithm &getX() const { return _x; }
  void setA(const Arithm &a) { _a = a; }
  void setX(const Arithm &x) { _x = x; }
  //  The infix notation does not pass here:
  typedef const Wrapper<Arithm> (*const ArOpPtr)(const Wrapper<Arithm> &, const Wrapper<Arithm> &);
  // TODO: 3: refactor with using and comment line 17
  // TODO: 4: then remove Wrapper<> to work with types directly, what happens then?
  const Arithm doOper(ArOpPtr op) { return _a = op(_a, _x); }
};