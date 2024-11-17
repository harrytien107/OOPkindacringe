#include "Bieuthuc.h"
#include <cstdlib>
#include <ctime>

Bieuthuc::Bieuthuc(int level) {
    srand(time(0));
    if (level == 1) {
        a = rand() % 11;
        b = rand() % 11;
        pheptoan = '+';
    } else if (level == 2) {
        a = rand() % 11;
        b = rand() % 11;
        pheptoan = (rand() % 2 == 0) ? '+' : '-';
    } else if (level == 3) {
        a = rand() % 11;
        b = rand() % 11;
        int op = rand() % 3;
        pheptoan = (op == 0) ? '+' : (op == 1) ? '-' : '*';
    } else if (level == 4) {
        a = rand() % 101;
        b = rand() % 101;
        pheptoan = (rand() % 2 == 0) ? '+' : '-';
    } else {
        a = rand() % 101;
        b = rand() % 101;
        int op = rand() % 3;
        pheptoan = (op == 0) ? '+' : (op == 1) ? '-' : '*';
    }
}

ostream& operator<<(ostream& out, Bieuthuc bt) {
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