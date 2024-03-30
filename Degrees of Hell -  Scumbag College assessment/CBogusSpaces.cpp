#include "CBogusSpaces.h"
#include "RandomNumberGenerator.h"

CBogusSpaces::CBogusSpaces(string name):CSpace(name)
{
	BogusList.push_back(Bogus("Fall asleep in a boring lecture.", 20));
	BogusList.push_back(Bogus("Meet with coach about poor attendance.", 50));
	BogusList.push_back(Bogus("Feel really tired after a night out.", 80));
	BogusList.push_back(Bogus("Get kicked out of lab for messing about.", 100));
	BogusList.push_back(Bogus("Get dumped before a big night out.", 150));
	BogusList.push_back(Bogus("Fail an assignment.", 200));
	BogusList.push_back(Bogus("Get caught skipping class.", 50));
	BogusList.push_back(Bogus("Your friend drops out of uni.", 200));
	BogusList.push_back(Bogus("Nobody turns up to teach your class.", 300));
	BogusList.push_back(Bogus("Lecturer changes assignment schedule.", 20));
}

void CBogusSpaces::Print(shared_ptr<CPlayer> player)
{
	CSpace::Print(player);

	int r = RandomNumberGenerator::Random();
	player->UpdateMotivation(-BogusList[r - 1].motivataionLoss);
	
	cout << player->GetName() << " spins " << r << endl;
	cout << BogusList[r - 1].name << " Loss motivation of " << BogusList[r - 1].motivataionLoss << endl;
	cout << player->GetName() << " has " << player->GetMotivation() << endl;
}
