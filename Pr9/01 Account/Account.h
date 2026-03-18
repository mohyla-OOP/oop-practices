#pragma once
#include <iostream>
#include <string>
using namespace std;

// TODO: 1: Overview the code, take attention to the ostream operators

class Account
{
 private:
  static unsigned int _freeID;
  unsigned int _number;
  int _balance;
  string _owner;

 public:
  Account(string owner, int balance) : _owner(owner), _balance(balance), _number(++_freeID) {};
  ~Account() {};
  string getName() const { return _owner; }
  int getBalance() const { return _balance; }
  unsigned int getNumber() const { return _number; }
  void setBalance(int balance) { _balance = balance; }
  // TODO: HW: 8: add method state() here returns int and returns the balance of the account
};

ostream &operator<<(ostream &os, const Account &ac)
{
  os << ac.getName() << ',' << ac.getNumber() << ',' << ac.getBalance() << endl;
  return os;
}

unsigned int Account::_freeID = 0;

class SavingAccount : public Account
{
 private:
  unsigned int _savingRate;
  int _interest;

 public:
  SavingAccount(string owner, int balance, unsigned int savingRate) : Account(owner, balance), _savingRate(savingRate) {};
  ~SavingAccount() {};
  unsigned int getSavingRate() const { return _savingRate; }
  void setInterest(int interest) { _interest = interest; }
  int getInterest() const { return _interest; }
  // TODO: HW: 8: add method state() here returns int and returns the balance of the account
  //          check the operator<< to understand how do we calculate the balance
};

ostream &operator<<(ostream &os, SavingAccount &ac)
{
  ac.setInterest(ac.getBalance() * double(ac.getSavingRate()) / 100);
  os << ac.getName() << ',' << ac.getNumber() << ',' << ac.getBalance() + ac.getInterest() << endl;
  return os;
}

class BonusSavingAccount : public SavingAccount
{
 private:
  unsigned int _bonus;

 public:
  BonusSavingAccount(string owner, int balance, unsigned int savingRate, unsigned int bonus)
      : SavingAccount(owner, balance, savingRate), _bonus(bonus) {};
  ~BonusSavingAccount() {};
  unsigned int getBonus() const { return _bonus; }
};

ostream &operator<<(ostream &os, BonusSavingAccount &ac)
{
  os << ac.getName() << ',' << ac.getNumber() << ',' << ac.getBalance() + ac.getInterest() + ac.getBonus() << endl;
  return os;
}
