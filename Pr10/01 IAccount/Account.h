#pragma once
#include <iostream>
#include <string>
using namespace std;

class IAccount
{
 public:
  virtual int getBalance() const = 0;
  virtual ~IAccount() {};
  virtual string getName() const = 0;
  virtual unsigned int getNumber() const = 0;
};

ostream &operator<<(ostream &os, const IAccount &ac)
{
  os << ac.getName() << ',' << ac.getNumber() << ',' << ac.getBalance() << endl;
  return os;
}

class Account : public IAccount
{
 private:
  static unsigned int _freeID;
  unsigned int _number;
  int _balance;
  string _owner;

 public:
  Account(string owner, int balance) : _owner(owner), _balance(balance), _number(++_freeID) {}
  ~Account() {};
  string getName() const { return _owner; }
  int getBalance() const { return _balance; }
  unsigned int getNumber() const { return _number; }
  void setBalance(int balance) { _balance = balance; }
};

unsigned int Account::_freeID = 0;

class SavingAccount : public IAccount
{
 private:
  Account *_account;
  double _savingRate;
  int _balance;

 public:
  SavingAccount(string owner, int balance, double savingRate) : _account(new Account(owner, balance)), _savingRate(1 + savingRate / 100.)
  {
    setBalance();
  }
  ~SavingAccount() {};
  string getName() const { return _account->getName(); }
  unsigned int getNumber() const { return _account->getNumber(); }
  unsigned int getSavingRate() const { return _savingRate; }
  void setBalance() { _balance = _account->getBalance() * _savingRate; }
  int getBalance() const { return _balance; }
};

class BonusSavingAccount : public IAccount
{
 private:
  SavingAccount *_account;
  unsigned int _bonus;
  int _balance;

 public:
  BonusSavingAccount(string owner, int balance, unsigned int savingRate, unsigned int bonus)
      : _account(new SavingAccount(owner, balance, savingRate)), _bonus(bonus)
  {
    setBalance();
  }
  ~BonusSavingAccount() {};
  unsigned int getBonus() const { return _bonus; }
  int getBalance() const { return _balance; }
  string getName() const { return _account->getName(); }
  unsigned int getNumber() const { return _account->getNumber(); }
  void setBalance() { _balance = _account->getBalance() + _bonus; }
};
