#include "CHearingSpace.h"

void CHearingSpace::Print(CPlayer *player)
{
	cout << player->GetName() + " lands on Plagiarism Hearing and supports their friend" << endl;
}

CHearingSpace::CHearingSpace(string name):CSpace(name)
{
}
