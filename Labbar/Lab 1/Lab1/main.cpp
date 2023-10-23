#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace this_thread;
using namespace chrono;
void raknaTillTre(){
    sleep_for(milliseconds(500));
    cout << "Ett" << endl;
    sleep_for(milliseconds(500));
    cout << "Tva" <<endl;
    sleep_for(milliseconds(1000));
    cout << "Tre "<<endl;
    sleep_for(milliseconds(500));
}

void raknaTillFyra(){
    raknaTillTre();
}
int main()
{
    raknaTillFyra();
    cout << "Rakna forsta gangen: "<<endl;
    raknaTillTre();
    cout <<"Rakna andra gangen till"<<endl;
    raknaTillTre();
    return 0;
}
