# include <iostream >
# include <cstdlib >
# include <cmath >
# include <cassert >


using namespace std ;

void kylskapMedWhileTrue () {
    cout << " kylskap med while true " << endl ;
    double tempratur;
    cout <<"Knappa in tempraturen: ";
    cin>>tempratur;
    while ( true ) {
        if(tempratur<-273)
            break;
        else if(tempratur <=2)
            cout << "Tempraturn ar for kallt"<< endl;
        else if(tempratur >=8)
            cout << "Tempraturn ar for varmt"<< endl;
        else cout << "Tempraturn ar lagom"<<endl;
        break;
    }
    cout << "lamnar kylskapsloop ." << endl ;
    return;
}

void ingangTillLoopar () {
    cout << endl << " ingangTillLoopar +++++ " << endl ;

    kylskapMedWhileTrue();
}
