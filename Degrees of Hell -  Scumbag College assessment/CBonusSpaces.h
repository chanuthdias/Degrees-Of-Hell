#pragma once
#include "CSpace.h"
#include "Bonus.h"
#include <vector>

class CBonusSpaces :
    public CSpace
{
private:
    typedef vector<Bonus> BonusListType;
    BonusListType BonusList;

public:
    CBonusSpaces(string name);
    void Print(shared_ptr<CPlayer> player) override;
};


