#pragma once
#include <iostream>
#include "CSpace.h"
class Activity :
    public CSpace
{
    private :
        int cost;
        CPlayer* CompletedByPlayer = nullptr;

    public:
        Activity(string name, SpaceTypes type, int motivationalCost);
        bool IsCompleted();
        CPlayer* CompletedBy();
        int GetMotivationCost();
        void SetComplete(CPlayer* player);

};

