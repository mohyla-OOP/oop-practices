#include "Account.h"
// How to fix lost bonuses?
// TODO: 9: How differs line 12 from line 27?
int main()
{
  Account ac("Ivanenko", 100);
  Account *pac = &ac;
  cout << *pac;

  SavingAccount sac("Petrenko", 200, 10);
  cout << sac;
  pac = &sac;  // We point to the area in memory where the SavingAccount object is located, but we can only access the Account part of it, because pac
               // is a pointer to Account.
  cout << *pac;                // We never assign objects of derived classes to object of base class, because of object slicing.
  SavingAccount *psac = &sac;  // TODO: 5: set a breakpoint here, check the console, what happens in the previous line? Why money has been lost?
  cout << *psac;

  BonusSavingAccount bsac("Pavlenko", 300, 20, 100);
  pac = &bsac;
  cout << *pac;  // TODO: 6: What is the "pac"? set a breakpoint and step into? In a method of which class we are now?
  psac = &bsac;
  cout << *psac;  // TODO: 7: same as in 6, but where we are now?
  BonusSavingAccount *pbsac = &bsac;
  cout << *pbsac;

  cout << sac;
  // TODO: 2: set breakpoint here, check console and explain what "sac" variable contains?
  Account forgetful = sac;  // Object slicing occurs here, only the Account part of sac is copied
  cout << forgetful;        // TODO: 3: make a step here, explain what happened in the previous code line

  SavingAccount forgetBonus = bsac;  // TODO: 4: check console, what happened with balance of Petrenko
  cout << forgetBonus;
  return 0;
}