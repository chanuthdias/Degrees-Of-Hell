#pragma once
#include "CSpace.h"
#include "Bogus.h"
#include <vector>

class CBogusSpaces :
    public CSpace
{
private:
    typedef vector<Bogus> BogusListType;
    BogusListType mBogusList;

public:
    CBogusSpaces( string name );
    void Print( shared_ptr<CPlayer> player ) override;
};