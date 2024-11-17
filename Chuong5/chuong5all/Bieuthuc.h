#pragma once
#include <iostream>
using namespace std;

class Bieuthuc {
protected:
    int a, b;
    char pheptoan; // phép toán: +, -, *

public:
    Bieuthuc(int level); // hàm tạo sinh biểu thức ngẫu nhiên theo cấp độ
    friend ostream& operator<<(ostream& out, const Bieuthuc& bt); // xuất biểu thức
    virtual bool kiemtra(float traloi); // kiểm tra câu trả lời
    virtual float giatri(); // tính giá trị biểu thức
};