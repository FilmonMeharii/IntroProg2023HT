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

void ingangTillLoopar3() {
    cout << endl << " ingangTillLoopar2 +++++ " << endl ;
    ritaMedText();
}
