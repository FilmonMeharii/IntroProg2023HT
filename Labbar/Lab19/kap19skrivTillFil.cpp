#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std ;

void skapaFilenHejFilsystem () {
    string filnamn = "../hejFilsystem.txt";

    ofstream utStrom;
    utStrom.open(filnamn);

    for(int i= 0; i<10; i+=1)
        utStrom << i << " Hej!" << endl;
    utStrom.close();
}
vector <string> ordlistan(){
    string filnamn="C:/Users/filmo/Desktop/Desktop/1st year/IntroProg2023HT/IntroProg/Labbar/ordlista.txt";
    ifstream filen(filnamn);
    vector<string> listan;
    while (!filen.fail()) {
        string ettOrd;
        filen>>ettOrd;
        if(!filen.fail())
            listan.push_back(ettOrd);
    }
    return listan;
}
void provaOrdlistan () {
    vector<string> ordlista = ordlistan();
    cout << "Listan innehaller foljande ord: "<< endl;

    for(const string &ord:ordlista){
        cout << ord << endl;
    }
    cout << "totalt "<< ordlista.size() << endl;
}
bool matcharFragenyckel ( string ord , string nyckel ){
    for(int i = 0; i<ord.length(); ++i){
        if(nyckel[i] == '?'){
            if(i>= ord.length()){
                return false;
            }
        }else if(tolower(ord[i]) !=tolower(nyckel[i])){
            return false;
        }
    }
    return true;
}
void automattestaMatcharFragenyckel () {
    cout << " testar matcharFragenyckel ... " << endl ;
    assert ( matcharFragenyckel (" xaby ", "?ab?") );
    assert ( ! matcharFragenyckel (" xaby ", "?abz ") ) ;
    assert ( ! matcharFragenyckel (" xaby ", "? abyx ") );
    assert ( ! matcharFragenyckel (" xabyx ", "? aby ") );
    cout << " automattestaMatcharFragenyckel lyckades " << endl ;
}

void skrivMatchningar ( const vector < string >& allaOrd , string nyckel ){
    for ( unsigned int i =0; i < allaOrd . size () ; ++ i) {
        if ( matcharFragenyckel ( allaOrd [i] , nyckel ))
            cout << allaOrd [i ] << endl ;
    }
}
void ordMatch () {
    vector < string > allaOrd = ordlistan () ;
    cout << "Vakommen till ordmatch !" << endl ;
    while ( true ) {
        cout << " NYCKEL :";
        string nyckel ;
        getline ( cin , nyckel );
        if ( nyckel == "")
            continue ;
        if ( nyckel == " avbryt ")
            break ;
        skrivMatchningar ( allaOrd , nyckel );
    }
    cout << "( ordmatchningen avbrots)" << endl ;
}


void ingangTillSkrivaFil () {
    cout << " ingang till skriva fil"<< endl;
    automattestaMatcharFragenyckel();
    ordMatch();
    //provaOrdlistan();
    //skapaFilenHejFilsystem();
}
