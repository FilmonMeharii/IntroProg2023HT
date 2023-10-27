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

void hejTal(int x){
    cout << "Hej heltal "<< x<<endl;
}
void hejTal(double x){
    cout << "Hej pa dig flyttal " << x<<endl;
}
void hejTal(double x, double y){
    cout << "Hej pa er flyttal "<< x << ","<<y << endl;
}
void hejTal(int x, int y, int z){
    cout << "Hej alla tre heltal "<< x << ","<<y <<","<<z<< endl;
}
void testaHejTal(){
    hejTal(2);
    hejTal(2.1);
    hejTal(2, 3);
    //hejTal(2.2, 3.1, 4.3);
    hejTal(2.0, 3.0, 4.0);
    double x=2;
    hejTal(x, 3.0,4.0);
}

void skrivResultat ( int x) {
    cout << " resultatet blev " << x << endl ;
}
int sju () {
    cout << " returnerar 7 ";
    return 7;
}
int tva () {
    cout << " returnerar 2 ";
    return 2;
}
int summan ( int x , int y ){
    int summa = x + y;
    cout << " returnerar summan " << summa ;
    return summa ;
}
void provaNastlatAnrop () {
    skrivResultat ( summan ( tva () , sju () ) ) ;
}

void ingangTillMerOmFunktioner () {

    cout << endl << " ingangTillMerOmFunktioner ....... " << endl ;
    provaNastlatAnrop();
    //testaHejTal();
    //provaBytVarden();
    //provaReferensanrop();
    //provaVardeanrop();
}


//Referensanrop finns inte i programspråket C. Om man i ett C-program
//skriver att en inparameter har datatypen int& får man syntaxfel.
