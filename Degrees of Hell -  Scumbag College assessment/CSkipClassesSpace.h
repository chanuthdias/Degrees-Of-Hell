#pragma once
#include "CSpace.h"
#include "CPlayer.h"
class CSkipClassesSpace :
    public CSpace
{
public:
    void Print(shared_ptr<CPlayer> player)override;
    CSkipClassesSpace(string name);
};

