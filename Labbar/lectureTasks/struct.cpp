#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct Datum{
    int m_ar;
    int m_manad;
    int m_dag;
};

Datum datumFranAMD(int ar, int manad, int dag){
    Datum d;
    d.m_ar =ar;
    d.m_manad = manad;
    d.m_dag = dag;
    return d;
}
/*Datum datumFranAMD(int ar, int manad, int dag){
    Datum d{ar,manad,dag};
    return d;
}*/

bool arSkottar(int ar){
    return (ar % 4==0 && ar %100 !=0) || ar%400==0 ;
}
int antalDagarIManad(int manad, int ar){
    static const int dagarIManad[13]{0,31,28,31,30,31,30,31,31,30,31,30,31};
    assert(1 <=manad && manad <=12);
    if(manad == 2 && arSkottar(ar))
        return 29;
    return dagarIManad[manad];
}
bool arEttTillatetDatum(const Datum& d){
    return 1 <= d.m_manad
            && d.m_manad <=12
            && 1<=d.m_dag
            && d.m_dag <= antalDagarIManad(d.m_manad, d.m_ar);
}

Datum nastaDagsDatum(const Datum& datum){
    Datum d=datum;
    d.m_dag +=1;

    if(d.m_dag>antalDagarIManad(datum.m_manad, datum.m_ar)){
        d.m_dag = 1;
        d.m_manad +=1;
        if(d.m_manad >12){
            d.m_manad = 1;
            d.m_ar +=1;
        }
    }
    return d;
}
Datum foregaendeDagsDatum(const Datum& datum){
    Datum d = datum;
    d.m_dag -=1;
    if(d.m_dag <1){
        d.m_manad -=1;
        if(d.m_manad <1){
            d.m_manad = 12;
            d.m_ar -=1;
        }
        d.m_dag = antalDagarIManad(d.m_manad, d.m_ar);
    }
    return d;
}
Datum datumEfterXDagar(const Datum& datum, int x);
bool arEttTillatetDatum(const Datum& datum);
bool arLikaDatum(const Datum& d1, const Datum& d2);
bool arMindreDatum(const Datum& d1, const Datum& d2);
void testaDatum();

enum Veckodag{mandag, tisdag, onsdag, torsdag, fredag, lordag,sondag};
const string ALLA_DAGNAMN[7]{"måndag", "tisdag", "onsdag",
                             "torsdag","fredag","lördag","söndag"};
// Returnerar vilken veckodag som ett datom har.
// Anm datumet måste ligga efter 1a jan 1900.
Veckodag veckodag(const Datum& dag){
    // Den 1a januari 1900 var en måndag.
    // Vi stegar fram från det datumet
    Datum d1900 = datumFranAMD(1900,1,1);
    assert(arMindreDatum(d1900, dag));
    int veckodag = mandag;
    Datum d = d1900;
    while (arMindreDatum(d, dag)){
        d = nastaDagsDatum(d);
        veckodag = (veckodag+1)%7;
    }
    return (Veckodag) veckodag;
}


bool string(string str1, string str2){
    for(int i= 0; str1[i] !=0; i++){
        if(str1[i] != str2[i])
            break;
        return false;
    }
    return true;
}
