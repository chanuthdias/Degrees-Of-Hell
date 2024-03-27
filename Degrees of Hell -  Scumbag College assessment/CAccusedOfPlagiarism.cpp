#include "CSpace.h"
#include "CAccusedOfPlagiarism.h"

void CAccusedOfPlagiarism::Print(CPlayer *player)
{
	cout << player->GetName() + " lands on Accused of Plagiarism and goes to the hearing" << endl;
	cout << player->GetName() + " loses motivation" << endl;
	player->UpdateMotivation(-50);
}

CAccusedOfPlagiarism::CAccusedOfPlagiarism(string name, SpaceTypes type):CSpace(name, type)
{
}
