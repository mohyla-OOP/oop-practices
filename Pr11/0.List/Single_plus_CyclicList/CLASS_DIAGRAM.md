# 0.List Single_plus_CyclicList Class Diagram

```mermaid
classDiagram
    class IList {
        <<interface>>
        +cons(const Elem& elem)
        +head() const Elem&
        +pop()
        +show(ostream&) ostream&
        +~IList()
    }

    class List {
        -ImpList* _implist
        +List(const Elem& elem)
        +~List()
        +cons(const Elem& elem)
        +head() const Elem&
        +pop()
        -show(ostream&) ostream&
    }

    class CyclicList {
        -ImpCyclicList* _implist
        +CyclicList(const Elem& elem)
        +~CyclicList()
        +cons(const Elem& elem)
        +head() const Elem&
        +pop()
        -show(ostream&) ostream&
    }

    class ImpList {
        #Node* _node
        +ImpList(const Elem& elem)
        +cons(const Elem& elem)
        +head() const Elem&
        +pop()
        +show(ostream&) ostream&
        +~ImpList()
    }

    class ImpCyclicList {
        +ImpCyclicList(const Elem& elem)
        +cons(const Elem& elem)
        +head() const Elem&
        +pop()
        +show(ostream&) ostream&
        +~ImpCyclicList()
    }

    class Node {
        +Elem _elem
        +Node* _next
    }

    IList <|-- List
    IList <|-- CyclicList
    ImpList <|-- ImpCyclicList
    List *-- ImpList : _implist
    CyclicList *-- ImpCyclicList : _implist
    ImpList *-- Node : _node
```
