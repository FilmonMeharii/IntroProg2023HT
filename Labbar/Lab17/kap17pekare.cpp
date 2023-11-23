#include <iostream>
#include <cassert>

using namespace std;

void ovaPaPekarnotation () {
    cout << "Ovar pa pekarnotation " << endl ;
    double x = 1.0;
    double *pX =&x;
    double **ppX = &pX;
    double ***pppX = &ppX;
    ***pppX = 2.0;
    cout << "x ar nu " << x << endl ;
    assert ( x == 2.0) ;
    cout << "Oningen lyckades ." << endl ;
}

void ingangTillPekare(){
    cout << "Ingang till pekare +++++++ "<< endl;
    ovaPaPekarnotation();
}
