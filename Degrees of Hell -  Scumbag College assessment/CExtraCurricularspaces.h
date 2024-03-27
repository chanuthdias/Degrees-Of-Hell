#pragma once
#include "Activity.h"
class CExtraCurricularspaces :
    public Activity
{
public:
    CExtraCurricularspaces(string name, int motivationalCost);
    void Print(CPlayer* player) override;
};

