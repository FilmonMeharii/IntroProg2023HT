// mattefunktioner . cpp
#include <cmath>


double storst ( double a , double b) {
    if (a >b)
        return a;
    return b;
}
double kvadrat ( double a){
return a*a ;
}
double hypotenusa ( double x , double y) {
return sqrt ( kvadrat (x )+ kvadrat (y) );
}
