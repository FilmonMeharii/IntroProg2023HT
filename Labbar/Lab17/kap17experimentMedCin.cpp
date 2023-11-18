# include <iostream>
# include <string>


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


void ingangTillExperimentMedCin () {
    cout << " ingangTillExperimentMedCin ." << endl ;
    testaCinIntMedFalhantering();
    //testaCinInt();
}
