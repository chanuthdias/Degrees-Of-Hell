#pragma once
#include "Activity.h"
class CExtraCurricularspaces :
    public Activity
{
public:
    CExtraCurricularspaces(string name, int motivationalCost);
    void Print(shared_ptr<CPlayer> player) override;
};

