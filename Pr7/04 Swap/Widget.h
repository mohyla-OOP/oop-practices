#pragma once
template <typename T>
class Widget
{
 public:
  Widget();
  void set(const T &);
  const T &show() const;

 private:
  // Implementation
  struct Impl;
  // Pointer to Implementation
  Impl *_p;
};
