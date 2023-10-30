# include <iostream >
# include <cstdlib >
# include <cmath >
# include <cassert >
#include <ctime>

using namespace std;

//returnerar tal mellan 0 och 100 och n (exklusive n)
int nyttTal(int n){
    int slumptal =rand()%(n+1);
    return slumptal;
}

int anvandarensGissning(){
    int gissning;
    cout << "Din gissning:";
    cin >> gissning;
    return gissning;
}

void utforEnSpelGissning(){
    cout << "Utfor en spelomgang "<< endl;
    const int n=100;
    const int datorsTal = nyttTal(n);
    int gissning;
    int antalUtfardaGissningar = 0;
    cout << "Datorn tanker pa ett tal mellan noll och " << n << ". Gissa vilket!" << endl;

    do{
        gissning =anvandarensGissning();
        antalUtfardaGissningar +=1;

        if(gissning<datorsTal){
            cout <<"For Lite"<< endl;
        } else if(gissning>datorsTal){
            cout << "For stort"<< endl;
        }else {
            cout << "Du fick ratt pa " << antalUtfardaGissningar <<":e forsoket!"<<endl;
        }
    }while (gissning != datorsTal);
    cout << endl;
}

void ingangTillLoopar2() {
    cout << endl << " ingangTillLoopar2 +++++ " << endl ;
    utforEnSpelGissning();
}
