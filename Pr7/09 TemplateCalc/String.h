#ifndef _string_h_
#define _string_h_

#include <iostream>
using namespace std;
#include <string>

class String
{
 private:
  size_t _len;
  char *_allocator;

 public:
  class BadString;

  String();
  String(const char *);
  String(const char);
  String(const string &);
  String(const String &s, int multiplayer = 1);

  ~String();

  String &operator=(const String &);
  String &operator=(const char *);
  String &operator=(const char);

  const string STL_string() const;
  const char *c_str() const { return _allocator; }
  size_t length() const { return _len; }

  bool empty() const { return _len == 0; }
  void clear() { *this = String(); }

  char &operator[](size_t);
  const char operator[](size_t) const;

  String &operator+=(const String &);
  String &operator+=(const char *);
};

void copyon(char *, const char *, size_t);

bool operator==(const String &, const String &);
bool operator!=(const String &s1, const String &s2);

bool operator<(const String &, const String &);
bool operator<=(const String &s1, const String &s2);
bool operator>(const String &s1, const String &s2);
bool operator>=(const String &s1, const String &s2);

const String operator+(String s1, const String &s2);

ostream &operator<<(ostream &, const String &);

class String::BadString
{
 private:
  string _reason;
  size_t _index;

 public:
  BadString(string reason = "", size_t index = 0) : _reason(reason), _index(index) { return; };
  ~BadString() {};
  void diagnose() const
  {
    cerr << _reason;
    if (_index != 0) cerr << ' ' << _index;
    cerr << endl;
  }
};

#endif