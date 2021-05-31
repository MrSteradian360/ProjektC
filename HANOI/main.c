/* Wie¿e Hanoi - projekt na Programowanie Komputerów
Plik g³owny
Przygotowali: Mateusz Duma, Miko³aj Kasperek, B³a¿ej Gawêda
Inspiracja: Shivam Shekhar*/

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <locale.h>

HANDLE out; //uchwyt do wejscia
HANDLE in;  //uchwyt do wyjscia
CONSOLE_SCREEN_BUFFER_INFO scrinfo; //informacje o buforze ekranu konsoli


int main()
{
    setlocale(LC_ALL, "polish"); //polskie znaki
    in = GetStdHandle(STD_INPUT_HANDLE); //pobranie uchwytu do wejœcia 
    out = GetStdHandle(STD_OUTPUT_HANDLE); //pobranie uchwytu do wyjœcia
    GetConsoleScreenBufferInfo(out, &scrinfo); //pobiera informacje o okreœlonym bufferze ekranu konsoli
    SetConsoleMode(in, ENABLE_PROCESSED_INPUT); //ustawianie trybu bufora ekranu konsoli
    tworzenie1();
    str_tytul();
    dzialanie();
    return 0;
}