#include "Account.h"

int main()
{
  IAccount *ac = new Account("Ivanenko", 100);
  cout << *ac;

  SavingAccount *sac = new SavingAccount("Petrenko", 200, 10);
  cout << *sac;

  BonusSavingAccount *bsac = new BonusSavingAccount("Pavlenko", 300, 20, 100);
  cout << *bsac;

  return 0;
}