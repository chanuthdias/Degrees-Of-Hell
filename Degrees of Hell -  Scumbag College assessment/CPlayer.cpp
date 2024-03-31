#include "CPlayer.h"

CPlayer::CPlayer ( string name ):mName( name )
{
	mMotivation = 1000;
	mSuccess = 0;
	mPosition = 0;
	mYear = 1;
}

string CPlayer::GetName( )
{
	return mName;
}

bool CPlayer::Move( int spin )
{
	mPosition = ( mPosition + spin );
	if ( mPosition >= 36 )
	{
		mPosition %= 36;
		mMotivation += 250;

		//cout << mAssessments[mYear - 1].size( ) << endl;

		if ( mAssessments[mYear - 1].size( ) >= 3 )
		{
			mYear += 1;
		}
		return true;
	}
	return false;
}

int CPlayer::GetPosition( )
{
	return mPosition;
}

void CPlayer::SetPosition( int position )
{
	mPosition = position;
}

int CPlayer::GetYear( )
{
	return mYear;
}

int CPlayer::GetMotivation( )
{
	return mMotivation;
}

int CPlayer::GetScore( )
{
	return mSuccess;
}

void CPlayer::UpdateMotivation( int delta )
{
	mMotivation += delta;
}

void CPlayer::UpdateSuccess( int gamma )
{
	mSuccess += gamma;

	if ( mSuccess < 0 )
	{
		mSuccess = 0;
	}
}

void CPlayer::AddCompletedAssessment( int year , string name )
{
	mAssessments[year - 1].insert( name );
}