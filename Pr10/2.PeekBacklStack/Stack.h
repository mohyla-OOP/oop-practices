#define _DEBUG_

template <class StackElem>
class Stack
{
 public:
  virtual bool empty() const = 0;
  virtual const StackElem &top() const = 0;
  virtual void pop() = 0;
  virtual void push(const StackElem &) = 0;
  virtual int size() const = 0;
  virtual ~Stack()
  {
#ifdef _DEBUG_
    cout << "Destructor Stack" << endl;
#endif
  };
};
