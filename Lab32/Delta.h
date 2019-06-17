#pragma once
class Delta
{
public:
	Delta();
	~Delta();
protected:
	virtual double oblicz_delte(int tab[]) = 0;
};

