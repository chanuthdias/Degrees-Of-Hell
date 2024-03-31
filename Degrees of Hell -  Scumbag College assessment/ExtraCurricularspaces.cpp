#include "ExtraCurricularspaces.h"
#include "Constants.h"


ExtraCurricularspaces::ExtraCurricularspaces( string name, int motivationalCost ) :CSpace( name ), mCost( motivationalCost )
{
}

void ExtraCurricularspaces::Print( shared_ptr<CPlayer> player )
{
    CSpace::Print( player );

    if ( IsCompleted( ) )
    {
        if ( CompletedBy( )->GetName( ) != player->GetName( ) )
        {
            if ( player->GetMotivation( ) >= GetMotivationCost( )/2 ) 
            {
                player->UpdateMotivation( -GetMotivationCost() / 2 );
                player->UpdateSuccess(kExtraCurricularSuccess/2);
                CompletedBy( )->UpdateSuccess(kExtraCurricularSuccess/2);
                CompletedBy( )->UpdateMotivation( GetMotivationCost( ) / 2 );
                cout << player->GetName( ) << " motivates " << CompletedBy( )->GetName( ) << " by joining their activity" << endl;
            }
            else 
            {
                cout << player->GetName( ) << " doesn't have the " << GetMotivationCost( ) / 2 << " motivation to complete the " << GetName( ) << endl;
            }
        }
    }
    else
    {
        if ( player->GetMotivation( ) >= GetMotivationCost( ) )
        {
            player->UpdateMotivation( -GetMotivationCost( ) );
            player->UpdateSuccess(kExtraCurricularSuccess);
            SetComplete( player );
            cout << player->GetName( ) << " undertakes " << GetName( ) << " activity for " << GetMotivationCost( ) << " and achieves 20" << endl;   
        }
        else 
        {
            cout << player->GetName( ) << " doesn't have the " << GetMotivationCost( ) << " motivation to complete the " << GetName( ) << endl;
        }
    }
}

bool ExtraCurricularspaces::IsCompleted( )
{
    if ( mCompletedByPlayer != nullptr )
        return true;
    return false;
}

shared_ptr<CPlayer> ExtraCurricularspaces::CompletedBy( )
{
    return mCompletedByPlayer;
}

int ExtraCurricularspaces::GetMotivationCost( )
{
    return mCost;
}

void ExtraCurricularspaces::SetComplete( shared_ptr<CPlayer> player )
{
    mCompletedByPlayer = player;
}