#include <iostream>
#include <iomanip>

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

bool arJamnt(int n){
    if(n%2 == 0)
        return true;
    else return false;
}

void provaAttJamforaFlyttal(){
    cout << "Provar att jamfora flyttal  " <<endl;
    double tal1 = 0.3;
    double tal2= 0.1 +0.1+0.1;

    if(tal1==tal2)
        cout <<tal1 << " och " << tal1 << " ar lika "<<endl;
    else cout << tal1 << " och "<< tal2 << " ar olika" << endl;

    cout<< setprecision(20) << tal1 << " och " <<tal2 << endl;
    cout << endl;
}

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

bool ungefarLika ( double a , double b){
    if(a==b)
        return true;
    return false;
}
void testaUngefarLika () {
    cout << " testar ungefarLika " << endl ;
    const double epsilon = 0.0005;
    const double delta = 0.002;
    const double x = 123.5;
    bool ok1 = ungefarLika ( x , x + epsilon ) ;
    bool ok2 = ungefarLika ( x , x - epsilon ) ;
    bool ok3 = ! ungefarLika ( x , x + delta );
    bool ok4 = ! ungefarLika ( x , x - delta );
    if ( ok1 && ok2 && ok3 && ok4 )
        cout << " ungefarLika klarade testen " << endl ;
    else cout << " ungefarLika har minst en BUGG !!!!! " << endl ;
    cout << endl ;
}
void ingangTillIfSatser(){
    cout << endl << "ingang Till If Satser .........."<< endl<< endl;
    testaUngefarLika();
    //provaAttJamforaFlyttal();
    //provaBooluttryck();
    //tempratur3();
}
