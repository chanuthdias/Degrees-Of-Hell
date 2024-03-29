#include "Degrees.h"
#include "Assessment.h"
#include "RandomNumberGenerator.h"
#include "CPlayer.h"
#include "CHearingSpace.h"
#include "CSkipClassesSpace.h"
#include "CAccusedOfPlagiarism.h"
#include "CExtraCurricularspaces.h"
#include "CBonusSpaces.h"
#include <fstream>
#include <string>
#include <sstream>
#include "CBogusSpaces.h"

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

                Assessment* pNewAssessment = new Assessment(assessmentType, motivationalCost, successScore, year);
                pSpaces.push_back(pNewAssessment);

                break;
            }
            case 2: {

                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                CSpace* pCSpace = new CSpace(name);
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

                CExtraCurricularspaces* pCSpace = new CExtraCurricularspaces(name, motivationalCost);
                pSpaces.push_back(pCSpace);

                break;
            }
            case 4: {
                iss >> token;

                CBonusSpaces* pCSpace = new CBonusSpaces(token);
                pSpaces.push_back(pCSpace);

                break;

            }
            case 5: {
                iss >> token;

                CBogusSpaces* pCSpace = new CBogusSpaces(token);
                pSpaces.push_back(pCSpace);

                break;

            }
            case 6: {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                CHearingSpace* pCSpace = new CHearingSpace(name);
                pSpaces.push_back(pCSpace);

                break;

            }
            case 7: {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                CAccusedOfPlagiarism* pCSpace = new CAccusedOfPlagiarism(name);
                pSpaces.push_back(pCSpace);

                break;

            }
            case 8: {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                CSkipClassesSpace* pCSpace = new CSkipClassesSpace(name);
                pSpaces.push_back(pCSpace);

                break;

            }
            default: {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                CSpace* pCSpace = new CSpace(name);
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
    CPlayer* pNewPlayer = new CPlayer(name);
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

Degrees::~Degrees() {
    for (int i = 0; i < pPlayers.size(); i++)
    {
        delete pPlayers[i];
    }

    for (int i = 0; i < pSpaces.size(); i++)
    {
        delete pSpaces[i];
    }
}
