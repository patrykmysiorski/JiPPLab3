#pragma once
#include "Delta.h"
#include "Complex.h"

class Obliczenia : protected Delta
{
private:
	double oblicz_delte(int tab[]) override;
public:
	Obliczenia();
	~Obliczenia();
	void oblicz_pierwiastki(int tab[]);
	void dodaj_l_zesp();
	void odejm_l_zesp();
	
	void wyswietl_wyniki(int tab[]);

private:
	Complex x1;
	Complex x2;
	Complex x3;
	Complex x4;
	Complex addResult;
	Complex subResult;
};

