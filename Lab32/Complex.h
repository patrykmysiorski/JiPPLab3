#pragma once
#include <string>
using namespace std;
class Complex
{
public:
	Complex();
	~Complex();
	void setRealNumber(double xr);
	double getRealNumber();

	void setImaginaryNumber(double xu);
	double getImaginaryNumber();
	void printString();
private:
	double realNumber;
	double imaginaryNumber;
};

