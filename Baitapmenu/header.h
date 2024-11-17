#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Khai báo lớp CauhoiTN
class CauhoiTN {
private:
    string noidung;   // Nội dung câu hỏi
    string dapanA;    // Nội dung đáp án A
    string dapanB;    // Nội dung đáp án B
    char dapanDung;   // Đáp án đúng (A hoặc B)

public:
    // Phương thức nhập câu hỏi từ bàn phím
    void nhap();

    // Phương thức đọc câu hỏi từ file
    void docfile(ifstream& f);

    // Phương thức ghi câu hỏi vào file
    void ghifile(ofstream& f) const;

    // Phương thức kiểm tra câu trả lời của người dùng
    bool kiemtra() const;

    // Phương thức xuất câu hỏi (bao gồm đáp án đúng) ra màn hình
    void xuat() const;

    // Phương thức friend kiểm tra hai câu hỏi có giống nhau không
    friend bool giongnhau(const CauhoiTN& cau1, const CauhoiTN& cau2);
};

// Khai báo lớp DeThi
class DeThi {
private:
    vector<CauhoiTN> dsCauhoi;  // Danh sách câu hỏi trắc nghiệm

public:
    // Thêm một câu hỏi mới từ bàn phím
    void themCauhoi();

    // In danh sách các câu hỏi hiện hành
    void inDanhsach() const;

    // Lưu danh sách câu hỏi vào file
    void luufile(const string& tenfile) const;

    // Đọc danh sách câu hỏi từ file
    void docfile(const string& tenfile);

    // Cho thi và tính số câu trả lời đúng
    void choThi() const;

    bool kiemtraTrung(const CauhoiTN& cauhoi) const;
};

#endif  // Kết thúc include guard
