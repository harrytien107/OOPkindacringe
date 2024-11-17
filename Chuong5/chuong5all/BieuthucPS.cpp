// #include "BieuthucPS.h"

// BieuthucPS::BieuthucPS(int level) : Bieuthuc(level) {}

// float BieuthucPS::giatri() {
//     Fraction f1(a, b == 0 ? 1 : b);
//     Fraction f2(b, a == 0 ? 1 : a);
//     Fraction result;
//     if (pheptoan == '+') result = f1 + f2;
//     else if (pheptoan == '-') result = f1 - f2;
//     else result = f1 * f2;
//     return result.value();
// }

// #include "BieuthucPS.h"

// BieuthucPS::BieuthucPS(int level) : Bieuthuc(level) {
//     // Khởi tạo các phân số hoặc các phần tử khác của BieuthucPS
// }

// ostream& operator<<(ostream& out, const BieuthucPS& bt) {
//     // Xuất biểu thức dạng phân số
//     cout << bt.a << " " << bt.pheptoan << " " << bt.b;
//     return out;
// }

// bool BieuthucPS::kiemtra(float traloi) {
//     return abs(traloi - giatri()) < 0.0001;
// }

// float BieuthucPS::giatri() {
//     // Giả sử a, b, và pheptoan là thành viên và kết quả biểu thức là giá trị cần trả về
//     switch (pheptoan) {
//         case '+': return a + b;
//         case '-': return a - b;
//         case '*': return a * b;
//         case '/': return b != 0 ? static_cast<float>(a) / b : 0;  // Chỉ thực hiện phép chia nếu b khác 0
//         default: return 0;
//     }
// }

#include "BieuthucPS.h"

BieuthucPS::BieuthucPS(int level) : Bieuthuc(level) {
    a = rand() % 11;
    b = rand() % 11;
    pheptoan = "+-*"[rand() % 3];
}

ostream& operator<<(ostream& out, const BieuthucPS& bt) {
    out << bt.a << " " << bt.pheptoan << " " << bt.b;
    return out;
}

bool BieuthucPS::kiemtra(float traloi) {
    return traloi == giatri();
}

float BieuthucPS::giatri() {
    Fraction result;
    switch (pheptoan) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
    }
    return result.toFloat(); // giả sử có hàm toFloat() trong lớp Fraction
}