// #include <iostream>
// #include <iomanip>
#include "TienThuongNgoaiGio.h"
#include "TienThuongNgoaiGio.cpp"
#include "TienThuongNgoaiTinh.h"
#include "TienThuongNgoaiTinh.cpp"
#include "TienThuongThongThuong.h"
#include "TienThuongThongThuong.cpp"

// Câu a TienThuong
// using namespace std;
// int main() {
//     const double luongCoBan = 10000000; // 10 million VND as example

//     TienThuong* cacLoaiThuong[] = {
//         new TienThuongNgoaiGio(),
//         new TienThuongNgoaiTinh(),
//         new TienThuongThongThuong()
//     };

//     cout << fixed << setprecision(0); // Set format for all following outputs
//     cout << "Demo tinh tien thuong voi luong co ban " << luongCoBan << " VND:\n";
//     cout << "Tien thuong ngoai gio: " << cacLoaiThuong[0]->tinhTienThuong(luongCoBan) << " VND\n";
//     cout << "Tien thuong ngoai tinh: " << cacLoaiThuong[1]->tinhTienThuong(luongCoBan) << " VND\n";
//     cout << "Tien thuong thong thuong: " << cacLoaiThuong[2]->tinhTienThuong(luongCoBan) << " VND\n";
// }        

// Câu b NhanVien
#include <iostream>
#include <iomanip>
#include <vector>
#include "NhanVien.h"
#include "NhanVien.cpp"
#include "LapTrinhVien.h"
#include "LapTrinhVien.cpp"          
#include "KeToanVien.h"
#include "KeToanVien.cpp"
#include "NhanVienKiemThu.h"
#include "NhanVienKiemThu.cpp"
#include "ChuyenVienPhanTich.h"
#include "ChuyenVienPhanTich.cpp"
// using namespace std;

// int main() {
//     // Create employee list
//     vector<NhanVien*> dsNhanVien;
    
//     // Initialize different employee types
//     dsNhanVien.push_back(new LapTrinhVien("LTV001", "Nguyen Van A", 10000000));
//     dsNhanVien.push_back(new KeToanVien("KTV001", "Tran Thi B", 8000000));
//     dsNhanVien.push_back(new NhanVienKiemThu("NVKT001", "Le Van C", 9000000));
//     dsNhanVien.push_back(new ChuyenVienPhanTich("CVPT001", "Pham Thi D", 11000000));
    
//     // Format output
//     cout << fixed << setprecision(0);
    
//     // Print header
//     cout << "\n=== DANH SACH NHAN VIEN VA TIEN THUONG ===\n\n";
    
//     // Display each employee and their bonus
//     for (const auto& nv : dsNhanVien) {
//         cout << "----------------------------------------\n";
//         cout << nv->toString() << endl;
//         cout << "Tien thuong: " << nv->getTienThuong() << " VND\n";
//     }
//     cout << "----------------------------------------\n";
    
//     // Calculate and display total bonus
//     double tongTienThuong = 0;
//     for (const auto& nv : dsNhanVien) {
//         tongTienThuong += nv->getTienThuong();
//     }
//     cout << "\nTong tien thuong: " << tongTienThuong << " VND\n";

//     return 0;
// }

// Câu c NhanVienFactory

#include "NhanVienFactory.h"
#include "NhanVienFactory.cpp"
#include "INhanVienFactory.h"
using namespace std;

int main() {
    // Create factory
    NhanVienFactory factory;
    vector<NhanVien*> dsNhanVien;
    
    // Create different types of employees using factory
    dsNhanVien.push_back(factory.createNhanVien(1, "NVKT001", "Su Duc A", 11000000));
    dsNhanVien.push_back(factory.createNhanVien(2, "LTV001", "Su Duc B", 13000000));
    dsNhanVien.push_back(factory.createNhanVien(3, "CVPT001", "Su Duc C", 9000000));
    dsNhanVien.push_back(factory.createNhanVien(4, "KTV001", "Su Duc D", 11000000));
    dsNhanVien.push_back(factory.createNhanVien(3, "KTV002", "Su Duc E", 2000000));
    // Format output
    cout << fixed << setprecision(0);
    
    // Display information
    cout << "\n=== DANH SACH NHAN VIEN VA TIEN THUONG ===\n\n";
    
    for (const auto& nv : dsNhanVien) {
        if (nv != nullptr) {
            cout << "----------------------------------------\n";
            cout << nv->toString() << endl;
            cout << "Tien thuong: " << nv->getTienThuong() << " VND\n";
        }
    }
    
    // Calculate total bonus
    double tongTienThuong = 0;
    for (const auto& nv : dsNhanVien) {
        if (nv != nullptr) {
            tongTienThuong += nv->getTienThuong();
        }
    }
    
    cout << "----------------------------------------\n";
    cout << "Tong tien thuong: " << tongTienThuong << " VND\n";

    // Cleanup
    for (auto nv : dsNhanVien) {
        delete nv;
    }
    dsNhanVien.clear();

    return 0;
}