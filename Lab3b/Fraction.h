#pragma once
#include <iostream>
using namespace std;

class Fraction
{
private:
	// Tu so
	int numerator;
	// Mau so
	int denominator;
public:
    Fraction(int num = 0, int denom = 1);
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);
    friend ostream& operator<<(ostream& os, const Fraction& frac);
};
