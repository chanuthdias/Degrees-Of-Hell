#include "CSpace.h"
#include "CPlayer.h"

CSpace::CSpace(string name, SpaceTypes type) :name(name),type(type)
{

}

void CSpace::Print(CPlayer *player)
{
	//cout << "name = " << name << endl;
	cout << player->GetName() << " lands on " << GetName() << endl;
}

string CSpace::GetName()
{
	return name;
}

SpaceTypes CSpace::GetType()
{
	return type;
}

