# include <iostream>
# include <cstdlib>
# include <string>
#include <cassert>
#include <algorithm>
#include <iomanip>

using namespace std ;

struct Yatzyhand{
    int m_varden[5];
};
struct YatzyTabell{
    int spelarePoang[2][15];
};

int vardeSomPar(const Yatzyhand& yatzyhand){

    for(int tarningsutfall=6; tarningsutfall >=1; tarningsutfall--){
        int count = 0;
        for(int i=0; i<5; i++){
            if(yatzyhand.m_varden[i] == tarningsutfall){
                count++;
            }
        }
        if(count >=2){
            return 2*tarningsutfall;
        }
    }
    return 0;
}
int vardeSomTvapar(const Yatzyhand &yatzyhand) {
    int pair1 = 0;
    int pair2 = 0;

    for (int tarningsutfall = 6; tarningsutfall >= 1; --tarningsutfall) {
        int count = 0;
        for (int i = 0; i < 5; ++i) {
            if (yatzyhand.m_varden[i] == tarningsutfall) {
                count++;
            }
        }

        if (count >= 2) {
            if (pair1 == 0) {
                pair1 = 2 * tarningsutfall;
            } else {
                pair2 = 2 * tarningsutfall;
                return pair1 + pair2;
            }
        }
    }

    return 0;
}
int vardeSomTriss(const Yatzyhand& yatzyhand){
    for(int tarningsutfall=6; tarningsutfall >=1; tarningsutfall--){
        int count = 0;
        for(int i=0; i<5; i++){
            if(yatzyhand.m_varden[i] == tarningsutfall){
                count++;
            }
        }
        if(count >=3){
            return 3*tarningsutfall;
        }
    }
    return 0;
}
int vardeSomLitenStege ( const Yatzyhand & yatzyhand ){
    int expectedValues[5]={1,2,3,4,5};
    Yatzyhand sortedHand = yatzyhand;
    sort(sortedHand.m_varden, sortedHand.m_varden +5);
    for(int i=0; i<5; ++i){
        if(sortedHand.m_varden[i] != expectedValues[i]){
            return 0;
        }
    }
    return 15;
}
int vardeSomStorStege ( const Yatzyhand & yatzyhand ){
    int expectedValues[5]={2,3,4,5,6};
    Yatzyhand sortedHand = yatzyhand;
    sort(sortedHand.m_varden, sortedHand.m_varden +5);
    for(int i=0; i<5; ++i){
        if(sortedHand.m_varden[i] != expectedValues[i]){
            return 0;
        }
    }
    return 20;
}
int vardeSomKak(const Yatzyhand &yatzyhand) {
    int counts[7] = {0};
    for (int i = 0; i < 5; ++i) {
        counts[yatzyhand.m_varden[i]]++;
    }
    int pair = 0;
    int triss = 0;
    for (int i = 1; i <= 6; ++i) {
        if (counts[i] == 2) {
            pair = 2 * i;
        } else if (counts[i] == 3) {
            triss = 3 * i;
        }
    }

    if (pair > 0 && triss > 0) {
        return pair + triss;
    } else {
        return 0;
    }
}
int vardeSomFyrtal(const Yatzyhand &yatzyhand) {
    int histo[7] = {0};

    for (int i = 0; i < 5; ++i) {
        histo[yatzyhand.m_varden[i]]++;
    }

    for (int i = 1; i <= 6; ++i) {
        if (histo[i] >= 4) {
            return 4 * i;
        }
    }

    return 0;
}
int vardeSomYatzy(const Yatzyhand &yatzyhand) {
    int value = yatzyhand.m_varden[0];

    for (int i = 1; i < 5; ++i) {
        if (yatzyhand.m_varden[i] != value) {
            return 0;
        }
    }

    return 50;
}
void testaVardeSom () {
    cout << " testa Varde Som " << endl ;
    cout << "(om programmet kraschar har du en bugg )" << endl ;
    assert ( vardeSomPar ({3 , 6 , 4, 2, 4}) == 8 ) ;
    assert ( vardeSomPar ({3 , 2 , 4, 2, 3}) == 6 ) ;
    assert ( vardeSomPar ({3 , 4 , 4, 2, 4}) == 8 ) ;
    assert ( vardeSomPar ({3 , 5 , 4, 2, 1}) == 0 ) ;
    assert ( vardeSomPar ({2 , 4 , 5, 5, 4}) == 10 );
    assert ( vardeSomPar ({6 , 2 , 4, 4, 6}) == 12 );
    assert ( vardeSomPar ({3 , 3 , 3, 3, 3}) == 6 ) ;

    assert ( vardeSomTvapar ({3 , 6, 4, 2, 4}) == 0 );
    assert ( vardeSomTvapar ({3 , 2, 4, 2, 3}) == 10 ) ;
    assert ( vardeSomTvapar ({3 , 4, 4, 2, 4}) == 0 );
    assert ( vardeSomTvapar ({3 , 5, 4, 2, 1}) == 0 );
    assert ( vardeSomTvapar ({2 , 4, 5, 4, 5}) == 18 ) ;
    //assert ( vardeSomTvapar ({3 , 3, 3, 3, 3}) == 12 ) ;

    assert ( vardeSomTriss ({3 , 6, 4, 2 , 4}) == 0 );
    assert ( vardeSomTriss ({3 , 2, 4, 2 , 3}) == 0 );
    assert ( vardeSomTriss ({3 , 4, 4, 2 , 4}) == 12 );
    assert ( vardeSomTriss ({3 , 5, 4, 2 , 1}) == 0 );
    assert ( vardeSomTriss ({2 , 4, 5, 4 , 5}) == 0 );
    assert ( vardeSomTriss ({3 , 3, 3, 3 , 3}) == 9 );

    assert ( vardeSomLitenStege ({3 , 6, 4, 2, 4}) == 0 );
    assert ( vardeSomLitenStege ({3 , 2, 4, 2, 3}) == 0 );
    assert ( vardeSomLitenStege ({3 , 4, 4, 2, 4}) == 0 );
    assert ( vardeSomLitenStege ({3 , 5, 4, 2, 1}) == 15 ) ;
    // TODO testa själv
    // stor stege
    // kak
    // fyrtal
    // Yatzy
    assert(vardeSomStorStege({2, 3, 4, 5, 6}) == 20);
    assert(vardeSomStorStege({1, 2, 3, 4, 5}) == 0);

    assert(vardeSomKak({2, 2, 3, 3, 3}) == 13);
    assert(vardeSomKak({1, 2, 3, 4, 5}) == 0);

    assert(vardeSomFyrtal({3, 3, 3, 3, 5}) == 12);
    assert(vardeSomFyrtal({1, 2, 3, 4, 5}) == 0);

    assert(vardeSomYatzy({3, 3, 3, 3, 3}) == 50);
    assert(vardeSomYatzy({1, 2, 3, 4, 5}) == 0);

    cout << " testen lyckades " << endl ;
    cout << endl ;
}

