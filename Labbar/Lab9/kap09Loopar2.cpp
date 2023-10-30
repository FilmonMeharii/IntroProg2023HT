# include <iostream >
# include <cstdlib >
# include <cmath >
# include <cassert >
#include <ctime>

using namespace std;

//returnerar tal mellan 0 och 100 och n (exklusive n)
int nyttTal(int n){
    srand(time(nullptr));
    int slumptal =rand()%(n+1);
    return slumptal;
}
int anvandarensGissning(){
    int gissning;
    cout << "Din gissning:";
    cin >> gissning;
    return gissning;
}
void utforEnSpelGissning(){
    cout << "Utfor en spelomgang "<< endl;
    const int n=100;
    const int datorsTal = nyttTal(n);
    int gissning;
    int antalUtfardaGissningar = 0;
    cout << "Datorn tanker pa ett tal mellan noll och " << n << ". Gissa vilket!" << endl;

    do{
        gissning =anvandarensGissning();
        antalUtfardaGissningar +=1;

        if(gissning<datorsTal){
            cout <<"For Lite"<< endl;
        } else if(gissning>datorsTal){
            cout << "For stort"<< endl;
        }else {
            cout << "Du fick ratt pa " << antalUtfardaGissningar <<":e forsoket!"<<endl;
        }
    }while (gissning != datorsTal);
    cout << endl;
}

//Returnerar ett exakt varde på hur stor yta som ligger under
//Funktionen y=x*x mellan a och b på x -axeln
double integralX2FranAnalys(double a, double b){
    return (b*b*b - a*a*a)/3;
}
//returnerar ett aproxmativt varde på hur stor yta som ligger under
//funktionen y = x*x mellan a och b på x-axeln
double integralX2FranLoop(double a, double b){
    const double dx=0.01;
    double area=0;
    for(float x=a; x<(b-dx); x+=dx)
        area +=x*x;
    return area;
}
void jamforIntegrralberakningar(double a, double b){
    double resultatLoop = integralX2FranLoop(a, b);
    double resultatAnalys = integralX2FranAnalys(a, b);
    double diff = resultatLoop-resultatAnalys;
    cout << "integralX2FranLoop ("<<a<< " , "<<b<<") = "
         << resultatLoop << ", diff =" << diff <<endl;
}

void jamforFleraIntegralBerakningar(){
    jamforIntegrralberakningar(-1,1);
    jamforIntegrralberakningar(0,1);
    jamforIntegrralberakningar(1,2);
    jamforIntegrralberakningar(2,10);
    cout << endl;
}
void ingangTillLoopar2() {
    cout << endl << " ingangTillLoopar2 +++++ " << endl ;
    jamforFleraIntegralBerakningar();
    //utforEnSpelGissning();
}
