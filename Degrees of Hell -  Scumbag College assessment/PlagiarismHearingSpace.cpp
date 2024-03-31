#include "PlagiarismHearingSpace.h"

void PlagiarismHearingSpace::Print( shared_ptr<CPlayer> player )
{
	cout << player->GetName( ) + " lands on Plagiarism Hearing and supports their friend" << endl;
}

PlagiarismHearingSpace::PlagiarismHearingSpace( string name ):CSpace( name )
{
}