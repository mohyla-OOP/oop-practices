#include "Complex.h"
#include "Itor.h"
#include "Map.h"
#include "Sequence.h"
#include "Set.h"
#include "utilities.h"

int main()
{
  Sequence<int> seq;
  seq.append(1).append(2).append(3).append(4);
  cout << seq << endl;
  {
    List<char> lchar;
    lchar.append('a').append('b').append('c').append('d').append('e').append('f');
    Iterator<char, List<char>> itor(lchar);
    cout << itor;

    itor.begin();
    bool found = find(itor, 'b');
    cout << itor;
    itor.begin();
    find(itor, [](auto x, auto y) { return x >= y; }, 'd');
    cout << itor;
    lchar.append('A').append('B').append('C');
    itor.begin();
    cout << itor;
    itor.begin();
    asort(itor);
    itor.begin();
    cout << itor;
  }
  {
    size_t n = 10;
    Array<int> a(n);
    for (size_t i = 0; i < n; ++i) a[i] = rand();
    Iterator<int, Array<int>> itor(a);
    while (!itor.end())
    {
      cout << *itor << ' ';
      ++itor;
    }
    cout << itor << endl;
    itor.begin();
    sort(itor);
    itor.begin();
    cout << itor << endl;
  }
  {
    const size_t n = 10;
    Array<double[n]> a;
    double x = -10, y = 20, z = 3;
    a[0] = a[1] = x;
    a[2] = y;
    a[3] = z;
    for (size_t i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << endl;
    Iterator<double, Array<double[n]>> itor(a);
    itor.begin();
    cout << itor << endl;
    itor.begin();
    bool found = find(itor, [](double x, double y) { return x < y; }, 100.0);
    if (found) cout << "found " << *itor << endl;
    cout << itor << endl;
    itor.begin();
    found = find(itor, [](auto x, auto y) { return x >= y; }, 100.0);
    if (found) cout << "found " << *itor << endl;
    cout << itor << endl;
  }
  {
    Array<double> a(7);
    double x = 10, y = 20, z = 3;
    a[0] = a[1] = x;
    a[2] = y;
    a[3] = z;
    for (size_t i = 0; i < a.size(); ++i) cout << a[i] << ' ';
    cout << endl;

    Iterator<double, Array<double>> itor(a);
    itor.begin();
    while (!itor.end())
    {
      *itor = *itor * 2;
      ++itor;
    }
    itor.begin();
    cout << itor << endl;
  }
  {
    Sequence<char> seq;
    seq.append('a').append('b').append('c');
    Iterator<char, Sequence<char>> itor(seq);
    itor.begin();
    while (!itor.end())
    {
      *itor = ++*itor;
      ++itor;
    }
    itor.begin();
    cout << itor << endl;
    seq.append('A').append('B').append('C');
    itor.begin();
    cout << itor << endl;
    OutIterator<char, Sequence<char>> out_itor(seq);
    cout << out_itor << endl;
    out_itor.begin();
    bool found = find(out_itor, [](auto x, auto y) { return x < y; }, 'C');
    if (found) cout << "found " << *out_itor << endl;
    cout << out_itor << endl;
  }
  {
    Set<char> set(20);
    set.add('a').add('b').add('c');
    OutIterator<char, Set<char>> itor(set);
    itor.begin();
    cout << itor << endl;
    set.add('A').add('B').add('C');
    itor.begin();
    cout << itor << endl;
    itor.begin();
    bool found = find(itor, [](auto x, auto y) { return x >= y; }, 'A');
    if (found) cout << "found " << *itor << endl;
    cout << itor << endl;
  }
  {
    MultiSet<char> set(20);
    set.add('a').add('b').add('c').add('a').add('b').add('a');
    Iterator<char, MultiSet<char>> itor(set);
    itor.begin();
    cout << itor << endl;
    set.add('A').add('B').add('A');
    itor.begin();
    cout << itor << endl;
    itor.begin();
    bool found = find(itor, 'b');
    if (found) cout << "found " << *itor << endl;
    cout << itor << endl;
    itor.begin();
    asort(itor);
    itor.begin();
    cout << itor << endl;
  }
  {
    using IC = Pair<int, char>;
    Map<int, char> map(20);
    map.add(IC(1, 'a')).add(IC(2, 'a')).add(IC(3, 'b'));
    Iterator<IC, Map<int, char>> itor(map);
    itor.begin();
    cout << itor << endl;
    map.add(IC(1, 'A')).add(IC(4, 'a')).add(IC(3, 'B'));
  }
  {
    using IC = Pair<int, Complex>;
    Map<int, Complex> map(20);
    cout << typeid(map).name() << endl;
    map.add(IC(1, 1)).add(IC(3, 2)).add(IC(1, 3)).add(IC(2, 1)).add(IC(4, 9)).add(IC(1, 8));
    Iterator<Pair<int, Complex>, Map<int, Complex>> itor(map);
    decltype(auto) copy(itor);
    cout << typeid(copy).name() << endl;
    itor.begin();
    cout << itor << endl;
    itor.begin();

    bool found = find(itor, IC(1, 8));
    if (found)
    {
      auto x = *itor;
      cout << typeid(x).name() << ':' << x << endl;
    }
    decltype(itor) itor1(map);
    cout << itor1 << endl;
  }
}