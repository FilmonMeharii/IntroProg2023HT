# include <iostream>
# include <cstdlib>
# include <string>

using namespace std ;
struct Cell {
    int m_siffra ;
    bool m_arFix ;
};
struct Sudoku {
    Cell m_mtx [9][9];
};
struct Speldrag {
    bool m_villAvsluta ;
    int m_r ;
    int m_k ;
    int m_siffra ;
};
Sudoku nyttSudoku () {
    // Då vi ä nnu inte behandlat text så någa kan du knycka denna kod
    // och lita på att den fungerar .
    // Nedanst å ende sudoku har jag " knyckt " från en annan kä lla .
    string rader [9]{
        "6 2581397 ",
        " 7819 452 ",
        "5 6278 1",
        " 7429 683 ",
        " 93841 2 5",
        " 265 73 4",
        " 56 42739 ",
        " 2 369158 ",
        " 319 8 6 "
    };
    // Skapar sudoku med siffror hä mtade från ovanst å ende str ä ngar .
    // Mellanslag symboliserar de tomma rutor anv ä ndaren skall fylla i.
    // Rutor med siffror anses vara " fixa ".
    Sudoku sudoku ;
    for ( int r =0; r <9;++ r )
        for ( int k =0; k <9; ++ k) {
            char tecken = rader [r ][ k ];
            if ( tecken == ' '){
                sudoku . m_mtx [r ][ k ]. m_siffra = 0;
                sudoku . m_mtx [r ][ k ]. m_arFix = false ;
            }
            else {
                sudoku . m_mtx [r ][ k ]. m_siffra = tecken -'0';
                sudoku . m_mtx [r ][ k ]. m_arFix = true ;
            }
        }
    return sudoku ;
}
// Promptar anv ä ndaren efter ett drag upprepade gå nger tills
// anv ä ndaren knappar in ett giltigt drag (ex AK4) eller
// skriver exit .
// Funktionen returnerar motsvarande Speldrag - objekt .
Speldrag speldragFranAnvandare () {
    while ( true ) {
        cout << ":";
        string str ;
        cin >> str ;
        if ( str ==" exit "){
            return Speldrag {true , 0 ,0 ,0};
        }
        if ( str . size () ==3) {
            int r = str [0] - 'A';
            int k = str [1] - 'J';
            if(str[2] == '\n'){
                cin.ignore();
            }
            int siffra = str [2] - '0';
            if (r >=0 && r <9 && k >=0 && k <9 && siffra >=0 && siffra <=9) {
                Speldrag drag {false , r ,k , siffra };
                return drag ;
            }
        }
    }
}
// Returnerar antalet gånger som " siffra " förekommer i den rektangulära
// region som ges av parametrarna rBegin , rEnd och kBegin , kEnd
int antalForekomsterIRegion ( const Sudoku & sudoku , int siffra ,
                              int rBegin , int rEnd , int kBegin , int kEnd ){
    int count = 0;
    for(int r=rBegin; r<=rEnd; ++r)
        for(int k=kBegin; k<=kEnd; k++)
            if(sudoku.m_mtx[r][k].m_siffra == siffra)
                count++;
    return count;
}
// Returnerar true omm det finns en siffra på position r,k som ocks å fö rekommer
// på nå got annat ställe i samma rad , kolumn , eller block .
bool arKonflikt ( const Sudoku & sudoku , int r , int k ){
    int siffra = sudoku . m_mtx [r ][ k ]. m_siffra ;
    if ( siffra == 0)
        return false ;

    // Returnera true om siffra fö rekommer mer än en gång i aktuell rad , kolumn , eller block .
    for(int i=0; i<9; ++i){
        if(i !=k && sudoku.m_mtx[r][i].m_siffra== siffra)
            return true;
    }
    //Kolallar konflikt i colmun
    for(int i=0; i<9; ++i){
        if(i !=r && sudoku.m_mtx[i][k].m_siffra== siffra)
            return true;
    }

    int blockRad = 3*(r/3);
    int blockCol = 3*(k/3);
    for(int i = blockRad; i<blockRad + 3; ++i){
        for(int j= blockCol; j<blockCol + 3; ++j){
            if ((i != r || j != k) && sudoku.m_mtx[i][j].m_siffra == siffra)
                return true;
        }
    }
    return false;
}
// Skriver ut sudokut på skä rmen . Raderna markeras med A..I och kolumnerna med J..R
// Siffror som står i konflikt med andra siffror markeras med parenteser

#include <iomanip>

void skrivUtSudoku(const Sudoku &sudoku) {
    cout << "  J K L M N O P Q R" << endl;
    cout << " +-+-+-+-+-+-+-+-+-" << endl;
    for (int r = 0; r < 9; ++r) {
        cout << char('A' + r) << "|";
        for (int k = 0; k < 9; ++k) {
            if (sudoku.m_mtx[r][k].m_siffra != 0) {
                if (arKonflikt(sudoku, r, k)) {
                    cout << "(" << setw(0) << sudoku.m_mtx[r][k].m_siffra << ")";
                } else {
                    cout << " " << setw(0) << sudoku.m_mtx[r][k].m_siffra << " ";
                }
            } else {
                cout << " . ";
            }
            if (k == 2 || k == 5) {
                cout << "|";
            }
        }
        cout << endl;
        if (r == 2 || r == 5) {
            cout << " +-+-+-+-+-+-+-+-" << endl;
        }
    }
    cout << " +-+-+-+-+-+-+-+-" << endl;
}


// Skriver ut flera tomma rader så att i praktiken terminalf ö nstret rensas .
void rensaTerminalfonster () {
    for (int i =0; i <10 ; ++ i)
        cout << endl ;
}
void utforSpeldrag ( Sudoku & sudoku , const Speldrag & speldrag ){
    if (!sudoku.m_mtx[speldrag.m_r][speldrag.m_k].m_arFix) {
        sudoku.m_mtx[speldrag.m_r][speldrag.m_k].m_siffra = speldrag.m_siffra;
    }
}
// Lå ter anvä ndaren fylla i ett sudoku .
void spelaSudoku () {
    Sudoku sudoku = nyttSudoku () ;
    while ( true ) {
        rensaTerminalfonster () ;
        skrivUtSudoku ( sudoku ) ;
        Speldrag drag = speldragFranAnvandare () ;
        if ( drag.m_villAvsluta)
            break ;
        utforSpeldrag ( sudoku , drag ) ;
    }
    cout << "(hej da! Spelet avslutas )" << endl ;
}


void ingangTillSudoku () {
    cout << endl << " ingangTillSudoku +++++ " << endl ;
    spelaSudoku();
}
