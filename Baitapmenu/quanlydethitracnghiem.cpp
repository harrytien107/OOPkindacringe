#include <bits/stdc++.h>
using namespace std;

// Hàm hỗ trợ chuyển đổi chuỗi thành chữ thường
string toLower(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

class CauhoiTN {
private:
    string noidung;   
    string dapanA;    
    string dapanB;    
    string dapanDung; // Thay đổi kiểu dữ liệu từ char thành string

public:
    // Nhập câu hỏi 
    void nhap();

    // Đọc câu hỏi từ file
    void docfile(ifstream& f);

    // Ghi câu hỏi vào file
    void ghifile(ofstream& f) const;

    // Kiểm tra câu trả lời
    bool kiemtra() const;

    // Xuất câu hỏi 
    void xuat() const;

    // Phương thức Friend kiểm tra hai câu hỏi có giống nhau không
    friend bool giongnhau(const CauhoiTN& cau1, const CauhoiTN& cau2);
};

// Lớp CauhoiTN
void CauhoiTN::nhap() {
    cout << "Nhap cau hoi: ";
    getline(cin, noidung);
    cout << "Nhap dap an A: ";
    getline(cin, dapanA);
    cout << "Nhap dap an B: ";
    getline(cin, dapanB);
    cout << "Nhap dap an dung: "; // Cho phép nhập nhiều từ
    getline(cin, dapanDung);
}

void CauhoiTN::docfile(ifstream& f) {
    getline(f, noidung);
    getline(f, dapanA);
    getline(f, dapanB);
    getline(f, dapanDung); // Đọc chuỗi đáp án
}

void CauhoiTN::ghifile(ofstream& f) const {
    f << noidung << endl;
    f << dapanA << endl;
    f << dapanB << endl;
    f << dapanDung << endl; // Ghi chuỗi đáp án
}

bool CauhoiTN::kiemtra() const {
    string dapanNguoidung;
    cout << noidung << endl;
    cout << "A. " << dapanA << endl;
    cout << "B. " << dapanB << endl;
    cout << "Nhap dap an cua ban: ";
    getline(cin, dapanNguoidung);  // Cho phép nhập nhiều ký tự
    
    return (toLower(dapanNguoidung) == toLower(dapanDung));
}

void CauhoiTN::xuat() const {
    cout << "Cau hoi: " << noidung << endl;
    cout << "A. " << dapanA << endl;
    cout << "B. " << dapanB << endl;
    cout << "Dap an dung la: " << dapanDung << endl;
}

// Hàm friend để so sánh hai câu hỏi
bool giongnhau(const CauhoiTN& cau1, const CauhoiTN& cau2) {
    return (toLower(cau1.noidung) == toLower(cau2.noidung) &&
            toLower(cau1.dapanA) == toLower(cau2.dapanA) &&
            toLower(cau1.dapanB) == toLower(cau2.dapanB) &&
            toLower(cau1.dapanDung) == toLower(cau2.dapanDung));
}

// Lớp DeThi
class DeThi {
private:
    vector<CauhoiTN> dsCauhoi;  

public:
    // Thêm một câu hỏi mới 
    void themCauhoi();

    // In danh sách các câu hỏi 
    void inDanhsach() const;

    // Lưu danh sách câu hỏi vào file
    void luufile(const string& tenfile) const;

    // Đọc danh sách câu hỏi từ file
    void docfile(const string& tenfile);

    // Cho thi và tính số câu trả lời đúng
    void choThi() const;

    bool kiemtraTrung(const CauhoiTN& cauhoi) const;
};

void DeThi::themCauhoi() {
    CauhoiTN cauhoi;
    do {
        cauhoi.nhap();
        if (kiemtraTrung(cauhoi)) {
            cout << "Cau hoi nay da ton tai trong de thi! Vui long nhap lai cau hoi." << endl;
        } else {
            dsCauhoi.push_back(cauhoi);
            cout << "-Da them cau hoi moi." << endl;
            break;
        }
    } while (true);
}

void DeThi::inDanhsach() const {
    for (size_t i = 0; i < dsCauhoi.size(); ++i) {
        cout << "Cau hoi thu " << i + 1 << ":" << endl;
        dsCauhoi[i].xuat();
        cout << endl;
    }
}

void DeThi::luufile(const string& tenfile) const {
    ofstream f(tenfile);
    if (!f) {
        cout << "Khong the mo file de ghi." << endl;
        return;
    }
    f << dsCauhoi.size() << endl;  
    for (const auto& cauhoi : dsCauhoi) {
        cauhoi.ghifile(f);
    }
    f.close();
}

void DeThi::docfile(const string& tenfile) {
    ifstream f(tenfile);
    if (!f) {
        cout << "Khong the mo file de doc." << endl;
        return;
    }
    size_t soluong;
    f >> soluong;
    f.ignore();  
    dsCauhoi.clear();
    for (size_t i = 0; i < soluong; ++i) {
        CauhoiTN cauhoi;
        cauhoi.docfile(f);
        dsCauhoi.push_back(cauhoi);
    }
    f.close();
}

void DeThi::choThi() const {
    int socaudung = 0;
    for (const auto& cauhoi : dsCauhoi) {
        if (cauhoi.kiemtra()) {
            ++socaudung;
        }
    }
    cout << "-So cau tra loi dung la: " << socaudung << "/" << dsCauhoi.size() << endl;
}

bool DeThi::kiemtraTrung(const CauhoiTN& cauhoi) const {
    for (const auto& cau : dsCauhoi) {
        if (giongnhau(cau, cauhoi)) {
            return true;  
        }
    }
    return false;  
}

int main() {
    DeThi dethitn;
    int chon;
    string tenfile;
    string input;

    do {
        cout << "---------- MENU ----------" << endl;
        cout << "1. Tao mot de thi trac nghiem moi" << endl;
        cout << "2. Them mot cau hoi moi vao de thi" << endl;
        cout << "3. In danh sach cau hoi" << endl;
        cout << "4. Luu danh sach cau hoi vao file" << endl;
        cout << "5. Doc noi dung tu file vao bo nho" << endl;
        cout << "6. Cho thi va tinh so cau tra loi dung" << endl;
        cout << "7. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon: ";
        
        getline(cin, input);
        stringstream ss(input);

        if (ss >> chon && ss.eof()) {
            switch (chon) {
                case 1:
                    dethitn = DeThi();
                    cout << "-Da tao de thi moi." << endl;
                    break;
                case 2:
                    dethitn.themCauhoi();
                    break;
                case 3:
                    dethitn.inDanhsach();
                    break;
                case 4:
                    cout << "-Nhap ten file de luu: ";
                    getline(cin, tenfile);
                    dethitn.luufile(tenfile);
                    break;
                case 5:
                    cout << "-Nhap ten file de doc: ";
                    getline(cin, tenfile);
                    dethitn.docfile(tenfile);
                    dethitn.inDanhsach();
                    break;
                case 6:
                    dethitn.choThi();
                    break;
                case 7:
                    cout << "-Thoat chuong trinh." << endl;
                    break;
                default:
                    cout << "-Lua chon khong hop le!" << endl;
                    break;
            }
        } else {
            cout << "-Lua chon khong hop le! Hay chay lai chuong trinh va nhap lai lua chon 1-0 ." << endl;
        }
    } while (chon != 7);

    return 0;
}
