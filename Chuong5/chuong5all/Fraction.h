// #ifndef FRACTION_H
// #define FRACTION_H
// #include <iostream>
// using namespace std;

// class Fraction {
//     int num, den; // Tử số và mẫu số
// public:
//     Fraction(int n = 0, int d = 1);
//     Fraction operator+(const Fraction& f);
//     Fraction operator-(const Fraction& f);
//     Fraction operator*(const Fraction& f);
//     float value() const;
// };

// #endif

#pragma once
#include <iostream>
#include <numeric> 

class Fraction {
private:
    int numerator; // tử số
    int denominator; // mẫu số

    void simplify(); // hàm nội bộ để rút gọn phân số

public:
    Fraction(int num = 0, int denom = 1); // khởi tạo phân số với tử và mẫu

    // Các phép toán cộng, trừ, nhân cho phân số
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;

    // Hàm chuyển đổi phân số thành giá trị thực
    float toFloat() const;

    // Toán tử nhập/xuất
    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);
    friend std::istream& operator>>(std::istream& in, Fraction& frac);
};