#include <cstdlib>
#include <iostream>

struct Node
{
  int data;
  Node *next;

  Node(int v, Node *n = nullptr) : data(v), next(n) {}
};

class List
{
  Node *_first = nullptr;

 public:
  List() = default;

  ~List()
  {
    Node *cur = _first;
    while (cur)
    {
      Node *tmp = cur->next;
      delete cur;
      cur = tmp;
    }
  }

  void push_front(int v) { _first = new Node(v, _first); }

  Node *first() const { return _first; }
};

class ListIterator
{
  Node *_current = nullptr;
  const List &_list;

 public:
  ListIterator(const List &lst) : _list(lst), _current(nullptr) {}

  void begin() { _current = _list.first(); }

  bool end() const { return _current == nullptr; }

  int &operator*() { return _current->data; }

  void operator++()
  {
    if (_current) _current = _current->next;
  }
};

template <typename Iter, typename T>
bool find(Iter &it, const T &elem)
{
  while (!it.end())
  {
    if (elem == *it) return true;
    ++it;
  }
  return false;
}

template <typename Iter, typename T>
bool find(Iter &it, const T &elem, bool (*func)(const T &, const T &))
{
  while (!it.end())
  {
    if (func(*it, elem)) return true;
    ++it;
  }
  return false;
}
template <typename T>
bool equal(T x, T y)
{
  return x == y;
}

template <typename Iter, typename T, typename Func>
bool find(Iter &it, const T &elem, Func f)
{
  while (!it.end())
  {
    if (f(*it, elem)) return true;
    ++it;
  }
  return false;
}
