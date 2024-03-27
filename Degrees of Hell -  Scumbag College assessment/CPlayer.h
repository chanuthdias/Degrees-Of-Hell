#pragma once
#include <iostream>
#include <string>
using namespace std;

class CPlayer
{
	private:
		string name;
		int motivation;
		int success;
		int position;
		int year;

	public:
		CPlayer(string name);
		string GetName();
		bool Move(int spin);
		int GetPosition();
		int GetYear();
		int GetMotivation();
		int GetScore();
		void UpdateMotivation(int delta);
		void UpdateSuccess(int gamma);
};

