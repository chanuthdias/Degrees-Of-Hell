#include "CPlayer.h"

CPlayer::CPlayer(string name):name(name)
{

	motivation = 1000;
	success = 0;
	position = 0;
	year = 1;
}

string CPlayer::GetName()
{
	return name;
}

bool CPlayer::Move(int spin)
{
	position = (position + spin);
	if (position >= 36)
	{
		position %= 36;
		motivation += 250;

		cout << Assessments[year - 1].size() << endl;

		if (Assessments[year - 1].size() >= 3)
		{
			year += 1;
		}
		return true;
	}
	return false;
}

int CPlayer::GetPosition()
{
	return position;
}

int CPlayer::GetYear()
{
	return year;
}

int CPlayer::GetMotivation()
{
	return motivation;
}

int CPlayer::GetScore()
{
	return success;
}

void CPlayer::UpdateMotivation(int delta)
{
	motivation += delta;
}

void CPlayer::UpdateSuccess(int gamma)
{
	success += gamma;

	if (success < 0)
	{
		success = 0;
	}
}

void CPlayer::AddCompletedAssessment(int year, string name)
{
	Assessments[year - 1].insert(name);
}

