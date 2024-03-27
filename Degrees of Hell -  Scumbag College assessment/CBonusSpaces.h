#pragma once
#include "CSpace.h"
#include <vector>

class Bonus {
public:
    string name;
    int motivataionGain;
    Bonus(string name, int gain) :name(name), motivataionGain(gain) {}
};

class CBonusSpaces :
    public CSpace
{
private:
    vector<Bonus>BonusList;
public:
    CBonusSpaces(string name);
    void Print(CPlayer* player) override;
};


