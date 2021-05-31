/* Wie�e Hanoi - projekt na Programowanie Komputer�w
Przygotowali: Mateusz Duma, Miko�aj Kasperek, B�a�ej Gaw�da
Inspiracja: Shivam Shekhar*/

#include "hanoi.h" 

//Str tytu�owa
void str_tytul()   // strona tytulowa
{

	out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(out, FOREGROUND_RED | FOREGROUND_INTENSITY);    // ustawiamy kolor tekstu
	printf("\n\n\n");

	printf("\t\t\t     ___      ___  ____________  _____      ___  ____________  ____\n");
	printf("\t\t\t     | |      | |  | ________ |  |   \\      | |  |  ______  |  |  |\n");
	printf("\t\t\t     | |      | |  | |      | |  | |\\ \\     | |  | |      | |  |  |\n");
	printf("\t\t\t     | |      | |  | |      | |  | | \\ \\    | |  | |      | |  |  |\n");
	printf("\t\t\t     | |______| |  | |______| |  | |  \\ \\   | |  | |      | |  |  |\n");
	printf("\t\t\t     |  ______  |  |  ______  |  | |   \\ \\  | |  | |      | |  |  |\n");
	printf("\t\t\t     | |      | |  | |      | |  | |    \\ \\ | |  | |      | |  |  |\n");
	printf("\t\t\t     | |      | |  | |      | |  | |     \\ \\| |  | |      | |  |  |\n");
	printf("\t\t\t     | |      | |  | |      | |  | |      \\   |  | |______| |  |  |\n");
	printf("\t\t\t     |_|      |_|  |_|      |_|  |_|       \\ _|  |__________|  |__|\n\n\n\n");

	SetConsoleTextAttribute(out, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

	printf("\t\t\t       Przygotowali: Mateusz Duma, Miko�aj Kasperek, B�a�ej Gaw�da\n");

	printf("\t\t\t       Naci�nij dowolny klawisz, aby zacz��...");;

	while (!kbhit()) Sleep(100);    // oczekiwanie na nacisniecie klawisza

}
//Zasady gry
void zasady()  // instrukcja obslugi
{
	system("cls");
	printf("1. Mamy trzy paliki i 6 kr��k�w u�o�onych od najwi�kszego do najmniejszego na pierwszym paliku. \nCelem gry jest przeniesienie wszystkich kr��k�w na trzeci palik.\n\n");
	printf("2. Mozesz przenie�� tylko jeden kr��ek na raz.\n\n");
	printf("3. Aby przenie�� kr��ek wpisz numer palika, na kt�rym znajduje si� kr��ek, a nast�pnie numer palika docelowego.\n\n");
	printf("4. Kr��ek mo�e by� umieszczony tylko na wi�kszym od siebie. Nie mo�na przenie�� wi�kszego kr��ka na mniejszy.\n\n");
	printf("Je�li chcesz zdobyc wiecej informacji, obejrzyj animacj�.\n\n");
	printf("Aby wyj�� z gry w jej trakcie, naci�nij klawisz ESC. Twoja liczba ruch�w wraz z dat�\nb�dzie zapisana w pliku \"Podej�cia.txt\" \n\n");
	printf("Mo�esz tak�e zobaczy� rozwi�zanie. UWAGA: Je�li wyjdziesz z gry w jej trakcie, aby zobaczy� rozwi�zanie,\nujrzysz tylko niepe�n� podpowied� odno�nie gry! \n\n\n\n");
	printf("Naci�nij dowolny klawisz, aby kontynuowa�...");
	getch();
}
//Animacja pokazowa trzech kr��k�w
void animacja()
{
	CHAR_INFO palik[10], kr1[3], kr2[5], kr3[7], pusty1[3], pusty2[5], pusty3[7]; // tablice reprezentujace przedmioty
	COORD p_palik = { 1,10 }, p_kr1 = { 3,1 }, p_kr2 = { 5,1 }, p_kr3 = { 7,1 }, tekst = { 56, 22 }; // rozmiary przedmiot�w
	SMALL_RECT wsp_palik1 = { 40,10,40,20 }, wsp_palik2 = { 60,10,60,20 }, wsp_palik3 = { 80,10,80,20 }; // wsp�rz�dne przedmiot�w
	SMALL_RECT wsp_kr1 = { 39,17,41,17 }, wsp_kr2 = { 38,18,42,18 }, wsp_kr3 = { 37, 19,43,19 };
	for (int i = 0; i < 10; ++i) // nadawanie atrybut�w znakom (numer Unicode, kolor)
	{
		palik[i].Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
		palik[i].Char.UnicodeChar = 449;

		if (i < 3)
		{
			kr1[i].Char.UnicodeChar = 9608; // numer Unicode klocka
			kr1[i].Attributes = 12; // kolor jasnoczerwony
			// tworzenie przedmiotu usuwaj�cego klocki z dotychczasowej pozycji:
			if (i == 1)
			{
				pusty1[i].Char.UnicodeChar = 449;
				pusty1[i].Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
			}
			else
			{
				pusty1[i].Char.UnicodeChar = 449;
				pusty1[i].Attributes = 0;
			}
		}
		if (i < 5)
		{
			kr2[i].Char.UnicodeChar = 9608;
			kr2[i].Attributes = 10; // kolor jasnozielony
			if (i == 2)
			{
				pusty2[i].Char.UnicodeChar = 449;
				pusty2[i].Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;

			}
			else
			{
				pusty2[i].Char.UnicodeChar = 173;
				pusty2[i].Attributes = 0;
			}
		}
		if (i < 7)
		{
			kr3[i].Char.UnicodeChar = 9608;
			kr3[i].Attributes = 9; // kolor niebieski
			if (i == 3)
			{
				pusty3[i].Char.UnicodeChar = 449;
				pusty3[i].Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
			}

			else
			{
				pusty3[i].Char.UnicodeChar = 173;
				pusty3[i].Attributes = 0;
			}
		}
	}

	// wypisywanie na konsol� przedmiot�w
	WriteConsoleOutput(out, palik, p_palik, zerozero, &wsp_palik1);
	WriteConsoleOutput(out, palik, p_palik, zerozero, &wsp_palik2);
	WriteConsoleOutput(out, palik, p_palik, zerozero, &wsp_palik3);
	WriteConsoleOutput(out, kr1, p_kr1, zerozero, &wsp_kr1);
	WriteConsoleOutput(out, kr2, p_kr2, zerozero, &wsp_kr2);
	WriteConsoleOutput(out, kr3, p_kr3, zerozero, &wsp_kr3);
	Sleep(2000);

	//krok 1
	SetConsoleCursorPosition(out, tekst); // pozycja tekstu
	printf("Z 1 na 3");
	WriteConsoleOutput(out, pusty1, p_kr1, zerozero, &wsp_kr1);
	wsp_kr1.Left += 40;
	wsp_kr1.Right += 40;
	wsp_kr1.Top += 2;
	wsp_kr1.Bottom += 2;
	WriteConsoleOutput(out, kr1, p_kr1, zerozero, &wsp_kr1);

	//krok 2
	Sleep(2000);
	SetConsoleCursorPosition(out, tekst);
	printf("       ");
	SetConsoleCursorPosition(out, tekst);
	printf("Z 1 na 2");
	WriteConsoleOutput(out, pusty2, p_kr2, zerozero, &wsp_kr2);
	wsp_kr2.Left += 20;
	wsp_kr2.Right += 20;
	wsp_kr2.Top += 1;
	wsp_kr2.Bottom += 1;
	WriteConsoleOutput(out, kr2, p_kr2, zerozero, &wsp_kr2);


	//krok 3
	Sleep(2000);
	SetConsoleCursorPosition(out, tekst);
	printf("        ");
	SetConsoleCursorPosition(out, tekst);
	printf("Z 3 na 2");
	WriteConsoleOutput(out, pusty1, p_kr1, zerozero, &wsp_kr1);
	wsp_kr1.Left -= 20;
	wsp_kr1.Right -= 20;
	wsp_kr1.Top -= 1;
	wsp_kr1.Bottom -= 1;
	WriteConsoleOutput(out, kr1, p_kr1, zerozero, &wsp_kr1);


	//krok 4
	Sleep(2000);
	SetConsoleCursorPosition(out, tekst);
	printf("        ");
	SetConsoleCursorPosition(out, tekst);
	printf("Z 1 na 3");
	WriteConsoleOutput(out, pusty3, p_kr3, zerozero, &wsp_kr3);
	wsp_kr3.Left += 40;
	wsp_kr3.Right += 40;
	WriteConsoleOutput(out, kr3, p_kr3, zerozero, &wsp_kr3);


	//krok 5
	Sleep(2000);
	SetConsoleCursorPosition(out, tekst);
	printf("        ");
	SetConsoleCursorPosition(out, tekst);
	printf("Z 2 na 1");
	WriteConsoleOutput(out, pusty1, p_kr1, zerozero, &wsp_kr1);
	wsp_kr1.Left -= 20;
	wsp_kr1.Right -= 20;
	wsp_kr1.Top += 1;
	wsp_kr1.Bottom += 1;
	WriteConsoleOutput(out, kr1, p_kr1, zerozero, &wsp_kr1);


	//krok 6
	Sleep(2000);
	SetConsoleCursorPosition(out, tekst);
	printf("        ");
	SetConsoleCursorPosition(out, tekst);
	printf("Z 2 na 3");
	WriteConsoleOutput(out, pusty2, p_kr2, zerozero, &wsp_kr2);
	wsp_kr2.Left += 20;
	wsp_kr2.Right += 20;
	wsp_kr2.Top -= 1;
	wsp_kr2.Bottom -= 1;
	WriteConsoleOutput(out, kr2, p_kr2, zerozero, &wsp_kr2);


	//krok 7
	Sleep(2000);
	SetConsoleCursorPosition(out, tekst);
	printf("        ");
	SetConsoleCursorPosition(out, tekst);
	printf("Z 1 na 3");
	WriteConsoleOutput(out, pusty1, p_kr1, zerozero, &wsp_kr1);
	wsp_kr1.Left += 40;
	wsp_kr1.Right += 40;
	wsp_kr1.Top -= 2;
	wsp_kr1.Bottom -= 2;
	WriteConsoleOutput(out, kr1, p_kr1, zerozero, &wsp_kr1);

}
//Tworzenie obiekt�w przy przesuwaniu kr��k�w
void tworzenie1()
{
	for (i = 0; i < 6; i++)
	{
		palik2o[i] = 6;
		palik3o[i] = 6;
	}
	for (i = 0; i < 10; i++) //Tworzenie palik�w
	{
		palik[i].Char.UnicodeChar = 449; //Nadawanie palikom kszta�tu poprzez Unicode
		palik[i].Attributes = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY; //Nadawanie koloru palikom
	}
	for (i = 0; i < 3; i++) //Pierwszy kr��ek 
	{
		kr1[i].Char.UnicodeChar = 9608;
		kr1[i].Attributes = 12;
	}
	for (i = 0; i < 5; i++)
	{
		kr2[i].Char.UnicodeChar = 9608;
		kr2[i].Attributes = 9;
	}
	for (i = 0; i < 7; i++)
	{
		kr3[i].Char.UnicodeChar = 9608;
		kr3[i].Attributes = 10;
	}
	for (i = 0; i < 9; i++)
	{
		kr4[i].Char.UnicodeChar = 9608;
		kr4[i].Attributes = 11;
	}
	for (i = 0; i < 11; i++)
	{
		kr5[i].Char.UnicodeChar = 9608;
		kr5[i].Attributes = 13;
	}
	for (i = 0; i < 13; i++)
	{
		kr6[i].Char.UnicodeChar = 9608;
		kr6[i].Attributes = 14;
	}
	//Tworzenie "pustych kr��k�w", kt�re b�d� imitowa�y animacj� przej�cia
	//Pierwszy "pusty kr��ek"
	for (i = 0; i < 3; i++)
	{
		pusty1[i].Char.UnicodeChar = 173;
		pusty1[i].Attributes = 0;
	}
	//�rodek kr��ka wygl�da jak palik
	pusty1[1].Char.UnicodeChar = 449;
	pusty1[1].Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
	//
	for (i = 0; i < 5; i++)
	{
		pusty2[i].Char.UnicodeChar = 173;
		pusty2[i].Attributes = 0;
	}
	pusty2[2].Char.UnicodeChar = 449;
	pusty2[2].Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;

	//
	for (i = 0; i < 7; i++)
	{
		pusty3[i].Char.UnicodeChar = 173;
		pusty3[i].Attributes = 0;
	}
	pusty3[3].Char.UnicodeChar = 449;
	pusty3[3].Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;

	//
	for (i = 0; i < 9; i++)
	{
		pusty4[i].Char.UnicodeChar = 173;
		pusty4[i].Attributes = 0;
	}
	pusty4[4].Char.UnicodeChar = 449;
	pusty4[4].Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;

	//
	for (i = 0; i < 11; i++)
	{
		pusty5[i].Char.UnicodeChar = 173;
		pusty5[i].Attributes = 0;
	}
	pusty5[5].Char.UnicodeChar = 449;
	pusty5[5].Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;

	for (i = 0; i < 13; i++)
	{
		pusty6[i].Char.UnicodeChar = 173;
		pusty6[i].Attributes = 0;
	}
	pusty6[6].Char.UnicodeChar = 449;
	pusty6[6].Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
}
//Czyszczenie obiekt�w przy przesuwaniu kr��k�w
void czyszczenie()
{
	//Palik 1
	WriteConsoleOutput(out, pusty1, p_kr1, zerozero, &wsp_kr1_p1);
	WriteConsoleOutput(out, pusty2, p_kr2, zerozero, &wsp_kr2_p1);
	WriteConsoleOutput(out, pusty3, p_kr3, zerozero, &wsp_kr3_p1);
	WriteConsoleOutput(out, pusty4, p_kr4, zerozero, &wsp_kr4_p1);
	WriteConsoleOutput(out, pusty5, p_kr5, zerozero, &wsp_kr5_p1);
	WriteConsoleOutput(out, pusty6, p_kr6, zerozero, &wsp_kr6_p1);
	//Palik 2
	WriteConsoleOutput(out, pusty1, p_kr1, zerozero, &wsp_kr1_p2);
	WriteConsoleOutput(out, pusty2, p_kr2, zerozero, &wsp_kr2_p2);
	WriteConsoleOutput(out, pusty3, p_kr3, zerozero, &wsp_kr3_p2);
	WriteConsoleOutput(out, pusty4, p_kr4, zerozero, &wsp_kr4_p2);
	WriteConsoleOutput(out, pusty5, p_kr5, zerozero, &wsp_kr5_p2);
	WriteConsoleOutput(out, pusty6, p_kr6, zerozero, &wsp_kr6_p2);
	//Palik 3
	WriteConsoleOutput(out, pusty1, p_kr1, zerozero, &wsp_kr1_p3);
	WriteConsoleOutput(out, pusty2, p_kr2, zerozero, &wsp_kr2_p3);
	WriteConsoleOutput(out, pusty3, p_kr3, zerozero, &wsp_kr3_p3);
	WriteConsoleOutput(out, pusty4, p_kr4, zerozero, &wsp_kr4_p3);
	WriteConsoleOutput(out, pusty5, p_kr5, zerozero, &wsp_kr5_p3);
	WriteConsoleOutput(out, pusty6, p_kr6, zerozero, &wsp_kr6_p3);
}
//Tworzenie ka�dego mo�liwego ruch dla ka�dego kr��ka
void tworzenie2()
{
	for (i = 0; i < 6; ++i)
	{
		//Ruchy na palikach
		switch (palik1o[i])
		{
		case 0:
			wsp_kr1_p1.Top = 14 + i;
			wsp_kr1_p1.Bottom = 14 + i;
			WriteConsoleOutput(out, kr1, p_kr1, zerozero, &wsp_kr1_p1);
			break;
		case 1:
			wsp_kr2_p1.Top = 14 + i;
			wsp_kr2_p1.Bottom = 14 + i;
			WriteConsoleOutput(out, kr2, p_kr2, zerozero, &wsp_kr2_p1);
			break;
		case 2:
			wsp_kr3_p1.Top = 14 + i;
			wsp_kr3_p1.Bottom = 14 + i;
			WriteConsoleOutput(out, kr3, p_kr3, zerozero, &wsp_kr3_p1);
			break;
		case 3:
			wsp_kr4_p1.Top = 14 + i;
			wsp_kr4_p1.Bottom = 14 + i;
			WriteConsoleOutput(out, kr4, p_kr4, zerozero, &wsp_kr4_p1);
			break;
		case 4:
			wsp_kr5_p1.Top = 14 + i;
			wsp_kr5_p1.Bottom = 14 + i;
			WriteConsoleOutput(out, kr5, p_kr5, zerozero, &wsp_kr5_p1);
			break;
		case 5:
			wsp_kr6_p1.Top = 14 + i;
			wsp_kr6_p1.Bottom = 14 + i;
			WriteConsoleOutput(out, kr6, p_kr6, zerozero, &wsp_kr6_p1);
			break;
		}
		switch (palik2o[i])
		{
		case 0:
			wsp_kr1_p2.Top = 14 + i;
			wsp_kr1_p2.Bottom = 14 + i;
			WriteConsoleOutput(out, kr1, p_kr1, zerozero, &wsp_kr1_p2);
			break;
		case 1:
			wsp_kr2_p2.Top = 14 + i;
			wsp_kr2_p2.Bottom = 14 + i;
			WriteConsoleOutput(out, kr2, p_kr2, zerozero, &wsp_kr2_p2);
			break;
		case 2:
			wsp_kr3_p2.Top = 14 + i;
			wsp_kr3_p2.Bottom = 14 + i;
			WriteConsoleOutput(out, kr3, p_kr3, zerozero, &wsp_kr3_p2);
			break;
		case 3:
			wsp_kr4_p2.Top = 14 + i;
			wsp_kr4_p2.Bottom = 14 + i;
			WriteConsoleOutput(out, kr4, p_kr4, zerozero, &wsp_kr4_p2);
			break;
		case 4:
			wsp_kr5_p2.Top = 14 + i;
			wsp_kr5_p2.Bottom = 14 + i;
			WriteConsoleOutput(out, kr5, p_kr5, zerozero, &wsp_kr5_p2);
			break;
		case 5:
			wsp_kr6_p2.Top = 14 + i;
			wsp_kr6_p2.Bottom = 14 + i;
			WriteConsoleOutput(out, kr6, p_kr6, zerozero, &wsp_kr6_p2);
			break;
		}
		switch (palik3o[i])
		{
		case 0:
			wsp_kr1_p3.Top = 14 + i;
			wsp_kr1_p3.Bottom = 14 + i;
			WriteConsoleOutput(out, kr1, p_kr1, zerozero, &wsp_kr1_p3);
			break;
		case 1:
			wsp_kr2_p3.Top = 14 + i;
			wsp_kr2_p3.Bottom = 14 + i;
			WriteConsoleOutput(out, kr2, p_kr2, zerozero, &wsp_kr2_p3);
			break;
		case 2:
			wsp_kr3_p3.Top = 14 + i;
			wsp_kr3_p3.Bottom = 14 + i;
			WriteConsoleOutput(out, kr3, p_kr3, zerozero, &wsp_kr3_p3);
			break;
		case 3:
			wsp_kr4_p3.Top = 14 + i;
			wsp_kr4_p3.Bottom = 14 + i;
			WriteConsoleOutput(out, kr4, p_kr4, zerozero, &wsp_kr4_p3);
			break;
		case 4:
			wsp_kr5_p3.Top = 14 + i;
			wsp_kr5_p3.Bottom = 14 + i;
			WriteConsoleOutput(out, kr5, p_kr5, zerozero, &wsp_kr5_p3);
			break;
		case 5:
			wsp_kr6_p3.Top = 14 + i;
			wsp_kr6_p3.Bottom = 14 + i;
			WriteConsoleOutput(out, kr6, p_kr6, zerozero, &wsp_kr6_p3);
			break;
		}
	}
}
//Ruch kr��k�w
void ruch_kr��k�w(char z, char na)
{
	if (na == 50 && z == 49)//ruch z palika 1 na 2
	{
		for (i = 0; i < 6; i++)
		{
			if (palik1o[i] != 6)
			{
				a = i;
				break;
			}
		}
		for (i = 0; i < 6; i++)
		{
			if (palik2o[i] != 6)
			{
				b = i;
				break;
			}
		}
		if (i == 6)
			b = 6;
		if (palik2o[b] > palik1o[a] || palik2o[5] == 6)
		{
			palik2o[b - 1] = palik1o[a];
			palik1o[a] = 6;
		}
	}
	else if (na == 51 && z == 49)//ruch z palika 1 na 3 
	{
		for (i = 0; i < 6; i++)
		{
			if (palik1o[i] != 6)
			{
				a = i;
				break;
			}
		}
		for (i = 0; i < 6; i++)
		{
			if (palik3o[i] != 6)
			{
				b = i;
				break;
			}
		}
		if (i == 6)
			b = 6;
		if (palik3o[b] > palik1o[a] || palik3o[5] == 6)
		{
			palik3o[b - 1] = palik1o[a];
			palik1o[a] = 6;
		}
	}
	else if (na == 49 && z == 50)//ruch z palika 2 na 1
	{
		for (i = 0; i < 6; i++)
		{
			if (palik2o[i] != 6)
			{
				a = i;
				break;
			}
		}
		for (i = 0; i < 6; i++)
		{
			if (palik1o[i] != 6)
			{
				b = i;
				break;
			}
		}
		if (i == 6)
			b = 6;
		if (palik1o[b] > palik2o[a] || palik1o[5] == 6)
		{
			palik1o[b - 1] = palik2o[a];
			palik2o[a] = 6;
		}
	}
	else if (na == 51 && z == 50)//ruch z palika 2 na 3
	{
		for (i = 0; i < 6; i++)
		{
			if (palik2o[i] != 6)
			{
				a = i;
				break;
			}
		}
		for (i = 0; i < 6; i++)
		{
			if (palik3o[i] != 6)
			{
				b = i;
				break;
			}
		}
		if (i == 6)
			b = 6;
		if (palik3o[b] > palik2o[a] || palik3o[5] == 6)
		{
			palik3o[b - 1] = palik2o[a];
			palik2o[a] = 6;
		}
	}
	else if (na == 49 && z == 51)//ruch z palika 3 na 1
	{
		for (i = 0; i < 6; i++)
		{
			if (palik3o[i] != 6)
			{
				a = i;
				break;
			}
		}
		for (i = 0; i < 6; i++)
		{
			if (palik1o[i] != 6)
			{
				b = i;
				break;
			}
		}
		if (i == 6)
			b = 6;
		if (palik1o[b] > palik3o[a] || palik1o[5] == 6)
		{
			palik1o[b - 1] = palik3o[a];
			palik3o[a] = 6;
		}
	}
	else if (na == 50 && z == 51)//ruch z palika 3 na 2
	{
		for (i = 0; i < 6; i++)
		{
			if (palik3o[i] != 6)
			{
				a = i;
				break;
			}
		}
		for (i = 0; i < 6; i++)
		{
			if (palik2o[i] != 6)
			{
				b = i;
				break;
			}
		}
		if (i == 6)
			b = 6;
		if (palik2o[b] > palik3o[a] || palik2o[5] == 6)
		{
			palik2o[b - 1] = palik3o[a];
			palik3o[a] = 6;
		}
	}
}
//Algorytm rozwi�zania
void algorytm(int n, char x, char y, char z)
{
	d++;

		if (n == 1)
		{

			czyszczenie();
			ruch_kr��k�w(x, z);
			tworzenie2();
			//printf("%d", d);
			Sleep(1000);
			return;

		}
		else
		{
			//Sleep(1000);
			algorytm(n - 1, x, z, y);
			//Sleep(1000);
			if (x <= 51 && x >= 49 && y <= 51 && y >= 49)
			{

				czyszczenie();
				ruch_kr��k�w(x, z);
				tworzenie2();
				Sleep(1000);
				for (i = 0; i < 6; i++)
				{
					if (win[i] != palik3o[i])
						break;
				}
				//printf("%d", d);
				//Sleep(1000);
			}

			//Sleep(1000);
			//printf("\n%c %c", x, y);
			//Sleep(1000);
			algorytm(n - 1, y, x, z);
		}
}
//Rozwi�zanie
void rozwiazanie()
{
	system("cls");

	WriteConsoleOutput(out, palik, p_palik, zerozero, &wsp_palik1);
	WriteConsoleOutput(out, palik, p_palik, zerozero, &wsp_palik2);
	WriteConsoleOutput(out, palik, p_palik, zerozero, &wsp_palik3);

	WriteConsoleOutput(out, kr1, p_kr1, zerozero, &wsp_kr1_p1);
	WriteConsoleOutput(out, kr2, p_kr2, zerozero, &wsp_kr2_p1);
	WriteConsoleOutput(out, kr3, p_kr3, zerozero, &wsp_kr3_p1);
	WriteConsoleOutput(out, kr4, p_kr4, zerozero, &wsp_kr4_p1);
	WriteConsoleOutput(out, kr5, p_kr5, zerozero, &wsp_kr5_p1);
	WriteConsoleOutput(out, kr6, p_kr6, zerozero, &wsp_kr6_p1);
	if (d == 0) Sleep(1000);
	algorytm(6, '1', '2', '3');
}
//Dzia�anie gry
int dzialanie()
{
	
	system("cls");
	while (t)
	{
		menu:
		system("cls"); //czyszczenie konsoli

		//ruchy = 0;
		SetConsoleCursorPosition(out, poz1); //ustawianie pozycji kursora
		printf("1. Zasady gry");
		poz1.Y++;
		poz1.Y++;
		SetConsoleCursorPosition(out, poz1);
		printf("2. Zobacz animacj�");
		poz1.Y++;
		poz1.Y++;
		SetConsoleCursorPosition(out, poz1);
		printf("3. Rozpocznij gr�");
		poz1.Y++;
		poz1.Y++;
		SetConsoleCursorPosition(out, poz1);
		printf("4. Rozwi�zanie");
		poz1.Y++;
		poz1.Y++;
		SetConsoleCursorPosition(out, poz1);
		printf("5. Zako�cz program");


		//wyb�r operacji:
		switch (getch())
		{
		case '1':
		{
			zasady();
			break;
		}
		case '2':
		{
			while (1)
			{
				system("cls");
				animacja();
				printf("\nCzy chcesz powt�rzy� animacj�? t/n");
				if (getch() == 't') continue;
				else break;
			}
			break;
		}
		case '3':
		{
			t = 0;
			break;
		}
		case '4':
		{
			rozwiazanie();
			system("cls");
			goto koniec;
		}
		case '5':
		{
			exit(0);
		}
		}
		poz1.Y -= 8;
	}
	system("cls");


	//Tworzenie pocz�tkowego obrazu ustawie� kr��k�w

	WriteConsoleOutput(out, palik, p_palik, zerozero, &wsp_palik1);
	WriteConsoleOutput(out, palik, p_palik, zerozero, &wsp_palik2);
	WriteConsoleOutput(out, palik, p_palik, zerozero, &wsp_palik3);

	WriteConsoleOutput(out, kr1, p_kr1, zerozero, &wsp_kr1_p1);
	WriteConsoleOutput(out, kr2, p_kr2, zerozero, &wsp_kr2_p1);
	WriteConsoleOutput(out, kr3, p_kr3, zerozero, &wsp_kr3_p1);
	WriteConsoleOutput(out, kr4, p_kr4, zerozero, &wsp_kr4_p1);
	WriteConsoleOutput(out, kr5, p_kr5, zerozero, &wsp_kr5_p1);
	WriteConsoleOutput(out, kr6, p_kr6, zerozero, &wsp_kr6_p1);

	//Rozpocz�cie gry
	while (1)
	{
		while (1)
		{
			//Czyszczenie linijek
			pos = tekst;
			pos_1 = tekst1;
			pos.X -= 3;
			SetConsoleCursorPosition(out, tekst);
			for (i = 0; i < 79; i++)
				printf(" ");
			pos.Y++;
			SetConsoleCursorPosition(out, pos);
			for (i = 0; i < 79; i++)
				printf(" ");
			pos_1.X -= 3;
			SetConsoleCursorPosition(out, tekst1);
			for (i = 0; i < 79; i++)
				printf(" ");
			//pos_1.Y++;
			SetConsoleCursorPosition(out, tekst1);
			for (i = 0; i < 79; i++)
				printf(" ");
			SetConsoleCursorPosition(out, tekst1);
			printf("Liczba ruch�w: %d", ruchy);
			//Pobieranie danych
			SetConsoleCursorPosition(out, tekst);
			printf("Z ");
			z = getch();
			if (z == 27) goto menu;
			printf("%d ", z - 48);
			printf("na ");
			na = getch();
			if (z == 27) goto menu;
			printf("%d", na - 48);
			pos = tekst;
			pos.Y++;

			SetConsoleCursorPosition(out, pos);

			//Przypadek wprowadzenia niepoprawnych danych
			if (z > 51 || z < 49 || na >51 || na < 49)
			{
				pos = tekst;
				pos.Y++;
				pos.X -= 3;
				SetConsoleCursorPosition(out, pos);
				for (i = 0; i < 79; i++)
					printf(" ");
				SetConsoleCursorPosition(out, pos);
				printf("Niepoprawne dane");
				ruchy++;
				Sleep(1000);
				continue;
			}
			else
				break;
		}
		ruchy++;
		czyszczenie();
		ruch_kr��k�w(z, na);
		tworzenie2();
		//warunek wygrania
		for (i = 0; i < 6; i++)
		{
			if (win[i] != palik3o[i])
				break;
		}
		if (i == 6)
			break;
	}

	SYSTEMTIME t; //deklaracja struktury SYSTEMTIME
	GetLocalTime(&t); //wype�nianie struktury 

	//tworzenie pliku do zapisu wynik�w

	FILE* plik;

	if (fopen_s(&plik, "Podej�cia.txt", "a+") != 0)
	{
		printf("Napotkano na b��d podczas otwierania pliku!");
		Sleep(2000);
		return;
	}
	fprintf(plik, "Data: %d/%d/%d\nGodzina: %d:%d:%d\n", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
	fprintf(plik, "Liczba ruch�w: %d\n\n", ruchy);
	fclose(plik);

	ruchy = 0;

	system("cls");
	printf("Gratulacje, wygra�e�!\n");
	koniec:
	printf("Naci�nij dowolny klawisz, aby zamkn�� program.");
	getch();
	return 0;
}

 