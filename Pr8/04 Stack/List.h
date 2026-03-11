#pragma once
#include <initializer_list>
#include <iostream>

// ============================================================
//  List<T> -- doubly linked list with a sentinel node
//
//  The sentinel closes the list into a ring:
//    [sentinel] <-> [1] <-> [2] <-> [3] <-> [sentinel]
//
//  Benefits of sentinel:
//    - no nullptr checks in push/pop/insert/erase
//    - end() is stable -- always points to sentinel
//    - empty list: sentinel._next == &sentinel
// ============================================================
template <typename T>
class List
{
  // NodeBase -- links only, no value
  // Allows sentinel to exist without any requirements on T
  struct NodeBase
  {
    NodeBase *_next;
    NodeBase *_prev;
    NodeBase() : _next(this), _prev(this) {}
  };

  // Node -- full node with a value
  struct Node : NodeBase
  {
    T _value;
    Node(const T &v) : NodeBase(), _value(v) {}
  };

  NodeBase _sentinel;  // plain member -- no new, no pointer

  // Single point of node splicing
  void attach_before(NodeBase *pos, Node *newNode)
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
    Iterator(NodeBase *node) : _node(node) {}

    T &operator*() { return static_cast<Node *>(_node)->_value; }
    const T &operator*() const { return static_cast<const Node *>(_node)->_value; }
    T *operator->() { return &static_cast<Node *>(_node)->_value; }

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
    NodeBase *_node;
    friend class List<T>;  // List can access _node; user cannot
  };

  // ---- Constructors / destructor ----
  List() = default;  // sentinel initialised automatically

  List(std::initializer_list<T> init) : List()
  {
    for (const T &val : init) push_back(val);
  }

  List(const List &) = delete;
  List &operator=(const List &) = delete;

  ~List()
  {
    NodeBase *cur = _sentinel._next;
    while (cur != &_sentinel)
    {
      NodeBase *tmp = cur->_next;
      delete static_cast<Node *>(cur);
      cur = tmp;
    }
  }

  // ---- Iteration ----
  Iterator begin() const { return Iterator(_sentinel._next); }
  Iterator end() const { return Iterator(const_cast<NodeBase *>(&_sentinel)); }

  // ---- State ----
  bool empty() const { return _sentinel._next == &_sentinel; }

  T &back() { return *(--end()); }

  // ---- Modification ----
  List &push_back(const T &x)
  {
    attach_before(&_sentinel, new Node(x));
    return *this;
  }

  List &push_front(const T &x)
  {
    attach_before(_sentinel._next, new Node(x));
    return *this;
  }

  List &pop_back()
  {
    erase(--end());
    return *this;
  }

  Iterator insert(Iterator pos, const T &x)
  {
    Node *newNode = new Node(x);
    attach_before(pos._node, newNode);
    return Iterator(newNode);
  }

  Iterator erase(Iterator pos)
  {
    NodeBase *node = pos._node;
    NodeBase *next = node->_next;
    node->_prev->_next = node->_next;
    node->_next->_prev = node->_prev;
    delete static_cast<Node *>(node);
    return Iterator(next);
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &list)
{
  os << '[';
  auto it = list.begin();
  while (it != list.end())
  {
    os << *it;
    if (++it != list.end()) os << ", ";
  }
  return os << ']';
}
