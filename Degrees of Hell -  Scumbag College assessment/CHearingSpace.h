#pragma once
#include "CSpace.h"
#include "CPlayer.h"
class CHearingSpace :
    public CSpace
{
public :
    void Print( shared_ptr<CPlayer> player )override;
    CHearingSpace( string name );
};

