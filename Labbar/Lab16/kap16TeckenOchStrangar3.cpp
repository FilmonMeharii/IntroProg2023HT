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

void ingangTillTeckenOchStrangar3 () {
    cout << endl << " ingangTillTeckenOchStrangar +++++ " << endl ;
    automattestaVersalstrang();
    //demoAvString();
}
