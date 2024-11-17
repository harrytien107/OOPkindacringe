#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Fraction.h"
#include "Fraction.cpp"

using namespace std;

int main() {
    string filename;
    cin >> filename;
    string fullPath = "Nhap duong dan cua file ban nam trong folder nao do VD: D://Code//" + filename;
    ifstream file(fullPath);
    if (!file) {
        cerr << "Khong the mo file" << endl;
        return 1;
    }

    int N;
    file >> N;

    vector<Fraction> fractions(N);
    for (int i = 0; i < N; ++i) {
        file >> fractions[i];
    }

    file.close();

    if (fractions.empty()) {
        cerr << "Khong co gia tri de thuc thi" << endl;
        return 1;
    }

    Fraction maxFraction = fractions[0];
    Fraction minFraction = fractions[0];

    for (const auto& fraction : fractions) {
        if (fraction > maxFraction) {
            maxFraction = fraction;
        }
        if (fraction < minFraction) {
            minFraction = fraction;
        }
    }

    cout << "GTLN: ";
    maxFraction.print();
    cout << endl;

    cout << "GTNN: ";
    minFraction.print();
    cout << endl;

    return 0;
}