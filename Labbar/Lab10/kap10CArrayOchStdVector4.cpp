#include <iostream> // innehaller cin , cout
#include <cstdlib> // innehaller rand
#include <cmath> // innehaller sqrt
#include <vector>
#include <ctime>

using namespace std ;

vector<double> vek{4,3, 5.0, 3.2};
void forsokAndraVektornsVarden(vector<int>vek){
    for (int i = 0; i< vek.size(); i++)
        vek[i] =42;
}
void anropaForokAndraVektornsVarden(){
    vector<int> vek{0,0};
    cout << "vek[]= "<<vek[0] << "," << vek[1] << endl;
}

/* ******************************************************************
* ANROP : bool hasNumber = innehaller (v, tal);
* UPPGIFT : Returnerar true omm vektorn v innehåller angivet tal .
****************************************************************** */
bool innehaller ( const vector <int >& v , int tal ){
    for(int num: v ){
        if(num == tal)
            return true;
    }
    return false;
}
/* ******************************************************************
* ANROP : vector <int > lottorad = lottoradFranAnvandare ();
* UPPGIFT : Returnerar en rad med 7 olika tal mellan 1 och 35 som
* anv ändaren knappat in.
****************************************************************** */
vector <int > lottoradFranAnvandare () {
    vector<int> lottorad;
    cout << "Knappa in 7 olika tal mellan 1 och 35: ";
    for (int i=0; i<7; i++){
        int num;
        cin>> num;
        lottorad.push_back(num);
    }
    return lottorad;
}
/* ******************************************************************
* ANROP : vector <int > lottorad = slumplottorad ();
* UPPGIFT : Returnerar en rad med 7 olika slumptal mellan 1 och 35.
****************************************************************** */
vector <int > slumplottorad () {
    vector <int> lottorad;
    srand(time(0));
    while(lottorad.size()<7){
        int num= 1+rand()%35;
        if(!innehaller(lottorad,num)){
            lottorad.push_back(num);
        }
    }
    return lottorad;
}
/* ******************************************************************
* ANROP : int antal = antalMatch (rad1 , rad2 );
* UPPGIFT : Returnerar antalet tal som finns i bä gge vektorerna
****************************************************************** */
int antalMatch ( const vector <int >& v1 , const vector <int >& v2 ){
    int count=0;
    for(int num:v1){
        if(innehaller(v2, num)){
            count++;
        }
    }
    return count;
}
/* ******************************************************************
* ANROP : korTusenExperiment ( anvandarensLottorad )
* UPPGIFT : Kör 1000 experiment med anvä ndarens rad och skriver sedan
* ut hur många rätt anv ä ndaren fick i genomsnitt och som mest
.
* Denna info skrivs ut på EN rad .
****************************************************************** */
void korTusenExperiment ( const vector <int > anvandarensRad ){
    int totalMatches = 0;
    int maxMatches = 0;
    for(int i=0; i<1000; i++){
        vector<int> slumptal = slumplottorad();
        int matches = antalMatch(anvandarensRad, slumptal);
        totalMatches+=matches;
        if(matches > maxMatches){
            maxMatches = matches;
        }
    }
    double averageMatches = static_cast<double>(totalMatches)/1000.0;
    cout << "Average matches: "<< averageMatches << ", Max Matches: "<< maxMatches<< endl;
}
/* ******************************************************************
* ANROP : lottoexperimentera ();
* UPPGIFT : Ber anv ä ndaren knappa in en lottorad och kör sedan
* 20 x 1000 experiment med denna rad och skriver ut
* statistik i terminalf ö nstret .
****************************************************************** */
void lottoexperimentera ( ){
    vector <int > anvandarrad = lottoradFranAnvandare () ;
    for (int i =0; i <20 ; i +=1) {
        korTusenExperiment ( anvandarrad );
    }
}


void ingangTillCArrayOchStdVector4 () {
    cout << endl << "IngangTillCArrayOchStdVector +++++ " << endl ;
    lottoexperimentera();
    //vek.push_back(3.3);
    //cout << vek.size()<<endl;
    //anropaForokAndraVektornsVarden();
}
