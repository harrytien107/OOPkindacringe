#include "Header.h"
#include "Source.cpp"
#include <iostream>

using namespace std;

int main() {
    int n, W;
    vector<pair<int, int>> items;

    // Nhap du lieu
    enter(n, W, items);

    // Giai bai toan va in ra ket qua
    solution(n, W, items);

    return 0;
}
