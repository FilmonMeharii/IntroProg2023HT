#include <iostream>
#include <cassert>

using namespace std ;


void testarMinaKunskaper () {
    cout << " >> testarMinaKunskaper >>" << endl ;
    assert ( 2.5 + 3 == 5.5 );
    assert ( 5/2 == 2 );
    assert ( 1.0/2 * 10 == 5.0);
    assert ( 1/2 * 10 == 5);
    assert ( (3 | 16) == 19 );
    assert ( (3 | 15) == 15 );
    assert ( (3 & 16) == 0 );
    assert ( (3 & 15) == 3);
    assert ( 3 << 2 == 12 );
    cout << " << testarMinaKunskaper <<" << endl ;
}

bool ungefarLika1(double a, double b){
    if(a ==b)
        return false;
    return true;
}

bool ungefarLika ( double x , double y){ // BUGG
    return x -y < 0.001;
}
bool ungefarLika ( double , double );
void automattestaUngefarLika () {
    cout << " >> automattestaUngefarLika >>" << endl ;
    assert ( ungefarLika ( 2 , 2.000005 ) ) ;
    assert ( ungefarLika ( 2 -0.000005 , 2 ) );
    assert ( ! ungefarLika (2 , 3) );
    assert ( ! ungefarLika (3 ,2) );
    cout << " << automattestaUngefarLika <<" << endl ;
}

unsigned int farginfoFranRGBO ( unsigned int r , unsigned int g ,
                                unsigned int b , unsigned int opacity ){
    assert ( r <256 && g <256 && b <256
             && opacity <256) ;// pre - condition
    // TODO
    return 0;
}

void ingangTillOmEnhetstestning () {
    cout << endl << " ingangTillOmEnhetstestning ....... " << endl ;
    farginfoFranRGBO(5,5,6,7);
    //automattestaUngefarLika();
    //testarMinaKunskaper();
}
