#pragma once
// Modify class CList into a specialization of the class TList

// TODO: 3: refactor to using
typedef char Item;
// TODO: 1: what is the list?
class CList
{
 public:
  CList();
  ~CList();
  CList &append(const Item &);

 private:
  // TODO: 2: What data is stored in the Node?
  struct Node
  {
    Item _elem;
    Node *_next;
  };
  //	Where the fist element is located
  Node *_head;
  //	Where the last element is located
  Node *_end;
};
