#include "header.h"

// Định nghĩa các phương thức của lớp CauhoiTN

void CauhoiTN::nhap() {
    cout << "Nhap cau hoi: ";
    getline(cin, noidung);
    cout << "Nhap dap an A: ";
    getline(cin, dapanA);
    cout << "Nhap dap an B: ";
    getline(cin, dapanB);
    cout << "Nhap dap an dung (A/B): ";
    cin >> dapanDung;
    cin.ignore();  // Bỏ qua ký tự newline sau khi nhập
}

void CauhoiTN::docfile(ifstream& f) {
    getline(f, noidung);
    getline(f, dapanA);
    getline(f, dapanB);
    f >> dapanDung;
    f.ignore();  // Bỏ qua ký tự newline
}

void CauhoiTN::ghifile(ofstream& f) const {
    f << noidung << endl;
    f << dapanA << endl;
    f << dapanB << endl;
    f << dapanDung << endl;
}

bool CauhoiTN::kiemtra() const {
    char dapanNguoidung;
    cout << noidung << endl;
    cout << "A. " << dapanA << endl;
    cout << "B. " << dapanB << endl;
    cout << "Nhap dap an cua ban (A/B): ";
    cin >> dapanNguoidung;
    return (dapanNguoidung == dapanDung);
}

void CauhoiTN::xuat() const {
    cout << "Cau hoi: " << noidung << endl;
    cout << "A. " << dapanA << endl;
    cout << "B. " << dapanB << endl;
    cout << "Dap an dung la: " << dapanDung << endl;
}

// Hàm friend để so sánh hai câu hỏi
bool giongnhau(const CauhoiTN& cau1, const CauhoiTN& cau2) {
    return (cau1.noidung == cau2.noidung &&
            cau1.dapanA == cau2.dapanA &&
            cau1.dapanB == cau2.dapanB &&
            cau1.dapanDung == cau2.dapanDung);
}

// Định nghĩa các phương thức của lớp DeThi

void DeThi::themCauhoi() {
    CauhoiTN cauhoi;
    cauhoi.nhap();

    // Kiểm tra xem câu hỏi mới có trùng với câu hỏi nào đã có hay không
    if (kiemtraTrung(cauhoi)) {
        cout << "Cau hoi nay da ton tai trong de thi!" << endl;
    } else {
        dsCauhoi.push_back(cauhoi);
        cout << "Da them cau hoi moi." << endl;
    }
}


// Định nghĩa các phương thức của lớp DeThi


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
    f << dsCauhoi.size() << endl;  // Ghi số lượng câu hỏi
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
    f.ignore();  // Bỏ qua ký tự newline sau khi nhập số lượng
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
    cout << "So cau tra loi dung la: " << socaudung << "/" << dsCauhoi.size() << endl;
}
// Kiểm tra xem câu hỏi có trùng với câu hỏi đã có trong danh sách không
bool DeThi::kiemtraTrung(const CauhoiTN& cauhoi) const {
    for (const auto& cau : dsCauhoi) {
        if (giongnhau(cau, cauhoi)) {
            return true;  // Trùng
        }
    }
    return false;  // Không trùng
}