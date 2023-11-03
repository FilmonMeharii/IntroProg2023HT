# include <iostream>
# include <cstdlib>
#include <cmath>
#include <cassert>


using namespace std ;
struct Vek2D{
    double m_x;
    double m_y;
};

Vek2D k{1.0, 2.0};
Vek2D vek2dFranXY(double x, double y){
    Vek2D vec;
    vec.m_x = x;
    vec.m_y = y;
    return vec;
}
Vek2D vek2dFranPolar(double radie, double vinkel){
    Vek2D vec;
    vec.m_x = radie*cos(vinkel);
    vec.m_y = radie*sin(vinkel);
    return vec;
}

struct Vaxel3 {
    int antal500 ;
    int antal200 ;
    int antal100 ;
    int antal20 ;
    int antal10 ;
    int antal5 ;
    int antal1 ;
};

// Returnerar ett objekt ifylld med angivna värden
Vaxel3 vaxel3FranAntal (int a500, int a200, int a100, int a20, int a10, int a5, int a1){
    Vaxel3 vaxel;
    vaxel.antal500 = a500;
    vaxel.antal200 = a200;
    vaxel.antal100 = a100;
    vaxel.antal20 = a20;
    vaxel.antal10 = a10;
    vaxel.antal5 = a5;
    vaxel.antal1 = a1;
    return vaxel;
}
// Returnerar ett objekt ifylld med motsvarande belopp
Vaxel3 vaxel3FranBelopp ( int belopp ){
    Vaxel3 vaxel;

    vaxel.antal500 = belopp/500;
    belopp %= 500;
    vaxel.antal200 = belopp/200;
    belopp %= 200;
    vaxel.antal100 = belopp/100;
    belopp %= 100;
    vaxel.antal20 = belopp/20;
    belopp %= 20;
    vaxel.antal10 = belopp/10;
    belopp %= 10;
    vaxel.antal5 = belopp/5;
    belopp %= 5;
    vaxel.antal1 = belopp/1;
    belopp %= 1;
    vaxel.antal1=belopp;
    return vaxel;
}
// Returnerar det belopp som motsvarar objektet vaxel
int beloppFranVaxel ( const Vaxel3 & vaxel ){
    return
            vaxel.antal500*500 +
            vaxel.antal200*200+
            vaxel.antal100*100+
            vaxel.antal20*20 +
            vaxel.antal10*10 +
            vaxel.antal5*5 +
            vaxel.antal1*1;
}
// Skriver ut växeln på skärmen
void skrivUtVaxel ( const Vaxel3 & vaxel ){
    cout << "500* " << vaxel.antal500 << endl;
    cout << "200* " << vaxel.antal200 << endl;
    cout << "100* " << vaxel.antal100 << endl;
    cout << "20* " << vaxel.antal20 << endl;
    cout << "10* " << vaxel.antal10 << endl;
    cout << "5* " << vaxel.antal5 << endl;
    cout << "1* " << vaxel.antal1 << endl;
}
bool arLika ( const Vaxel3 &v1 , const Vaxel3 & v2 ){
    return
            v1.antal500 == v2.antal500 &&
            v1.antal200 == v2.antal200 &&
            v1.antal100 == v2.antal100 &&
            v1.antal20 == v2.antal20 &&
            v1.antal10 == v2.antal10 &&
            v1.antal5 == v2.antal5 &&
            v1.antal1 == v2.antal1;

}
// Automattestar de funktioner som har med Vä xel att göra
void automattestaVaxel () {
        assert ( arLika ( vaxel3FranBelopp (947) , vaxel3FranAntal (1 ,2 ,0 ,2 ,0 ,1 ,0) ) );
        Vaxel3 vaxel = vaxel3FranBelopp (836) ;
        assert ( beloppFranVaxel ( vaxel ) == 836 );
}
// Skriver ut vä xeln på skä rmen
void skrivUtVaxelV3 ( int belopp ){
    skrivUtVaxel ( vaxel3FranBelopp ( belopp ) );
}

void ingangTillStructar () {
    cout << endl << " ingangTillStructar +++++ " << endl ;
   skrivUtVaxelV3(947);
   automattestaVaxel();

}
