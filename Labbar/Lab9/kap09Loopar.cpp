# include <iostream >
# include <cstdlib >
# include <cmath >
# include <cassert >
#include <ctime>


using namespace std ;

void kylskapMedWhileTrue () {
    cout << " kylskap med while true " << endl ;

    while ( true ) {
        double tempratur=0;
        cout <<"Knappa in tempraturen: ";
        cin>>tempratur;
        if(tempratur<-273)
            break;
        else if(tempratur <=2)
            cout << "Tempraturn ar for kallt"<< endl;
        else if(tempratur >=8)
            cout << "Tempraturn ar for varmt"<< endl;
        else cout << "Tempraturn ar lagom"<<endl;
        break;
    }
    cout << "lamnar kylskapsloop ." << endl ;
    return;
}
void kylskapMedWhileVillkor () {
    cout << " kylskap med while villkor " << endl ;

    double temperatur = 0;
    while ( temperatur > -273) {
        cout << "Ange  tempratur: ";
        cin >> temperatur;

        if(temperatur<-273)
            continue;
        else if(temperatur <=2)
            cout << "Tempraturn ar for kallt"<< endl;
        else if(temperatur >=8)
            cout << "Tempraturn ar for varmt"<< endl;
        else cout << "Tempraturn ar lagom"<<endl;
        break;
    }
    cout << "lamnar kylskapsloop " << endl ;
}

// ******** Summa ************
/* ************************************************************
* ANROP : int summa = aritmetiskSummaFranAnalys (n);
* UPPGIFT : Returnerar summan 1+2+3+....+ n
* ANM: Summan ber ä knas mha en formel .
************************************************************ */
int aritmetiskSummaFranAnalys ( int n) {
    int summa =(n*(n+1))/2;
    return summa;
}
/* ************************************************************
* ANROP : int summa = aritmetiskSummaFranLoop (n);
* UPPGIFT : Returnerar summan 1+2+3+....+ n
* ANM: Summan ber ä knas mha en loop .
************************************************************ */
int aritmetiskSummaFranLoop ( int n){
    int summa=0;
    while(n){
        summa+=n;
    }
    return summa;
}
/* ************************************************************
* ANROP : jamforSummaberakningar (n);
* UPPGIFT : Ber ä knar summan 1+2+3+....+ n på två olika sätt ,
* skriver ut summan och skillnaden (bör vara 0) mellan
* de två ber ä kningarna .
************************************************************ */
void jamforSummaberakningar ( int n ){
    int resultat = aritmetiskSummaFranLoop (n );
    int diff = resultat - aritmetiskSummaFranAnalys (n);
    cout << " aritmetiskSummaFranLoop (" << n << ") = " << resultat
         << ", diff = " << diff << endl ;
    assert ( diff == 0 );
}
void jamforFleraSummaberakningar () {
    for (int n =0; n <100 ; n +=20)
        jamforSummaberakningar (n) ;
}

unsigned int PSEUDOSLUMPTAL = 42;
void froaSlumptalsgeneratorn(unsigned int fro){
    PSEUDOSLUMPTAL = fro;
}
unsigned int ettSlumptal(){
    cout <<"returnerar rand"<<endl;
    return rand();
    //PSEUDOSLUMPTAL = 1664525*PSEUDOSLUMPTAL + 1013904223;
    //return PSEUDOSLUMPTAL;
}

unsigned int froaSlumptal(){
    froaSlumptalsgeneratorn(time(nullptr));
    return ettSlumptal();
}
void provaFroaSlumptal(){
    cout << "ProvaFroaslumptal "<< endl;
    cout << "Skriver 5 froade slumptal" << endl;

    for (int i =0; i<5; ++i)
        cout << froaSlumptal() << " ";
    cout << endl;
}

/*
void genereraNagraSlumptal(){
    cout << "Skriver 5 stora slumptal: "<<endl;

    for (int i=0; i<5; i++)
        cout << ettSlumptal()<<" ";
    cout <<endl;
    cout << "Skriver 30 mindre slumptal: "<<endl;

    for(int i=0; i<6; ++i)
        cout << ettSlumptal() % 10 << " ";
    cout << endl;
}
*/
void genereraNagraSlumptal(){
    cout << "Skriver 5 tarningskast: "<<endl;

    for (int i=0; i<5; i++){
        int tarning =(ettSlumptal()%6)+1;
        cout << tarning;
    }
    cout <<endl;

    cout << "Skriver 30 mindre slumptal: "<<endl;

    for(int i=0; i<30; ++i){
        int tarning =(ettSlumptal()%6)+1;
        cout << tarning << " ";
    }
    cout << endl;
}

void undersokSlumptalsgeneratorn(){
    cout << " undersokSlumptalsgeneratorn " << endl ;
    unsigned long int antalAnrop = 0;
    unsigned long int foregaendeAntal = 0;
    int antal42or = 0;
    while ( antal42or < 4) {
        unsigned int i = ettSlumptal () ;
        antalAnrop += 1;
        if (i ==42) {
            cout << "sag 42 efter " << antalAnrop << " anrop ." ;
            if ( antal42or ==0)
                cout << " ( den forsta 42: an)" << endl ;
            else cout << " Dvs " << antalAnrop - foregaendeAntal << " steg efter foregaende 42: a" << endl ;
            foregaendeAntal = antalAnrop ;
            antal42or += 1;
        }
    }
}
void provaMinaSlumptal(){
    cout << "provaMinaSlumptal "<< endl;
    genereraNagraSlumptal();
    undersokSlumptalsgeneratorn();
}


void ingangTillLoopar () {
    cout << endl << " ingangTillLoopar +++++ " << endl ;
    provaFroaSlumptal();
    //provaMinaSlumptal();
    // jamforFleraSummaberakningar();
    //kylskapMedWhileVillkor();
    //kylskapMedWhileTrue();
}
