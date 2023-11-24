#include <iostream>
#include <string>
#include <limits>
#include <sstream>

using namespace std ;


void  utforBerakning(string uttryck){
    cout << "todo: berakna " << uttryck << endl;
    int a,b;
    char op;

    istringstream datastrom(uttryck);
    datastrom >> a >> op >> b;
    bool ok = !datastrom.fail();
    if(ok){
        char dum;
        datastrom >> dum;
        ok = datastrom.fail();
    }
    if(ok){
        if(op == '+') cout << a+b << endl;
        else if(op == '*') cout << a*b << endl;
        else if(op == '/') cout << a/b << endl;
        else if(op == '%') cout << a%b << endl;
        else ok = false;
    }
    if(!ok)
        cout << "Fattar ej!" << endl;
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
