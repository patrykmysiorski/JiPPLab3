#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Complex.h"
#include "Obliczenia.h"
#include <iostream>
#include "Rownanie.h"
#include "Quadratic.h"
#include "DoubleQuadratic.h"

using namespace std;
/*dziediczenie
polimorfizm
enkapsuilacja
dynamicznie tworzenie obiektow (rob przez new i delete)
//dodaj i odejmij peirwsiastki suma rzeczywistych plus suma urojonych do printowania
//bierze x r i x u i twrozy printuje xr + xu <- to jest string
*/
int main()
{
	int* tab = new int[3];
	Rownanie *wskaznik;
	
	cout << "a: ";
	cin >> tab[0];

	cout << "b: ";
	cin >> tab[1];

	cout << "c: ";
	cin >> tab[2];
	/*tab[0] = 0;
	tab[1] = 2;
	tab[2] = 1;*/
	cout << endl;
	Obliczenia* obliczenie = new Obliczenia();
	if (tab[0] == 0) {
		wskaznik = new Quadratic();
	}
	else {
		wskaznik = new DoubleQuadratic();
	}
	wskaznik->formatuj_rnie(tab);
	cout << endl;
	obliczenie->oblicz_pierwiastki(tab);
	obliczenie->wyswietl_wyniki(tab);

	system("pause");
	return 0;
}
