#include <iostream>

#include "Array.h"
#include "List.h"
#include "Sequence.h"
#include "Stack.h"

void section(const char *title) { std::cout << "\n=== " << title << " ===\n"; }

// ============================================================
//  1. Array<T>
// ============================================================
void demo_array()
{
  section("Array");

  Array<int> a = {10, 20, 30, 40, 50};
  std::cout << "size: " << a.size() << '\n';
  std::cout << "a[2] = " << a[2] << '\n';

  a[2] = 99;
  std::cout << "a[2] after assignment = " << a[2] << '\n';

  a.resize(8);
  std::cout << "size after resize(8): " << a.size() << '\n';
  std::cout << "a[6] (new, zero-initialised) = " << a[6] << '\n';

  try
  {
    int x = a[100];
    (void) x;
  }
  catch (const std::runtime_error &e)
  {
    std::cout << "Exception: " << e.what() << '\n';
  }
}

// ============================================================
//  2. Sequence<T> -- sequence built on Array
// ============================================================
void demo_sequence()
{
  section("Sequence");

  Sequence<int> s = {1, 2, 3};
  std::cout << "initial: " << s << '\n';
  std::cout << "size=" << s.size() << " capacity=" << s.capacity() << '\n';

  s.append(4).append(5);
  std::cout << "after append(4, 5): " << s << '\n';

  s.insert(99, 2);
  std::cout << "after insert(99, 2): " << s << '\n';

  s.remove(2);
  std::cout << "after remove(2): " << s << '\n';

  s.pop_back();
  std::cout << "after pop_back: " << s << '\n';

  std::cout << "back = " << s.back() << '\n';

  Sequence<int> empty_seq;
  std::cout << "empty sequence: " << empty_seq << '\n';
  std::cout << "empty(): " << empty_seq.empty() << '\n';
}

// ============================================================
//  3. List<T> -- doubly linked list with sentinel
// ============================================================
void demo_list()
{
  section("List");

  List<int> lst = {1, 2, 3, 4, 5};
  std::cout << "initial: " << lst << '\n';

  lst.push_back(6);
  lst.push_front(0);
  std::cout << "after push_back(6), push_front(0): " << lst << '\n';

  auto it = lst.begin();
  ++it;
  ++it;
  lst.insert(it, 99);
  std::cout << "after insert(99) at position 2: " << lst << '\n';

  it = lst.begin();
  ++it;
  ++it;
  lst.erase(it);
  std::cout << "after erase at position 2: " << lst << '\n';

  // range-based for works because begin()/end() are defined
  std::cout << "doubled values: ";
  for (auto &val : lst) std::cout << val * 2 << ' ';
  std::cout << '\n';

  // backward iteration via operator--
  std::cout << "reverse order: ";
  for (auto rit = --lst.end(); rit != lst.begin(); --rit) std::cout << *rit << ' ';
  std::cout << *lst.begin() << '\n';
}

// ============================================================
//  4. Stack<T, Base> -- adapter over List and Sequence
// ============================================================
void demo_stack()
{
  section("Stack over List (default)");

  Stack<int, List> s1;
  s1.push(10);
  s1.push(20);
  s1.push(30);

  std::cout << "top: " << s1.top() << '\n';
  s1.pop();
  std::cout << "top after pop: " << s1.top() << '\n';
  std::cout << "empty: " << s1.empty() << '\n';

  section("Stack over Sequence");

  Stack<int, Sequence> s2;
  s2.push(100);
  s2.push(200);
  s2.push(300);

  while (!s2.empty())
  {
    std::cout << s2.top() << ' ';
    s2.pop();
  }
  std::cout << '\n';
  std::cout << "empty after draining: " << s2.empty() << '\n';
}

// ============================================================
//  EXERCISES FOR STUDENTS
// ============================================================

// EXERCISE 1: Implement copy constructor for Array<T>
// Hint: allocate new memory and copy elements
//
// Array<int> a1 = {1, 2, 3};
// Array<int> a2 = a1;   // must work after your implementation
// a2[0] = 99;
// std::cout << a1[0];   // must still print 1

// EXERCISE 2: Implement Queue<T, Base> analogous to Stack
// Queue uses FIFO: push adds to the back, pop removes from the front
// Hint: List already has push_back; you need to add pop_front
//
// template<typename T, template<typename> class Base>
// class Queue { ... };

// EXERCISE 3: Add size() to List<T>
// Hint 1: store a counter _size as a field
// Hint 2: update it in push_back, push_front, pop_back, erase, insert
// Hint 3: what happens to size() after insert and erase?

// EXERCISE 4: Write a function that checks whether a string is a palindrome
// using Stack<char, Sequence>
//
// bool is_palindrome(const std::string& s) { ... }
// std::cout << is_palindrome("racecar");  // 1
// std::cout << is_palindrome("hello");    // 0

int main()
{
  demo_array();
  demo_sequence();
  demo_list();
  demo_stack();

  std::cout << "\nDone.\n";
  return 0;
}
