# include <iostream>
# include <string>
#include <limits>
#include <sstream>


using namespace std ;

void testaCinString(){
    cout <<"testaCinString" <<endl<<endl;
    while (true) {
        cout << "Skriv en textstrang:";
        string strang;
        cin>>strang;
        if(strang=="exit")
            break;
        cout << "Du skrev "<<strang<<endl;
    }
}
void testaCinInt(){
    cout <<"testa cin int" << endl;
    while (true) {
        cout << "Skriv ett heltal:";
        int heltal =0;
        cin >> heltal;
        cout << "Du skrev "<<heltal<<endl;
    }
}
void testaCinIntMedFalhantering(){
    cout << "testaCinInt med felhantering" << endl;
    while(true){
        cout  << "Skriv ett heltal:";
        int heltal = 0;
        cin>>heltal;
        if(!cin.fail()){
            cout << "Du skrev: " << heltal << endl;
        }
        else{
            cout << "Misslyckad lasning"<< endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
    }
}
double flyttalFranUppmaning ( const string uppmaning ){
    double resultat;
    string inmatning;
    while (true) {
        cout << uppmaning;
        getline(cin, inmatning);

        stringstream ss(inmatning);
        if(ss >> resultat){
            if(ss.eof()){
                break;
            }
        }
        cout << "Ogiltigt tal, forsok igen" << endl;
    }
    return resultat;
}
void provaFlyttalFranUppmaning () {
    const double bokPris = flyttalFranUppmaning (" Hur manga kronor kostar boken?") ;
    const double antalSidor = flyttalFranUppmaning (" Hur manga sidor har boken?") ;
    const double procentAttLasa = flyttalFranUppmaning (" Hur manga procent av sidorna kommer du att lasa? ");
    cout << "Du har angett att boken kostar " << bokPris <<" kronor "
         << ", och att den har " << antalSidor <<" sidor "
         << ", och att du tanker lasa " << procentAttLasa << "%" << endl
            ;
}


void ingangTillExperimentMedCin () {
    cout << " ingangTillExperimentMedCin ." << endl ;
    provaFlyttalFranUppmaning();
    //testaCinIntMedFalhantering();
    //testaCinInt();
}