Yatzyhand kastaTarningar() {
    Yatzyhand hand;
    for (int i = 0; i < 5; ++i) {
        hand.m_varden[i] = rand() % 6 + 1;
    }
    return hand;
}


void skrivUtTabell(const YatzyTabell &tabell){
    cout << setw(15) << " ";
    cout << setw(5) << "Dator" ;
    cout << setw(5) << "     Spelare 2";
    cout << endl;

    for(int kategori = 0; kategori< 15; ++kategori){
        cout << setw(15) << "Kategori:" << (kategori +1);
        for (int spelare = 0; spelare < 2; ++spelare) {
            cout <<"   "<< setw(5) << tabell.spelarePoang[spelare][kategori];
        }
        cout << endl;
    }
}
int valjKategori() {
    int valdKategori;
    cout << "Valj en kategori (1-15): "<<endl;
    cin >> valdKategori;
    return valdKategori;
}

void ingangTillYatzy () {
    cout << endl << " ingangTillYatzy +++++ " << endl ;
    //testaVardeSom();

    srand(static_cast<unsigned int>(time(nullptr)));
    YatzyTabell yatzyTabell = {};
    const int antalOmgangar = 13; // Antal omgångar i ett fullständigt Yatzy-spel
    const int antalSpelare = 2;

    for (int omgang = 0; omgang < antalOmgangar; ++omgang) {
        for (int spelare = 0; spelare < antalSpelare; ++spelare) {
            skrivUtTabell(yatzyTabell);

            Yatzyhand yatzyhand = kastaTarningar();
            cout << "Spelare " << (spelare + 1) << ", tarningskast: ";
            for (int i = 0; i < 5; ++i) {
                cout << yatzyhand.m_varden[i] << " ";
            }
            cout << endl;

            int valdKategori = valjKategori();
            int poang = 0;
            switch (valdKategori) {
            case 1:
                poang = vardeSomPar(yatzyhand);
                break;
            case 2:
                poang = vardeSomTvapar(yatzyhand);
                break;
            case 3:
                poang = vardeSomTriss(yatzyhand);
                break;
            case 4:
                poang = vardeSomLitenStege(yatzyhand);
                break;
            case 5:
                poang = vardeSomStorStege(yatzyhand);
                break;
            case 6:
                poang = vardeSomKak(yatzyhand);
                break;
            case 7:
                poang = vardeSomFyrtal(yatzyhand);
                break;
            case 8:
                poang = vardeSomYatzy(yatzyhand);
                break;
                // Fortsätt för alla kategorier...
            default:
                std::cout << "Ogiltig kategori vald." << std::endl;
                break;
            }

            // Uppdatera poängtabellen för den aktuella spelaren och kategorin
            yatzyTabell.spelarePoang[spelare][valdKategori - 1] = poang;
        }
    }
    skrivUtTabell(yatzyTabell);
}
