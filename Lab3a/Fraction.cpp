#include "Fraction.h"

Fraction::Fraction(int num, int den) {
    if (den == 0) {
        numerator = 0;
        denominator = 1;
    } else {
        numerator = num;
        denominator = den;
    }
}

Fraction::Fraction(int random) {
    numerator = rand() % (random + 1);
    denominator = rand() % (random + 1);
    if (denominator == 0) {
        denominator = 1;
    }
}

ostream& operator<<(ostream& os, const Fraction& fraction) {
    os << fraction.numerator << "/" << fraction.denominator;
    return os;
}