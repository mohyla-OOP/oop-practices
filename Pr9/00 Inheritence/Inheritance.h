#include <iostream>
#include <string>
using namespace std;

// TODO: 1: Explain all the classes, their members and the access specifiers used in the code.
//          Explain what is the protected and what it is function

class Opa
{
 private:
  int _age;
  void priv1() { cout << "1: priv1() from Opa " << endl; }
  void priv2() { cout << "1: priv2() from Opa " << endl; }

 protected:
  int _wealth;
  void prot1() { cout << "1: prot1() from Opa " << endl; }
  void prot2() { cout << "1: prot2() from Opa " << endl; }

 public:
  Opa(int age, int wealth, int seniority) : _age(age), _wealth(wealth), _seniority(seniority) {};
  int _seniority;
  void pub1() { cout << "1: pub1() from Opa " << endl; }
  void pub2() { cout << "1: pub2() from Opa " << endl; }
  void demo()
  {
    cout << "Demo of Opa inside (" << _age << ',' << _wealth << ',' << _seniority << ')' << endl;
    // Check the calls here, check the console
    priv1();
    prot1();
    pub1();
  }
};

class Dad : public Opa
{
 private:
  int _age;
  void priv1() { cout << "2: priv1() from Dad" << endl; }
  void privDad() { cout << "2: privDad() from Dad " << endl; }

 protected:
  int _wealth;
  void prot1() { cout << "2: prot1() from Dad " << endl; }
  void protDad() { cout << "2: protDad() from Dad " << endl; }  // TODO: 6: Define the protDad() in Son public section => Dad::protDad;
 public:
  Dad(int age, int wealth, int seniority) : _age(age), _wealth(wealth), _seniority(seniority), Opa(age + 20, wealth + 100, seniority + 20) {};
  int _seniority;
  void pub1() { cout << "2: pub1() from Dad " << endl; }
  void pubDad() { cout << "2: pubDad() from Dad " << endl; }
  void demo()
  {
    cout << "Demo of Dad inside (" << _age << ',' << _wealth << ',' << _seniority << ')' << endl;
    priv1();
    //		Opa::priv1();
    //		priv2(); not accessable
    privDad();
    cout << "prot1() exists in Dad and Opa; the unqualified call resolves to Dad::prot1(), while qualified calls select a specific base or "
            "current-class version."
         << endl;
    prot1();
    Dad::prot1();
    Opa::prot1();
    prot2();
    Opa::prot2();
    protDad();
    pub1();
    Opa::pub1();
    Dad::pub1();
    pub2();
    pubDad();
  }
};

class Son : public Dad
{
 private:
  int _age;
  void priv1() { cout << "3: priv1() from Son" << endl; }
  void privSon() { cout << "3: privSon() from Son " << endl; }

 protected:
  int _wealth;
  void prot1() { cout << "3: prot1() from Son " << endl; }
  void protSon() { cout << "3: protSon() from Son " << endl; }

 public:
  Son(int age, int wealth, int seniority) : _age(age), _wealth(wealth), _seniority(seniority), Dad(age + 20, wealth + 100, seniority + 20) {};
  int _seniority;
  void pub1() { cout << "3: pub1() from Son " << endl; }
  void pubSon() { cout << "3: pubSon() from Son " << endl; }
  void demo()
  {
    cout << "Demo of Son inside (" << _age << ',' << _wealth << ',' << _seniority << ')' << endl;
    priv1();
    privSon();
    //		Opa::priv1();
    //		priv2(); not accessable
    //		privDad();
    prot1();
    Dad::prot1();
    Opa::prot1();
    prot2();
    protDad();
    pub1();
    Dad::pub1();
    Opa::pub1();
    pub2();
    Opa::pub2();
    pubDad();
  }
};
