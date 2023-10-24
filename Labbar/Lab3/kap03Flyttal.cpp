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

void ingangTillFlyttal(){
    cout << endl << "ingangTillFlyttal...."<<endl;
    beraknaBokkostnad();
    //provaUtskriftAvFlyttal();

}
