#include <iostream> // innehaller cin , cout
#include <cstdlib> // innehaller rand
#include <cmath> // innehaller sqrt
#include <cassert>

using namespace std ;

void skrivUtArr ( const int arr [] , int antal ){
    cout << "(";
    for(int i =0; i<antal; i++){
        cout << " "<< arr[i];
        if(i<antal-1){
            cout << " ";
        }
    }
    cout << ")";
}
void fyllMedVarde ( int arr [] , int antal , int varde ){
    for(int i=0; i<antal; i++){
        arr[i]=varde;
    }
}
void fyllMedSlumptal ( int arr [] , int antal , int minsta , int storsta ) {
    for(int i=0; i<antal; i++){
        arr[i]=minsta + rand()%(storsta-minsta +1);
    }
}
int minst ( const int arr [] , int antal ){
    int min = arr[0];
    for(int i=0; i<antal; i++){
        if(arr[i]<min)
            min= arr[i];
    }
    return min;
}
int storst ( const int arr [] , int antal ){
    int max = arr[0];
    for(int i = 0; i<antal; i++){
        if(arr[i]>max)
            max= arr[i];
    }
    return max;
}
int indexTillMinsta ( const int arr [] , int antal ) {
    int min = arr[0];
    int indexMin =0;
    for(int i = 0; i<antal; i++){
        if(arr[i]<min){
            min=arr[i];
            indexMin = i;
        }
    }
    return indexMin;
}
int indexTillStorsta ( const int arr [] , int antal ){
    int max = arr[0];
    int indexMax =0;
    for(int i = 0; i<antal; i++){
        if(arr[i]>max){
            max=arr[i];
            indexMax = i;
        }
    }
    return indexMax;
}
bool arSorterad ( const int arr [] , int antal ){
    for(int i=0; i<antal; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}
bool innehaller ( const int arr [] , int antal , int x){
    for(int i= 0; i<antal; i++){
        if(arr[i]==x){
            return true;
        }
    }
    return false;
}


void provaArrayFunktionerna () {
    cout << " prova Array Funktionerna " << endl ;
    cout << "(om programmet kraschar har du en bug)" << endl ;
    const int storlek = 20;
    const int sista = storlek -1;
    int arr [ storlek ];
    fyllMedVarde ( arr , storlek , 5) ;
    skrivUtArr ( arr , storlek ) ;
    arr [0] = 4;
    arr [ sista ] = 6; // inneh å ller nu: 4 5 5 .... 5 5 6
    assert ( arSorterad ( arr , storlek ));
    assert ( innehaller ( arr , storlek , 4) );
    assert ( innehaller ( arr , storlek , 6) );
    assert (! innehaller ( arr , storlek , 3) );
    assert ( minst ( arr , storlek ) == 4) ;
    assert ( storst ( arr , storlek ) == 6) ;
    assert ( indexTillMinsta ( arr , storlek ) == 0) ;
    assert ( indexTillStorsta ( arr , storlek ) == sista );
    arr [ sista ]=3; // inneh å ller nu: 4 5 5 .... 5 5 3
    assert ( minst ( arr , storlek ) == 3) ;
    assert (! arSorterad ( arr , storlek ));
    // fyll med 20 och 21
    fyllMedSlumptal ( arr , storlek , 20 ,21) ;
    assert ( minst ( arr , storlek ) == 20 );
    assert ( storst ( arr , storlek ) == 21 );
    cout << endl;
    cout << " testen provaArrayFunktionerna lyckades !" << endl ;
    cout << endl ;
}

void ingangTillCArrayOchStdVector2 () {
    cout << endl << "IngangTillCArrayOchStdVector +++++ " << endl ;
    provaArrayFunktionerna();

}
