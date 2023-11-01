# include <iostream >
# include <cstdlib >
# include <cmath >
# include <cassert >
#include <ctime>
#include <iomanip>

using namespace std;

void skrivCollatzSekvens(long int startvarde){
    while (startvarde  !=1){
        cout << startvarde<< " ";
        if(startvarde % 2==0){
            startvarde /=2;
        }else {
            startvarde = startvarde*3+1;
        }
    }
}
long int collatzMax(long int startvarde){
    long int max= startvarde;
    while(startvarde !=1){
        if(startvarde > max){
            max=startvarde;
        }
        if(startvarde%2==0){
            startvarde /=2;
        }else{
            startvarde = startvarde*3+1;
        }
    }
    return max;
}
long int collatzLangd(long int startvarde){
    long int langd= 0;
    while(startvarde !=1){
        langd++;
        if(startvarde%2==0){
            startvarde /=2;
        }else{
            startvarde = startvarde*3+1;
        }
    }
    return langd+1;
}
void skrivCollatzStatistik(long int maxN){
    long int maxMax = 0;
    long int maxLangd = 0;
    long int maxMaxStart = 0;
    long int maxMaxLangd = 0;

    for(long int i =1; i<= maxN; i++){
        long int maxN = collatzMax(i);
        long int langd = collatzLangd(i);

        if(maxN > maxMax){
            maxMax = maxN;
            maxMaxStart = i;
        }

        if(langd >maxLangd){
            maxLangd = langd;
            maxMaxLangd = i;
        }
    }
    cout << "maximalt varde = "<< maxMax << " (for startVarde = " << maxMaxStart<< ")"<< endl;
    cout << "maximalt langd = " << maxLangd << " (for startVarde = " << maxMaxLangd <<")"<<endl;
}
void provaCollatzfunktionerna () {
    cout << endl << " provaCollatzfunktionerna " << endl ;
    cout << " Anropar skrivCollatzSekvens (7) " << endl ;
    skrivCollatzSekvens (7) ;
    cout << " collatzMax (7) = " << collatzMax (7) << endl ;
    cout << " collatzLangd (7) = " << collatzLangd (7) << endl ;
    skrivCollatzStatistik (10000) ;
    cout << endl ;
}

void ingangTillLoopar4() {
    cout << endl << " ingangTillLoopar4 +++++ " << endl ;
    provaCollatzfunktionerna();
}
