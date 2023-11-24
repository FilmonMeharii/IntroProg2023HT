#include <iostream>
#include <cassert>

using namespace std;

void fyllMedVarde(int *pBegin, int *pEnd, int varde){
    for(int *pData=pBegin; pData != pEnd; ++pData)
        *pData = varde;
}
void provaFyllMedVarde(){
    const int antalElement = 10;
    int arr[antalElement];
    fyllMedVarde(&arr[0], &arr[antalElement], 42);
}

void skrivUtArr ( const int * pBegin , const int * pEnd ){
    for(const int *i = pBegin; i<pEnd; ++i){
        cout << "( "<< i << ")"<< " "<< endl;
    }
}
void fyllMedVarden ( int * pBegin , int * pEnd , int varde ) {
    for( int *i = pBegin; i<pEnd; ++i){
        *i = varde;
    }
}
void fyllMedSlumptal ( int * pBegin , int * pEnd , int minst , int storst ) {
    for( int *i = pBegin; i<pEnd; ++i){
        *i = rand()%(storst-minst+1)+minst;
    }
}
int minst ( const int * pBegin , const int * pEnd ){
    assert ( pEnd - pBegin > 0) ;
    int minst = *pBegin;
    for(const int *i=pBegin; i<pEnd; ++i ){
        if(*i < minst)
            minst= *i;
    }
    return minst;
}
int storst ( const int * pBegin , const int * pEnd ){
    assert ( pEnd - pBegin > 0) ;
    int storsta = *pBegin;
    for(const int *i=pBegin; i<pEnd; ++i ){
        if(*i > storsta)
            storsta= *i;
    }
    return storsta;
}
bool arSorterad ( const int * pBegin , const int * pEnd ){
    for(const int *i=pBegin; i<pEnd; ++i ){
        if(*(i-1)>*i)
            return  false;
    }
    return true;
}
bool innehaller ( const int * pBegin , const int * pEnd , int x){
    for(const int *i=pBegin; i<pEnd; ++i ){
        if(*i == x)
            return  true;
    }
    return false;
}
void testaArrayfunktionernaP () {
    cout << " testar arrayfunktionerna -P " << endl ;
    const int storlek = 10;
    int arr [ storlek ];
    fyllMedVarde (& arr [0] , & arr [ storlek ], 5) ;
    skrivUtArr (& arr [0] , & arr [ storlek ]) ;
    arr [0] -= 1;
    arr [ storlek -1] += 1;
    assert ( arSorterad (& arr [0] , & arr [ storlek ]) );
    arr [0] = 6;
    assert ( ! arSorterad (& arr [0] , & arr [ storlek ]) ) ;
    fyllMedSlumptal (& arr [0] , & arr [ storlek ], -2, 2) ;
    skrivUtArr (& arr [0] , & arr [ storlek ]) ;
    arr [1] = -3; // Detta blir det minsta vä rdet
    arr [ storlek -1] = 3; // Detta blir det stö rsta vä rdet
    int m = minst (& arr [0] , & arr [ storlek ]) ;
    int s = storst (& arr [0] , & arr [ storlek ]) ;
    assert ( m == -3 && s == 3 ) ;
    assert ( innehaller (& arr [0] , & arr [ storlek ] , 3) );
    cout << " testar av arrayfunktionerna -P lyckades " << endl ;
}

void ingangTillPekare2(){
    cout << "Ingang till pekare2 +++++++ "<< endl;

    testaArrayfunktionernaP();
    //provaFyllMedVarde();
}
