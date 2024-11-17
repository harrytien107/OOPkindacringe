#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>  

using namespace std;

struct SinhVien {
    string maSo;
    string hoTen;
    int soBuoiVang;
    float diemTH;
    float diemGK;
    float diemQT; 

    // Tính điểm quá trình
    void tinhDiemQT() {
        if (soBuoiVang <= 5) {
            diemQT = (10 - soBuoiVang * 2) * 0.2 + diemTH * 0.3 + diemGK * 0.5;
        } else {
            diemQT = 0;
        }
    }
};


bool laSo(const string &str) {
    for (char const &c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}


bool laSoThuc(const string &str) {
    istringstream iss(str);
    float f;
    iss >> noskipws >> f; 
    return iss.eof() && !iss.fail(); 
}


void nhapThongTinSinhVien(SinhVien &sv) {
    while (true) {
        cout << "Nhap ma so sinh vien: ";
        getline(cin, sv.maSo);
        if (laSo(sv.maSo)) break;
        cout << "Ma so sinh vien chi duoc phep chua so. Vui long nhap lai.\n";
    }
    cout << "Nhap ho va ten sinh vien: ";
    getline(cin, sv.hoTen);

    string input;
    while (true) {
        cout << "Nhap so buoi vang: ";
        getline(cin, input);
        if (laSo(input)) {
            sv.soBuoiVang = stoi(input);
            break;
        }
        cout << "So buoi vang chi duoc phep chua so. Vui long nhap lai.\n";
    }

    while (true) {
        cout << "Nhap diem thuc hanh: ";
        getline(cin, input);
        if (laSoThuc(input)) {
            sv.diemTH = stof(input);
            break;
        }
        cout << "Diem thuc hanh chi duoc phep chua so. Vui long nhap lai.\n";
    }

    while (true) {
        cout << "Nhap diem giua ky: ";
        getline(cin, input);
        if (laSoThuc(input)) {
            sv.diemGK = stof(input);
            break;
        }
        cout << "Diem giua ky chi duoc phep chua so. Vui long nhap lai.\n";
    }

    sv.tinhDiemQT();
}

// Xuất thông tin sinh viên ra màn hình
void xuatThongTinSinhVien(const SinhVien &sv) {
    cout << "Ma so: " << sv.maSo << "\nHo ten: " << sv.hoTen
         << "\nSo buoi vang: " << sv.soBuoiVang << "\nDiem thuc hanh: " << sv.diemTH
         << "\nDiem giua ky: " << sv.diemGK << "\nDiem qua trinh: " << sv.diemQT << endl;
}

// Nhập danh sách sinh viên
void nhapDanhSachSinhVien(vector<SinhVien> &danhSach) {
    int n;
    string input;
    while (true) {
        cout << "Nhap so luong sinh vien: ";
        getline(cin, input);
        if (laSo(input)) {
            n = stoi(input);
            break;
        }
        cout << "So luong sinh vien chi duoc phep chua so. Vui long nhap lai.\n";
    }

    for (int i = 0; i < n; ++i) {
        SinhVien sv;
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        nhapThongTinSinhVien(sv);
        danhSach.push_back(sv);
    }
}

// Xuất danh sách sinh viên
void xuatDanhSachSinhVien(const vector<SinhVien> &danhSach) {
    for (const auto &sv : danhSach) {
        xuatThongTinSinhVien(sv);
        cout << "----------------------\n";
    }
}

// Ghi danh sách sinh viên ra file
void ghiFile(const vector<SinhVien> &danhSach, const string &fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
        for (const auto &sv : danhSach) {
            file << sv.maSo << "," << sv.hoTen << "," << sv.soBuoiVang << "," << sv.diemTH
                 << "," << sv.diemGK << "," << sv.diemQT << endl;
        }
        file.close();
        cout << "Ghi file thanh cong.\n";
    } else {
        cout << "Khong mo duoc file!\n";
    }
}

// Đọc danh sách sinh viên từ file
void docFile(vector<SinhVien> &danhSach, const string &fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string maSo, hoTen;
            int soBuoiVang;
            float diemTH, diemGK, diemQT;

            getline(ss, maSo, ',');
            getline(ss, hoTen, ',');
            ss >> soBuoiVang;
            ss.ignore();
            ss >> diemTH;
            ss.ignore();
            ss >> diemGK;
            ss.ignore();
            ss >> diemQT;

            SinhVien sv = {maSo, hoTen, soBuoiVang, diemTH, diemGK, diemQT};
            danhSach.push_back(sv);
        }
        file.close();
        cout << "Doc file thanh cong.\n";
    } else {
        cout << "Khong mo duoc file!\n";
    }
}

// In danh sách sinh viên đủ điều kiện dự thi
void inDanhSachDuDieuKien(const vector<SinhVien> &danhSach) {
    cout << "Danh sach sinh vien du dieu kien du thi (DiemQT >= 3):\n";
    for (const auto &sv : danhSach) {
        if (sv.diemQT >= 3) {
            xuatThongTinSinhVien(sv);
            cout << "----------------------\n";
        }
    }
}

// In danh sách sinh viên có họ "Nguyen"
void inDanhSachHoNguyen(const vector<SinhVien> &danhSach) {
    cout << "Danh sach sinh vien co ho 'Nguyen':\n";
    for (const auto &sv : danhSach) {
        if (sv.hoTen.find("Nguyen") == 0) {  // Kiểm tra xem họ có phải "Nguyen" không
            xuatThongTinSinhVien(sv);
            cout << "----------------------\n";
        }
    }
}

// In danh sách sinh viên có cùng tên với một sinh viên khác
void inDanhSachTrungTen(const vector<SinhVien> &danhSach) {
    cout << "Danh sach sinh vien co ten trung lap:\n";
    for (size_t i = 0; i < danhSach.size(); ++i) {
        string ten1 = danhSach[i].hoTen.substr(danhSach[i].hoTen.find_last_of(' ') + 1);
        for (size_t j = i + 1; j < danhSach.size(); ++j) {
            string ten2 = danhSach[j].hoTen.substr(danhSach[j].hoTen.find_last_of(' ') + 1);
            if (ten1 == ten2) {
                xuatThongTinSinhVien(danhSach[i]);
                xuatThongTinSinhVien(danhSach[j]);
                cout << "----------------------\n";
            }
        }
    }
}

int main() {
    vector<SinhVien> danhSach;

    // Nhập dữ liệu từ bàn phím
    nhapDanhSachSinhVien(danhSach);

    // Xuất danh sách sinh viên ra màn hình
    cout << "\nDanh sach sinh vien:\n";
    xuatDanhSachSinhVien(danhSach);

    // Ghi danh sách vào file
    ghiFile(danhSach, "danhsach.csv");

    // Đọc danh sách từ file
    vector<SinhVien> danhSachTuFile;
    docFile(danhSachTuFile, "danhsach.csv");

    // In danh sách sinh viên đủ điều kiện dự thi
    inDanhSachDuDieuKien(danhSachTuFile);

    // In danh sách sinh viên có họ "Nguyen"
    inDanhSachHoNguyen(danhSachTuFile);

    // In danh sách sinh viên có cùng tên với một sinh viên khác
    inDanhSachTrungTen(danhSachTuFile);

    return 0;
}
