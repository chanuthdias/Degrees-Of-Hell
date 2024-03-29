#pragma once
#include <iostream>
#include "CSpace.h"
class Activity :
    public CSpace
{
    private :
        int cost;
        shared_ptr<CPlayer> CompletedByPlayer = nullptr;

    public:
        Activity(string name, int motivationalCost);
        bool IsCompleted();
        shared_ptr<CPlayer> CompletedBy();
        int GetMotivationCost();
        void SetComplete(shared_ptr<CPlayer> player);

};

