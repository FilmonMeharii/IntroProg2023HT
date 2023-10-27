# include <iostream >
# include <cstdlib >
# include <cmath >
# include <cassert >


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


void ingangTillLoopar () {
    cout << endl << " ingangTillLoopar +++++ " << endl ;

    jamforFleraSummaberakningar();
      //kylskapMedWhileVillkor();
    //kylskapMedWhileTrue();
}
