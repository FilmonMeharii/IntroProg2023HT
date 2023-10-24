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

void okaHeltalsVariabel(){
    int x;
    cout << "knappa in siffra for x: ";
    cin >> x;
    x+=10;
    cout <<"ny varde for x ar: "<< x<<endl;
}

void preOchPostInkrementering(){
    int x= 10;
    int y= 10;
    int ppX =++x;
    int yPp = y++;
    int yefter =y;
    cout << ppX << endl;
    cout << yPp << endl;
    cout << yefter << endl;
}

void skrivHypotenusaBerakning(double x, double y){
    double rKvadrat = (x*x) + (y*y);
    double r = sqrt(rKvadrat);
    cout << "x ar : " << x << " och y ar "<< y << "."<<endl;
    cout << "Summan av kvadreterna blir " << rKvadrat << endl;
    cout << "Vilket gor att hypotenusans blir " << r << endl ;
}

void provaAnropaHypotenusaBerakning(){
    skrivHypotenusaBerakning(4, 3);
    double a= 1;
    double b= 2;
    skrivHypotenusaBerakning(a, b);
    double x= 2;
    double y= 3;
    skrivHypotenusaBerakning(y,x);
}

int GLOBAL_VARIABEL{0};
void funkC(){
    int x{7};
    cout << "funkC: x ar "<< x << endl;
    cout << "funkB GLOBAL_VARIABEL ar " << GLOBAL_VARIABEL << endl;

    GLOBAL_VARIABEL = 77;
}

void funkB(){
    int x{5};
    GLOBAL_VARIABEL = 15;

    cout << " funkB x ar " << x << endl;
    cout << "funkB GLOBAL_VARIABEL ar " << GLOBAL_VARIABEL << endl;

    funkC();

    cout << " funkB x ar " << x << endl;
    cout << "funkB GLOBAL_VARIABEL ar " << GLOBAL_VARIABEL << endl;
}

void funkA(){
    funkB();
    funkC();
}

//5 15 7 15 5 77 7 77


void ingangTillVariabler(){
    cout << "ingangTillVariabler"<<endl;
    funkA();
    //provaAnropaHypotenusaBerakning();
    //preOchPostInkrementering();
    //okaHeltalsVariabel();
    //lasString();
    //provaTilldelning();
    //lasOchSummera();
    //lasochBytVarden();
}
