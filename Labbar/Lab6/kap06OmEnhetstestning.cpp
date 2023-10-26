#include <iostream>
#include <cassert>

using namespace std ;


void testarMinaKunskaper () {
    cout << " >> testarMinaKunskaper >>" << endl ;
    assert ( 2.5 + 3 == 5.5 );
    assert ( 5/2 == 2 );
    assert ( 1.0/2 * 10 == 5.0);
    //assert ( 1/2 * 10 == 5);
    assert ( (3 | 16) == 19 );
    assert ( (3 | 15) == 15 );
    assert ( (3 & 16) == 0 );
    assert ( (3 & 15) == 3);
    assert ( 3 << 2 == 12 );
    cout << " << testarMinaKunskaper <<" << endl ;
}


void ingangTillOmEnhetstestning () {
    cout << endl << " ingangTillOmEnhetstestning ....... " << endl ;
    testarMinaKunskaper();
}
