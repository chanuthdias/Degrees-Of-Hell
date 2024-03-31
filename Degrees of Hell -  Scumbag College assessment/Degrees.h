#pragma once
#include "CSpace.h"
#include "CPlayer.h"
#include "Types.h"
using namespace std;

class Degrees
{
	private:
		spacesVectorType mpSpaces;
		playerVectorType mpPlayers;

	public:
		bool ReadSpacesFormFile( string path );
		void GameStart( int rounds );
		void AddPlayer( string name );
		void GameOver( );
};