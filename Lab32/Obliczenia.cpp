#include "Obliczenia.h"
#include <iostream>
using namespace std;




Obliczenia::Obliczenia()
{
}


Obliczenia::~Obliczenia()
{
}


double Obliczenia::oblicz_delte(int tab[])
{
	int a = tab[0];
	int b = tab[1];
	int c = tab[2];
	double delta = 0;
	if (a != 0) {
		delta = 1.0 * b * b - 4.0 * a * c;
	}
	else if (b != 0) {
		delta = -4.0 * b * c;
	}
	return delta;
}

void Obliczenia::oblicz_pierwiastki(int tab[])
{
	int a = tab[0];
	int b = tab[1];
	int c = tab[2];
	x1.setRealNumber(0);
	x1.setImaginaryNumber(0);
	x2.setRealNumber(0);
	x2.setImaginaryNumber(0);
	x3.setRealNumber(0);
	x3.setImaginaryNumber(0);
	x4.setRealNumber(0);
	x4.setImaginaryNumber(0);

	if (a != 0) { //a nierowne 0
		double delta = oblicz_delte(tab);

		if (delta > 0) { //delta dodatnia
			double pdelta = sqrt(delta);

			double t1 = (-1.0 * b - pdelta) / (2.0 * a);
			double t2 = (-1.0 * b + pdelta) / (2.0 * a);

			if (t1 < 0) {//t1 ujemne 
				x1.setRealNumber(0.0);
				x1.setImaginaryNumber(sqrt(-1.0 * t1));
				x2.setRealNumber(x1.getRealNumber());
				x2.setImaginaryNumber(-1.0 * x1.getImaginaryNumber());
			}
			else { //t1 dodatnie lub rowne 0
				x1.setRealNumber(sqrt(t1));
				x2.setRealNumber(-1.0 * sqrt(t1));
			}

			if (t2 < 0) { //t2 ujemne
				x3.setRealNumber(0.0);
				x3.setImaginaryNumber(sqrt(-1.0 * t2));
				x4.setRealNumber(x3.getRealNumber());
				x4.setImaginaryNumber(-1.0 * x3.getImaginaryNumber());
			}
			else { //t2 wieksze lub rowne 0
				x3.setRealNumber(sqrt(t2));
				x4.setRealNumber(-1.0 * sqrt(t2));
			}
		}
		else if (delta == 0) {//delta rowna 0
			double t = (-1.0 * b) / (2.0 * a);

			if (t >= 0) { // t wieksze lub rowne 0
				x1.setRealNumber(sqrt(t));
				x2.setRealNumber(-1.0 * sqrt(t));
			}
			else { // t ujemne
				x1.setRealNumber(0.0);
				x1.setImaginaryNumber(sqrt(-1.0 * t));
				x2.setRealNumber(x1.getRealNumber());
				x2.setImaginaryNumber(-1.0 * x1.getImaginaryNumber());
			}
		}
		else { //delta ujemna
			double pdelta = sqrt(-1.0 * delta);

			double t1r = (-1.0 * b) / (2.0 * a);
			double t1u = (-1.0 * pdelta) / (2.0 * a);
			double t2r = t1r;
			double t2u = (1.0 * pdelta) / (2.0 * a);

			x1.setRealNumber(sqrt((sqrt(t1r * t1r + t1u * t1u) + t1r) / 2.0));
			x1.setImaginaryNumber(sqrt((sqrt(t1r * t1r + t1u * t1u) - t1r) / 2.0));

			x2.setRealNumber(x1.getRealNumber());
			x2.setImaginaryNumber(-1.0 * x1.getImaginaryNumber());

			x3.setRealNumber(-1.0 * sqrt((sqrt(t2r * t2r + t2u * t2u) + t2r) / 2.0));
			x3.setImaginaryNumber(-1.0 * sqrt((sqrt(t2r * t2r + t2u * t2u) - t2r) / 2.0));

			x4.setRealNumber(x3.getRealNumber());
			x4.setImaginaryNumber(-1.0 * x3.getImaginaryNumber());
		}
	}
	else if (b != 0) {//a rowne 0, b rozne od 0
		double delta = oblicz_delte(tab);

		if (delta > 0) { //delta dodatnia
			double pdelta = sqrt(delta);
			x1.setRealNumber((-1.0 * pdelta) / (2.0 * b));
			x2.setRealNumber((1.0 * pdelta) / (2.0 * b));
		}
		else if (delta == 0) {//delta rowna 0
			x1.setRealNumber(0.0);
			x2.setRealNumber(x1.getRealNumber());
		}
		else { //delta ujemna
			double delta_2 = -1.0 * delta;
			double pdelta = sqrt(delta_2);

			x1.setRealNumber(0.0);
			x1.setImaginaryNumber((-1.0 * pdelta) / (2.0 * b));
			x2.setRealNumber(0.0);
			x2.setImaginaryNumber((1.0 * pdelta) / (2.0 * b));
		}
	}
}

