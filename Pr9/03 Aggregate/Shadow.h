#ifndef _SHADOW_MAKER_
#define _SHADOW_MAKER_
#include <iostream>
using namespace std;

class ShadowMakerAss
{
 private:
  char _myChar;
  char *_pChar;

 public:
  ShadowMakerAss(char c) : _myChar(c), _pChar(&_myChar) {};
  ShadowMakerAss &operator=(const ShadowMakerAss &tar)
  {
    cout << "base assignment" << endl;
    _myChar = tar._myChar;
    return *this;
  }
  const char &getChar() const { return _myChar; }
  void *const getPChar() const { return _pChar; }
  bool invariant() const { return &_myChar == _pChar; }
};

inline ostream &operator<<(ostream &os, const ShadowMakerAss &shm)
{
  os << shm.getChar() << hex << ',' << shm.getPChar() << endl;
  return os;
}

class ShadowMakerDerivedAss : public ShadowMakerAss
{
 private:
  int _myInt;
  int *_pInt;

 public:
  ShadowMakerDerivedAss(char c, int i) : ShadowMakerAss(c), _myInt(i), _pInt(&_myInt) {};
  ShadowMakerDerivedAss &operator=(const ShadowMakerDerivedAss &tar)
  {
    cout << "derived assignment" << endl;
    this->ShadowMakerAss::operator=(tar);
    _myInt = tar._myInt;
    return *this;
  }
  const int &getInt() const { return _myInt; }
  void *const getPInt() const { return _pInt; }
};

inline ostream &operator<<(ostream &os, const ShadowMakerDerivedAss &shm)
{
  os << shm.getChar() << hex << ',' << shm.getPChar() << ':' << dec << shm.getInt() << hex << ',' << shm.getPInt() << endl;
  return os;
}

class ShadowMakerNoAss
{
 private:
  char _myChar;
  char *_pChar;

 public:
  ShadowMakerNoAss(char c) : _myChar(c), _pChar(&_myChar) {};
  const char &getChar() const { return _myChar; }
  void *const getPChar() const { return _pChar; }
  bool invariant() const { return &_myChar == _pChar; }
};

inline ostream &operator<<(ostream &os, const ShadowMakerNoAss &shm)
{
  os << shm.getChar() << hex << ',' << shm.getPChar() << endl;
  return os;
}

class ShadowMakerDerivedNoAss : public ShadowMakerNoAss
{
 private:
  int _myInt;
  int *_pInt;

 public:
  ShadowMakerDerivedNoAss(char c, int i) : ShadowMakerNoAss(c), _myInt(i), _pInt(&_myInt) {};
  const int &getInt() const { return _myInt; }
  void *const getPInt() const { return _pInt; }
};

inline ostream &operator<<(ostream &os, const ShadowMakerDerivedNoAss &shm)
{
  os << shm.getChar() << hex << ',' << shm.getPChar() << ':' << dec << shm.getInt() << hex << ',' << shm.getPInt() << endl;
  return os;
}
#endif