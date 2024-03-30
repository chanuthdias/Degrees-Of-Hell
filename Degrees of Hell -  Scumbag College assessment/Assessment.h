#pragma once
#include <iostream>
#include "CSpace.h"
#include "Types.h"

class Assessment :
    public CSpace
{
    private :
        int success;
        int year;
        int cost;
        playerVectorType CompletedPlayers;

    public:
        Assessment(string assessmentsType, int motivationalCost, int successScore, int year);
        void Print(shared_ptr<CPlayer> player) override;
        int GetSuccessScore();
        int GetYear();
        bool IsCompleted();
        bool IsCompleted(shared_ptr<CPlayer> player);
        playerVectorType CompletedBy();
        int GetMotivationCost();
        void SetComplete(shared_ptr<CPlayer> player);
};

