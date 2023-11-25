#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std ;

void skapaFilenHejFilsystem () {
    string filnamn = "../hejFilsystem.txt";

    ofstream utStrom;
    utStrom.open(filnamn);

    for(int i= 0; i<10; i+=1)
        utStrom << i << " Hej!" << endl;
    utStrom.close();
}
void ingangTillSkrivaFil () {
    skapaFilenHejFilsystem();
}