void Obliczenia::dodaj_l_zesp()
{
	addResult.setRealNumber(0);
	addResult.setImaginaryNumber(0);
	addResult.setRealNumber(x1.getRealNumber() + x2.getRealNumber() + x3.getRealNumber() + x4.getRealNumber());
}

void Obliczenia::odejm_l_zesp()
{
	subResult.setRealNumber(0);
	subResult.setImaginaryNumber(0);
	subResult.setRealNumber(x1.getRealNumber() - x2.getRealNumber() - x3.getRealNumber() - x4.getRealNumber());
	subResult.setImaginaryNumber(x1.getImaginaryNumber() - x2.getImaginaryNumber() - x3.getImaginaryNumber() - x4.getImaginaryNumber());
	if (subResult.getImaginaryNumber() < 0) {
		subResult.setImaginaryNumber(subResult.getImaginaryNumber() * -1);
	}
}

void Obliczenia::wyswietl_wyniki(int tab[])
{
	int a = tab[0];
	int b = tab[1];
	int c = tab[2];

	if (a != 0) {
		double delta = oblicz_delte(tab);
		cout << "delta: " << delta << endl;
		if (delta != 0) //delta rozna od zera
		{
			//wypisz x1
			cout << "x1: ";
			//cout << x1.getRealNumber() << "+" << x1.getImaginaryNumber() << endl;
			x1.printString();
			//wypisz x2
			cout << "x2: ";
			x2.printString();
			//wypisz x3
			cout << "x3: ";
			x3.printString();
			//wypisz x4
			cout << "x3: ";
			x4.printString();
		}
		else // delta rowna 0
		{
			x1.printString();
			x2.printString();
		}
	}
	else //a rowne zero
	{
		double delta = oblicz_delte(tab);
		cout << "delta: " << delta << "\n";
		if (delta < 0) //delta ujemna
		{
			//cout << x1.getRealNumber() << "+" << x1.getImaginaryNumber() << endl;
			x1.printString();
			x2.printString();
		}
		else //delta wieksza lub rowna zero
		{
			cout << "x1: " << x1.getRealNumber() << "\n";
			cout << "x2: " << x2.getRealNumber() << "\n";
		}
	}
	odejm_l_zesp();
	dodaj_l_zesp();
	
	cout << "sr: " << addResult.getRealNumber() << endl;
	cout << "su: " << addResult.getImaginaryNumber() << endl;
	cout << "rr: " << subResult.getRealNumber() << endl;
	cout << "ru: " << subResult.getImaginaryNumber() << endl;
	cout << "suma: ";
	if (addResult.getRealNumber() == 0 && addResult.getImaginaryNumber() == 0) {
		cout << endl;
	}
	else {
		addResult.printString();
	}
	cout << "roznica: ";
	if (subResult.getRealNumber() == 0 && subResult.getImaginaryNumber() == 0) {
		cout << endl;
	}
	else {
		subResult.printString();
	}
}
