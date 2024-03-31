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

bool Degrees::ReadSpacesFormFile( string path )
{
    string line;
    int hearingSpaceIndex = 0;
    int accusedOfPlagiarismIndex = 0;
    
    ifstream file( path );

    if ( !file.is_open( ) ) 
    {
        cerr << "Error opening the file." << std::endl;
        return false;
    }

    while ( getline ( file , line ) ) 
    {
        string token;
        istringstream iss( line );
        
        iss >> token;

        switch ( stoi ( token ) )
        {
            case 1: 
            {
                string assessmentType;
                iss >> token;
                assessmentType = token;
                iss >> token;
                assessmentType += " " + token;
                iss >> token;
                int motivationalCost = stoi( token );
                iss >> token;
                int successScore = stoi( token );
                iss >> token;
                int year = stoi( token );

                auto pNewAssessment = make_shared<Assessment> ( assessmentType , motivationalCost , successScore , year );
                mpSpaces.push_back( pNewAssessment );

                break;
            }
            case 2: 
            {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                auto pCSpace = make_shared<CSpace> ( name );
                mpSpaces.push_back( pCSpace );

                break;
            }
            case 3: 
            {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;
                iss >> token;
                int motivationalCost = stoi( token );

                auto pCSpace = make_shared<CExtraCurricularspaces> ( name , motivationalCost );
                mpSpaces.push_back( pCSpace );

                break;
            }
            case 4: 
            {
                iss >> token;

                auto pCSpace = make_shared<CBonusSpaces> ( token );
                mpSpaces.push_back( pCSpace );

                break;
            }
            case 5: 
            {
                iss >> token;

                auto pCSpace = make_shared<CBogusSpaces> ( token );
                mpSpaces.push_back( pCSpace );

                break;
            }
            case 6: 
            {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                auto pCSpace = make_shared<CHearingSpace> ( name );
                mpSpaces.push_back( pCSpace );
                hearingSpaceIndex = mpSpaces.size( ) - 1;

                break;
            }
            case 7: 
            {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                auto pCSpace = make_shared<CAccusedOfPlagiarism> ( name );
                mpSpaces.push_back( pCSpace );
                accusedOfPlagiarismIndex = mpSpaces.size() - 1;

                break;
            }
            case 8: 
            {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                auto pCSpace = make_shared<CSkipClassesSpace> ( name );
                mpSpaces.push_back( pCSpace );

                break;
            }
            default: 
            {
                iss >> token;
                string name = token;
                iss >> token;
                name += " " + token;

                auto pCSpace = make_shared<CSpace> ( name );
                mpSpaces.push_back( pCSpace );
                break;
            }    
        }
    }
    (static_pointer_cast <CAccusedOfPlagiarism> (mpSpaces[accusedOfPlagiarismIndex]))->SetHearingSpaceIndex(hearingSpaceIndex);
    return true;
}

void Degrees::GameStart( int rounds )
{
    if (!ReadSpacesFormFile("degrees.txt")) 
    {
        return;
    }

    RandomNumberGenerator::SetSeed( );

    cout << "Welcome to Scumbag College" << endl;

    for ( int i = 0; i < rounds; i++ )
    {
        cout << endl << "ROUND " << i+1 << endl;
        cout << "=========" << endl;

        for ( int j = 0; j < mpPlayers.size( ); j++ )
        {
            int r = RandomNumberGenerator::Random( );
            cout << mpPlayers[j]->GetName( ) << " spins " << r << endl;
            int previousYear = mpPlayers[j]->GetYear( );

            if ( mpPlayers[j]->Move( r ) > 0 )
            {
                if ( mpPlayers[j]->GetYear( ) == 4 ) 
                {
                    cout << mpPlayers[j]->GetName() << " has successfully completed Year " << mpPlayers[j]->GetYear() - 1 << endl;
                    cout << "congratulating on your graduation." << endl;
                    GameOver( );
                    return;
                }
                else 
                {
                    if ( previousYear != mpPlayers[j]->GetYear( ) )
                    {
                        cout << mpPlayers[j]->GetName() << " has successfully completed Year " << mpPlayers[j]->GetYear() - 1 << endl;
                        cout << mpPlayers[j]->GetName(  ) << " attends Welcome Week and starts Year " << mpPlayers[j]->GetYear( ) << " more motivated! " << endl;
                    }
                    else 
                    {
                        cout << mpPlayers[j]->GetName( ) << " attends Welcome Week and starts Year " << mpPlayers[j]->GetYear( ) << " again " << endl;
                    }
                }
            }

            mpSpaces[mpPlayers[j]->GetPosition( )]->Print( mpPlayers[j] );

            cout << mpPlayers[j]->GetName( ) << "'s motivation is " << mpPlayers[j]->GetMotivation( ) << " and success is " << mpPlayers[j]->GetScore( ) << endl << endl;
        }
    }
    GameOver( );
}

void Degrees::AddPlayer( string name ) 
{
    auto pNewPlayer = make_shared<CPlayer> ( name );
    mpPlayers.push_back( pNewPlayer );
}

void Degrees::GameOver( )
{
    int winner = 0;
    int maxScore = -1;

    cout << endl << "Game Over" << endl;
    cout << "=========" << endl;

    for ( int i = 0; i < mpPlayers.size( ); i++ )
    {
        cout << mpPlayers[i]->GetName( ) << " has achieved " << mpPlayers[i]->GetScore( ) << endl;

        if ( maxScore < mpPlayers[i]->GetScore( ) )
        {
            maxScore = mpPlayers[i]->GetScore( );
            winner = i;
        }
    }
    cout << endl << mpPlayers[winner]->GetName( ) << " wins! " << endl;
}