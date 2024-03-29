#include <iostream>
#include "Assessment.h"

Assessment::Assessment(string assessmentType, int motivationalCost, int successScore, int year) :CSpace(assessmentType), year(year), cost(motivationalCost)
{
	success = successScore;
}

void Assessment::Print(shared_ptr<CPlayer> player)
{
    if (IsCompleted())
    {
        if (CompletedBy()->GetName() != player->GetName())
        {
            player->UpdateMotivation(-GetMotivationCost()/2);
            player->UpdateSuccess(GetSuccessScore()/2);
            CompletedBy()->UpdateSuccess(GetSuccessScore() / 2);
            cout << player->GetName() << " helps and achieves " << GetSuccessScore() << endl;

            player->AddCompletedAssessment(year, GetName());
        }
    }
    else
    {
        if (player->GetMotivation() >= GetMotivationCost())
        {
            player->UpdateMotivation(-GetMotivationCost());
            player->UpdateSuccess(GetSuccessScore());

            cout << player->GetName() << " completes " << GetName() << " for " << GetMotivationCost() << " and achieve's " << GetSuccessScore() << endl;
            
            SetComplete(player);

            player->AddCompletedAssessment(year, GetName());
        }
    }
}

int Assessment::GetSuccessScore()
{
	return success;
}

int Assessment::GetYear()
{
    return year;
}

bool Assessment::IsCompleted()
{
    if (CompletedByPlayer != nullptr)
        return true;
    return false;
}

shared_ptr<CPlayer> Assessment::CompletedBy()
{
    return CompletedByPlayer;
}

int Assessment::GetMotivationCost()
{
    return cost;
}

void Assessment::SetComplete(shared_ptr<CPlayer> player)
{
    CompletedByPlayer = player;
}
