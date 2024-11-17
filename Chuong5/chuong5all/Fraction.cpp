// #include "Fraction.h"

// Fraction::Fraction(int n, int d) : num(n), den(d == 0 ? 1 : d) {}

// Fraction Fraction::operator+(const Fraction& f) {
//     return Fraction(num * f.den + f.num * den, den * f.den);
// }

// Fraction Fraction::operator-(const Fraction& f) {
//     return Fraction(num * f.den - f.num * den, den * f.den);
// }

// Fraction Fraction::operator*(const Fraction& f) {
//     return Fraction(num * f.num, den * f.den);
// }

// float Fraction::value() const {
//     return static_cast<float>(num) / den;
// }

#include "Fraction.h"
#include <stdexcept> // std::invalid_argument cho trường hợp mẫu số bằng 0

// Hàm tự định nghĩa gcd nếu C++17 không hỗ trợ
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    if (denom == 0) {
        throw std::invalid_argument("Mẫu số không thể bằng 0");
    }
    simplify();
}

void Fraction::simplify() {
    int gcd_val = gcd(numerator, denominator); // sử dụng hàm gcd tự định nghĩa
    numerator /= gcd_val;
    denominator /= gcd_val;
    if (denominator < 0) { // đảm bảo mẫu số luôn dương
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction Fraction::operator+(const Fraction& other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int denom = denominator * other.denominator;
    return Fraction(num, denom);
}

Fraction Fraction::operator-(const Fraction& other) const {
    int num = numerator * other.denominator - other.numerator * denominator;
    int denom = denominator * other.denominator;
    return Fraction(num, denom);
}

Fraction Fraction::operator*(const Fraction& other) const {
    int num = numerator * other.numerator;
    int denom = denominator * other.denominator;
    return Fraction(num, denom);
}

float Fraction::toFloat() const {
    return static_cast<float>(numerator) / denominator;
}

std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
    out << frac.numerator << "/" << frac.denominator;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& frac) {
    char slash;
    in >> frac.numerator >> slash >> frac.denominator;
    if (frac.denominator == 0) {
        throw std::invalid_argument("Mau ko the bang 0");
    }
    frac.simplify();
    return in;
}