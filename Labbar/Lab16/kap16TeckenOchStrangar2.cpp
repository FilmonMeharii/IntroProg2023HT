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

bool arVokal ( char ch ) {
    const char vokal [] = "aeiouyAEIOUY";
    for(int i=0; vokal[i]!=0; ++i){
        if(ch ==vokal[i]){
            return true;
        }
    }
    return false;
}
bool arKonsonant ( char ch ) {
   const  char konsonanter [] = "bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ";
    for(int i=0; konsonanter[i]!=0; ++i){
        if(ch == konsonanter[i]){
            return true;
        }
    }
    return false;
}
void automattestaArVokalOchArKonsonant () {
    cout << " automattestar arVokal och arKonsonant " << endl ;
    char vokaler [] = "aeiouyAEIOUY";
    char konsonanter [] = "bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ";
    char andraTecken [] = ". ,?!; ";
    for (int i =0; vokaler [i] != 0; ++ i)
        assert ( arVokal ( vokaler [i ]) );
    for (int i =0; konsonanter [i] != 0; ++ i)
        assert ( arKonsonant ( konsonanter [i ]) );
    for (int i =0; andraTecken [i] != 0; ++ i)
        assert ( ! arVokal ( andraTecken [i ]) && ! arKonsonant ( andraTecken [i ])
                 );
    cout << " testerna av arVokal / arKonsonant lyckades !" << endl ;
}

void ingangTillTeckenOchStrangar2() {
    cout << endl << " ingangTillTeckenOchStrangar2 +++++ " << endl ;
    automattestaArVokalOchArKonsonant();
    //automattestaKonverteraTillRubrik();
    //automatestaKonverteraTillVersaler();
    //automatestaArLika();
    //provaFleraArLika();
}
