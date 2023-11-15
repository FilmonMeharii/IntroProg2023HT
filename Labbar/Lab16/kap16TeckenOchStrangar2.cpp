# include <iostream>
# include <cassert>

using namespace std ;

bool arLika(const char str1[], const char str2[]){
    for(int i=0; str1[i]!=0 || str2[i]!=0; ++i){
        if(str1[i] != str2[i])
            return false;
    }
    return true;
}
void automatestaArLika(){
    cout << "automattestar arLika"<<endl;

    assert(arLika("abcd", "abcd"));
    assert(!arLika("abcd", "abcX"));
    assert(!arLika("abcd", "Xbcd"));
    assert(!arLika("abcd e", "abcd"));
    assert(!arLika("abcd", "abcd e"));
    cout << "testen av arLika lyckades!" << endl;
}
void provaarArLika(const char str1[], const char str2[]){
    bool lika = arLika(str1, str2);
    if(lika)
        cout << str1 << " och " << str2 << " ar lika"<<endl;
    else cout << str1 << " och "<<str2 << " ar olika "<< endl;
}
void provaFleraArLika(){
    provaarArLika("hej hopp", "hej hopp");
    provaarArLika("hej hopp", "hej hoppitopptop");
    provaarArLika("hej hoppitopptop", "hej hopp");
}

void konverteraTillVersaler(char str[]){
    for(int i= 0; str[i]!=0; ++i)
        str[i]=toupper(str[i]);
}
void automatestaKonverteraTillVersaler(){
    cout << "automattesta konverteraTillVersaler"<< endl;

    char str1 [] = " abc ABC 123 . ,- xyz ";
    char str2 [] = " ABC ABC 123 . ,- XYZ ";

    konverteraTillVersaler(str1);
    assert(arLika(str1, str2));

    cout << "testen av konverteraTillVersaler lyckades!"<<endl;
}

void konverteraTillRubrik ( char str []) {
    for(int i=0; str[i] !=0; ++i)
        if(i>0 && str[i-1]==' ')
            str[i]=toupper(str[i]);
        else
            str[i]=tolower(str[i]);
}
void automattestaKonverteraTillRubrik () {
    cout << " automattestar konverteraTillRubrik " << endl ;

    char str1 [] = " this is a test ";
    char str2 [] = " THIS IS A TEST ";
    char rubrik [] = " This Is A Test ";

    konverteraTillRubrik ( str1 );
    konverteraTillRubrik ( str2 );

    assert ( arLika ( str1 , rubrik ) );
    assert ( arLika ( str2 , rubrik ) );
    cout << " testen av konverteraTillRubrik lyckades !" << endl ;
}

void ingangTillTeckenOchStrangar2() {
    cout << endl << " ingangTillTeckenOchStrangar2 +++++ " << endl ;
    automattestaKonverteraTillRubrik();
    //automatestaKonverteraTillVersaler();
    //automatestaArLika();
    //provaFleraArLika();
}
