#include "NhanVienKiemThu.h"
#include "TienThuongNgoaiGio.h"    

NhanVienKiemThu::NhanVienKiemThu() : NhanVien() {
    setPhuongthucTienThuong(new TienThuongNgoaiGio());  
}

NhanVienKiemThu::NhanVienKiemThu(const string maso, const string hoten, double luongCB)
    : NhanVien(maso, hoten, luongCB) {
    setPhuongthucTienThuong(new TienThuongNgoaiGio());  
}

double NhanVienKiemThu::getTienThuong() const {
    return phuongthucTienThuong->tinhTienThuong(luongCB);
}

string NhanVienKiemThu::toString() const {
    return "Nhan Vien Kiem Thu [" + NhanVien::toString() + "]";
}