#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

void skrivTalV1(int tal){
    if(tal==1)
        cout << "ett"<<endl;
    else if(tal ==2)
        cout << "tva"<< endl;
    else if(tal==3)
        cout << "tre"<<endl;
    else cout<< tal<<endl;
}

void skrivTalV2(int tal){
    switch (tal) {
    case 1:cout << "ett" <<endl;
        break;
    case 2: cout << "tva"<<endl;
        break;
    case 3:cout << "tre "<< endl;
        break;
    default:cout << tal<<endl;
    }
}

void ifOchSwitch(){
    skrivTalV1(1);
    skrivTalV1(2);
    skrivTalV1(3);
    skrivTalV1(4);
    skrivTalV2(1);
    skrivTalV2(2);
    skrivTalV2(3);
    skrivTalV2(4);

}
