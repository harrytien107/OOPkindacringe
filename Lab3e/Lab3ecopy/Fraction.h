#pragma once
#include <iostream>
using namespace std;
class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction();
    Fraction(int num, int denom);

    friend istream& operator>>(istream& in, Fraction& fraction);
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;

    double value() const;
    void print() const;
};
