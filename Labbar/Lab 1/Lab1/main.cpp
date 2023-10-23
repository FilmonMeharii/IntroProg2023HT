#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace this_thread;
using namespace chrono;

int main()
{
    sleep_for(milliseconds(500));
    cout << "Ett" << endl;
    sleep_for(milliseconds(500));
    cout << "Tva" <<endl;
    sleep_for(milliseconds(10000));
    cout << "Tre "<<endl;
    sleep_for(milliseconds(500));
    return 0;
}
