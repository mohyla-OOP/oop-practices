#pragma once
//	��������� �� ������������� ����� ������������ ��������
class ShadowMakerNoAssignConst
{
 private:
  static unsigned int _freeId;
  const unsigned int _id;
  char _myChar;
  char *_pChar;

 public:
  ShadowMakerNoAssignConst(char c) : _id(++_freeId), _myChar(c), _pChar(&_myChar) {};
  const char &getChar() const { return _myChar; }
  void *const getPChar() const { return _pChar; }
};