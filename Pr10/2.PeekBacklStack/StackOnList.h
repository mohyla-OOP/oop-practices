#ifndef _StackOnList_h
#define _StackDerivedArray_h

template <class Elem>
class Stack;

template <class Elem>
class StackOnList : virtual public Stack<Elem>
{
 private:
  int _size;

  //	Whre is located the fist element
 protected:
  struct ListNode
  {
    Elem _elem;
    ListNode *_next;
  };
  ListNode *_top;
  //	Array<Elem> stackArray;

 public:
  class BadStack
  {
  };
  explicit StackOnList<Elem>() : _top(0), _size(0)
  {
#ifdef _DEBUG_
    cout << "Constructor StackOnList" << endl;
#endif
  };
  virtual ~StackOnList()
  {
#ifdef _DEBUG_
    cout << "Destructor StackOnList" << endl;
#endif
  }
  bool empty() const { return _top == 0; }
  const Elem &top() const { return _top->_elem; }
  void pop()
  {
    if (empty()) throw BadStack();
    ListNode *next;
    next = _top->_next;
    delete _top;
    _top = next;
    _size--;
  }
  void push(const Elem &value)
  {
    ListNode *newnode;
    newnode = new ListNode;
    if (!newnode) throw BadStack();
    newnode->_elem = value;
    newnode->_next = _top;
    _top = newnode;
    _size++;
  }
  int size() const { return _size; }
};

#endif
