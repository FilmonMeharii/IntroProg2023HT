#include <iostream>
#include <iomanip>

using namespace std ;


void provaLiteraler(){
    cout << endl << "testar berakningar med litteraler" << endl;

    cout << 7/10*500.0 << endl;
    cout << 7/10.0*500 <<endl;
    cout << 3/4 + 3/4 + 3/4 + 3/4 << endl;
    cout << 3.0/4 + 3/4 << endl;
    cout << -58/10 << endl;
}

void provaRest () {
    cout << " Provar restber berakningar ." << endl ;
    cout << 13 % 10 << endl ;
    cout << 57 % 10 << endl ;
    cout << 39 % 20 << endl ;
    cout << -57 % 10 << endl ;
    cout << endl ;
}

void provaHexUtskrift(){
    cout << "Provar hex-utskrift" << endl;
    int x = 256 + 10;

    cout << "1) " << x <<endl;
    cout << "2) " <<hex<< x <<endl;
    cout << "3) " << x <<endl;
    cout << "4) " <<setw(8)<< x <<endl;
    cout << "5) " << setw(8) <<setfill('0')<< x <<endl;
    cout << "6) " <<"x=" <<setw(8)<< ", x=" <<x <<endl;
    cout << dec << setfill(' ');
}

void provaHexLitteraler () {
    cout << " Provar hexlitteraler ." << endl ;
    unsigned int x = 0xa7 ;
    cout << "x = " << x << endl ;

    // Hur stor plats tar en int ?
    int antalOktetter = sizeof ( unsigned int );
    int antalHex = 2* antalOktetter ;
    int antalBit = 8* antalOktetter ;
    cout << "En ( unsigned ) int upptar " << antalOktetter
         << " oktetter ( dvs " << antalHex << " hex - siffror , eller "
         << antalBit << " bit )" << endl ;
    cout << "x = " << hex << setw ( antalHex ) << setfill ('_') << x <<
            endl << endl ;
    cout << dec << setfill (' ');
}

void provaBitvisLogik(){
    cout << "Prova bitvis logik "<<endl;

    unsigned int x = 0x123456;
    unsigned int mask = 0xF0;
    int antalSiffror = 2*sizeof (int);
    cout << hex << setfill('-');

    cout << "1) " << setw(antalSiffror) << x << endl;
    cout << "2) " << setw(antalSiffror) << mask << endl;
    cout << "3) " << setw(antalSiffror) << ~mask<< endl;
    cout << "4) " << setw(antalSiffror) << (x|mask) << endl;
    cout << "5) " << setw(antalSiffror) << (x&~mask) << endl;
    cout << "6) " << setw(antalSiffror) << (x^mask) << endl;

    cout << endl;
    cout << dec << setfill(' ');
}

unsigned int xMedEttstalldBit ( unsigned int x , int bitnummer ){
    unsigned int mask = 1 << bitnummer;
    return x|mask;
}
unsigned int xMedNollstalldBit ( unsigned int x , int bitnummer ){
    unsigned int mask = ~(1 << bitnummer);
    return x&mask;;
}
void testaBitFunktionerna () {
    cout << " testar bitfunktionerna ." << endl ;
    cout << "Bor bli 1: " << xMedEttstalldBit (0 , 0) << endl ;
    cout << "Bor bli 2: " << xMedEttstalldBit (0 , 1) << endl ;
    cout << "Bor bli 4: " << xMedEttstalldBit (0 , 2) << endl ;
    cout << "Bor bli 1024: " << xMedEttstalldBit (0 , 10) << endl ;
    cout << "Bor bli 1025: " << xMedEttstalldBit (1024 , 0) << endl ;
    cout << "Bor bli 1025: " << xMedEttstalldBit (1025 , 0) << endl ;
    cout << "Bor bli 1: " << xMedNollstalldBit (1025 , 10) << endl ;
    cout << "Bor bli 1: " << xMedNollstalldBit (1 , 10) << endl ;
    cout << endl ;
}


unsigned int farginfoFranRGBO ( unsigned int r , unsigned int g , unsigned
                                int b , unsigned int opacity ){
    return (opacity <<24) | (r<<16) | (g<<8) |b;
}
unsigned int blaFranFarginfo ( unsigned int farginfo ){
    return farginfo & 0xFF;
}
unsigned int gronFranFarginfo ( unsigned int farginfo ){
    return (farginfo >> 8) & 0xFF;
}
unsigned int rodFranFarginfo ( unsigned int farginfo ){
    return (farginfo >>16 )& 0xFF;
}
unsigned int opacityFranFarginfo ( unsigned int farginfo ){
    return (farginfo >> 24)& 0xFF;
}
void testaFargFunktionerna () {
    cout << " testar fargfunktionerna ." << endl ;
    unsigned int farg = farginfoFranRGBO (10 ,20 ,30 ,40) ;
    cout << rodFranFarginfo ( farg ) << endl ;
    cout << gronFranFarginfo ( farg ) << endl ;
    cout << blaFranFarginfo ( farg ) << endl ;
    cout << opacityFranFarginfo ( farg ) << endl ;
    cout << endl ;
}
void provaLitteraler(){
    testaFargFunktionerna();
    //testaBitFunktionerna();
    //provaBitvisLogik();
    //provaHexLitteraler();
    //provaHexUtskrift();
    //provaLiteraler();
    //provaRest();
}
