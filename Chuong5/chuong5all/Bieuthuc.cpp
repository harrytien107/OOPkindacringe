// #include "Bieuthuc.h"

// Bieuthuc::Bieuthuc(int level) {
//     srand(time(0)); // Seed để tạo số ngẫu nhiên
//     a = rand() % (level >= 4 ? 100 : 10) + 1;
//     b = rand() % (level >= 4 ? 100 : 10) + 1;
    
//     // Chọn phép toán dựa trên cấp độ
//     if (level == 1) pheptoan = '+';
//     else if (level == 2 || level == 4) pheptoan = rand() % 2 == 0 ? '+' : '-';
//     else pheptoan = "+-*"[rand() % 3];
// }

// ostream& operator<<(ostream& out, const Bieuthuc& bt) {
//     out << bt.a << " " << bt.pheptoan << " " << bt.b;
//     return out;
// }

// bool Bieuthuc::kiemtra(float traloi) {
//     return traloi == giatri();
// }

// float Bieuthuc::giatri() {
//     if (pheptoan == '+') return a + b;
//     if (pheptoan == '-') return a - b;
//     return a * b;
// }

// #include "Bieuthuc.h"

// Bieuthuc::Bieuthuc(int level) {
//     a = rand() % ((level < 4) ? 11 : 101);  // Nếu level < 4 thì a, b <= 10; nếu >=4 thì <= 100
//     b = rand() % ((level < 4) ? 11 : 101);
//     if (level == 1) pheptoan = '+';
//     else if (level == 2) pheptoan = (rand() % 2 == 0) ? '+' : '-';
//     else pheptoan = (rand() % 3 == 0) ? '+' : (rand() % 2 == 0) ? '-' : '*';
// }

// ostream& operator<<(ostream& out, const Bieuthuc& bt) {
//     out << bt.a << " " << bt.pheptoan << " " << bt.b;
//     return out;
// }

// bool Bieuthuc::kiemtra(float traloi) {
//     return abs(traloi - giatri()) < 0.0001;
// }

// float Bieuthuc::giatri() {
//     switch (pheptoan) {
//         case '+': return a + b;
//         case '-': return a - b;
//         case '*': return a * b;
//     }
//     return 0;
// }

#include "Bieuthuc.h"
#include <cstdlib> // rand(), srand()
#include <ctime> // time()

Bieuthuc::Bieuthuc(int level) {
    srand(time(0));
    // Sinh ngẫu nhiên a và b theo cấp độ
    switch (level) {
        case 1:
            a = rand() % 11;
            b = rand() % 11;
            pheptoan = '+'; // chỉ có phép cộng
            break;
        case 2:
            a = rand() % 11;
            b = rand() % 11;
            pheptoan = (rand() % 2) == 0 ? '+' : '-'; // cộng hoặc trừ
            break;
        case 3:
            a = rand() % 11;
            b = rand() % 11;
            pheptoan = "+-*"[rand() % 3]; // cộng, trừ hoặc nhân
            break;
        case 4:
            a = rand() % 101;
            b = rand() % 101;
            pheptoan = (rand() % 2) == 0 ? '+' : '-'; // cộng hoặc trừ
            break;
        default:
            a = rand() % 101;
            b = rand() % 101;
            pheptoan = "+-*"[rand() % 3]; // cộng, trừ hoặc nhân
            break;
    }
}

ostream& operator<<(ostream& out, const Bieuthuc& bt) {
    out << bt.a << " " << bt.pheptoan << " " << bt.b;
    return out;
}

bool Bieuthuc::kiemtra(float traloi) {
    return traloi == giatri();
}

float Bieuthuc::giatri() {
    switch (pheptoan) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        default: return 0;
    }
}