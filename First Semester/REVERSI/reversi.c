#include <stdio.h>
#include <stdbool.h>

#define Wiersze (8)
#define Kolumny (8)
#define Liczba(litera) (litera - 97) // a ---> 0
#define Litera(liczba) (liczba + 97) // 0 ---> a

// Resetujemy tablicę do symulowania rozgrywki.
int przygotowanieTablicy(char tab[Wiersze][Kolumny]) {
    for (int i = 0; i < Kolumny; i++) {
        for (int j = 0; j < Wiersze; j++) {
            tab[j][i] = 'P';
        }
    }
    tab[3][Liczba('d')] = 'B', tab[4][Liczba('d')] = 'C';
    tab[3][Liczba('e')] = 'C', tab[4][Liczba('e')] = 'B';
    return 0;
}

char przypisanieKolorow(int licznik, char *aktualnyKolor, char *odwrotnyKolor) {
    if (licznik % 2 == 0) {
        *aktualnyKolor = 'C';
        *odwrotnyKolor = 'B';
    }
    else {
        *aktualnyKolor = 'B';
        *odwrotnyKolor = 'C';
    }
    return 0;
}

/* Funkcja sprawdza, czy jeżeli pójdziemy w daną stronę (funkcja sprawdza każdą przekątną, pionową i poziomą linię)
   od miejsca na planszy to najpierw napotkamy ciąg żetonów przeciwnego koloru, a później
   żeton koloru aktualnego gracza któremu przysługuje ruch. Mówi to o tym, że na danym pustym polu można postawić
   żeton aktualnego koloru, ergo ruch jest legalny.*/

int szukanie(char tab[Wiersze][Kolumny], int i, int j, char aktKolor, char odwKolor) {
    int x, y;
    for (int iteracjaPion = -1; iteracjaPion <= 1; iteracjaPion++) {
        for (int iteracjaPoziom = -1; iteracjaPoziom <= 1; iteracjaPoziom++) {
            if (iteracjaPion == 0 && iteracjaPoziom == 0) {
                continue;
            }
            x = i + iteracjaPion, y = j + iteracjaPoziom;
            if (x >= 0 && y >= 0 && x <= Wiersze - 1 && y <= Kolumny - 1 && tab[x][y] == odwKolor) {
                while (x >= 0 && y >= 0 && x <= Wiersze - 1 && y <= Kolumny - 1 && tab[x][y] == odwKolor) {
                    x += iteracjaPion, y += iteracjaPoziom;
                }
                if (x >= 0 && y >= 0 && x <= Wiersze - 1 && y <= Wiersze - 1 && tab[x][y] == aktKolor) {
                    return true;
                }
            }
        }
    }
    return false;
}

/* Symulujemy ruch na planszy idąc z pola na którym gracz chce postawić żeton w każdą z 8 stron i patrzymy
   czy w daną stronę znajduje się ciąg żetonów odwrotnego koloru po czym spotykamy żeton aktualnego koloru.
   Jeżeli tak to odwracamy ten ciąg żetonów odwrotnego koloru.*/
int symulacjaRuchu(char tab[Wiersze][Kolumny], int i, int j, char aktKolor, char odwKolor) {
    tab[i][j] = aktKolor;
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (l == 0 && k == 0) {
                continue;
            }
            int x = i + k, y = j + l, licznikZamian = 0;
            if (x >= 0 && y >= 0 && x <= Wiersze - 1 && y <= Kolumny - 1 && tab[x][y] == odwKolor) {
                while (x >= 0 && y >= 0 && x <= Wiersze - 1 && y <= Kolumny - 1 && tab[x][y] == odwKolor) {
                    x += k, y += l, licznikZamian++;
                }
                if (x >= 0 && y >= 0 && x <= Wiersze - 1 && y <= Kolumny - 1 && tab[x][y] == aktKolor) {
                    for (int m = 1; m <= licznikZamian; m++) {
                        x -= k, y -= l;
                        tab[x][y] = aktKolor;
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    char plansza[Wiersze][Kolumny], aktualnyKolor, odwrotnyKolor;
    int licznikKolejnosci = 0;
    przygotowanieTablicy(plansza);

    // Główna pętla.
    while (true) {
        przypisanieKolorow(licznikKolejnosci, &aktualnyKolor, &odwrotnyKolor);
        putchar(aktualnyKolor);
        // Wyszukiwanie możliwych opcji ustawienia żetonu.
        for (int j = 0; j < Kolumny; j++) {
            for (int i = 0; i < Wiersze; i++) {
                if (plansza[i][j] == 'P' && szukanie(plansza, i, j, aktualnyKolor, odwrotnyKolor)) {
                    printf(" %c%d", Litera(j), i + 1);
                }
            }
        }
        putchar('\n');
        // Użytkownik wpisuje dane.
        char wejscie1;
        scanf(" %c", &wejscie1);

        if (wejscie1 == '-') {
            licznikKolejnosci++;
        }
        else if (wejscie1 == '=') {
            break;
        }
        else {
            int wejscie2;
            scanf("%d", &wejscie2);
            int j = Liczba(wejscie1), i = wejscie2 - 1;
            symulacjaRuchu(plansza, i, j, aktualnyKolor, odwrotnyKolor);
            licznikKolejnosci++;
        }
    }
}
