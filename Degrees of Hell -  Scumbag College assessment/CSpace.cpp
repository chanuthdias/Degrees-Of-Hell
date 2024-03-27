#include "CSpace.h"

CSpace::CSpace(string name) :name(name)
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
