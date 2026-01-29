module;
#include <ostream>

export module MComplex;

export class Complex
{
	// Insider
	friend Complex operator+(const Complex& a, const Complex& b);
	friend std::ostream& operator<<(std::ostream& os, const Complex& a);
	
private:
	double _re = 0;
	double _im = 0;
public:
	Complex(double re, double im) :_re(re), _im(im) {}
	Complex(double re) :_re(re) {}
	Complex() {};
};
export Complex operator+(const Complex& a, const Complex& b);
export std::ostream& operator<<(std::ostream& os, const Complex& a);

double normalisePhi(double phi);

export class TComplex
{
	// Insider
	friend std::ostream& operator<<(std::ostream& os, const TComplex& a);
	friend TComplex operator*(const TComplex& a, const TComplex& b);
	
private:
	double _r, _phi;
	
public:
	struct BadRho {
		double _rho;
		BadRho(double r) :_rho(r) {};
	};

	TComplex(double r = 0, double phi = 0) :_r(r), _phi(normalisePhi(phi)) {
		if (r < 0) throw BadRho(r);
	}
};
export std::ostream& operator<<(std::ostream& os, const TComplex& a);
export TComplex operator*(const TComplex& a, const TComplex& b);
