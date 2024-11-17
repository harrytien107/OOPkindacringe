#include "KeToanVien.h"
#include "TienThuongThongThuong.h"  

KeToanVien::KeToanVien() : NhanVien() {
    setPhuongthucTienThuong(new TienThuongThongThuong());
}

KeToanVien::KeToanVien(const string maso, const string hoten, double luongCB)
    : NhanVien(maso, hoten, luongCB) {
    setPhuongthucTienThuong(new TienThuongThongThuong());
}

double KeToanVien::getTienThuong() const {
    return phuongthucTienThuong->tinhTienThuong(luongCB);
}

string KeToanVien::toString() const {
    return "Ke Toan Vien [" + NhanVien::toString() + "]";
}