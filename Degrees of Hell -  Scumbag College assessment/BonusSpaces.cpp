#include "BonusSpaces.h"
#include "RandomNumberGenerator.h"

BonusSpaces::BonusSpaces( string name ):CSpace( name )
{
	mBonusList.push_back( Bonus ( "Receive some useful feedback.", 20 ) );
	mBonusList.push_back( Bonus ( "Win a hackathon.", 50 ) );
	mBonusList.push_back( Bonus ( "Get a free coffee with full loyalty card.", 80 ) );
	mBonusList.push_back( Bonus ( "Impress your lecturer in class.", 100 ) );
	mBonusList.push_back( Bonus ( "Motivational talk from course leader", 5 ) );
	mBonusList.push_back( Bonus ( "Secure an industry placement", 150 ) );
	mBonusList.push_back( Bonus ( "Attend an inspiring C++ lecture.", 200 ) );
	mBonusList.push_back( Bonus ( "Get your best ever assignment mark", 300 ) );
	mBonusList.push_back( Bonus ( "Make a new romantic friend", 150 ) );
	mBonusList.push_back( Bonus ( "Get elected School President", 10 ) );
}

void BonusSpaces::Print( shared_ptr<CPlayer> player )
{
	CSpace::Print( player );

	int r = RandomNumberGenerator::Random( );
	player->UpdateMotivation( mBonusList[r - 1].mMotivataionGain );

	cout << player->GetName( ) << " spins " << r << endl;
	cout << mBonusList[r - 1].mName << " Gain motivation of " << mBonusList[r - 1].mMotivataionGain << endl;
	cout << player->GetName( ) << " has " << player->GetMotivation( ) << endl;
}