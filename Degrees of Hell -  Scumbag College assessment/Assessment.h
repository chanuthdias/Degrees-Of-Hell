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
        void Print(CPlayer* player) override;
        int GetSuccessScore();
};

