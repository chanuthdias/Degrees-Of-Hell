#pragma once
#include "CSpace.h"
#include "CPlayer.h"
#include <vector>
using namespace std;

class GameManager
{
	private:
		vector<CSpace*> pSpaces;
		vector<CPlayer*>pPlayers;

	public:
		bool ReadSpacesFormFile(string path);
		void GameStart(int rounds);
		void AddPlayer(string name);
		void GameOver();
		~GameManager();
		
};


