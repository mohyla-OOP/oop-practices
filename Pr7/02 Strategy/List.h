#include "DeletePolicy.h"
// template <class Item>
// class List;
#include <iostream>
using namespace std;

// TODO: 4: How the type of data in list is defined?
// TODO: 5: Check delete policy
template <class Item, template <typename> class DeletePolicy>
class List
{
 public:
  List();
  ~List();

  List &append(const Item &);

 private:
  struct Node
  {
    Item _elem;
    Node *_next;
  };
  //	Where the first element is located
  Node *_head;
  //	Where the last element is located
  Node *_end;
};

template <class Item, template <typename Item> class DeletePolicy>
List<Item, DeletePolicy>::List() : _head(nullptr), _end(nullptr)
{
}

template <class Item, template <typename Item> class DeletePolicy>
List<Item, DeletePolicy>::~List()
{
  if (_head == nullptr) return;
  do
  {
    // TODO: 5: Do delete, what is it? From where is it taken?
    DeletePolicy<Item>::doDelete(_head->_elem);
    Node *node = _head;
    _head = _head->_next;
    delete node;
  } while (_head != nullptr);
}

template <class Item, template <typename Item> class DeletePolicy>
List<Item, DeletePolicy> &List<Item, DeletePolicy>::append(const Item &item)
{
  Node *node = new Node;
  node->_elem = item;
  if (_head == nullptr)
  {
    node->_next = nullptr;
    _head = _end = node;
  }
  else
  {
    _end->_next = node;
    node->_next = nullptr;
    _end = node;
  }
  return *this;
}