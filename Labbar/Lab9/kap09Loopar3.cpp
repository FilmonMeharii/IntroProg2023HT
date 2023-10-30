# include <iostream >
# include <cstdlib >
# include <cmath >
# include <cassert >
#include <ctime>
#include <iomanip>

using namespace std;

void skrivMultipliktionsmatris(){
    cout << "Multiplikationsmatris" << endl;
    for(int i=1; i<=10; ++i){
        for(int j=1; j<=10; ++j)
            cout << setw(5)<<i*j;
        cout <<endl;
    }
    cout <<endl;
}
void fyllRektangel(int hojd, int bredd){
    cout << "Fylld rektangel"<< endl;
    for(int i=1; i<=hojd; ++i){
        for (int j=1; j<=bredd; ++j)
            cout << "#";
        cout <<endl;
    }
    cout <<endl;

}
void ritaRektangel(int hojd, int bredd){
    cout << "ritad rektangel"<<endl;
    for(int i=0; i<hojd; i++){
        for(int j=0; j<bredd; j++){
            if(i==0 || i==hojd-1||j==0||j==bredd-1){
                cout <<"#";
            } else {
                cout <<"  ";
            }
        }
        cout <<endl;
    }
    cout << endl;
}
void fyllTriangel(int hojd){
    cout << "Fylld triangel." << endl;
    for(int i=0; i<=hojd; i++){
        for(int j=0; j<=i; j++){
            cout << "#";
        }
        cout <<endl;
    }
    cout << endl;
}
void fyllCirkel(int radie){
    cout <<"Fylld cirkel" << endl;
    for(int r = -radie; r<=radie; r++){
        for(int k =-radie; k<=radie; k++){
            if(r*r+k*k<= radie*radie){
                cout <<"#";
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
    cout <<endl;
}
void ritaMedText(){
    cout << "ritaMedText."<<endl;
    cout <<endl;
    skrivMultipliktionsmatris();
    fyllRektangel(4,20);
    cout <<endl;
    ritaRektangel(4,20);
    cout <<endl;
    fyllTriangel(5);
    cout <<endl;
    fyllCirkel(5);
    cout <<endl;

}

// ******** estimera PI ************
double estimatAvCirkelareaFranRadie ( int radie ) {
    int punkterinomCirkeln=0;
    for(int y=-radie; y<=radie; ++y)
        for(int x=-radie; x<=radie; ++x){
            if(x*x+y*y<=radie*radie){
                punkterinomCirkeln ++;
            }
        }
}
// Returnerar ett estimat av talet pi. Stö rre radie
// ger ett bä ttre estimat .
double estimatAvPiFranRadie ( int radie ) {
    // pi*r2 = area
    // pi = area /r2
    double cirkelAreaEstimat = estimatAvCirkelareaFranRadie(radie);
    double piEstimat = cirkelAreaEstimat;
    return piEstimat;

}
void gorFleraEstimatAvPi(){
    for(int radie =1; radie <10000; radie = radie*2){
        double pi = estimatAvPiFranRadie(radie);
        cout << " radie = " << radie << ", pi estimeras till "<< pi <<endl;
    }
}


bool detArEttPrimtal(int n){
    if(n <=1){
        return false;
    }
    for(int i=2; i*i<=n; i++){
        if(n%i==0 )
            return false;
    }
    return true;
}


void provaPrimtal(){
    cout << endl<< "provaPrimtal " << endl
         << "knappa in tal, avsluta med 0"<< endl;
    while(true){
        cout << "ge tal:";
        int tal = 1;
        cin >> tal;
        if(tal<=0)
            break;
        if(detArEttPrimtal(tal))
            cout <<tal<<"ar primtal"<<endl;
        else cout << tal << "kan faktoriseras" <<endl;
    }
    cout << "(avslutar provaPrimtal)" << endl;
}

void testaPrimtal(){
    cout <<"testPrimtal"<<endl;
    assert(detArEttPrimtal(7));
    assert(detArEttPrimtal(7919));
    assert(!detArEttPrimtal(7913));
    assert(!detArEttPrimtal(10201));
    cout << "testaPrimtal lyckades"<<endl;
}


void ingangTillLoopar3() {
    cout << endl << " ingangTillLoopar2 +++++ " << endl ;
    testaPrimtal();
    //gorFleraEstimatAvPi();
    //ritaMedText();
}
