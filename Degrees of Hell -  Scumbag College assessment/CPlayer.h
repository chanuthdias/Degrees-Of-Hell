#pragma once
#include <iostream>
#include <string>
#include <set>
using namespace std;

class CPlayer
{
	private:
		string mName;
		int mMotivation;
		int mSuccess;
		int mPosition;
		int mYear;
		typedef set<string> stringSetType;
		stringSetType mAssessments[3];

	public:
		CPlayer( string name );
		string GetName( );
		bool Move( int spin );
		int GetPosition( );
		void SetPosition(int position);
		int GetYear( );
		int GetMotivation( );
		int GetScore( );
		void UpdateMotivation( int delta );
		void UpdateSuccess( int gamma );
		void AddCompletedAssessment( int year , string name );
};