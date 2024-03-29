#include "CExtraCurricularspaces.h"


CExtraCurricularspaces::CExtraCurricularspaces(string name, int motivationalCost) :CSpace(name), cost(motivationalCost)
{
}

void CExtraCurricularspaces::Print(shared_ptr<CPlayer> player)
{
    if (IsCompleted())
    {
        if (CompletedBy()->GetName() != player->GetName())
        {
            player->UpdateMotivation(-GetMotivationCost() / 2);
            CompletedBy()->UpdateMotivation(GetMotivationCost());
            cout << player->GetName() << " motivates " << CompletedBy()->GetName() << " by joining their activity" << endl;
        }
    }
    else
    {
        if (player->GetMotivation() >= GetMotivationCost())
        {
            player->UpdateMotivation(-GetMotivationCost());
            SetComplete(player);
        }
    }
}

bool CExtraCurricularspaces::IsCompleted()
{
    if (CompletedByPlayer != nullptr)
        return true;
    return false;
}

shared_ptr<CPlayer> CExtraCurricularspaces::CompletedBy()
{
    return CompletedByPlayer;
}

int CExtraCurricularspaces::GetMotivationCost()
{
    return cost;
}

void CExtraCurricularspaces::SetComplete(shared_ptr<CPlayer> player)
{
    CompletedByPlayer = player;
}

