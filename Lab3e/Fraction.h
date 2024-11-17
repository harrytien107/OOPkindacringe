/* #pragma once
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
    // Default constructor
    Fraction() : numerator(0), denominator(1) {}

    // Parameterized constructor
    Fraction(int num, int denom);

    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    friend ostream& operator<<(ostream& os, const Fraction& frac);
    friend istream& operator>>(istream& is, Fraction& frac); // Added >> operator
};
 */

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction();
    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
};

#endif // FRACTION_H