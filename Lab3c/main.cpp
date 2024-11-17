#include <iostream>
#include "Fraction.h"
#include "Fraction.cpp"
using namespace std;

int main()
{
    char test_op = '+';
    cin >> test_op;
    Fraction f1(1,2), f2(2,3), f3(-1,1);
    switch (test_op) {
    case '+':
        cout << f1 << " + " << f2 << "=" << f1 + f2 << endl;
        cout << f1 << " + " << f3 << "=" << f1 + f3 << endl;
        break;
    case '-':
        cout << f1 << " - " << f2 << "=" << f1 - f2 << endl;
        cout << f1 << " - " << f3 << "=" << f1 - f3 << endl;
        break;
    case '*':
        cout << f1 << " * " << f2 << "=" << f1 * f2 << endl;
        cout << f1 << " * " << f3 << "=" << f1 * f3 << endl;
        break;
    case '/':
        cout << f1 << " / " << f2 << "=" << f1 / f2 << endl;
        cout << f1 << " / " << f3 << "=" << f1 / f3 << endl;
        break;
    }
    return 0;
}