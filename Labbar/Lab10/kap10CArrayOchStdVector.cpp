#include <iostream> // innehaller cin , cout
#include <cstdlib> // innehaller rand
#include <cmath> // innehaller sqrt

using namespace std ;

bool arSkottar(int ar){
    return (ar%4 ==0) && ((ar%100 !=0)|| (ar%400 ==0));
}
int antalDagar(int ar, int manad){
    static const int dagarIManad[13]{0, 31,28,31,30,31,30,31,30,31,30,31,30};
    if(manad==2 && arSkottar(ar))
        return 29;
    return dagarIManad[manad];
}

void forsokAndraVarden(int a, int& b, int arr[], int antalVarden){
    a = 42;
    b= 42;
    for (int i=0; i<antalVarden; i++)
        arr[i] =42;
}
void anropaForsokAndraVarden(){
    int a = 0;
    int b=0;
    int arr[2] {0, 0};
    forsokAndraVarden(a, b, arr, 2);
    cout << "a=" << a << " b= "<< b<< " arr[]=" <<arr[0] <<" , " << arr[1]<< endl;
}

void ingangTillCArrayOchStdVector () {
    cout << endl << "IngangTillCArrayOchStdVector +++++ " << endl ;
    anropaForsokAndraVarden();
    //    int resultat = antalDagar(2024, 9);
    //    cout << resultat << endl;
}
