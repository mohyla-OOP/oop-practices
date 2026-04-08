#pragma once
#pragma once
template <typename T>
class List;
template <class T, class Container>
class ListIterator;
template <class T, class Container>
class Iterator;
template <class T>
class Iterator<T, List<T>>;

template <typename T>
class List
{
 public:
  friend class ListIterator<T, List<T>>;
  friend class Iterator<T, List<T>>;

 private:
  struct Node
  {
    Node(const T &value) : _value(value), _next(0) {}
    T _value;
    Node *_next;
  };

  Node *_first, *_last;

 public:
  List() : _first(0), _last(0) {}
  ~List()
  {
    while (_first)
    {
      Node *tmp = _first->_next;
      delete _first;
      _first = tmp;
    }
  }
  List &append(const T &x)
  {
    _last = (_first ? _last->_next : _first) = new Node(x);
    return *this;
  }
};