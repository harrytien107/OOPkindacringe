/* #include <iostream>
#include <fstream>
#include <vector>
#include "Fraction.h"
#include "Fraction.cpp"
using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream infile(filename);
    if (!infile) {
        cerr << "Khong the mo file" << endl;
        return 1;
    }

    int N;
    infile >> N;

    vector<Fraction> fractions(N);
    for (int i = 0; i < N; ++i) {
        infile >> fractions[i];
    }

    if (fractions.empty()) {
        cerr << "No fractions to process!" << endl;
        return 1;
    }

    Fraction maxFraction = fractions[0];
    Fraction minFraction = fractions[0];

    for (const auto& frac : fractions) {
        if (frac > maxFraction) {
            maxFraction = frac;
        }
        if (frac < minFraction) {
            minFraction = frac;
        }
    }

    cout << "Maximum fraction: " << maxFraction << endl;
    cout << "Minimum fraction: " << minFraction << endl;

    return 0;
} */

#include <iostream>
#include <fstream>
#include <vector>
#include "Fraction.h"
#include "Fraction.cpp"

using namespace std;

int main() {
string filename;
cout << "Enter the filename: ";
cin >> filename;

// Prepend the directory path
string fullPath = "D:\\CODE\\BaitapC++\\Lab3e\\" + filename;

ifstream file(fullPath);
if (!file) {
    cerr << "Error opening file!" << endl;
    return 1;
}

int N;
file >> N;

vector<Fraction> fractions(N);
for (int i = 0; i < N; ++i) {
    file >> fractions[i];
}

if (fractions.empty()) {
    cerr << "No fractions to process!" << endl;
    return 1;
}

Fraction maxFraction = fractions[0];
Fraction minFraction = fractions[0];

for (const auto& frac : fractions) {
    if (frac > maxFraction) {
        maxFraction = frac;
    }
    if (frac < minFraction) {
        minFraction = frac;
    }
}

cout << "Maximum fraction: " << maxFraction << endl;
cout << "Minimum fraction: " << minFraction << endl;

return 0;
}