#pragma once
#include <iostream>
#include <set>
#include <type_traits>
#include <vector>

template <typename T>
concept arithmetic = std::is_arithmetic_v<T>;
template <arithmetic T>
class AbstractContainer
{
 public:
  virtual void add(const T &) = 0;
  virtual void print() const = 0;
};
template <arithmetic T>
void useContainer(AbstractContainer<T> &c)
{
  c.add(10);
  c.add(5);
  c.print();
}

template <typename T>
class VectorContainer : public AbstractContainer<T>
{
 public:
  void add(const T &value) override { data.push_back(value); }
  void print() const override
  {
    for (const auto &item : data) std::cout << item << " ";
    std::cout << std::endl;
  }

 private:
  std::vector<T> data;
};
template <typename T>
class SetContainer : public AbstractContainer<T>
{
 public:
  void add(const T &value) override { data.insert(value); }
  void print() const override
  {
    for (const auto &item : data) std::cout << item << " ";
    std::cout << std::endl;
  }

 private:
  std::set<T> data;
};

template <typename T>
class GostakContainer : public AbstractContainer<T>
{
 public:
  void add(const T &value) override {}

  void print() const override { std::cout << "The gostak distims the doshes" << std::endl; }
};
