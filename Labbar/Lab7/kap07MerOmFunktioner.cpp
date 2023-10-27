#include <iostream>
#include <cassert>

using namespace std ;

void demoAvVardeanrop(int x){
    x*=2;
    cout << "x ar nu "<<x<<endl;
}
void provaVardeanrop(){
    int a = 10;
    demoAvVardeanrop(a);
    cout << " a ar nu "<< a<<endl;
}

void demoAvReferesanrop(int& x){
    x*=2;
    cout << "x ar nu "<<x << endl;
}
void provaReferensanrop(){
    int a = 10;
    demoAvReferesanrop(a);
    cout << "a ar nu "<< a<<endl;
}

void bytVarden(int &a, int &b){
    int temp = a;
    a=b;
    b=temp;
}

void provaBytVarden(){
    int a{42};
    int b{108};
    bytVarden(a, b);
    cout << "a ar nu " << a << endl;
    cout <<" b  ar nu "<< b << endl;
    assert(a==108 && b==42 );
}
void ingangTillMerOmFunktioner () {

    cout << endl << " ingangTillMerOmFunktioner ....... " << endl ;
    provaBytVarden();
    //provaReferensanrop();
    //provaVardeanrop();
}


//Referensanrop finns inte i programspråket C. Om man i ett C-program
//skriver att en inparameter har datatypen int& får man syntaxfel.
