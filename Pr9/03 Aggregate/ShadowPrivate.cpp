#include "ShadowPrivate.h"

ShadowMakerAggrAss::ShadowMakerAggrAss(char c, int i) : _shadm(new ShadowMakerAss(c)), _myInt(i), _pInt(&_myInt) {};
ShadowMakerAggrAss &ShadowMakerAggrAss::operator=(const ShadowMakerAggrAss &tar)
{
  cout << "Composit assignment" << endl;
  *_shadm = *(tar._shadm);
  _myInt = tar._myInt;
  return *this;
}
const char &ShadowMakerAggrAss::getChar() const { return _shadm->getChar(); }
void *const ShadowMakerAggrAss::getPChar() const { return _shadm->getPChar(); }
ShadowMakerAggrAss::~ShadowMakerAggrAss() { delete _shadm; }

ShadowMakerAggr2Ass::ShadowMakerAggr2Ass(char c, int i, double d) : _shadm(new ShadowMakerAggrAss(c, i)), _myDouble(d), _pDouble(&_myDouble) {};
ShadowMakerAggr2Ass &ShadowMakerAggr2Ass::operator=(const ShadowMakerAggr2Ass &tar)
{
  cout << "Composit assignment" << endl;
  *_shadm = *(tar._shadm);
  _myDouble = tar._myDouble;
  return *this;
}
const char &ShadowMakerAggr2Ass::getChar() const { return _shadm->getChar(); }
void *const ShadowMakerAggr2Ass::getPChar() const { return _shadm->getPChar(); }
const int &ShadowMakerAggr2Ass::getInt() const { return _shadm->getInt(); }
void *const ShadowMakerAggr2Ass::getPInt() const { return _shadm->getPInt(); }
ShadowMakerAggr2Ass::~ShadowMakerAggr2Ass() { delete _shadm; }