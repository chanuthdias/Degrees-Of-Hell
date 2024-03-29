#include "CBonusSpaces.h"
#include "RandomNumberGenerator.h"

CBonusSpaces::CBonusSpaces(string name):CSpace(name)
{
	BonusList.push_back(Bonus("Receive some useful feedback.", 20));
	BonusList.push_back(Bonus("Win a hackathon.", 50));
	BonusList.push_back(Bonus("Get a free coffee with full loyalty card.", 80));
	BonusList.push_back(Bonus("Impress your lecturer in class.", 100));
	BonusList.push_back(Bonus("Motivational talk from course leader", 5));
	BonusList.push_back(Bonus("Secure an industry placement", 150));
	BonusList.push_back(Bonus("Attend an inspiring C++ lecture.", 200));
	BonusList.push_back(Bonus("Get your best ever assignment mark", 300));
	BonusList.push_back(Bonus("Make a new romantic friend", 150));
	BonusList.push_back(Bonus("Get elected School President", 10));
}

void CBonusSpaces::Print(shared_ptr<CPlayer> player)
{
	int r = RandomNumberGenerator::Random()%10;

	player->UpdateMotivation(BonusList[r].motivataionGain);

	cout << player->GetName() << " lands on Bonus" << endl;
	cout << BonusList[r].name << " Gain motivation of " << BonusList[r].motivataionGain << endl;
	cout << player->GetName() << " has " << player->GetMotivation() << endl;
}
