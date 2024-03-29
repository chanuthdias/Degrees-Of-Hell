#pragma once
#include "CSpace.h"

class CExtraCurricularspaces :
    public CSpace


{
private:
    int cost;
    shared_ptr<CPlayer> CompletedByPlayer = nullptr;

public:
    CExtraCurricularspaces(string name, int motivationalCost);
    bool IsCompleted();
    shared_ptr<CPlayer> CompletedBy();
    int GetMotivationCost();
    void SetComplete(shared_ptr<CPlayer> player);
    void Print(shared_ptr<CPlayer> player) override;
};

