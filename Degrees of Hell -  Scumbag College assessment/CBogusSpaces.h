#pragma once
#include "CSpace.h"
#include <vector>

class Bogus {
public:
    string name;
    int motivataionLoss;
    Bogus(string name, int gain) :name(name), motivataionLoss(gain) {}
};

class CBogusSpaces :
    public CSpace
{
private:
    vector<Bogus>BogusList;
public:
    CBogusSpaces(string name);
    void Print(CPlayer* player) override;
};

