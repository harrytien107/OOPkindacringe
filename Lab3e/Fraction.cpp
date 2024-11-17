#include "Fraction.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Fraction::Fraction() : numerator(0), denominator(1) {}

// Custom gcd function
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

istream& operator>>(istream& in, Fraction& fraction) {
    in >> fraction.numerator >> fraction.denominator;
    if (fraction.denominator == 0) {
        throw invalid_argument("Denominator cannot be zero");
    }
    int gcd_value = gcd(fraction.numerator, fraction.denominator);
    fraction.numerator /= gcd_value;
    fraction.denominator /= gcd_value;
    // Ensure the denominator is positive
    if (fraction.denominator < 0) {
        fraction.numerator = -fraction.numerator;
        fraction.denominator = -fraction.denominator;
    }
    return in;
}

ostream& operator<<(ostream& os, const Fraction& frac) {
    os << frac.numerator << "/" << frac.denominator;
    return os;
}

bool Fraction::operator<(const Fraction& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool Fraction::operator>(const Fraction& other) const {
    return other < *this;
}