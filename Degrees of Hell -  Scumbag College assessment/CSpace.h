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
		virtual void Print(shared_ptr<CPlayer> player);
		string GetName();
};


