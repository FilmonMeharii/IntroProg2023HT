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

void provaLitteraler(){

    provaHexUtskrift();
     //provaLiteraler();
    //provaRest();
}
