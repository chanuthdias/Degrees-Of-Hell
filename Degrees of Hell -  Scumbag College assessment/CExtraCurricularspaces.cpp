#include "CExtraCurricularspaces.h"


CExtraCurricularspaces::CExtraCurricularspaces(string name, SpaceTypes type, int motivationalCost):Activity(name, SpaceTypes::extraCurricularspaces, motivationalCost)
{
    
}

void CExtraCurricularspaces::Print(CPlayer* player)
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

