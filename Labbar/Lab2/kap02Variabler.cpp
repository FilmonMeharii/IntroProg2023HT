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

void ingangTillVariabler(){
    cout << "ingangTillVariabler"<<endl;
    provaTilldelning();
    lasOchSummera();
}
