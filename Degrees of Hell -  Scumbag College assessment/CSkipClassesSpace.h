#pragma once
#include "CSpace.h"
#include "CPlayer.h"
class CSkipClassesSpace :
    public CSpace
{
public:
    void Print(CPlayer *player)override;
    CSkipClassesSpace(string name);
};

