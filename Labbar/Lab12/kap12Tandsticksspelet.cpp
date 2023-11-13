#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

bool boolFranUppmaning(const string& uppmaning){
    cout << uppmaning <<"(ja/nej): ";
    string svar;
    cin>>svar;
    return (svar=="ja");

}
string stickStrang(int antaStickor){
    string str="";
    for(int i=0; i<antaStickor; i++){
        if(i % 5 ==0 && i> 0){
            str+=" ";
        }
        str+="|";
    }
    return str;
}

string testaStickString(){
    assert(stickStrang(1) == "|");
    assert(stickStrang(4) == "||||");
    assert(stickStrang(6) == "||||| |");
    assert(stickStrang(19) == "||||| ||||| ||||| ||||");
    return "Test passed";
}

int spelarensDrag(int antalStickor){
    int drag;
    do{
        cout << "Hur manga stickor vill du plocka(1 eller 2) ? ";
        cin >> drag;
    }while(drag !=1 && drag !=2);
    antalStickor--;
    return drag;
}

int datornsDrag(int antalStickor){
    assert(antalStickor >=1);
    return 1;
}


void spelaSticksspelet(){
    while(true){
        bool spela = boolFranUppmaning("Vill du spela sticka?");
        if(!spela){
            cout << "Fegis"<<endl;
            break;
        }
        int antalStickor = 20 + rand()%8;
        cout << "SPELBORD:" << stickStrang(antalStickor)<< endl;

        while(antalStickor>0){
            antalStickor -=spelarensDrag(antalStickor);
            cout << "SPELBORD:" <<stickStrang(antalStickor)<<endl;
            if(antalStickor<=0){
                cout << "Du vann, vilken tur du hade!" << endl;
                break;
            }
            int drag = datornsDrag(antalStickor);
            cout << "Datorn tar "<< drag << endl;
            antalStickor -= drag;
            cout << "SPELBORD:" << stickStrang(antalStickor)<<endl;

            if(antalStickor <=0){
                cout << "Datorn vann, loser!"<< endl;
                break;
            }
        }
    }
}

void ingangTillTandsticksspelet(){
    cout << endl << "ingang till tandsticks spelet +++"<< endl;

    spelaSticksspelet();
}
