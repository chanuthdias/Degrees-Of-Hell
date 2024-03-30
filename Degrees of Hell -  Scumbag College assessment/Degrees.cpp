#include "Degrees.h"
#include "Assessment.h"
#include "RandomNumberGenerator.h"
#include "CPlayer.h"
#include "CHearingSpace.h"
#include "CSkipClassesSpace.h"
#include "CAccusedOfPlagiarism.h"
#include "CExtraCurricularspaces.h"
#include <fstream>
#include <string>
#include <sstream>
#include "CBogusSpaces.h"
#include "CBonusSpaces.h"

using namespace std;

bool Degrees::ReadSpacesFormFile(string path)
{
    string line;
    
    ifstream file(path);

    if (!file.is_open()) {
        cerr << "Error opening the file." << std::endl;
        return false;
    }

    while (getline(file, line)) {

        string token;
        istringstream iss(line);
        
        iss >> token;

        switch (stoi(token))
        {
            case 1: {

                string assessmentType;
                iss >> token;
                assessmentType = token;
                iss >> token;
                assessmentType += " " + token;
                iss >> token;
                int motivationalCost = stoi(token);
                iss >> token;
                int successScore = stoi(token);
                iss >> token;
                int year = stoi(token);

                auto pNewAssessment = make_shared<Assessment> (assessmentType, motivationalCost, successScore, year);
                pSpaces.push_back(pNewAssessment);

                break;
            }
            case 2: {

                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                auto pCSpace = make_shared<CSpace> (name);
                pSpaces.push_back(pCSpace);

                break;
            }
            case 3: {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;
                iss >> token;
                int motivationalCost = stoi(token);

                auto pCSpace = make_shared<CExtraCurricularspaces> (name, motivationalCost);
                pSpaces.push_back(pCSpace);

                break;
            }
            case 4: {
                iss >> token;

                auto pCSpace = make_shared<CBonusSpaces> (token);
                pSpaces.push_back(pCSpace);

                break;

            }
            case 5: {
                iss >> token;

                auto pCSpace = make_shared<CBogusSpaces> (token);
                pSpaces.push_back(pCSpace);

                break;

            }
            case 6: {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                auto pCSpace = make_shared<CHearingSpace> (name);
                pSpaces.push_back(pCSpace);

                break;

            }
            case 7: {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                auto pCSpace = make_shared<CAccusedOfPlagiarism> (name);
                pSpaces.push_back(pCSpace);

                break;

            }
            case 8: {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                auto pCSpace = make_shared<CSkipClassesSpace> (name);
                pSpaces.push_back(pCSpace);

                break;

            }
            default: {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                auto pCSpace = make_shared<CSpace> (name);
                pSpaces.push_back(pCSpace);
                break;
            }
                
        }
    }
    return true;
}

void Degrees::GameStart(int rounds)
{
	if(!ReadSpacesFormFile("degrees.txt"))
        return;

    RandomNumberGenerator::SetSeed();

    cout << "Welcome to Scumbag College" << endl << endl;

    for (int i = 0; i < rounds; i++)
    {
        cout << endl << "round " << i+1 << endl;

        for (int j = 0; j < pPlayers.size(); j++)
        {
            int r = RandomNumberGenerator::Random();
            cout << pPlayers[j]->GetName() << " spins " << r << endl;

            if (pPlayers[j]->Move(r))
            {
                if (pPlayers[j]->GetYear() == 4)
                {
                    cout << "congratulating on your graduation." << endl;
                    GameOver();
                    return;
                }
                cout << pPlayers[j]->GetName() << " attends Welcome Week and starts year " << pPlayers[j]->GetYear() << " more motivated! " << endl;
            }

            pSpaces[pPlayers[j]->GetPosition()]->Print(pPlayers[j]);

            cout << pPlayers[j]->GetName() << " motivation is " << pPlayers[j]->GetMotivation() << " and success is " << pPlayers[j]->GetScore() << endl;
        }
    }

    GameOver();
}

void Degrees::AddPlayer(string name) 
{
    auto pNewPlayer = make_shared<CPlayer> (name);
    pPlayers.push_back(pNewPlayer);
}

void Degrees::GameOver()
{
    int winner = 0;
    int maxScore = -1;

    cout << endl << "Game Over" << endl;

    for (int i = 0; i < pPlayers.size(); i++)
    {
        cout << pPlayers[i]->GetName() << " has achieved " << pPlayers[i]->GetScore() << endl;
        if (maxScore < pPlayers[i]->GetScore())
        {
            maxScore = pPlayers[i]->GetScore();
            winner = i;
        }
    }

    cout << pPlayers[winner]->GetName() << " wins. " << endl;
}

