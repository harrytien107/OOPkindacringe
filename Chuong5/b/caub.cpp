#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

struct CauHoi {
    string cau_hoi;
    string dap_an;
    int do_kho;
};

vector<CauHoi> cau_hoi_list = {
    {"Thu do cua Phap la gi?", "Paris", 1},
    {"2 + 2 bang bao nhieu?", "4", 1},
    {"Can bac hai cua 16 la gi?", "4", 2},
    {"Ai la tac gia cua 'Giet con chim nhai'?", "Harper Lee", 3},
    {"Truong UTH co dang nho?", "Khong", 2},
    {"Cau chuyen Donkihote co bi kich khong?", "Khong", 3},
};

bool hoi_cau_hoi(const CauHoi& cau_hoi) {
    cout << "Cau hoi (Do kho " << cau_hoi.do_kho << "): " << cau_hoi.cau_hoi << endl;
    string dap_an;
    cout << "Dap an la: ";
    getline(cin, dap_an);
    transform(dap_an.begin(), dap_an.end(), dap_an.begin(), ::tolower);
    string correct_answer = cau_hoi.dap_an;
    transform(correct_answer.begin(), correct_answer.end(), correct_answer.begin(), ::tolower);
    return dap_an == correct_answer;
}

void tro_choi_trac_nghiem() {
    int diem = 0;
    srand(time(0));
    while (true) {
        CauHoi cau_hoi = cau_hoi_list[rand() % cau_hoi_list.size()];
        if (hoi_cau_hoi(cau_hoi)) {
            diem += cau_hoi.do_kho;
            cout << "Dung roi!" << endl;
        } else {
            cout << "Sai roi! Dap an dung la: " << cau_hoi.dap_an << endl;
        }
        cout << "Diem hien tai cua ban la: " << diem << endl;

        string tiep_tuc;
        cout << "Ban co muon tiep tuc khong? (co/khong): ";
        getline(cin, tiep_tuc);
        transform(tiep_tuc.begin(), tiep_tuc.end(), tiep_tuc.begin(), ::tolower);
        if (tiep_tuc != "co") {
            break;
        }
    }

    cout << "Diem cuoi cung cua ban la: " << diem << endl;
}

int main() {
    tro_choi_trac_nghiem();
    return 0;
}