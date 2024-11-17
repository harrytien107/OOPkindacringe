#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    vector<int> arr;
    int n, x;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back(x);
    }

    map<int, int> frequency;
    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++; 
    }
    
    cout << "\na) So gia tri khac nhau trong mang: " << frequency.size() << endl;
    cout << "\nb) So lan xuat hien cua moi gia tri:\n";
    for (auto it : frequency) {
        cout << "Gia tri " << it.first << " xuat hien " << it.second << " lan\n";
    }
    
    map<int, vector<int>> positions;
    for (int i = 0; i < n; i++) {
        positions[arr[i]].push_back(i); 
    }
    
    cout << "\nc) Vi tri xuat hien cua moi gia tri:\n";
    for (auto it : positions) {
        cout << "Gia tri " << it.first << " xuat hien tai cac vi tri: ";
        for (int pos : it.second) {
            cout << pos << " ";  
        }
        cout << endl;
    }
    
    return 0;
}