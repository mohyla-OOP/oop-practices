#pragma once
template <class Elem>
class ListStack
{
 private:
  size_t _size;
  struct ListNode
  {
    Elem _elem;
    ListNode *_next;
  };
  ListNode *_top;

 public:
  class BadStack
  {
  };
  ListStack();
  ListStack(const ListStack &) = delete;
  ListStack &operator=(const ListStack &) = delete;
  virtual ~ListStack();
  bool empty() const;
  const Elem &top() const;
  void pop();
  void push(const Elem &value);
  size_t size() const;
};

template <class Elem>
ListStack<Elem>::ListStack() : _top(0), _size(0)
{
#ifndef NDEBUG
  cout << "Constructor StackOnList" << endl;
#endif
}
template <class Elem>
ListStack<Elem>::~ListStack()
{
#ifndef NDEBUG
  cout << "Destructor StackOnList" << endl;
#endif
}
template <class Elem>
bool ListStack<Elem>::empty() const
{
  return _top == 0;
}
template <class Elem>
const Elem &ListStack<Elem>::top() const
{
  return _top->_elem;
}
template <class Elem>
void ListStack<Elem>::pop()
{
  if (empty()) throw BadStack();
  ListNode *next;
  next = _top->_next;
  delete _top;
  _top = next;
  _size--;
}
template <class Elem>
void ListStack<Elem>::push(const Elem &value)
{
  ListNode *newnode;
  newnode = new ListNode;
  if (!newnode) throw BadStack();
  newnode->_elem = value;
  newnode->_next = _top;
  _top = newnode;
  _size++;
}
template <class Elem>
size_t ListStack<Elem>::size() const
{
  return _size;
}