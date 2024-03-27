#include "CExtraCurricularspaces.h"

void CExtraCurricularspaces::Print(CPlayer* player)
{

}

CExtraCurricularspaces::CExtraCurricularspaces(string name, SpaceTypes type, int motivationalCost) :CSpace(name, type)
{
	cost = motivationalCost;
}

bool CExtraCurricularspaces::IsCompleted()
{
    return isCompleted >= 0;
}

int CExtraCurricularspaces::CompletedBy()
{
	return isCompleted;
}

int CExtraCurricularspaces::GetMotivationCost()
{
	return cost;
}

void CExtraCurricularspaces::SetComplete(int player)
{
	isCompleted = player;
}