#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;


int GLOBAL_VARIABEL{0};
void funkC(){
    int x{7};
    cout << "funcC: x ar " << x << endl;
    cout << "funcC: GLOBAL_VARIABEL ar " << GLOBAL_VARIABEL << endl;
    GLOBAL_VARIABEL = 77;
}
void funkB(){
    int x{5};
    GLOBAL_VARIABEL = 15;
    cout << "funcB: x ar " << x << endl;
    cout << "funcB: GLOBAL_VARIABEL ar " << GLOBAL_VARIABEL << endl;

    funkC();
    cout << "funcB: x ar " << x << endl;
    cout << "funcB: GLOBAL_VARIABEL ar " << GLOBAL_VARIABEL << endl;
}
void funkA(){
    funkB();
    funkC();
}
void anvandStatic1(){
    int a = 42;
    cout << "first " << a << " ";
    a = 108;
    cout << "sedan " << a << endl;
}
void anvandStatic2(){
    static int a = 42;
    cout << "first " << a << " ";
    a = 108;
    cout << "sedan " << a << endl;
}
void provaStatic1(){
    anvandStatic1();
    anvandStatic1();
}
void provaStatic2(){
    anvandStatic2();
    anvandStatic2();
}
void flyttalstyper(){
    cout << "EN float upptar " << 8*sizeof (float) <<" bit."<< endl;
    cout << "EN double upptar " << 8*sizeof (double) <<" bit."<< endl;
    cout << "EN long double upptar " << 8*sizeof (long double) <<" bit."<< endl;

}
void count (){
    int intN=1;
    for(int i = 0; i<5; i++){
        for(int j = 1; j<6; j++ ){
            cout << intN<< "  ";
            intN += (i+1);
        }
        cout << endl;
    }
}
void skrivUtFaktura(){
    const double procentMoms = 25.0;

    cout << "Utskrift av faktura. " << endl<< endl;
    cout << "Antal enheter:";
    int antalEnheter;
    cin>> antalEnheter;
    cout << "Pris per enhet:";
    double prisPerEnhet;
    cin >> prisPerEnhet;
    double prisUtanMoms = prisPerEnhet*antalEnheter;
    double moms = (prisUtanMoms * procentMoms)/100;
    double prisMedMoms = prisUtanMoms + moms;
    cout << setprecision(2) << fixed;
    cout << endl
         << "FAKTURA" << endl
         << "======" << endl
         <<"Antal enheter: " << setw(9) << antalEnheter << endl
        << "Pris/enhet:      " << setw(9) << prisPerEnhet << endl
        << "Totalt pris:       " << setw(9) << prisMedMoms << endl
        <<"Varv moms:      " << setw(9) << moms << endl;
}

int main()
{
    cout << "Hello World!" << endl;
    skrivUtFaktura();
    //count();
    //flyttalstyper();
    //provaStatic1();
    //provaStatic2();
    //    funkA(); //5 15 7 15 5 77 7 77
    return 0;
}
