#include <iostream>

using namespace std;

void tempratur(){
    double tempratur = 18;
    cout << "Hej, idag ar det "<< tempratur << " grader varmt" << endl;
    if(tempratur>25)
        cout << "Du bor dricka mycket vatten. "<< endl;
    cout << "Ha en bra dag!"<< endl;
}

void tempratur2(){
    double tempratur = 18;
    cout << "Hej, idag ar det "<< tempratur << " grader varmt" << endl;
    if(tempratur>25){
        cout << "Du bor dricka mycket vatten. "<< endl;
        if(tempratur>=40)
            cout << "Hall dig inomhus om du kan."<< endl;
    }
    cout << "Ha en bra dag!"<< endl;
}

void tempratur3(){
    double tempratur = 18;
    cout << "Hej, idag ar det "<< tempratur << " grader varmt" << endl;
    if(tempratur>25){
        cout << "Du bor dricka mycket vatten. "<< endl;
        if(tempratur>=40)
            cout << "Hall dig inomhus om du kan."<< endl;
        else cout << "Perfekt vader for en utomhus aktivitet" << endl;
    }
    else cout << "Drick garna nagot varmt"<< endl;
    cout << "Ha en bra dag!"<< endl;
}
bool t1(){cout << "t1 " ; return true;}
bool t2(){cout << "t2 " ; return true;}
bool f1(){cout << "f1 " ; return false;}
bool f2(){cout << "f2 " ; return false;}

void provaBooluttryck(){
    cout << "provar boolska uttryck. "<< endl;
    bool b1=t1()&& (t2() || f1());
    cout << "resultat "<< b1<< endl;
    bool b2 = t1() || t2() ||f1();
    cout << "resultat "<< b2<<endl;
    bool b3= f1() || (t2() && (f1() || f2()));
    cout << "resultat "<<b3 << endl;
    cout << endl;
}
void ingangTillIfSatser(){
    cout << endl << "ingang Till If Satser .........."<< endl;
    provaBooluttryck();
    //tempratur3();
}
