#include <iostream>
#include <string>
#include <limits>
#include <sstream>

using namespace std ;


void  utforBerakning(string uttryck){
    cout << "todo: berakna " << uttryck << endl;
}

void huvudLoop(){
    cout << "Valkommen till komandotolken!"<< endl;

    while (true) {
        string textRad;
        cout << ":";
        getline(cin, textRad);
        if(textRad == "")
            continue;
        if(textRad=="exit")
            break;
        utforBerakning(textRad);
    }
    cout << "(Lamnar komandotolken)" << endl;
}

void ingangTillExperimentMedCin2 () {
    cout << " ingangTillExperimentMedCin2 ." << endl ;
    huvudLoop();
}
