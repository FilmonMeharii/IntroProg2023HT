#include <iostream>
#include <cstdlib>
#include<thread>
#include <chrono>
#include <ctime>
#include <random>


using namespace std;
using namespace chrono;
using namespace this_thread;

struct Triplett{
    int m_varden[3];
};
Triplett slumpadTriplett(){
    Triplett treSlumptal;
    for(int i= 0; i<3; i++){
        treSlumptal.m_varden[i]= rand()%6+1;
    }
    return treSlumptal;
}
int bruttovinstFranTriplett (const Triplett& tripplett){
    int countSex = 0;
    for(int i=0; i<3; i++){
        if(tripplett.m_varden[i]==6){
            countSex++;
        }
    }
    if(countSex==3){
        return 100;
    }else{
        return 0;
    }
}
void skrivTriplett(const Triplett& tripplett){
    for (int i=0; i<3; i++){
        cout<<"Tarning "<< i +1 << ":  " <<tripplett.m_varden[i]<<endl;
        sleep_for(milliseconds(1000));
    }
}
bool boolFranUppmaning(const string& uppmaning){
    cout << uppmaning << "(ja/nej): "<< endl;
    string svar;
    cin >> svar;
    return svar == "ja";
}
void skrivResultat(int bruttovinst, int kapital){
    cout <<"Du vann "<< bruttovinst << " kronor och har nu " << kapital
        << " kronor kvar att spela for"<<endl;
}

void spelaTarningensspelet(){
    int kapital = 100;
    cout << "Du har "<< kapital << " kronor " << endl;
    while(kapital >=10){
        bool villSpela = boolFranUppmaning("Vill du spela ");
        if(villSpela){
            Triplett triplett = slumpadTriplett();
            skrivTriplett(triplett);
            int bruttovinst = bruttovinstFranTriplett(triplett);
            kapital = kapital + bruttovinst- 10;
            skrivResultat(bruttovinst, kapital);
        }
        else {
            cout << "Fegis!"<< endl;
            break;
        }
    }
}

void ingangTillTarningsspelet(){
    srand(static_cast<unsigned>(time(0)));

    cout << endl << " ingangTillTarningsspelet +++++ " << endl ;
    spelaTarningensspelet();
}
