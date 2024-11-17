#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include "Dethi.h"
#include "Dethi.cpp"
#include "Bieuthuc.h"
#include "Bieuthuc.cpp"
#include "BieuthucCong.h"
#include "BieuthucCong.cpp"
#include "BieuthucTru.h"
#include "BieuthucTru.cpp"
#include "BieuthucNhan.h"
#include "BieuthucNhan.cpp"
#include "BieuthucPS.h"
#include "BieuthucPS.cpp"
#include "BieuthucPT.h"
#include "BieuthucPT.cpp"
#include "Fraction.h"
#include "Fraction.cpp"
using namespace std;


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "Bieuthuc.h"
#include "BieuthucCong.h"
#include "BieuthucTru.h"
#include "BieuthucNhan.h"

using namespace std;

int main() {
    srand(time(0)); // Khởi tạo seed cho hàm rand()

    int level = 1;
    int correctCount = 0;
    int score = 0;

    while (true) {
        Bieuthuc* expression = nullptr;
        switch (level) {
            case 1:
                expression = new BieuthucCong(level);
                break;
            case 2:
                expression = (rand() % 2 == 0) ? static_cast<Bieuthuc*>(new BieuthucCong(level)) 
                                               : static_cast<Bieuthuc*>(new BieuthucTru(level));
                break;
            case 3:
            case 4:
            default:
                switch (rand() % 3) {
                    case 0: expression = new BieuthucCong(level); break;
                    case 1: expression = new BieuthucTru(level); break;
                    case 2: expression = new BieuthucNhan(level); break;
                }
                break;
        }

        cout << "Cap do: " << level << " | Diem: " << score << endl;
        cout << "Cau hoi: " << *expression << " = ";
        float answer;
        cin >> answer;

        if (expression->kiemtra(answer)) {
            cout << "Chinh xac!" << endl;
            score++;
            correctCount++;

            if (correctCount == 3) {
                level++;
                correctCount = 0;
                cout << "Chuc mung ban da len cap : " << level << endl;
            }
        } else {
            cout << "Sai, dap an dung la : " << expression->giatri() << endl;
            correctCount = 0;
            if (level > 1) {
                level--;
                cout << "Rat buon ban da xuong cap : " << level << endl;
            }
        }

        delete expression;
        cout << endl;

        char choice;
        while (true) {
            cout << "Ban co muon tiep tuc? (y/n): ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Xóa buffer

            if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') {
                break;  // Thoát khỏi vòng lặp nếu input hợp lệ
            }
            cout << "Nhap khong hop le. Vui long nhap 'y' hoac 'n'." << endl;
        }

        if (choice == 'n' || choice == 'N') {
            break;  // Thoát khỏi vòng lặp chính nếu người dùng chọn không tiếp tục
        }
    }

    cout << "Game Over. Diem cuoi cung la : " << score << endl;
    return 0;
}