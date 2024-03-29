#include "CSkipClassesSpace.h"

void CSkipClassesSpace::Print(shared_ptr<CPlayer> player)
{
	cout << player->GetName() + " lands on Skip Classes and hangs out with their dodgy mates" << endl;
}

CSkipClassesSpace::CSkipClassesSpace(string name):CSpace(name)
{
}
