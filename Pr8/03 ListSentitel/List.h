#pragma once
#include <initializer_list>
#include <iostream>

template <typename T>
class List
{
  struct Node
  {
    T _value;
    Node *_next;
    Node *_prev;
    Node() : _next(nullptr), _prev(nullptr) {}
    Node(const T &v) : _value(v), _next(nullptr), _prev(nullptr) {}
  };

  Node *_sentinel;

  // внутрішній helper
  void attach_before(Node *pos, Node *newNode)
  {
    newNode->_prev = pos->_prev;
    newNode->_next = pos;
    pos->_prev->_next = newNode;
    pos->_prev = newNode;
  }

 public:
  // ---- Iterator ----
  struct Iterator
  {
    friend class List<T>;

    Iterator(Node *node) : _node(node) {}

    T &operator*() { return _node->_value; }
    const T &operator*() const { return _node->_value; }
    T *operator->() { return &_node->_value; }

    Iterator &operator++()
    {
      _node = _node->_next;
      return *this;
    }
    Iterator operator++(int)
    {
      Iterator tmp = *this;
      ++(*this);
      return tmp;
    }

    Iterator &operator--()
    {
      _node = _node->_prev;
      return *this;
    }
    Iterator operator--(int)
    {
      Iterator tmp = *this;
      --(*this);
      return tmp;
    }

    bool operator==(const Iterator &o) const { return _node == o._node; }
    bool operator!=(const Iterator &o) const { return _node != o._node; }

   private:
    Node *_node;
  };

  // ---- Конструктори / деструктор ----
  List()
  {
    _sentinel = new Node();
    _sentinel->_next = _sentinel;  // кільце замкнене
    _sentinel->_prev = _sentinel;
  }

  List(std::initializer_list<T> init) : List()
  {
    for (const T &val : init) push_back(val);
  }

  // заборонимо копіювання поки не реалізували
  List(const List &) = delete;
  List &operator=(const List &) = delete;

  ~List()
  {
    Node *cur = _sentinel->_next;
    while (cur != _sentinel)
    {
      Node *tmp = cur->_next;
      delete cur;
      cur = tmp;
    }
    delete _sentinel;
  }

  // ---- Ітерація ----
  Iterator begin() const { return Iterator(_sentinel->_next); }
  Iterator end() const { return Iterator(_sentinel); }

  bool empty() const { return _sentinel->_next == _sentinel; }

  // ---- Модифікація ----
  List &push_back(const T &x)
  {
    attach_before(_sentinel, new Node(x));  // перед sentinel == в кінець
    return *this;
  }

  List &push_front(const T &x)
  {
    attach_before(_sentinel->_next, new Node(x));  // перед першим == на початок
    return *this;
  }

  // insert перед довільним ітератором — тепер тривіально
  Iterator insert(Iterator pos, const T &x)
  {
    Node *newNode = new Node(x);
    attach_before(pos._node, newNode);
    return Iterator(newNode);
  }

  // erase — теж без жодних перевірок
  Iterator erase(Iterator pos)
  {
    Node *node = pos._node;
    Node *next = node->_next;
    node->_prev->_next = node->_next;
    node->_next->_prev = node->_prev;
    delete node;
    return Iterator(next);
  }
};

// ---- operator<< ----
template <typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &list)
{
  for (auto it = list.begin(); it != list.end(); ++it) os << *it << ' ';
  return os;
}
