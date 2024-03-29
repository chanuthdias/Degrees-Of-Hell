#include "CExtraCurricularspaces.h"


CExtraCurricularspaces::CExtraCurricularspaces(string name, int motivationalCost):Activity(name, motivationalCost)
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

