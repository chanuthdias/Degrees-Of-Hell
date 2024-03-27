#include "Assessment.h"
#include <iostream>
#include "Assessment.h"

Assessment::Assessment(string assessmentType, int motivationalCost, int successScore, int year) :CSpace(assessmentType, SpaceTypes::assessment), year(year)
{
	type = assessmentType;
	cost = motivationalCost;
	success = successScore;
	isCompleted = -1;
}

void Assessment::Print()
{
	//cout << "assessment = " << type << " cost = " << cost << " success = " << success << endl;

}

bool Assessment::IsCompleted()
{
	return isCompleted >= 0;
}

int Assessment::GetMotivationCost()
{
	return cost;
}

int Assessment::GetSuccessScore()
{
	return success;
}

void Assessment::SetComplete(int player)
{
	isCompleted = player;
}

int Assessment::CompletedBy()
{
	return isCompleted;
}


