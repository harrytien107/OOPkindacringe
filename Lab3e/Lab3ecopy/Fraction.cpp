#include "Fraction.h"
#include <stdexcept>

using namespace std;

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    if (denom == 0) {
        throw invalid_argument("Mau so khong the bang 0");
    }
}

istream& operator>>(istream& in, Fraction& fraction) {
    in >> fraction.numerator >> fraction.denominator;
    if (fraction.denominator == 0) {
        throw invalid_argument("Mau so khong the bang 0");
    }
    return in;
}

bool Fraction::operator<(const Fraction& other) const {
    return this->value() < other.value();
}

bool Fraction::operator>(const Fraction& other) const {
    return this->value() > other.value();
}

double Fraction::value() const {
    return static_cast<double>(numerator) / denominator;
}

void Fraction::print() const {
    cout << numerator << "/" << denominator;
}