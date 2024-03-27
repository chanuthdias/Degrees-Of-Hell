#pragma once
#include "CSpace.h"
class CExtraCurricularspaces :
    public CSpace
{
private:
    int cost;
    int isCompleted;

public:
    void Print(CPlayer* player)override;
    CExtraCurricularspaces(string name, SpaceTypes type, int motivationalCost);

    bool IsCompleted();
    int CompletedBy();
    int GetMotivationCost();
    void SetComplete(int player);

};

