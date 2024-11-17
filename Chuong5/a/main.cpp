#include <iostream>
#include "Bieuthuc.h"

using namespace std;

int main() {
    int level;
    cout << "Nhap level 1-5: ";
    cin >> level;

    Bieuthuc bt(level);

    cout << "Bieu thuc " << bt << endl;

    float answer;
    cout << "Nhap dap an: ";
    cin >> answer;

    if (bt.kiemtra(answer)) {
        cout << "Dung!" << endl;
    } else {
        cout << "Sai!" << endl;
    }

    return 0;
}