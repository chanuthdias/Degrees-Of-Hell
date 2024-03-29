#pragma once
#include <iostream>
#include "CSpace.h"
class Assessment :
    public CSpace
{
    private :
        int success;
        int year;
        int cost;
        shared_ptr<CPlayer> CompletedByPlayer = nullptr;

    public:
        Assessment(string assessmentsType, int motivationalCost, int successScore, int year);
        void Print(shared_ptr<CPlayer> player) override;
        int GetSuccessScore();
        int GetYear();
        bool IsCompleted();
        shared_ptr<CPlayer> CompletedBy();
        int GetMotivationCost();
        void SetComplete(shared_ptr<CPlayer> player);
};

