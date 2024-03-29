#pragma once
#include "CSpace.h"
#include "CPlayer.h"
#include <vector>
using namespace std;

class Degrees
{
	private:
		typedef vector<shared_ptr<CSpace>> spacesVectorType;
		spacesVectorType pSpaces;
		typedef vector<shared_ptr<CPlayer>>playerVectorType;
		playerVectorType pPlayers;

	public:
		bool ReadSpacesFormFile(string path);
		void GameStart(int rounds);
		void AddPlayer(string name);
		void GameOver();
		
};


