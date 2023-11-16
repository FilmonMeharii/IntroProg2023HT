# include <iostream>
# include <cassert >


using namespace std ;

void experimenteraMedChar () {
    cout << " experimenteraMedChar ..... " << endl ;
    char ch1 = 'R';
    char ch2 = 82;
    int i1 = 'R';
    int i2 = 82;
    cout <<"ch1 "<< ch1 << endl ;
    cout << "ch2 "<< ch2 << endl ;
    cout <<"i1 "<< i1 << endl ;
    cout << "i1 "<< i2 << endl ;
}
void skrivNagraAsciiTecken () {
    cout << " skrivNagraAsciiTecken " << endl ;
    const char tabulator = 9;
    for (int asciital = 'a' -5; asciital <= 'z'+5; ++ asciital ){
        char tecken = asciital ;
        cout << asciital << tabulator << tecken << endl ;
    }
}
void demoAvInbyggdStrang () {
    cout << " demoAvInbyggdStrang ............. " << endl ;
    char strang0 [4]{72 , 101 , 106 , 0};
    char strang1 [4]{ 'H', 'e', 'j', 0};
    char strang2 []{ 'H', 'e', 'j', 0};
    char strang3 [] = "Hej ";
    char strang4 []{ " Hej "};
    cout << "strang0 "<< strang0 << endl ;
    cout << "strang1 " << strang1 << endl ;
    cout << strang2 << endl ;
    cout << strang3 << endl ;
    cout << strang4 << endl ;
    cout << " Hej" << endl ;
}
void demoAvUtf8 () {
    cout << " demoAvUtf8 ............. " << endl ;
    char strang [] = " ABC 012 ÅÄÖ";
    cout << strang << endl ;
    for ( int i =0; strang [i ]!=0 ; ++ i){
        int heltal = strang [ i ];
        cout << heltal << " ";
    }
    cout << endl ;
}
void demoAvConst(const char str[]){
    int i= 0;
    while(str[i] !=0){
        i+=1;
        cout << "Antal Byte i "<< str<<" ar "<< i <<endl;
    }
}
void provaDemoAvConst(){
    char str[] = "Hej";
    demoAvConst(str);//IFK
    demoAvConst("Hello");//IFMMN
}
void demoAvStrangjamforelse(){
    cout << "demo av strang jamforelse................"<<endl;

    const char str1[] = "hej";
    const char str2[] = "hej";
    if(str1 == str2)
        cout << "aha, det star fel i kompendiet!"<<endl;
    else cout << "Ok, strangen ar olika" << endl;
}


void ingangTillTeckenOchStrangar () {
    cout << endl << " ingangTillTeckenOchStrangar +++++ " << endl ;
    demoAvStrangjamforelse();
    //provaDemoAvConst();
    //demoAvUtf8();
    //demoAvInbyggdStrang();
    //skrivNagraAsciiTecken();
    //experimenteraMedChar();
}
