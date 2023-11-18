#include <iostream>
#include <cassert>
#include <string>


using namespace std ;

void demoAvString(){
    string str1 = "hej";
    string str2 = "hej";
    if(str1==str2)
        cout << "Hurra, man kan jamfora stringar utan anropa arLika!"<<endl;
    else cout << "Rackans, det gar fortforande inte att jamfora!"<<endl;

    if(str1 == "hej")
        cout << "Det gick att jamfora med en litteral!"<<endl;
    else cout << "Det gick dock inte att jamfora med en litteral "<< endl;

    cout << "Strangen  "<<str1 << " har "<< str1.size() << " tecken " <<endl;
    str2 += " da!";
    cout <<str2 <<endl;
}
string versalstrang ( const string & str ){
    string ch = str;
    for (int i = 0; i < str.length(); ++i) {
        ch[i] = toupper(str[i]);
    }
    return ch;
}
void automattestaVersalstrang () {
    cout << " testar versalStrang " << endl;
    assert( versalstrang ("abc ABC 123 .,- xyz") == "ABC ABC 123 .,- XYZ" );
    cout << " test av versalStrang lyckades !" << endl ;
}

string rubrikstrang(const string &str) {
    string rubrik;
    for(int i=0; i<str.size(); i++){
        if(str[i-1]==' ' || i==0){
            rubrik += toupper(str[i]);
        }else{
            rubrik += tolower(str[i]);
        }
    }
    return rubrik;
}
void automattestaRubrikstrang () {
    cout << " testar rubrikstrang " << endl ;
    assert(rubrikstrang("ha en BRA DAG!") == "Ha En Bra Dag!");
    assert(rubrikstrang("ha en BRA DAG!")=="Ha En Bra Dag!");
    assert ( rubrikstrang ("") == "" );
    cout << " test av rubrikstrang lyckades !" << endl ;
}

string trimmad ( const string & str ) {
    string trimmad;
    for(int i = 0; i<str.size(); ++i){
        if(str[i-1]==' ' || str[0]== ' '){
            trimmad =-str[i-1];
        }else trimmad +=str[i];
    }
    return trimmad;
}
void automattestaTrimmad () {
    cout << " testar trimmad " << endl ;
    assert ( trimmad (" Ha en bra dag ! ") == "Ha en bra dag!" ) ;
    assert ( trimmad (" A B C ") == "A B C" ) ;
    assert ( trimmad (" ") == "" );
    assert ( trimmad ("") == "" ) ;
    assert ( trimmad (" abc ") == " abc " );
    cout << " testen av trimmad lyckades !" << endl ;
}


void ingangTillTeckenOchStrangar3 () {
    cout << endl << " ingangTillTeckenOchStrangar +++++ " << endl ;
    automattestaTrimmad();
    //automattestaRubrikstrang();
    //demoAvString();
}
