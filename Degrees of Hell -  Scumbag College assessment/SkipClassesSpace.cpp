#include "SkipClassesSpace.h"

void SkipClassesSpace::Print( shared_ptr<CPlayer> player )
{
	cout << player->GetName( ) + " lands on Skip Classes and hangs out with their dodgy mates" << endl;
}

SkipClassesSpace::SkipClassesSpace( string name ):CSpace( name )
{
}