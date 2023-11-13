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
    int count[7] ={ 0};
    for(int i=0; i<3; i++){
        count[tripplett.m_varden[i]]++;
    }
    if(count[6]==3){
        return 100;
    }else if(count[tripplett.m_varden[0]] ==3 && tripplett.m_varden[0] !=6){
        return 50;
    }else if(count[tripplett.m_varden[0]]==2 || count[tripplett.m_varden[1]]==2
             ||count[tripplett.m_varden[2]]==2){
        return 20;
    }else if(count[tripplett.m_varden[0]]==2 && count[6]==1){
        return 20;
    }
    return 0;
}
void skrivTriplett(const Triplett& tripplett){
    cout << "Tarningarna blev ";
    for (int i=0; i<3; i++){
        cout<<endl<< tripplett.m_varden[i]<<endl;
        sleep_for(milliseconds(1000));
    }
    cout<< endl;
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
    srand(time(0));

    cout << endl << " ingangTillTarningsspelet +++++ " << endl ;
    spelaTarningensspelet();
}
