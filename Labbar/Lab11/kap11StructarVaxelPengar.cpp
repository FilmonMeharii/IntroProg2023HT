#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cassert>

using namespace std ;

struct Valuta {
    string m_namn;
    vector<int> m_valorer;
};

const Valuta SEK{"Svenska Kronor" ,{500,200,100,50,20,10,5,2,1}};

//Returnerar true om sorterad i avtagande ordning,
bool arGiltig( const Valuta& v){
    for(unsigned int i=1; i<v.m_valorer.size(); i++)
        if(v.m_valorer[i-1] <= v.m_valorer[i])
            return false;
    return true;
}
//Returnera true om a==b
bool arLika(const Valuta& a, const Valuta& b){
    return a.m_namn ==  b.m_namn &&
            a.m_valorer ==b.m_valorer;
}
struct Vaxel4{
    Valuta m_valuta;
    vector <int> m_antal;
};

bool arLika(const Vaxel4& a, const Vaxel4& b){
    return a.m_antal == b.m_antal && arLika(a.m_valuta, b.m_valuta);
}

Vaxel4 vaxel4FranValutaBelopp(const Valuta& valuta, int belopp){
    assert(arGiltig(valuta));

    int kvarAttBetala = belopp;
    vector<int> antal(valuta.m_valorer.size(), 0);

    for(unsigned int i =0; i<valuta.m_valorer.size(); i++){
        int valor = valuta.m_valorer[i];
        if(kvarAttBetala >= valor){
            antal[i] = kvarAttBetala/valor;
            kvarAttBetala %= valor;
        }
    }
    return Vaxel4{valuta, antal};
}

int beloppFranVaxel(const Vaxel4& vaxel){
    int belopp =0;
    for(unsigned int i=0; i<vaxel.m_valuta.m_valorer.size(); i++){
        int valor = vaxel.m_valuta.m_valorer[i];
        belopp += valor * vaxel.m_antal[i];
    }
    return belopp;
}
void skrivUtVaxel(const Vaxel4& vaxel){
    cout << "Valuta: " << vaxel.m_valuta.m_namn<<endl;

    cout << "Valorer: ";
    for (unsigned int i=0; i<vaxel.m_valuta.m_valorer.size(); ++i){
        cout << vaxel.m_valuta.m_valorer[i]<< " ";
    }
    cout << endl;

    cout << "Antal: ";
    for (unsigned int i=0; i<vaxel.m_antal.size(); i++){
        cout << vaxel.m_antal[i]<< " ";
    }
    cout << endl;
}

void automattestaVaxel4 () {
    cout << " >> automattestaVaxel " << endl ;
    assert ( arLika ( vaxel4FranValutaBelopp ( SEK , 947) ,
                      Vaxel4{SEK , {1 ,2 ,0 ,0 ,2 ,0 ,1 ,1 ,0} }));
    Vaxel4 vaxel = vaxel4FranValutaBelopp ( SEK , 836) ;
    assert ( beloppFranVaxel ( vaxel ) == 836 );
    cout << " << automattestaVaxel " << endl ;
}
void provaVaxel4 () {
    Vaxel4 vaxel = vaxel4FranValutaBelopp ( SEK , 947) ;
    skrivUtVaxel ( vaxel ) ;
}

void ingangTillStructar3(){
    cout << endl << " ingangTillStructar2 +++++ " << endl ;
    provaVaxel4();
    cout << endl<<endl;
}
