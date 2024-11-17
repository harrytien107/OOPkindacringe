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
    Fraction(int num, int denom);
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    friend ostream& operator<<(ostream& os, const Fraction& frac);
};