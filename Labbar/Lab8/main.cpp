#include "vanligt.h"

using namespace std;
void testaIf(){
    int x=0;
    if(true){
        x+=1;
        if(false){
            x+=2;
            if(true)
                x+=4;
            else x+=8;}
        else x+=16;
    }
    else x+=32;
    cout << x<<endl;
}
int main()
{
    cout << "Hello World!" << endl;
    cout << 6/2 + 6/2<< endl;
    testaIf();
    return 0;
}
