#include <iostream>
#include <functional>
#include "Triangle.h"

int main()
{
    Triangle t({ 0,0 }, { 1,0 }, { 0,1 });
    //TODO: 4: chain operations in mirror .print().scale()...
    t.mirrorX().print();
    auto t2 = t.mirrorX().scale(2);
    t2.print();
    t.mirrorX().scale(2).swapAB().print();

    auto(Triangle:: * op)() = &Triangle::mirrorX;
    (t.*op)().print();

    {
        // invoke callable
        auto op = &Triangle::mirrorX;
        std::invoke(op, t).print();
    }
    {
        // Adapter, convert to function
        auto op = std::mem_fn(&Triangle::mirrorX);
        op(t).print();
    }
    {
        //TODO: 5: lambda return type -> Triange& to chain operations
        auto op = [](Triangle& t) {
            t.mirrorX();
            };

        op(t);
        t.print();
        //TODO: 6: chain operations here
    }
    {
        apply(t, &Triangle::mirrorX);
        t.print();
        apply(t, [](Triangle& t) { t.mirrorX(); });
        t.print();

    }
}