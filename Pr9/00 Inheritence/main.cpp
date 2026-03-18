// ************************************************
//
//	1. Run the program and examine the results
//	2. Code and run tests for clients of the classes
//		Opa, Dad and Son
//
//	***********************************************

#include "Inheritance.h"

int main()
{
  Opa opa(50, 400, 25);
  opa.demo();  // TODO: 2: Set a breakpoint in the demo() and analyze the call sequence

  Dad dad(40, 100, 15);
  cout << "dad.demo() call sequence: Dad::demo -> Dad::priv1 -> Dad::privDad -> "
          " Dad::prot1 -> Dad::prot1 -> Opa::prot1 -> Opa::prot2 -> Opa::prot2 ->"
          " Dad::protDad -> Dad::pub1 -> Opa::pub1 -> Dad::pub1 -> Opa::pub2 ->"
          " Dad::pubDad"
       << endl;
  dad.demo();
  dad.Opa::demo();

  Son son(10, 0, 0);
  son.demo();  // TODO: 5: Set a breakpoint in the demo() and analyze the call sequence
  son.Dad::demo();
  son.Opa::demo();

  return 0;
}
