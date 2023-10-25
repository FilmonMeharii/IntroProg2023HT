#include <iostream>

using namespace std ;

void undersokHeltalsTyper(){

    cout << "En char upptar "    << 8*sizeof (char) << " bit." <<endl;
    cout << "En short upptar "     << 8*sizeof (short) << " bit." <<endl;
    cout << "En int upptar "     << 8*sizeof (int) << " bit." <<endl;
    cout << "En long int upptar " << 8*sizeof (long int) << " bit." <<endl;
    cout << "En long longint upptar " << 8*sizeof (long long int) << " bit." <<endl;
 }

void provaStorreAnStorst(){
    cout << "provaStorreAnStorst "<<endl;
    int storstHeltalet = INT_MAX;
    int annuStorre = storstHeltalet + 1;
    cout << "StorstHeltalet: " << storstHeltalet << endl;
    cout << "Storre an storst a: "<< annuStorre << endl;
}

void provaDivision(){
    cout << "ProvaDivision:" << endl;
    int tva = 2;
    int fem= 5;
    cout << fem/tva << endl;
    cout << tva/fem << endl;
    cout << tva/fem + tva/fem + tva/fem << endl;
}

void provaDivisionMedNoll(){
    cout << "ProvaDivisionMedNoll "<<endl;
    int noll = 0;
    int tva = 2;
    cout << "noll/ noll ar: " << noll/noll << endl;
    cout << "tva/noll ar: " << tva/noll << endl;
}
void provaHeltal(){
    provaDivisionMedNoll();
    //provaDivision();
    //provaStorreAnStorst();
}

void skrivUtVaxel(int antalkronor){

    int kronorKvarAttBetala =antalkronor;
    int antal500 = kronorKvarAttBetala/500;
    kronorKvarAttBetala -= antal500*500;
    cout << antal500 <<"*"<<500<< endl;
    int antal200 = kronorKvarAttBetala/200;
    kronorKvarAttBetala -= antal200*200;
    cout <<  antal200 <<"*"<< 200 << endl;
    int antal100 = kronorKvarAttBetala/100;
    kronorKvarAttBetala -= antal100*100;
    cout <<  antal100 <<"*"<< 100 << endl;
    int antal20 = kronorKvarAttBetala/20;
    kronorKvarAttBetala -= antal20*20;
    cout << antal20 <<"*"<<20<< endl;
    int antal10 = kronorKvarAttBetala/10;
    kronorKvarAttBetala -= antal10*10;
    cout << antal10 <<"*"<<10<< endl;
    int antal5 = kronorKvarAttBetala/5;
    kronorKvarAttBetala -= antal5*5;
    cout <<  antal5 <<"*"<< 5 << endl;
    int antal2 = kronorKvarAttBetala/2;
    kronorKvarAttBetala -= antal2*2;
    cout << antal2 <<"*"<<2<< endl;
    int antal1 = kronorKvarAttBetala/1;
    kronorKvarAttBetala -= antal1*1;
    cout << antal1 <<"*"<<1<< endl;

    cout << kronorKvarAttBetala<< endl;
    }

void ingangTillHeltal () {
    cout << endl << " ingangTillHeltal ....... " << endl ;
    skrivUtVaxel(947);
    //provaHeltal();
    //undersokHeltalsTyper();
}
