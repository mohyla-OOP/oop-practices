#ifndef _PeekbackStack_h
#define _PeekbackStack_h

template <class Elem>
class StackAgregatingArray;
template <class Elem>
class StackDerivedArray;
template <class Elem>
class StackOnList;

#define _DEBUG_

template <class Elem>
class PeekBack
{
  //	double x;
 public:
  virtual bool peekback(int i, Elem &elem) const = 0;
  virtual ~PeekBack()
  {
#ifdef _DEBUG_
    cout << "Destructor PeekBack" << endl;
#endif
  }
};

template <class Elem>
class PeekbackStack
    : virtual public Stack<Elem>
    , public PeekBack<Elem>
{
 public:
  virtual bool peekback(int i, Elem &elem) const = 0;
  virtual ~PeekbackStack()
  {
#ifdef _DEBUG_
    cout << "Destructor PeekBackStack" << endl;
#endif
  }
};

template <class Elem>
class AgregatingPeekbackStack
    : public StackAgregatingArray<Elem>
    , public PeekbackStack<Elem>
{
 public:
  //	Its own functions
  AgregatingPeekbackStack(int size) : StackAgregatingArray<Elem>(size)
  {
#ifdef _DEBUG_
    cout << "Constructor AgregatingPeekbackStack " << size << endl;
#endif
  };
  virtual ~AgregatingPeekbackStack()
  {
#ifdef _DEBUG_
    cout << "Destructor AgregatingPeekbackStack" << endl;
#endif
  }
  virtual bool peekback(int i, Elem &elem) const
  {
    if (i < 0 || i >= volume()) throw StackAgregatingArray<Elem>::BadStack();
    if (i > _top)
    {
      elem = top();
      return false;
    }
    elem = stackArray[i];
    return true;
  };
};

template <class Elem>
class DerivedPeekbackStack
    : public StackDerivedArray<Elem>
    , public PeekbackStack<Elem>
{
 public:
  //	Its own functions
  DerivedPeekbackStack(int size) : StackDerivedArray<Elem>(size)
  {
#ifdef _DEBUG_
    cout << "Constructor DerivedPeekbackStack " << size << endl;
#endif
  };
  virtual ~DerivedPeekbackStack()
  {
#ifdef _DEBUG_
    cout << "Destructor DerivedPeekbackStack" << endl;
#endif
  }
  virtual bool peekback(int i, Elem &elem) const
  {
    if (i < 0 || i >= volume()) throw StackDerivedArray<Elem>::BadStack();
    if (i > _top)
    {
      elem = top();
      return false;
    }
    elem = (*this)[i];
    return true;
  };
};

template <class Elem>
class ListedPeekbackStack
    : public StackOnList<Elem>
    , public PeekbackStack<Elem>
{
 public:
  //	Its own functions
  ListedPeekbackStack()
  {
#ifdef _DEBUG_
    cout << "Constructor ListedPeekbackStack " << endl;
#endif
  };
  virtual ~ListedPeekbackStack()
  {
#ifdef _DEBUG_
    cout << "Destructor ListedPeekbackStack " << endl;
#endif
  }
  virtual bool peekback(int i, Elem &elem) const
  {
    if (empty()) throw StackOnList<Elem>::BadStack();
    ListNode *cur = _top;
    for (int k = 0; k < i; k++)
    {
      if (!(cur->_next))
      {
        elem = cur->_elem;
        return false;
      }
      cur = cur->_next;
    }
    elem = cur->_elem;
    return true;
  };
};
#endif