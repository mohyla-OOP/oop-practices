# 02 Assignment Composit Class Diagram

```mermaid
classDiagram
    class A {
        -int _x
        -int* _px
        +A(int x)
        +dump(const char* name)
        +operator=(const A& rhs) A&
    }

    class B {
        -int _y
        -int* _py
        -A _a
        +B(int x, int y)
        +dump(const char* name)
        +dump()
        +operator=(const B& rhs) B&
    }

    B *-- A : _a
```
