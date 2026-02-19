class Calc  {
private:
     double _a;
     double _x;
public:
	using Oper = double& (Calc::*) ();

	Calc (const double& a =0,
			const double& x=0): _a(a),_x(x){};
	const double& getA() const {return _a; }
	const double& getX() const {return _x; }
	void setA (const double& a ) { _a = a; }
	void setX (const double& x ) { _x = x; }
//   a += x 
    double& add() { return _a += _x;}
	double& min() { return _a -= _x; }
	double& mlt() { return _a *= _x; } 
	double& div() { return _a /= _x; }
};

double& exe(Calc& c, Calc::Oper op)
{
	return (c.*op)();
}



