#pragma once

// ============================================================
//  Stack<T, Base> -- stack adapter over a container Base
//
//  Base must satisfy the minimal interface:
//    push_back(const T&)
//    pop_back()
//    back()  -> T&
//    empty() -> bool
//
//  Default Base is List, but Sequence works too:
//    Stack<int, List>      s1;   // default
//    Stack<int, Sequence>  s2;   // array-backed
//
//  Stack intentionally has no iterator -- LIFO means
//  access to the top only. This is a design choice, not a flaw.
// ============================================================
template <typename T, template <typename> class Base>
class Stack
{
  Base<T> _c;

 public:
  Stack() = default;
  ~Stack() = default;

  Stack(const Stack &) = delete;
  Stack &operator=(const Stack &) = delete;

  bool empty() const { return _c.empty(); }
  const T &top() const { return _c.back(); }
  T &top() { return _c.back(); }

  void push(const T &x) { _c.push_back(x); }
  void pop() { _c.pop_back(); }
};
