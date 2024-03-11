## Wprowadzenie
Gra Reversi , znana też pod nazwą Othello, jest rozgrywana na 64-polowej planszy podzielonej na wiersze od 1 do 8 i kolumny od a do h. Pola nazywamy, wskazując najpierw kolumnę a następnie wiersz.

W Reversi gra się dwustronnymi czarno-białymi pionami. Na każdym polu może być co najwyżej jeden pion. Jeśli pion w danej chwili jest odwrócony do góry stroną czarną, nazywamy go pionem czarnym, jeśli białą - jest pionem białym.

Partię gry w Reversi zaczyna się na planszy z pionami białymi na polach d4 i e5 oraz pionami czarnymi na polach d5 i e4. Pozostałe pola są puste.

W grze bierze udział dwóch graczy, nazywanych Czarnym i Białym, od koloru pionów, którym się posługują. Grę rozpoczyna gracz Czarny.

Gracze wykonują, na przemian, po jednym ruchu polegającym na położeniu na planszy piona swojego koloru. Jeśli na wszystkich polach w linii, czyli w wierszu, kolumnie lub przekątnej, między położonym właśnie pionem a innym pionem tego samego koloru, są piony w kolorze przeciwnym, zmieniają one kolor, czyli są odwracane. Położenie na planszy jednego piona może spowodować jednoczesną zmianę kilku linii pionów.

Ruch jest legalny, tylko gdy powoduje zmianę koloru co najmniej jednego piona na planszy. Jeśli w danej chwili gracz nie może wykonać legalnego ruchu to rezygnuje z niego i nie kładzie na planszy piona.

Choć nie jest to zgodne z regułami gry w Reversi, w tym zadaniu pozwalamy graczowi zrezygnować z ruchu nawet, gdy może wykonać ruch legalny.

Kolejna reguła, która również u nas nie obowiązuje, określa że gra automatycznie kończy się, gdy żaden z graczy nie może wykonać legalnego ruchu. Zwycięzcą zostaje wówczas gracz, który ma na planszy więcej pionów swojego koloru.

#Polecenie
Napisz program umożliwiający grę w Reversi dwóm graczom.

Program, w pętli:

pisze tekst zachęty (ang. prompt) wskazujący, do którego gracza należy ruch i jakie legalne ruchy może on wykonać;

czyta polecenie aktualnego gracza;

jeśli wczytał polecenie przerwania gry, kończy pracę;

jeśli wczytał polecenie rezygnacji z ruchu, wraca na początek pętli;

jeśli wczytał polecenie wykonania ruchu, to wykonuje ten ruch i wraca na początek pętli.

Program nie kończy pracy przed dojściem do polecenia przerwania gry, nawet gdyby stwierdził, że żaden z graczy nie może wykonać legalnego ruchu. Nie uznaje też za błąd sytuacji, w której użytkownik rezygnuje z ruchu lub prosi o przerwania gry, choć może wykonać legalny ruch.

#Postać danych
Na wejściu programu są polecenia graczy. Każde polecenie zajmuje jeden wiersz. Wszystkie polecenia mają poprawną postać. Polecenia wykonania ruchu wskazują ruch legalny. Po poleceniu przerwania gry jest dowolny tekst, ignorowany przez program.

Polecenie przerwania gry ma postać wiersza o treści =.

Polecenie rezygnacji z ruchu ma postać wiersza o treści -.

Polecenie wykonania ruchu ma postać wiersza z nazwą pola.

#Postać wyniku
Na wyjściu programu jest ciąg tekstów zachęty. Każdy z nich zajmuje jeden wiersz.

Tekst zachęty zaczyna się od wskazania gracza, do którego należy ruch:

znak C wskazuje gracza Czarnego;

znak B wskazuje gracza Białego.

Resztę treści tekstu zachęty stanowi ciąg nazw pól, na których gracz może położyć swojego piona. Nazwy są uporządkowane leksykograficznie. Każda nazwa jest poprzedzona spacją.

#Walidacja i testy
Rozwiązania podlegają walidacji, wstępnie badającej zgodność ze specyfikacją.

Walidacja sprawdza działanie programu na przykładach dołączonych do treści zadania.

Pomyślne przejście walidacji jest warunkiem dopuszczenia programu do testów poprawności. Program, który walidacji nie przejdzie, dostaje zerową ocenę poprawności.

Walidacja i testy są prowadzone na komputerze students.

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

Podczas walidacji i testów, program nazwa jest uruchamiany pod kontrolą programu Valgrind poleceniem:

valgrind --leak-check=full -q --error-exitcode=1 ./nazwa
Jeśli Valgrind wykryje błąd, to nawet gdyby wynik był prawidłowy, uznajemy, że program testu nie przeszedł.

Opcja -q powoduje, że jedynymi informacjami, wypisywanymi przez program Valgrind, są komunikaty o błędach.

Opcja --leak-check=full wskazuje Valgrindowi, że powinien, między innymi, szukać wycieków pamięci.

Opcja --error-exitcode=1 określa kod wyjścia programu w przypadku, gdy Valgrind wykryje błąd.

Przyjmujemy, że niezerowy wynik funkcji main() informuje o błędzie wykonania programu.

Poprawność wyniku sprawdzamy, przekierowując na wejście programu zawartość pliku .in i porównując rezultat, za pomocą programu diff, z plikiem .out, np.:

< przyklad.in ./nazwa | diff - przyklad.out
Ocena poprawności wyniku jest binarna. Wynik uznajemy za poprawny, jeżeli program diff nie wskaże żadnej różnicy względem wyniku wzorcowego.

#Uwagi i wskazówki
Jako rozwiązanie należy wysłać plik tekstowy .c z kodem źródłowym w języku C.

Wolno założyć, że dane są poprawne.

Wolno założyć, że każdy wiersz danych, w tym ostatni, kończy się reprezentacją końca wiersza '\n'.

Należy zadbać, by warunek ten spełniał także wynik programu.
