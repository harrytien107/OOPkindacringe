#ifndef BIEUTHUC_H
#define BIEUTHUC_H

#include <iostream>
using namespace std;

class Bieuthuc
{
protected:
    int a, b; // hai toán hạng
    char pheptoan; // ký tự đại diện phép toán {+, -, *}
public:
    Bieuthuc(int level); // sinh ngẫu nhiên biểu thức theo quy luật
    friend ostream& operator<<(ostream& out, Bieuthuc bt); // xuất ra theo dạng a # b
    bool kiemtra(float traloi); //nhận câu trả lời và kiểm tra xem giá trị biểu thức có trùng câu trả lời không
    float giatri(); //tính giá trị biểu thức
};

#endif // BIEUTHUC_H