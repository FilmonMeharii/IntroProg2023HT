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

//Kvadratroten
double kvadratroten(double x){
    double k=0;
    double area =1.0;
    for(int i =0; i<10; ++i){
        k=x/area;
        area =(area+k)/2.0;
    }
    return area;
}
void jamforKvadratrotsberakningar(double x){
    double resultat = kvadratroten(x);
    double diff = resultat - sqrt(x);
    cout <<"Kvadratroten(" << x<< ") beraknad till " << resultat << " diff " << diff << endl;
}
void jamforFleraKvadratrotsberakningar(){
    jamforKvadratrotsberakningar(2);
    jamforKvadratrotsberakningar(10);
    jamforKvadratrotsberakningar(100);
    cout << endl;
}

// Skriver ut de n förrsta fibonacci - talen numrerade från 1.
// skrivUtFibonacci (6) skall skriva ut 1:1 , 2:1 , 3:2 , 4:3 , 5:5 , 6:8

void skrivUtFibonaci(int n){
    if(n>=1)
        cout << "1:1";
    if(n>=2)
        cout << ", 2:1";
    int x2 = 1;
    int x1 = 1;
    int tal;
    for (int i = 3; i<=n; ++i){
        tal = x1+x2;
        x2=x1;
        x1=tal;
        cout << ", "<< i  << ":" << tal;
    }
    cout << endl;
}

void ingangTillLoopar2() {
    cout << endl << " ingangTillLoopar2 +++++ " << endl ;
    skrivUtFibonaci(6);
    //jamforFleraKvadratrotsberakningar();
    //jamforFleraIntegralBerakningar();
    //utforEnSpelGissning();
}
