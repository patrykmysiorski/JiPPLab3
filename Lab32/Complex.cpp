#include "Complex.h"
#include <string>
#include <iostream>
using namespace std;
Complex::Complex()
{
}


Complex::~Complex()
{
}

void Complex::setRealNumber(double xr)
{
	realNumber = xr;
}

void Complex::setImaginaryNumber(double xu)
{
	imaginaryNumber = xu;
}

double Complex::getImaginaryNumber()
{
	return imaginaryNumber;
}

void Complex::printString()
{
	if (imaginaryNumber < 0) {
		cout << realNumber << imaginaryNumber << "i" << endl;
	}
	else {
		cout << realNumber << "+" << imaginaryNumber << "i" << endl;
	}
}

double Complex::getRealNumber()
{
	return realNumber;
}


