#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Fraction
{
private:
	// Tu so
	int numerator;
	// Mau so
	int denominator;
public:
    Fraction(int num, int den);
    Fraction(int random);
    friend ostream& operator<<(ostream& os, const Fraction& fraction);
};
