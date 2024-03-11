<h3>Wprowadzenie</h3>
System Lindenmayera, w skrócie L-system , to system formalny definiujący języki. Został stworzony w celu modelowania roślin przez biologa, Aristida Lindenmayera.

Deterministyczny bezkontekstowy L-system, nazywany D0L, jest trójką (S, A, R), w której S to alfabet, A jest słowem nad S nazywanym aksjomatem, a R to zbiór reguł zastępowania, wiążących symbole ze słowami nad S. Dla każdego elementu S, w R jest co najwyżej jedna reguła.

Słowo w należy do języka definiowanego przez L-system wtedy i tylko wtedy, gdy istnieje nieujemna liczba całkowita n taka, że w ma wyprowadzenie długości n. Przyjmujemy, że aksjomat ma wyprowadzenie długości 0. Słowo o wyprowadzeniu długości n + 1 powstaje ze słowa o wyprowadzeniu długości n przez jednoczesne zastąpienie każdego symbolu słowem określonym przez jego regułę, lub pozostawienie go bez zmian, jeśli nie ma dla niego reguły.

Rozważamy tekstową interpretację słów języka definiowanego przez L-system. Interpretacja zaczyna się do ciągu wierszy, nazywanego prologiem, po nim jest ciąg wierszy odpowiadających poszczególnym symbolom słowa, a na zakończenie jest ciąg wierszy nazywany epilogiem. Wiersze odpowiadające symbolom określone są za pomocą reguł interpretacji. Dla każdego symbolu mamy co najwyżej jedną regułę interpretacji. Symbole słowa, dla których nie określono interpretacji, są w niej pomijane.

<h3>Polecenie</h3>
Napisz program, który czyta z wejścia długość wyprowadzenia, opis L-systemu oraz jego interpretacji i pisze na wyjście interpretację wyprowadzonego słowa należącego do języka definiowanego przez L-system.

<h3>Postać danych</h3>
Na wejściu programu jest wiersz z nieujemną liczbą całkowitą określającą długość wyprowadzenia, wiersze opisu L-systemu i wiersze opisu interpretacji słowa.

Opis L-systemu składa się z wiersza zawierającego aksjomat, po którym następuje ciąg wierszy z regułami zastępowania. Wiersz reguły zastępowania zaczyna się od zastępowanego symbolu, a po nim jest zastępujące go słowo. Alfabet L-systemu nie jest jawnie podany. Przyjmujemy, że jest zbiorem symboli występujących w aksjomacie i regułach zastępowania.

Opis interpretacji słowa zaczyna się od ciągu wierszy prologu, po nim są wiersze reguł interpretacji, a po nich wiersze epilogu. Każdy z tych trzech ciągów jest poprzedzony wierszem pustym. Wiersz reguły interpretacji zaczyna się od interpretowanego symbolu, a reszta wiersza jest tekstem, który dla tego symbolu należy wypisać na wyjście.

<h3>Postać wyniku</h3>
Wynikiem programu jest ciąg wierszy będący interpretacją słowa.

<h3>Walidacja i testy</h3>
Rozwiązania podlegają walidacji, wstępnie badającej zgodność ze specyfikacją.

Walidacja sprawdza działanie programu na przykładach dołączonych do treści zadania.

Pomyślne przejście walidacji jest warunkiem dopuszczenia programu do testów poprawności. Program, który walidacji nie przejdzie, dostaje zerową ocenę poprawności.

Programy są kompilowane poleceniem:

gcc @opcje nazwa.c -o nazwa
gdzie nazwa.c to nazwa pliku z kodem źródłowym, a plik opcje ma zawartość:

-std=c17
-pedantic
-Wall
-Wextra
-Wformat-security
-Wduplicated-cond
-Wfloat-equal
-Wshadow
-Wconversion
-Wjump-misses-init
-Wlogical-not-parentheses
-Wnull-dereference
-Wvla
-Werror
-fstack-protector-strong
-fsanitize=undefined
-fno-sanitize-recover
-g
-fno-omit-frame-pointer
-O1

<h3>Uwagi i wskazówki</h3>
Jako rozwiązanie należy wysłać plik tekstowy .c z kodem źródłowym w języku C.

Wolno założyć, że dane są poprawne.

Wolno założyć, że każdy wiersz danych, w tym ostatni, kończy się reprezentacją końca wiersza '\n'. Należy zadbać, by warunek ten spełniał także wynik programu.

Wolno założyć, że znaki na wejściu programu mają kody od zera do wartości stałej CHAR_MAX, która jest zdefiniowana w pliku nagłówkowym limits.h.

Wolno założyć, że najdłuższy wiersz na wejściu programu, bez reprezentacji końca wiersza, ma nie więcej niż 100 znaków.
