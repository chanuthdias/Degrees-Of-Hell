#pragma once
#include <iostream>
#include <string>
#include "CPlayer.h"
using namespace std;

class CSpace
{
	private:
		string name;
		
	public:
		CSpace(string name);
		virtual void Print(CPlayer *player);
		string GetName();
};


