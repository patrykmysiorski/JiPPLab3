#include "DoubleQuadratic.h"
#include <iostream>
using namespace std;



void DoubleQuadratic::formatuj_rnie(int tab[])
{
	int a = tab[0];
	int b = tab[1];
	int c = tab[2];

	//wszystkie mozliwosci a
	if (a != 0)
	{
		if (a == -1)
		{
			cout << "-xxxx";
		}
		else if (a == 1)
		{
			cout << "xxxx";
		}
		else
		{
			cout << a << "xxxx";
		}

		//wszystkie mozliwosci b
		if (b != 0)
		{
			if (b < 0) //b ujemne
			{
				cout << b << "xx";
			}
			else {
				cout << "+" << b << "xx";
			}
		}

		//c
		if (c != 0) {
			if (c < 0) {
				cout << c;
			}
			else {
				cout << "+" << c;
			}
		}
		printf("=0\n");
	}
	else { //a rowne zero
		if (b != 0) {
			cout << b << "xx";
			if (c != 0) {
				if (c < 0) {
					cout << c;
				}
				else {
					cout << "+" << c;
				}
			}
			printf("=0\n");
		}
		else { //b rowne zero
			if (c != 0) {
				printf("Rownanie sprzeczne.\n");
			}
			else {
				printf("Rownanie tozsamosciowe. 0=0\n");
			}
		}
	}
	//koniec wypisywania
}

DoubleQuadratic::DoubleQuadratic()
{
}


DoubleQuadratic::~DoubleQuadratic()
{
}
