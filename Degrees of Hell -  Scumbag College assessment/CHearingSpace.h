#pragma once
#include "CSpace.h"
#include "CPlayer.h"
class CHearingSpace :
    public CSpace
{
public :
    void Print(CPlayer *player)override;
    CHearingSpace(string name, SpaceTypes type);
};

