#include <iostream>
#include "Assessment.h"

Assessment::Assessment( string assessmentType , int motivationalCost , int successScore , int year ) : CSpace( assessmentType ) , mYear( year ) , mCost( motivationalCost )
{
	mSuccess = successScore;
}

void Assessment::Print( shared_ptr<CPlayer> player )
{
    CSpace::Print( player );

    if ( IsCompleted ( ) )
    {
        if ( !IsCompleted( player ) )
        {
            if ( player->GetMotivation( ) >= GetMotivationCost( ) / 2 )
            {
                SetComplete(player);

                int totalNumberCompleted = CompletedBy().size();

                player->UpdateMotivation( -GetMotivationCost( ) / 2 );
                
                int successPotion = floor(GetSuccessScore() / float(totalNumberCompleted));
                
                cout << player->GetName() << " completes " << GetName() << " for " << GetMotivationCost() / 2 << " and achieves " << successPotion << endl;

                for ( int i = 0; i < totalNumberCompleted; i++ )
                {
                    CompletedBy( )[i]->UpdateSuccess( successPotion );
                    if (i != totalNumberCompleted - 1) 
                    {
                        cout << " ..." << CompletedBy()[i]->GetName() << " helps and achieves " << successPotion << endl;
                    }
                }

                player->AddCompletedAssessment( mYear , GetName( ) );
            }
            else 
            {
                cout << player->GetName( ) << " doesn't have the " << GetMotivationCost( ) / 2 << " motivation to complete the " << GetName( ) << endl;
            }
        }
        else 
        {
            cout << player->GetName( ) << " has already completed the " << GetName( ) << endl;
        }
    }
    else
    {
        if ( player->GetMotivation( ) >= GetMotivationCost( ) )
        {
            player->UpdateMotivation( -GetMotivationCost( ) );
            player->UpdateSuccess( GetSuccessScore( ) );

            cout << player->GetName( ) << " completes " << GetName( ) << " for " << GetMotivationCost( ) << " and achieves " << GetSuccessScore( ) << endl;
            
            SetComplete( player );

            player->AddCompletedAssessment( mYear , GetName( ) );
        }
        else 
        {
            cout << player->GetName( ) << " doesn't have the " << GetMotivationCost( ) << " motivation to complete the " << GetName( ) << endl;

        }
    }
}

int Assessment::GetSuccessScore( )
{
	return mSuccess;
}

int Assessment::GetYear( )
{
    return mYear;
}

bool Assessment::IsCompleted( )
{
    if ( mCompletedPlayers.size( ) > 0 )
        return true;
    return false;
}

bool Assessment::IsCompleted( shared_ptr<CPlayer> player )
{
    for ( int i = 0; i < mCompletedPlayers.size( ); i++ )
    {
        if( mCompletedPlayers[i]->GetName( ) == player->GetName( ) )
        {
            return true;
        }
    }
    return false;
}

playerVectorType Assessment::CompletedBy( )
{
    return mCompletedPlayers;
}

int Assessment::GetMotivationCost( )
{
    return mCost;
}

void Assessment::SetComplete( shared_ptr<CPlayer> player )
{
    mCompletedPlayers.push_back( player );
}