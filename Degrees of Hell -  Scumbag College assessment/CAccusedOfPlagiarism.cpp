
#include "CAccusedOfPlagiarism.h"

void CAccusedOfPlagiarism::Print( shared_ptr<CPlayer> player )
{
	cout << player->GetName( ) + " lands on Accused of Plagiarism and goes to the hearing" << endl;
	cout << player->GetName( ) + " loses motivation" << endl;
	player->UpdateMotivation( -50 );
	player->SetPosition(mHearingSpaceIndex);
}

CAccusedOfPlagiarism::CAccusedOfPlagiarism( string name ):CSpace( name )
{
	mHearingSpaceIndex = 32;
}

void CAccusedOfPlagiarism::SetHearingSpaceIndex(int index)
{
	mHearingSpaceIndex = index;
}
