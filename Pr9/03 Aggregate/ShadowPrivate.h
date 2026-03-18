#ifndef _SHADOW_MAKER_AGGR_
#define _SHADOW_MAKER_AGGR_
#include <iostream>

#include "Shadow.h"
using namespace std;

class PShadowMakerDerivedAss : private ShadowMakerAss
{
 private:
  int _myInt;
  int *_pInt;

 public:
  PShadowMakerDerivedAss(char c, int i) : ShadowMakerAss(c), _myInt(i), _pInt(&_myInt) {};
  inline PShadowMakerDerivedAss &operator=(const PShadowMakerDerivedAss &tar)
  {
    cout << "derived assignment" << endl;
    this->ShadowMakerAss::operator=(tar);
    _myInt = tar._myInt;
    return *this;
  }
  inline const int &getInt() const { return _myInt; }
  inline void *const getPInt() const { return _pInt; }
  inline const char &getChar() const { return ShadowMakerAss::getChar(); }
  inline void *const getPChar() const { return ShadowMakerAss::getPChar(); }
};

inline ostream &operator<<(ostream &os, const PShadowMakerDerivedAss &shm)
{
  os << shm.getChar() << hex << ',' << shm.getPChar() << ':' << dec << shm.getInt() << hex << ',' << shm.getPInt() << endl;
  return os;
}

// Composition
class ShadowMakerCompAss
{
 private:
  ShadowMakerAss _shadm;
  int _myInt;
  int *_pInt;

 public:
  ShadowMakerCompAss(char c, int i) : _shadm(c), _myInt(i), _pInt(&_myInt) {};
  inline ShadowMakerCompAss &operator=(const ShadowMakerCompAss &tar)
  {
    cout << "Composit assignment" << endl;
    _shadm = tar._shadm;
    _myInt = tar._myInt;
    return *this;
  }
  inline const int &getInt() const { return _myInt; }
  inline void *const getPInt() const { return _pInt; }
  inline const char &getChar() const { return _shadm.getChar(); }
  inline void *const getPChar() const { return _shadm.getPChar(); }
};

inline ostream &operator<<(ostream &os, const ShadowMakerCompAss &shm)
{
  os << shm.getChar() << hex << ',' << shm.getPChar() << ':' << dec << shm.getInt() << hex << ',' << shm.getPInt() << endl;
  return os;
}

class ShadowMakerAggrAss
{
 private:
  ShadowMakerAss *_shadm;
  int _myInt;
  int *_pInt;

 public:
  ShadowMakerAggrAss(char c, int i);
  ShadowMakerAggrAss::~ShadowMakerAggrAss();
  ShadowMakerAggrAss &operator=(const ShadowMakerAggrAss &tar);
  inline const int &getInt() const { return _myInt; }
  inline void *const getPInt() const { return _pInt; }
  const char &getChar() const;
  void *const getPChar() const;
};

inline ostream &operator<<(ostream &os, const ShadowMakerAggrAss &shm)
{
  os << shm.getChar() << hex << ',' << shm.getPChar() << ':' << dec << shm.getInt() << hex << ',' << shm.getPInt() << endl;
  return os;
}

class ShadowMakerAggr2Ass
{
 private:
  ShadowMakerAggrAss *_shadm;
  double _myDouble;
  double *_pDouble;

 public:
  ShadowMakerAggr2Ass(char c, int i, double d);
  ShadowMakerAggr2Ass::~ShadowMakerAggr2Ass();
  ShadowMakerAggr2Ass &operator=(const ShadowMakerAggr2Ass &tar);
  inline const double &getDouble() const { return _myDouble; }
  inline void *getPDouble() const { return _pDouble; }
  const int &getInt() const;
  void *const getPInt() const;
  const char &getChar() const;
  void *const getPChar() const;
};

inline ostream &operator<<(ostream &os, const ShadowMakerAggr2Ass &shm)
{
  os << shm.getChar() << hex << ',' << shm.getPChar() << ':' << dec << shm.getInt() << hex << ',' << shm.getPInt() << ':' << dec << shm.getDouble()
     << hex << ',' << shm.getPDouble() << endl;
  return os;
}
#endif