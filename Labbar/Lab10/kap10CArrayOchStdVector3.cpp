#include <iostream> // innehaller cin , cout
#include <cstdlib> // innehaller rand
#include <cmath> // innehaller sqrt

using namespace std ;

void skrivUtvaxelV2(int antalKronor){
    const int antalValorer = 8;
    static const int valorer[antalValorer]{500,200,100,20,10,5,2};

    for (int i=0; i<antalKronor; i++){
        int antal =antalKronor/valorer[i];
        if(antal>0){
            cout << antal << " * " << valorer[i]<<endl;
            antalKronor-=antal*valorer[i];
        }
    }
}
void provaSkrivUtVaxel2(){
    cout << "provaSkrivUtVaxel2" << endl;
    skrivUtvaxelV2(947);
}

void ingangTillCArrayOchStdVector3 () {
    cout << endl << "IngangTillCArrayOchStdVector +++++ " << endl ;
    provaSkrivUtVaxel2();
}
