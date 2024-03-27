#pragma once
#include <iostream>
#include <string>
#include "CPlayer.h"
using namespace std;

enum SpaceTypes
{
	space,
	assessment,
	hearingSpace,
	accusedOfPlagiarism,
	skipClassesSpace,
	extraCurricularspaces,

};

class CSpace
{
	private:
		string name;
		SpaceTypes type;
	public:
		CSpace(string name, SpaceTypes type);
		virtual void Print(CPlayer *player);
		string GetName();
		SpaceTypes GetType();
};


