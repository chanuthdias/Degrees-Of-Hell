#include "HearingSpace.h"

void HearingSpace::Print( shared_ptr<CPlayer> player )
{
	cout << player->GetName( ) + " lands on Plagiarism Hearing and supports their friend" << endl;
}

HearingSpace::HearingSpace( string name ):CSpace( name )
{
}