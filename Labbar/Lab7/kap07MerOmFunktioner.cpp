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

double storst ( double a , double b) {
    if(a>b)
        return a;
    return b;
}
double storst ( double a , double b , double c){
    if(storst(a,b)>c)
        return storst(a,b);
    return c;
}
double storst ( double a , double b , double c , double d){
    if(storst(a,b,c)>d)
        return storst(a,b,c);
    return d;
}
double storst ( double a , double b , double c , double d , double e ){
    if(storst(a,b,c,d)>e)
        return storst(a,b,c,d);
    return e;
}
void provaAllaStorst () {
    cout << storst ( 3 ,7 ) << endl ; // 7
    cout << storst ( 3, 8, 7 , 5 ) << endl ; // 8
    cout << storst (1 , 3, 2, 9, 8) << endl ; // 9
    cout << storst (5.2 , 4.3 , 10.5 , 10.4) << endl ; // 10.5
    assert ( storst (2.0 , 2.5 , 1.0) > 2.4 );
    assert ( storst (2 , 3, 1, 8 ,3) == 8 );
}



void ingangTillMerOmFunktioner () {

    cout << endl << " ingangTillMerOmFunktioner ....... " << endl ;
    provaAllaStorst();
    //provaNastlatAnrop();
    //testaHejTal();
    //provaBytVarden();
    //provaReferensanrop();
    //provaVardeanrop();
}


//Referensanrop finns inte i programspråket C. Om man i ett C-program
//skriver att en inparameter har datatypen int& får man syntaxfel.
