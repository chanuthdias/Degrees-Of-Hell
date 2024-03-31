#include "BogusSpaces.h"
#include "RandomNumberGenerator.h"

BogusSpaces::BogusSpaces( string name ):CSpace( name )
{
	mBogusList.push_back( Bogus ( "Fall asleep in a boring lecture.", 20 ) );
	mBogusList.push_back( Bogus ( "Meet with coach about poor attendance.", 50 ) );
	mBogusList.push_back( Bogus ( "Feel really tired after a night out.", 80 ) );
	mBogusList.push_back( Bogus ( "Get kicked out of lab for messing about.", 100 ) );
	mBogusList.push_back( Bogus ( "Get dumped before a big night out.", 150 ) );
	mBogusList.push_back( Bogus ( "Fail an assignment.", 200 ) );
	mBogusList.push_back( Bogus ( "Get caught skipping class.", 50 ) );
	mBogusList.push_back( Bogus ( "Your friend drops out of uni.", 200 ) );
	mBogusList.push_back( Bogus ( "Nobody turns up to teach your class.", 300 ) );
	mBogusList.push_back( Bogus ( "Lecturer changes assignment schedule.", 20 ) );
}

void BogusSpaces::Print( shared_ptr<CPlayer> player )
{
	CSpace::Print( player );

	int r = RandomNumberGenerator::Random( );
	player->UpdateMotivation( -mBogusList[r - 1].mMotivataionLoss );
	
	cout << player->GetName( ) << " spins " << r << endl;
	cout << mBogusList[r - 1].mName << " Loss motivation of " << mBogusList[r - 1].mMotivataionLoss << endl;
	cout << player->GetName( ) << " has " << player->GetMotivation( ) << endl;
}