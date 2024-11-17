#include "BieuthucPT.h"
#include <cstdlib>
#include <cmath>

BieuthucPT::BieuthucPT(int level) : Bieuthuc(level) {
    if (level <= 3) {
        c = rand() % 10 + 1;
        d = rand() % 10 + 1;
    } else {
        c = rand() % 90 + 10;
        d = rand() % 90 + 10;
    }

    int randomOp = rand() % 3;
    pheptoan2 = (randomOp == 0) ? '+' : (randomOp == 1) ? '-' : '*';
}

float BieuthucPT::giatri() {
    float result1 = Bieuthuc::giatri();
    float result2;

    switch (pheptoan2) {
        case '+': result2 = c + d; break;
        case '-': result2 = c - d; break;
        case '*': result2 = c * d; break;
        default: result2 = 0;
    }

    switch (pheptoan) {
        case '+': return result1 + result2;
        case '-': return result1 - result2;
        case '*': return result1 * result2;
        default: return 0;
    }
}

bool BieuthucPT::kiemtra(float traloi) {
    return std::abs(giatri() - traloi) < 0.001;
}

ostream& operator<<(ostream& out, const BieuthucPT& bt) {
    out << "(" << bt.a << " " << bt.pheptoan << " " << bt.b << ") "
        << bt.pheptoan << " "
        << "(" << bt.c << " " << bt.pheptoan2 << " " << bt.d << ")";
    return out;
}

// #include "BieuthucPT.h"

// BieuthucPT::BieuthucPT(int level) : Bieuthuc(level) {
//     // Sinh ngẫu nhiên biểu thức phức tạp
//     a = rand() % 101;
//     b = rand() % 101;
// }

// ostream& operator<<(ostream& out, const BieuthucPT& bt) {
//     out << "(" << bt.a << " + " << bt.b << ") * (" << bt.a << " - " << bt.b << ")";
//     return out;
// }

// bool BieuthucPT::kiemtra(float traloi) {
//     return traloi == giatri();
// }

// float BieuthucPT::giatri() {
//     return (a + b) * (a - b);
// }