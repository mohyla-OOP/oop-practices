#include "Header.h"
#include "Shadow.h"
#include "ShadowPrivate.h"
unsigned int ShadowMakerNoAssignConst::_freeId = 0;

// Hierarchy with assignments
// Suply every class with an invariant and check them

int main()
{
  ShadowMakerNoAssignConst a('a');
  ShadowMakerNoAssignConst b('b');
  // a = b;
  {
    cout << endl << "+++++++++ DEFAULT ASSIGNMENT ++++++++++++++++" << endl;
    ShadowMakerNoAss nshma('A'), nshmb('B');
    cout << nshma;
    cout << boolalpha << nshma.invariant() << endl;
    cout << nshmb;
    cout << nshmb.invariant() << endl;

    nshma = nshmb;
    cout << nshma;
    cout << boolalpha << nshma.invariant() << endl;
    cout << nshmb;
    cout << nshmb.invariant() << endl;

    ShadowMakerDerivedNoAss ndshma('A', 1), ndshmb('B', 2);
    cout << ndshma;
    cout << ndshmb;

    ndshma = ndshmb;
    cout << ndshma;

    ShadowMakerDerivedNoAss ndshmd('D', 3);
    nshma = ndshmd;
    cout << nshma;

    cout << endl << "+++++++++ COPY ASSIGNMENT ++++++++++++++++" << endl;
    ShadowMakerAss shma('a'), shmb('b');
    cout << shma;
    cout << shmb;

    shma = shmb;
    cout << shma;

    ShadowMakerDerivedAss dshma('a', 1), dshmb('b', 2);
    cout << dshma;
    cout << dshmb;

    dshma = dshmb;
    cout << dshma;

    ShadowMakerDerivedAss dshmd('d', 3);
    shma = dshmd;
    cout << shma << "-------------------" << endl;
  }
  {
    cout << endl << "+++++++++ PRIVATE INHERITANCE ++++++++++++++++" << endl;
    PShadowMakerDerivedAss dshma('a', 1), dshmb('b', 2);
    cout << dshma;
    cout << dshmb;

    dshma = dshmb;
    cout << dshma;
  }
  {
    cout << endl << "+++++++++ LAYERING ++++++++++++++++" << endl;
    ShadowMakerCompAss dshma('a', 1), dshmb('b', 2);
    cout << dshma;
    cout << dshmb;

    dshma = dshmb;
    cout << dshma;
  }
  {
    cout << endl << "+++++++++ AGGREGATING ++++++++++++++++" << endl;
    ShadowMakerAggrAss dshma('a', 1), dshmb('b', 2);
    cout << dshma;
    cout << dshmb;

    dshma = dshmb;
    cout << dshma;
  }
  {
    cout << endl << "+++++++++ AGGREGATING2 ++++++++++++++++" << endl;
    ShadowMakerAggr2Ass dshma('a', 1, 11), dshmb('b', 2, 22);
    cout << dshma;
    cout << dshmb;

    dshma = dshmb;
    cout << dshma;
  }
  return 0;
}