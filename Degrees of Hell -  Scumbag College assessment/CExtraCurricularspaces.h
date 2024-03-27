#pragma once
#include "Activity.h"
class CExtraCurricularspaces :
    public Activity
{
public:
    CExtraCurricularspaces(string name, SpaceTypes type, int motivationalCost);
    void Print(CPlayer* player) override;
};

