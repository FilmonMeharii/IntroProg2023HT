#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;
using namespace this_thread;
using namespace chrono;



void provaUtskriftAvFlyttal(){
    cout << "provaUtskriftAvFlyttal" << endl;
    double tal = 7.7777777;
    cout << "Talet ar : " << tal << endl;
    cout << "Med 3 vardesiffror: "<< setprecision(3)<< tal << endl;
    cout << "Med 3 decimaler:  "<< fixed << setprecision(3)<< tal<<endl;
    cout << "Talet ar: " << tal << endl;
}

void beraknaBokkostnad(){
    double pris;
    int antalSidor;
    double procentAttLasa ;
    double minuterPerSida;

    cout <<"Hur mycket kostar boken: ";
    cin >> pris;
    cout << "Hur manga sidor har boken?: ";
    cin >> antalSidor;
    cout << "Hur mycket procent kommer du att lasa:";
    cin >> procentAttLasa;
    cout << "Hur manga minuter tar det att lasa en sida?:";
    cin >> minuterPerSida;

    cout << "Tystnad berakning pagar ..." << endl;
    sleep_for(milliseconds(1000));

    double totalAntalTimmar;
    double kostnadPerTimme;
    totalAntalTimmar= (procentAttLasa/100)*minuterPerSida*antalSidor;
    kostnadPerTimme = pris/(totalAntalTimmar/60);
    cout << "Du beraknas agna boken ca "<<totalAntalTimmar<<endl;
    cout << " Boken beraknas darfor kosta dig " << setprecision(2)<< kostnadPerTimme << "kr/timme"<<endl;
}

void undersokFlyttalstyper(){
    cout << "En float upptar " << 8*sizeof (float)<< " bit." <<endl;
    cout << "En double upptar "<< 8*sizeof (double)<<" bit."<<endl;
    cout << "En long double upptar "<< 8 *sizeof (long double) << " bit."<<endl;
}

void provaNoggrannhet () {
    double nollKommaEtt = 0.1;
    double nollKommaTreA = 0.3;
    double nollKommaTreB = 3* nollKommaEtt ;
    cout << endl ;
    cout << " Skriver ut 0.1 och 0.3 och 0.3: " << endl ;
    cout << nollKommaEtt << endl ;
    cout << nollKommaTreA << endl ;
    cout << nollKommaTreB << endl ;
    cout << setprecision (17) ;
    cout << endl ;
    cout << " Skriver ut 0.1 och 0.3 och 0.3 igen :" << endl ;
    cout << nollKommaEtt << endl ;
    cout << nollKommaTreA << endl ;
    cout << nollKommaTreB << endl ;
}
void provaInfinity () {
    double noll = 0;
    double tva = 2;
    cout << endl ;
    cout << " Division med noll :" << endl ;
    cout << noll / noll << endl ;
    cout << tva / noll << endl ;
    cout << - tva / noll << endl ;
    cout << endl ;
    cout << "En liten lek med oä ndligheten :" << endl ;
    double oo = tva / noll ;
    cout << tva * oo << endl ;
    cout << oo + oo << endl ;
    cout << oo - oo << endl ;
    cout << -oo - oo << endl ;
    cout << endl ;
    cout << " Division med oä ndligheten :" << endl ;
    cout << tva / oo << endl ;
    cout << - tva / oo << endl ;
    cout << oo / oo << endl ;
    cout << -oo / oo << endl ;
    cout << endl ;
}
void provaFlyttal () {
    cout << endl << " provaFlyttal " << endl ;
    provaNoggrannhet () ;
    provaInfinity () ;
}


void ingangTillFlyttal(){
    cout << endl << "ingangTillFlyttal...."<<endl;
   provaFlyttal();
    //undersokFlyttalstyper();
    //beraknaBokkostnad();
    //provaUtskriftAvFlyttal();

}
