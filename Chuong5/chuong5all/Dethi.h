// #ifndef DETHI_H
// #define DETHI_H

// #include "Bieuthuc.h"
// #include <iostream>

// class Dethi {
// private:
//     int level; // Đặt level trước cauHoiHienTai để tránh cảnh báo về thứ tự khởi tạo
//     Bieuthuc* cauHoiHienTai;
//     Bieuthuc* taoBieuthucNgauNhien(int level);
// public:
//     Dethi(int level = 1);
//     ~Dethi();
//     void taoCauHoi();
//     void xuat(std::ostream& output = std::cout);
//     bool danhgia(float traloi);
//     void tangCapDo() { if (level < 5) level++; }
//     void giamCapDo() { if (level > 1) level--; }
// };

// #endif

#pragma once
#include "Bieuthuc.h"
#include "BieuthucCong.h"
#include "BieuthucTru.h"
#include "BieuthucNhan.h"
#include <vector>
using namespace std;

class Dethi {
private:
    vector<Bieuthuc*> ds;

public:
    Dethi(int n1, int n2, int n3, int level=1);
    vector<Bieuthuc*> danhsach() const { return ds; }
    void xuat(ostream& output=cout);
    int danhgia(istream& input=cin);
    ~Dethi();
};
