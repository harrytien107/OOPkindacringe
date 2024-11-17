#include "Menu.h"

Menu::Menu(string tieude)
{
    this->tieude = tieude;
}

void Menu::themLuachon(string luachon)
{
    dsLuachon.push_back(luachon);
}

void Menu::xuat()
{
    cout << "\n-----" << tieude << "-----\n";
    for (int i = 0; i < dsLuachon.size(); i++)
        cout << i << ". " << dsLuachon[i] << endl;
}

int Menu::chon()
{
    int ch;
    do {
        xuat();
        cout << "Hay chon mot so: ";
        cin >> ch;
        string tmp;
        getline(cin, tmp);
        if (ch < 0 || ch >= dsLuachon.size())
            cout << "Chon sai, moi chon lai!!!\n";
    } while (ch < 0 || ch >= dsLuachon.size()); 
    return ch;
}

// Cài đặt toán tử chèn
Menu& Menu::operator<<(const string& luachon)
{
    themLuachon(luachon);
    return *this; 
}