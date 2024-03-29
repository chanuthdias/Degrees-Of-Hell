#pragma once
#include "CSpace.h"
#include "CPlayer.h"
#include <vector>
using namespace std;

class Degrees
{
	private:
		typedef vector<CSpace*> spacesVectorType;
		spacesVectorType pSpaces;
		typedef vector<CPlayer*>playerVectorType;
		playerVectorType pPlayers;

	public:
		bool ReadSpacesFormFile(string path);
		void GameStart(int rounds);
		void AddPlayer(string name);
		void GameOver();
		~Degrees();
		
};


