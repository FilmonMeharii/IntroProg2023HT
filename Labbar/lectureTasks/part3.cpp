#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
using namespace chrono;

void t1(){
    int a = 0;
    while (a<10)
        a += 1;
    cout << a << endl;
}
void t2(){
    int a = 0;
    while (a<25)
        a += 10;
    cout << a << endl;
}
void t3(){
    int a = 1;
    while (a<10)
        a = a << 1;
    cout << a << endl;
}
void t4(){
    int a = 0;
    while (a<10){
        a += 1;
        cout << a << endl;
    }
}
void t5(){
    int a = 0;
    while (a<10)
        a += 1;
    cout << a << endl;
}
void forsokAndraVarden(int a, int& b, int arr[], int antalVarden){
    a = 42;
    b = 42;
    for(int i=0; i<antalVarden; ++i)
        arr[i] = 42;
    cout << "a= "<<a<<" ,b= "<<b<< " ,arr[]= "<<arr[0]<<arr[1]<<endl;
}
void anropaForsokAndraVarden(){
    int a = 0;
    int b = 0;
    int arr[2]{0,0};
    forsokAndraVarden(a, b, arr, 2);
    cout << "a= "<<a<<" ,b= "<<b<<  " ,arr[]= "<<arr[0]<<arr[1]<<endl;
}
int f(int a, int b){
    if(a>b)
        return a;
    return b;
}
int f(int a, int b, int c, int d){
    return f(f(a,b), f(c,d));
}
void testaF(){
    int tal = f(42,108,912, 13);
    cout << tal<<endl;
}
int x(const char *str){
    const char *pCh=str;
    while (*pCh !=0)
        ++pCh;
    return pCh -str;
}
void provaX(){
    cout << x("Jul")<< endl;
    cout << x("0123456789")<<endl;
}
double summa(double arr[], int antal){
    double summa =0.0;
    for(int i=0; i<antal; i++){
        summa +=arr[i];
    }
    return summa;
}
bool isSorted(double *pBegin, double *pEnd){

    for(double *pi =pBegin; pi<pEnd-1; pi++){
        if(*pi>*(pi+1))
            return false;
    }
    return true;
}
int maxStjarnasekvenslangd(const string str){
    int antalSjarna =0;
    int maxLength = 0;
    for(size_t i=0; i<str.size(); i++){
        if(str[i]=='*'){
            antalSjarna++;
        }
        else {
            maxLength = max(maxLength ,antalSjarna);
            antalSjarna = 0;
        }
    }
    maxLength = max(maxLength, antalSjarna);
    return maxLength;
}
int antalUnikaTecken(char* str){
    int count =0;
    for(int i =0; str[i] !=0;  i++){
        bool arOlika = true;
        for(int j=0; j<i; j++){
            if(str[i] ==str[j]){
                arOlika =false;
                break;}
        }
        if(arOlika){
            count++;
        }
    }
    return count;
}
void ordna(int* a, int* b){
    if(a>b){
        int temp = *a;
        *a= *b;
        *b=temp;
    }
}
void testIf(){
    int x=0;
    if(false){
        x+=1;
        if(true){
            x +=2;
            if(false)
                x+=4;
            else x+=8;
        }
        else x+=16;
    }
    else x+=32;
    cout << x<<endl;
}


void part3(){

    vector<int> numbers;
    for(int i=0; i<=10; i++){
        numbers.push_back(i);
    }

    for(int number:numbers)
        cout <<number<<endl;

    //provaX();
    //testaF();
    //anropaForsokAndraVarden();
}
