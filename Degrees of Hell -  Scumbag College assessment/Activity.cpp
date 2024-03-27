#include "Activity.h"

Activity::Activity(string name, SpaceTypes type, int motivationalCost) : CSpace(name, type)
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
