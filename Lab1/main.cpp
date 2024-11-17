#include "Menu.h"
#include "Menu.cpp"

int main() {
    Menu menu("Menu Chuc Nang");

    // Sử dụng toán tử chèn để thêm lựa chọn
    menu << "Chuc nang 0" 
         << "Chuc nang 1" 
         << "Chuc nang 2";

    // Gọi hàm chọn
    int luaChon = menu.chon();
    cout << "Ban da chon: " << luaChon << endl;

    return 0;
}