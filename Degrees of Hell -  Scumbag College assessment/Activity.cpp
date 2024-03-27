#include "Activity.h"

Activity::Activity(string name, int motivationalCost) : CSpace(name)
{
    cost = motivationalCost;
    CompletedByPlayer = nullptr;
}

bool Activity::IsCompleted()
{
    if(CompletedByPlayer!=nullptr)
        return true;
    return false;
}

CPlayer* Activity::CompletedBy()
{
    return CompletedByPlayer;
}

int Activity::GetMotivationCost()
{
    return cost;
}

void Activity::SetComplete(CPlayer* player)
{
    CompletedByPlayer = player;
}
