#include "ChuyenVienPhanTich.h"
#include "TienThuongNgoaiTinh.h"    

ChuyenVienPhanTich::ChuyenVienPhanTich() : NhanVien() {
    setPhuongthucTienThuong(new TienThuongNgoaiTinh());  
}

ChuyenVienPhanTich::ChuyenVienPhanTich(const string maso, const string hoten, double luongCB)
    : NhanVien(maso, hoten, luongCB) {
    setPhuongthucTienThuong(new TienThuongNgoaiTinh()); 
}

double ChuyenVienPhanTich::getTienThuong() const {
    return phuongthucTienThuong->tinhTienThuong(luongCB);
}

string ChuyenVienPhanTich::toString() const {
    return "Chuyen Vien Phan Tich [" + NhanVien::toString() + "]";
}