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

void ingangTillHeltal () {
    cout << endl << " ingangTillHeltal ....... " << endl ;
    provaHeltal();
    //undersokHeltalsTyper();
}
