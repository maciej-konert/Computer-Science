#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAKS_ZNAKI (100) // Maksymalna liczba znaków w linii wejścia.

// Dodawanie kolejnych reguł do tablicy.
static void wypelnienieRegul(char tab[CHAR_MAX + 1][MAKS_ZNAKI + 1]) {
    while (true) {
        int pierwszyZnak, aktualneWejscie;
        pierwszyZnak = getchar();
        if (pierwszyZnak == '\n') {
            break;
        }
        else {
            int i = 0;
            do {
                aktualneWejscie = getchar();
                if (aktualneWejscie == '\n' && i == 0) {
                    tab[pierwszyZnak][0] = '\n';
                    tab[pierwszyZnak][1] = 'x';
                }
                else {
                    tab[pierwszyZnak][i] = (char) aktualneWejscie;
                }
                i++;
            } while (aktualneWejscie != '\n' && i < MAKS_ZNAKI);
        }
    }
}

// Rekurencyjne zastępowanie litery  zgodnie z regułami, w ostatnim kroku interpretacja.
static void rekurencyjneZastepowanie(char litera, int glebokosc, char zast[][MAKS_ZNAKI + 1], char inter[][MAKS_ZNAKI + 1]) {
    int i = 0;
    if (glebokosc > 0) {
        while (zast[(int) litera][i] != '\n' && i < MAKS_ZNAKI) {
            rekurencyjneZastepowanie(zast[(int) litera][i], glebokosc - 1, zast, inter);
            i++;
        }
    }
    else {
        if (inter[(int) litera][0] != '\n' || inter[(int) litera][1] != '\n') {
            while (inter[(int) litera][i] != '\n' && i < MAKS_ZNAKI) {
                putchar(inter[(int) litera][i]);
                i++;
            }
            putchar('\n');
        }
    }
}

static void czytanieLinijki(char slowo[]) {
    int wejscie, i = 0;
    while (true) {
        wejscie = getchar();
        if (wejscie == '\n') {
            slowo[i] = '\n';
            break;
        }
        else {
            slowo[i] = (char) wejscie;
            i++;
        }
    }
}

static void wypisanieProloguLubEpilogu() {
    while (true) {
        int sprawdzenieWejscia = getchar();
        if ((char) sprawdzenieWejscia == '\n' || sprawdzenieWejscia == EOF) {
            break;
        }
        else {
            ungetc(sprawdzenieWejscia, stdin);
            char wierszProloguLubEpilogu[MAKS_ZNAKI];
            czytanieLinijki(wierszProloguLubEpilogu);
            int i = 0;
            while (wierszProloguLubEpilogu[i] != '\n' && i < MAKS_ZNAKI) {
                putchar(wierszProloguLubEpilogu[i]);
                i++;
            }
            putchar('\n');
        }
    }
}

int main() {
    char regulyZastepowania[CHAR_MAX + 1][MAKS_ZNAKI + 1] = {{'0'}}, aksjomat[MAKS_ZNAKI + 1];
    char regulyInterpretacji[CHAR_MAX + 1][MAKS_ZNAKI + 1] = {{'0'}};
    int dlugoscWyprowadzenia;

    for (int i = 0; i < CHAR_MAX + 1; i++) {
        regulyZastepowania[i][0] = (char) i;
        regulyZastepowania[i][1] = '\n';
        regulyInterpretacji[i][0] = '\n';
        regulyInterpretacji[i][1] = '\n';
    }

    scanf("%d", &dlugoscWyprowadzenia);

    getchar();
    czytanieLinijki(aksjomat);

    wypelnienieRegul(regulyZastepowania);

    wypisanieProloguLubEpilogu();

    wypelnienieRegul(regulyInterpretacji);

    int j = 0;
    while (aksjomat[j] != '\n' && j < MAKS_ZNAKI) {
        rekurencyjneZastepowanie(aksjomat[j], dlugoscWyprowadzenia, regulyZastepowania, regulyInterpretacji);
        j++;
    }

    wypisanieProloguLubEpilogu();
}
