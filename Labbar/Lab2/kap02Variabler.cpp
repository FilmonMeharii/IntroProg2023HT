#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void provaTilldelning(){
    int x{10};
    int y{20};

    x=y;
    cout << "x ar " << x << " och y ar " << y << endl;
    y=100;
    cout << "x ar " << x << " och y ar " << y << endl;
}

void lasOchSummera(){
    int x, y;
    cout << " Ange x : ";
    cin >> x;
    cout << "Ange y: ";
    cin>>y;
    cout << "Summan ar : "<< x+y << endl;
}

void lasochBytVarden(){
    int x, y;
    cout << " Ange x : ";
    cin >> x;
    cout << "Ange y: ";
    cin>>y;
    int temp = x;
    x=y;
    y=temp;
    cout << "x ar "<< x << " och y ar " << y << endl;
}

void lasString(){
    string fornamn;
    cout<< "Ange ditt fornamn:" ;
    cin >> fornamn;
    string efternamn;
    cout << "Tack " << fornamn << ", ange nu ditt efternamn: " ;
    cin>> efternamn;
    cout << "Hej " << fornamn << " "<<  efternamn << "!" << endl;
}


void ingangTillVariabler(){
    cout << "ingangTillVariabler"<<endl;
    lasString();
    //provaTilldelning();
    //lasOchSummera();
    //lasochBytVarden();
}
