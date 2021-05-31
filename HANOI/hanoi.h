/* Wie¿e Hanoi - projekt na Programowanie Komputerów
Plik nag³ówkowy
Przygotowali: Mateusz Duma, Miko³aj Kasperek, B³a¿ej Gawêda
Inspiracja: Shivam Shekhar*/

#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <windows.h>
#include <time.h>


HANDLE out; //uchwyt do wejscia
HANDLE in;  //uchwyt do wyjscia
CONSOLE_SCREEN_BUFFER_INFO scrinfo; //informacje o buforze ekranu konsoli
INPUT_RECORD input; //okreœla zdarzenie wejœciowe w buforze wejœciowym konsoli
//rozmiar klocków: 
CHAR_INFO palik[10], kr1[3], kr2[5], kr3[7], kr4[9], kr5[11], kr6[13], pusty1[3], pusty2[5], pusty3[7], pusty4[9], pusty5[11], pusty6[13];
//koordynaty:
COORD poz1 = { 46, 8 }, zerozero = { 0,0 };
COORD p_palik = { 1,10 }, p_kr1 = { 3,1 }, p_kr2 = { 5,1 }, p_kr3 = { 7,1 }, p_kr4 = { 9,1 }, p_kr5 = { 11,1 }, p_kr6 = { 13,1 };
COORD tekst = { 56, 22 }, pos, pos1 = { 30,11 }, tekst1 = { 53, 25 }, pos_1;
//pozycje palikow:
SMALL_RECT wsp_palik1 = { 40,10,40,20 }, wsp_palik2 = { 60,10,60,20 }, wsp_palik3 = { 80,10,80,20 }; // wspó³rzêdne przedmiotów
//pozycje jakie mo¿e przyj¹æ kr¹¿ek:
SMALL_RECT wsp_kr1_p1 = { 39,14,41,14 }, wsp_kr2_p1 = { 38,15,42,15 }, wsp_kr3_p1 = { 37,16,43,16 }, wsp_kr4_p1 = { 36,17,44,17 }, wsp_kr5_p1 = { 35,18,45,18 }, wsp_kr6_p1 = { 34,19,46,19 };
SMALL_RECT wsp_kr1_p2 = { 59,14,61,14 }, wsp_kr2_p2 = { 58,15,62,15 }, wsp_kr3_p2 = { 57,16,63,16 }, wsp_kr4_p2 = { 56,17,64,17 }, wsp_kr5_p2 = { 55,18,65,18 }, wsp_kr6_p2 = { 54,19,66,19 };
SMALL_RECT wsp_kr1_p3 = { 79,14,81,14 }, wsp_kr2_p3 = { 78,15,82,15 }, wsp_kr3_p3 = { 77,16,83,16 }, wsp_kr4_p3 = { 76,17,84,17 }, wsp_kr5_p3 = { 75,18,85,18 }, wsp_kr6_p3 = { 74,19,86,19 };
int i, j, palik1o[6] = { 0,1,2,3,4,5 }, palik2o[6], palik3o[6], win[6] = { 0,1,2,3,4,5 };
int a, b, t = 1, ruchy, d;
char z, na; //informacje o przenoszeniu kr¹¿ków


//deklaracje funkcji:

void str_tytul(void);
void zasady(void);
void animacja(void);
void tworzenie1(void);
void czyszczenie(void);
void tworzenie2(void);
void ruch_kr¹¿ków(char, char);
void algorytm(int n, char x, char y, char z);
void rozwiazanie(void);
int dzialanie(void);
