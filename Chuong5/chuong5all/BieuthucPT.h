#pragma once
#include "Bieuthuc.h"
#include <iostream>
using namespace std;

class BieuthucPT : public Bieuthuc
{
private:
    int c, d;
    char pheptoan2;

public:
    BieuthucPT(int level);
    friend ostream& operator<<(ostream& out, const BieuthucPT& bt);
    bool kiemtra(float traloi) override;
    float giatri() override;
};