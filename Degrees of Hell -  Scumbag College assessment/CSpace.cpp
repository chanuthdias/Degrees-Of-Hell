#include "CSpace.h"

CSpace::CSpace( string name ) :mName( name )
{
}

void CSpace::Print( shared_ptr<CPlayer> player )
{
	//cout << "name = " << name << endl;
	cout << player->GetName( ) << " lands on " << GetName( ) << endl;
}

string CSpace::GetName( )
{
	return mName;
}