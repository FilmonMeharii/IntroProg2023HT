#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>


using namespace std ;

struct Datum{
    int m_ar;
    int m_manad;
    int m_dag;
};

Datum datumFranAMD(int ar, int manad, int  dag){

    Datum datum;
    datum.m_ar=ar;
    datum.m_manad=manad;
    datum.m_dag=dag;
    return datum;
}
bool arEttTillatetDatum(Datum datum){
    if(datum.m_manad < 1 || datum.m_manad>12 ||datum.m_dag<1 || datum.m_dag>31){
        return false;
    }
    return true;
}
Datum nastaDagDatum(Datum datum){
    if(arEttTillatetDatum(datum)){
        if(datum.m_dag < 31){
            datum.m_dag++;
        }else if(datum.m_manad < 12){
            datum.m_manad++;
            datum.m_dag =1;
        }else{
            datum.m_ar++;
            datum.m_manad =1;
            datum.m_dag =1;
        }
    }
    return datum;;
}
Datum foregaendeDagsDatum(Datum datum){
    if(arEttTillatetDatum(datum)){
        if(datum.m_dag > 1){
            datum.m_dag--;
        }else if(datum.m_manad > 1){
            datum.m_manad--;
            datum.m_dag =31;
        }else{
            datum.m_ar--;
            datum.m_manad =12;
            datum.m_dag =31;
        }
    }
    return datum;;
}
Datum datumEfterXDagar(Datum datum, int x){
    if(x>0){
        for(int i=0; i<x; i++){
            datum = nastaDagDatum(datum);
        }
    }else if(x<0){
        for(int i=0; i<-x; i++){
            datum = foregaendeDagsDatum(datum);
        }
    }
    return datum;
}
bool arLikaDatum(Datum d1, Datum d2){
    return
            d1.m_ar==d2.m_ar &&
            d1.m_manad == d2.m_manad &&
            d1.m_dag == d2.m_dag;
}
bool arMindreDatum(Datum d1, Datum d2){
    if(d1.m_ar < d2.m_ar){
        return true;
    }else if(d1.m_ar == d2.m_ar &&d1.m_manad == d2.m_manad){
        return true;
    }else if(d1.m_ar ==d2.m_ar &&d1.m_manad == d2.m_manad &&d1.m_dag == d2.m_dag){
        return true;
    }
    return false;
}
void testaDatum(){
    Datum idag = datumFranAMD(2023, 11, 6);
    cout  << "Idag ar det "
          << idag.m_ar << "-"
          << idag.m_manad << "-"
          << idag.m_dag << endl;

    Datum imorgon = nastaDagDatum(idag);
    cout <<endl<< "Imorgon ar det "
        << imorgon.m_ar << "-"
        << imorgon.m_manad << "-"
        << imorgon.m_dag << endl;

    Datum igar = foregaendeDagsDatum(idag);
    cout << endl << "Igar var det "
         << igar.m_ar << "-"
         << igar.m_manad << "-"
         << igar.m_dag << endl;

    int x=3;
    Datum omTreDagar = datumEfterXDagar(idag, x);
    cout <<endl<< "Om "  << x << " dagar ar det "
        << omTreDagar.m_ar << "-"
        << omTreDagar.m_manad << "-"
        << omTreDagar.m_dag << endl;

    Datum sammaDag = datumFranAMD(2023,11,6);
    if(arLikaDatum(idag,sammaDag)){
        cout<< "Idag och sammadag ar samma datum "<<endl;
    }

    Datum tidigareDatum = datumFranAMD(2023,11,5);
    if(arMindreDatum(tidigareDatum,idag)){
        cout << "Tidigare datumm kommer fore idag" << endl;
    }
}
void ingangTillStructar2 () {
    cout << endl << " ingangTillStructar2 +++++ " << endl ;
    testaDatum();
    cout << endl<<endl;
}
