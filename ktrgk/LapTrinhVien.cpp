#include "LapTrinhVien.h"
#include "TienThuongNgoaiGio.h" 

LapTrinhVien::LapTrinhVien() : NhanVien() {
    setPhuongthucTienThuong(new TienThuongNgoaiGio());
}

LapTrinhVien::LapTrinhVien(const string maso, const string hoten, double luongCB)
    : NhanVien(maso, hoten, luongCB) {
    setPhuongthucTienThuong(new TienThuongNgoaiGio());
}

double LapTrinhVien::getTienThuong() const {
    return phuongthucTienThuong->tinhTienThuong(luongCB);
}

string LapTrinhVien::toString() const {
    return "Lap Trinh Vien [" + NhanVien::toString() + "]";
}