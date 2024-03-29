#pragma once
#include <iostream>
#include <string>
#include <set>
using namespace std;

class CPlayer
{
	private:
		string name;
		int motivation;
		int success;
		int position;
		int year;
		typedef set<string> stringSetType;
		stringSetType Assessments[3];

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
		void AddCompletedAssessment(int year, string name);
};

