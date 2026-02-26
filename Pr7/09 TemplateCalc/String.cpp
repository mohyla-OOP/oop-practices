#include "String.h"

#include <string>

String::String() : _allocator(new char[1]), _len(0)
{
#ifndef NDEBUG
  cout << "Empty string " << *this << " created" << endl;
#endif
  _allocator[0] = '\0';
  return;
}

String::String(const char c) : _allocator(new char[2]), _len(1)
{
#ifndef NDEBUG
  cout << "One symbol string " << *this << " created" << endl;
#endif
  _allocator[0] = c;
  _allocator[1] = '\0';
  return;
}

String::String(const string &s) : _allocator(new char[s.length() + 1]), _len(s.length())
{
#ifndef NDEBUG
  cout << "String from string" << *this << " created" << endl;
#endif
  copyon(_allocator, s.c_str(), s.length());
  return;
}

String::String(const char *ps) : _len(strlen(ps)), _allocator(new char[_len + 1])
{
  if (ps == 0) throw BadString("Attempt to use not defined pointer");
  copyon(_allocator, ps, strlen(ps));
#ifndef NDEBUG
  cout << "String from char* " << *this << " created" << endl;
#endif
  return;
}

String::String(const String &s, int multiplayer) : _len(multiplayer > 0 ? s._len * multiplayer : s._len), _allocator(new char[_len + 1])
{
  char *target = _allocator;
  for (int i = 0; i < multiplayer; i++)
  {
    copyon(target, s._allocator, s._len);
    target += s._len;
  }
#ifndef NDEBUG
  cout << "String " << *this << " copied" << endl;
#endif
  return;
};

const string String::STL_string() const { return string(_allocator); }

String::~String()
{
  delete[] _allocator;
  return;
}

String &String::operator=(const String &s)
{
  if (this == &s) return *this;
  delete[] _allocator;
  _len = s._len;
  _allocator = new char[_len + 1];
  if (_allocator == 0) throw BadString("No more space in the system");
  copyon(_allocator, s._allocator, s._len);
  return *this;
}

String &String::operator=(const char *ps)
{
  if (ps == 0) throw BadString("Attempt to use not defined pointer");
  delete[] _allocator;
  _len = strlen(ps);
  _allocator = new char[_len + 1];
  copyon(_allocator, ps, strlen(ps));
  return *this;
}

String &String::operator=(const char c)
{
  delete[] _allocator;
  _len = 1;
  _allocator = new char[2];
  _allocator[0] = c;
  _allocator[1] = '\0';
  return *this;
}

// void String::clear()
//{
//	_len=0;
//	delete [] _allocator;
//	_allocator=new char[1];
//	_allocator[0]='\0';
// }

char &String::operator[](size_t i)
{
  if ((i < 0) || (_len <= i)) throw BadString("Bad index: ", i);
  return _allocator[i];
};

const char String::operator[](size_t i) const
{
  if ((i < 0) || (_len <= i)) throw BadString("Bad index: ", i);
  return _allocator[i];
}

void copyon(char *target, const char *source, size_t len)
{
  for (size_t i = 0; i < len; ++i) target[i] = source[i];
  target[len] = '\0';
}

bool operator==(const String &s1, const String &s2)
{
  bool equal = s1.length() == s2.length();
  for (size_t i = 0; (i < s1.length()) && equal; i++) equal = s1[i] == s2[i];
  return equal;
}
bool operator!=(const String &s1, const String &s2) { return !(s1 == s2); }
bool operator<(const String &s1, const String &s2)
{
  bool res = true;
  size_t i = 0;
  while (res && (i < min(s1.length(), s2.length())))
  {
    res = res && (s1[i] == s2[i]);
    i++;
  }
  if (res) return s1.length() < s2.length();
  i--;
  return s1[i] < s2[i];
}

bool operator<=(const String &s1, const String &s2)
{
  if (s1 == s2) return true;
  return s1 < s2;
}
bool operator>(const String &s1, const String &s2) { return !(s1 <= s2); }
bool operator>=(const String &s1, const String &s2) { return !(s1 < s2); }

String &String::operator+=(const String &s)
{
  size_t len = length() + s.length();
  char *newAllocator = new char[len + 1];
  copyon(newAllocator, _allocator, _len);
  copyon(newAllocator + _len, s._allocator, s._len);
  delete _allocator;
  _allocator = newAllocator;
  _len = len;
  return *this;
}

String &String::operator+=(const char *ps)
{
  if (ps == 0) throw String::BadString("Attempt to use not defined pointer");
  size_t len = strlen(ps) + length();
  char *newAllocator = new char[len + 1];
  copyon(newAllocator, _allocator, _len);
  copyon(newAllocator + _len, ps, strlen(ps));
  delete _allocator;
  _allocator = newAllocator;
  _len = len;
  return *this;
}

const String operator+(String s1, const String &s2) { return s1 += s2; }

ostream &operator<<(ostream &os, const String &s)
{
  for (size_t i = 0; i < s.length(); i++) os << s[i];
  return os;
}
