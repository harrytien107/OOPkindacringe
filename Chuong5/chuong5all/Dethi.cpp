// #include "Dethi.h"
// #include "BieuthucCong.h"
// #include "BieuthucTru.h"
// #include "BieuthucNhan.h"
// #include <cstdlib>
// #include <ctime>

// Dethi::Dethi(int level) : level(level), cauHoiHienTai(nullptr) { // Correct order
//     std::srand(static_cast<unsigned int>(std::time(nullptr)));
//     taoCauHoi();
// }

// Dethi::~Dethi() {
//     delete cauHoiHienTai;
// }

// Bieuthuc* Dethi::taoBieuthucNgauNhien(int level) {
//     int op = std::rand() % 3;
//     switch (op) {
//         case 0: return new BieuthucCong(level);
//         case 1: return new BieuthucTru(level);
//         case 2: return new BieuthucNhan(level);
//         default: return new BieuthucCong(level);
//     }
// }

// void Dethi::taoCauHoi() {
//     delete cauHoiHienTai; // Xóa câu hỏi cũ nếu có

//     switch (level) {
//         case 1:
//             cauHoiHienTai = new BieuthucCong(level);
//             break;
//         case 2:
//             cauHoiHienTai = (std::rand() % 2 == 0) ? 
//                 static_cast<Bieuthuc*>(new BieuthucCong(level)) : 
//                 static_cast<Bieuthuc*>(new BieuthucTru(level));
//             break;
//         case 3:
//             cauHoiHienTai = taoBieuthucNgauNhien(level);
//             break;
//         case 4:
//             cauHoiHienTai = (std::rand() % 2 == 0) ? 
//                 static_cast<Bieuthuc*>(new BieuthucCong(level)) : 
//                 static_cast<Bieuthuc*>(new BieuthucTru(level));
//             break;
//         default: // Level 5+
//             cauHoiHienTai = taoBieuthucNgauNhien(level);
//             break;
//     }
// }

// void Dethi::xuat(std::ostream& output) {
//     if (cauHoiHienTai) {
//         output << *cauHoiHienTai << " = ?" << std::endl;
//     }
// }

// bool Dethi::danhgia(float traloi) {
//     if (cauHoiHienTai && cauHoiHienTai->kiemtra(traloi)) {
//         taoCauHoi(); // Tạo câu hỏi mới nếu trả lời đúng
//         return true;
//     }
//     return false;
// }

// #include "Dethi.h"

// Dethi::Dethi(int n1, int n2, int n3, int level) {
//     for (int i = 0; i < n1; ++i) ds.push_back(new BieuthucCong(level));
//     for (int i = 0; i < n2; ++i) ds.push_back(new BieuthucTru(level));
//     for (int i = 0; i < n3; ++i) ds.push_back(new BieuthucNhan(level));
// }

// void Dethi::xuat(ostream& output) {
//     for (size_t i = 0; i < ds.size(); ++i) {
//         output << *ds[i] << " = ?" << endl;
//     }
// }

// int Dethi::danhgia(istream& input) {
//     int correct = 0;
//     float traloi;
//     for (size_t i = 0; i < ds.size(); ++i) {
//         input >> traloi;
//         if (ds[i]->kiemtra(traloi)) correct++;
//     }
//     return correct;
// }

#include "Dethi.h"

Dethi::Dethi(int n1, int n2, int n3, int level) {
    for (int i = 0; i < n1; ++i)
        ds.push_back(new BieuthucCong(level));
    for (int i = 0; i < n2; ++i)
        ds.push_back(new BieuthucTru(level));
    for (int i = 0; i < n3; ++i)
        ds.push_back(new BieuthucNhan(level));
}

void Dethi::xuat(std::ostream& output) {
    for (const auto& bt : ds) {
        output << *bt << " = ?" << std::endl;
    }
}

int Dethi::danhgia(std::istream& input) {
    int soCauDung = 0;
    float traloi;
    for (const auto& bt : ds) {
        input >> traloi;
        if (bt->kiemtra(traloi))
            soCauDung++;
    }
    return soCauDung;
}

Dethi::~Dethi() {
    for (auto bt : ds)
        delete bt;
}