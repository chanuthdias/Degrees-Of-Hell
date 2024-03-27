#pragma once
#include <iostream>
#include "CSpace.h"
class Assessment :
    public CSpace
{
    private :
        string type;
        int cost;
        int success;
        int year;
        int isCompleted;

    public:
        Assessment(string assessmentsType, int motivationalCost, int successScore, int year);
        void Print();
        bool IsCompleted();
        int GetMotivationCost();
        int GetSuccessScore();
        void SetComplete(int player);
        int CompletedBy();
};

