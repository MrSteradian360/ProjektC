/* Wie�e Hanoi - projekt na Programowanie Komputer�w
Plik g�owny
Przygotowali: Mateusz Duma, Miko�aj Kasperek, B�a�ej Gaw�da
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
    in = GetStdHandle(STD_INPUT_HANDLE); //pobranie uchwytu do wej�cia 
    out = GetStdHandle(STD_OUTPUT_HANDLE); //pobranie uchwytu do wyj�cia
    GetConsoleScreenBufferInfo(out, &scrinfo); //pobiera informacje o okre�lonym bufferze ekranu konsoli
    SetConsoleMode(in, ENABLE_PROCESSED_INPUT); //ustawianie trybu bufora ekranu konsoli
    tworzenie1();
    str_tytul();
    dzialanie();
    return 0;
}