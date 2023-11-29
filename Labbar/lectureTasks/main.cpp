#include <iostream>

using namespace std;

int GLOBAL_VARIABEL{0};
void funkC(){
    int x{7};
    cout << "funcC: x ar " << x << endl;
    cout << "funcC: GLOBAL_VARIABEL ar " << GLOBAL_VARIABEL << endl;
    GLOBAL_VARIABEL = 77;
}
void funkB(){
    int x{5};
    GLOBAL_VARIABEL = 15;
    cout << "funcB: x ar " << x << endl;
    cout << "funcB: GLOBAL_VARIABEL ar " << GLOBAL_VARIABEL << endl;

    funkC();
    cout << "funcB: x ar " << x << endl;
    cout << "funcB: GLOBAL_VARIABEL ar " << GLOBAL_VARIABEL << endl;
}
void funkA(){
    funkB();
    funkC();
}
void anvandStatic1(){
    int a = 42;
    cout << "first " << a << " ";
    a = 108;
    cout << "sedan " << a << endl;
}
void anvandStatic2(){
    static int a = 42;
    cout << "first " << a << " ";
    a = 108;
    cout << "sedan " << a << endl;
}

void provaStatic1(){
    anvandStatic1();
    anvandStatic1();
}
void provaStatic2(){
    anvandStatic2();
    anvandStatic2();
}
int main()
{
    cout << "Hello World!" << endl;
    provaStatic1();
    provaStatic2();
    //    funkA(); //5 15 7 15 5 77 7 77
    return 0;
}
