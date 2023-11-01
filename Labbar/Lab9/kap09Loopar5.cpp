# include <iostream >
# include <cstdlib >
# include <cmath >
# include <cassert >
#include <ctime>
#include <iomanip>

using namespace std;

// ******** e Upph öjt Till x ************
double minExponent ( double x){
    double term = 1.0;
    double summa = 1.0;
    for(int i=1; i<20; i++){
        term *=x/i;
        summa+=term;
    }
    return summa;
}
void testaMinExponent ( double x ) {
    double resultat = minExponent (x);
    double diff = resultat - exp ( x );
    cout << " eUpphojtTill (" << x << ") beraknad till " << resultat << " diff " << diff ;
    if ( -0.01 < diff && diff < 0.01)
        cout << " (ok)" << endl ;
    else cout << " !!!!!!!!!!!!!!!!!1 " << endl ;
}
void testaFleraExponenter () {
    for ( double x =0.1; x <20; x *=2)
        testaMinExponent (x );
}

// ******** minSinus ************
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double minSinus ( double x) {
    double sinValue = 0.0;
    double term = x;
    double faktor = 1.0;
    int n = 1;

    for (int i=0; i<10; ++i){
        sinValue += term;
        faktor *= -1.0;
        n+=2;
        term = faktor * (pow(x, n))/ factorial(n);
    }
    return sinValue;
}
void plottaMinSinus () {
    for (int vinkelIGrader =0; vinkelIGrader <4*360; vinkelIGrader +=15) {
        double vinkelIGradianer = M_PI * vinkelIGrader /180.0;
        double s = minSinus ( vinkelIGradianer ) ;
        int antalSpace = s *10 + 50;
        for (int i =0; i < antalSpace ; ++ i)
            cout << " ";
        cout << "*" << endl ;
    }
}

void ingangTillLoopar5() {
    cout << endl << " ingangTillLoopar5 +++++ " << endl ;
    plottaMinSinus();
    //testaFleraExponenter();
}
