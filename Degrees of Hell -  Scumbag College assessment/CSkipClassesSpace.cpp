#include "CSkipClassesSpace.h"

void CSkipClassesSpace::Print(CPlayer *player)
{
	cout << player->GetName() + " lands on Skip Classes and hangs out with their dodgy mates" << endl;
}

CSkipClassesSpace::CSkipClassesSpace(string name, SpaceTypes type):CSpace(name, type)
{
}
