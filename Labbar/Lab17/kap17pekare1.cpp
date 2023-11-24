#include <iostream>
#include <cassert>

using namespace std;

void ovaPaPekarnotation () {
    cout << "Ovar pa pekarnotation " << endl ;
    double x = 1.0;
    double *pX =&x;
    double **ppX = &pX;
    double ***pppX = &ppX;
    ***pppX = 2.0;
    cout << "x ar nu " << x << endl ;
    assert ( x == 2.0) ;
    cout << "Oningen lyckades ." << endl ;
}
void bytVarden(int *pA, int *pB){
    int temp = *pA;
    *pA = *pB;
    *pB = temp;

}
void bytVarden(double *pA, double *pB){
    double temp = *pA;
    *pA = *pB;
    *pB = temp;
}
void automattestaBytVarden(){
    cout << "testar bytvarden "<< endl;
    int a=1;
    int b= 2;
    bytVarden(&a,&b);
    assert(a==2 && b== 1);
    double x = 1.5;
    double y = 2.5;
    bytVarden(&x,&y);
    assert(x==2.5 && y==1.5);
    cout << "Testet av bytVarden lyckades!" << endl;
}
int langd(const char *str){
    const char *pCh = str;
    while (*pCh != 0)
        ++pCh;
    return pCh -str;
}
void automattestaLangd(){
    assert(langd("hej") == 3);
    cout << "Testet av langd lyckades!" << endl;
}
bool arLikaP ( const char * str1 , const char * str2 ) {
    for(;*str1!=0 && *str2!=0;++str1, ++str2)
        if(*str1 != *str2)
            return false;
    return (*str1 == 0 && *str2==0);
}
void konverteraTillVersalerP ( char * str ){
    for(; *str!=0; ++str)
        *str = toupper(*str);
}
void konverteraTillRubrikP ( char * str ) {
    char* prev = nullptr;
    for (; *str != 0; ++str) {
        if (prev == nullptr || *prev == ' ' || *prev == '\t') {
            *str = toupper(*str);
        } else {
            *str = tolower(*str);
        }
        prev = str;
    }
}
void automattestaStrangfunktionerP () {
    cout << " automattestar strangfunktionerna -P" << endl ;
    assert ( arLikaP (" abcd ", " abcd ") ) ;
    assert ( ! arLikaP (" abcd ", " abcX ") );
    assert ( ! arLikaP (" abcd ", " Xbcd ") );
    assert ( !arLikaP ("abcd e", "abcd") );
    assert ( !arLikaP ("abcd", "abcd e") );
    char strA [] = " abc ABC 123 . ,- xyz ";
    char strB [] = " ABC ABC 123 . ,- XYZ ";
    konverteraTillVersalerP ( strA );
    assert ( arLikaP ( strA , strB ) ) ;
    char str1 [] = " this is a test ";
    char str2 [] = " THIS IS A TEST ";
    char rubrik [] = " This Is A Test ";
    char tom [] = "";
    konverteraTillRubrikP ( str1 );
    konverteraTillRubrikP ( str2 );
    konverteraTillRubrikP ( tom );
    assert ( arLikaP ( str1 , rubrik ) );
    assert ( arLikaP ( str2 , rubrik ) );
    assert ( arLikaP ( tom , "") );
    cout << " testen av strangfunktionerna -P lyckades !" << endl ;
}
void skrivStrangar ( const char ** strangar , int antal ) {
    for(int i=0; i<antal; i++)
        cout <<strangar[i] << endl;
}
void provaSkrivStrangar () {
    const int antal = 7;
    const char * dagnamn [ antal ] = { "mandag ", " tisdag ", " onsdag ",
                                       " torsdag ", " fredag ", "lordag ", "sondag " };
    skrivStrangar ( dagnamn , antal );
}


void ingangTillPekare1(){
    cout << "Ingang till pekare +++++++ "<< endl;
   provaSkrivStrangar();
    //automattestaStrangfunktionerP();
    //automattestaLangd();
    //ovaPaPekarnotation();
}
