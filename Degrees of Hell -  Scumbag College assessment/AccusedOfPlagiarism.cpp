
#include "AccusedOfPlagiarism.h"
#include "Constants.h"

void AccusedOfPlagiarism::Print( shared_ptr<CPlayer> player )
{
	cout << player->GetName( ) + " lands on Accused of Plagiarism and goes to the hearing" << endl;
	cout << player->GetName( ) + " loses motivation" << endl;
	player->UpdateMotivation( -kAccusedOfPlagiarism);
	player->SetPosition(mHearingSpaceIndex);
}

AccusedOfPlagiarism::AccusedOfPlagiarism( string name ):CSpace( name )
{
	mHearingSpaceIndex = 32;
}

void AccusedOfPlagiarism::SetHearingSpaceIndex(int index)
{
	mHearingSpaceIndex = index;
}
