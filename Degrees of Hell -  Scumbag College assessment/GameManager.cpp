#include "GameManager.h"
#include "Assessment.h"
#include "RandomNumberGenerator.h"
#include "CPlayer.h"
#include "CHearingSpace.h"
#include "CSkipClassesSpace.h"
#include "CAccusedOfPlagiarism.h"
#include <fstream>
#include <string>
#include <sstream>
#include "CExtraCurricularspaces.cpp"


using namespace std;

void GameManager::ReadSpacesFormFile(string path) 
{
    string line;
    
    ifstream file(path);

    if (!file.is_open()) {
        cerr << "Error opening the file." << std::endl;
        return;
    }

    while (getline(file, line)) {

        string token;
        istringstream iss(line);

        //cout << line << endl;

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

                CSpace* pCSpace = new CSpace(name,SpaceTypes::space);
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

                CExtraCurricularspaces* pCSpace = new CExtraCurricularspaces(name, SpaceTypes::hearingSpace, motivationalCost);
                pSpaces.push_back(pCSpace);

                break;
            }
            case 6: {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                CHearingSpace* pCSpace = new CHearingSpace(name, SpaceTypes::hearingSpace);
                pSpaces.push_back(pCSpace);

                break;

            }
            case 7: {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                CAccusedOfPlagiarism* pCSpace = new CAccusedOfPlagiarism(name, SpaceTypes::accusedOfPlagiarism);
                pSpaces.push_back(pCSpace);

                break;

            }
            case 8: {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                CSkipClassesSpace* pCSpace = new CSkipClassesSpace(name, SpaceTypes::skipClassesSpace);
                pSpaces.push_back(pCSpace);

                break;

            }

            default: {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                CSpace* pCSpace = new CSpace(name, SpaceTypes::space);
                pSpaces.push_back(pCSpace);
                break;
            }
                
        }
    }
}

void GameManager::GameStart(int rounds)
{
	ReadSpacesFormFile("degrees.txt");

    /*for (int i = 0; i < pSpaces.size(); i++)
    {
        pSpaces[i] -> Print();
    }*/

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
                cout << pPlayers[j]->GetName() << " attends Welcome Week and starts year " << pPlayers[j]->GetYear() << " more motivated! " << endl;
            }

            pSpaces[pPlayers[j]->GetPosition()]->Print(pPlayers[j]);

            ProcessAssessment(j, pPlayers[j]->GetPosition());

            cout << pPlayers[j]->GetName() << " motivation is " << pPlayers[j]->GetMotivation() << " and success is " << pPlayers[j]->GetScore() << endl;
        }
    }

    GameOver();
}

void GameManager::AddPlayer(string name) 
{
    CPlayer* pNewPlayer = new CPlayer(name);
    pPlayers.push_back(pNewPlayer);
}

void GameManager::ProcessAssessment(int player, int space) 
{
    if (pSpaces[space]->GetType() == SpaceTypes::assessment)
    {
        Assessment* pAsmt = (Assessment*)pSpaces[space];
        if (pAsmt->IsCompleted())
        {
            if (pAsmt->CompletedBy() != player)
            {
                pPlayers[player]->UpdateMotivation(-pAsmt->GetMotivationCost()/2);
                pPlayers[player]->UpdateSuccess(pAsmt->GetSuccessScore()/2);
                pPlayers[pAsmt->CompletedBy()]->UpdateSuccess(pAsmt->GetSuccessScore() / 2);
                cout << pPlayers[player]->GetName() << " helps and achieves " << pAsmt->GetSuccessScore() << endl;
            }
        }
        else
        {
            if (pPlayers[player]->GetMotivation() >= pAsmt->GetMotivationCost())
            {
                pPlayers[player]->UpdateMotivation(-pAsmt->GetMotivationCost());
                pPlayers[player]->UpdateSuccess(pAsmt->GetSuccessScore());

                cout << pPlayers[player]->GetName() << " completes " << pAsmt->GetName() << " for " << pAsmt->GetMotivationCost() << " and achieve's " << pAsmt->GetSuccessScore() << endl;
                
                pAsmt->SetComplete(player);
            }
        }
    }
}

void GameManager::ProcessExtraCurricularActivities(int player, int space)
{
    if (pSpaces[space]->GetType() == SpaceTypes::extraCurricularspaces)
    {
        CExtraCurricularspaces* pEcur = (CExtraCurricularspaces*)pSpaces[space];
        if (pEcur->IsCompleted())
        {
            if (pEcur->CompletedBy() != player)
            {
                pPlayers[player]->UpdateMotivation(-pEcur->GetMotivationCost() / 2);
                pPlayers[pEcur->CompletedBy()]->UpdateMotivation(pEcur->GetMotivationCost());
                cout << pPlayers[player]->GetName() << " motivates " << pPlayers[pEcur->CompletedBy()]->GetName() << " by joining their activity" << endl;
            } 
        }
        else
        {
            if (pPlayers[player]->GetMotivation() >= pEcur->GetMotivationCost())
            {
                pPlayers[player]->UpdateMotivation(-pEcur->GetMotivationCost());
                pEcur->SetComplete(player);
            }
        }
    }
}

void GameManager::GameOver()
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