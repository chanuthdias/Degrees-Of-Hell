#pragma once
#include <iostream>
#include "Activity.h"
class Assessment :
    public Activity
{
    private :
        int success;
        int year;

    public:
        Assessment(string assessmentsType, int motivationalCost, int successScore, int year);
        void Print(shared_ptr<CPlayer> player) override;
        int GetSuccessScore();
        int GetYear();
};

