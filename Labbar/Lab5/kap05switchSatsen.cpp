#include <iostream>
#include <iomanip>

using namespace std;

void ifSatsen(){
    int tal=0;
    if(tal==1)
        cout << "ett";
    else if (tal==2)
        cout << "tva";
    else if(tal==3)
        cout << "tre";
    else cout <<tal <<endl;
}

void switchSatsen(){
    int tal=10;
    switch (tal) {
    case 1: cout << "ett";
        break;
    case 2: cout<< "tva";
        break;
    case 3: cout << "tre";
        break;
    default: cout << tal <<endl;
    }
}

int maxKaffekopparFranKlockslag ( int klockslag ){
    if ( klockslag <18)
        return 2;
    else if ( klockslag < 23)
        return 1;
    else return 0;
}

void ingangTillSwitchSatser(){
    cout << endl << "Ingang Till Switch Satser .........."<< endl<< endl;
    maxKaffekopparFranKlockslag(90);
    //ifSatsen();
    //switchSatsen();

}
