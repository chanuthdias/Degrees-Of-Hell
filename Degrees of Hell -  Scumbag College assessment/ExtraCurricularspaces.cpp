#include "ExtraCurricularSpaces.h"
#include "Constants.h"

ExtraCurricularSpaces::ExtraCurricularSpaces( string name, int motivationalCost ) :CSpace( name ), mCost( motivationalCost )
{
}

void ExtraCurricularSpaces::Print( shared_ptr<CPlayer> player )
{
    CSpace::Print( player );

    if ( IsCompleted( ) )
    {
        if (!IsCompleted(player))
        {
            if ( player->GetMotivation( ) >= GetMotivationCost( )/2 ) 
            {
                SetComplete(player);

                int totalNumberCompleted = CompletedBy().size();
                int successPotion = floor(kExtraCurricularSuccess / float(totalNumberCompleted));

                player->UpdateMotivation( -GetMotivationCost() / 2 );
                cout << player->GetName() << " undertakes " << GetName() << " activity for " << GetMotivationCost() / 2 << " and achieves " << successPotion << endl;
                player->UpdateSuccess( successPotion );

                for (int i = 0; i < totalNumberCompleted - 1; i++)
                {
                    CompletedBy()[i]->UpdateSuccess(successPotion);
                    cout << player->GetName() << " motivates " << CompletedBy()[i]->GetName() << " by 50 joining their activity" << endl;
                    cout << " ..." << CompletedBy()[i]->GetName() << " helps and achieves " << successPotion << endl;
                    CompletedBy()[i]->UpdateMotivation(GetMotivationCost() / 2);

                }
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

bool ExtraCurricularSpaces::IsCompleted()
{
    if (mCompletedPlayers.size() > 0)
        return true;
    return false;
}

bool ExtraCurricularSpaces::IsCompleted(shared_ptr<CPlayer> player)
{
    for (int i = 0; i < mCompletedPlayers.size(); i++)
    {
        if (mCompletedPlayers[i]->GetName() == player->GetName())
        {
            return true;
        }
    }
    return false;
}

playerVectorType ExtraCurricularSpaces::CompletedBy()
{
    return mCompletedPlayers;
}

int ExtraCurricularSpaces::GetMotivationCost( )
{
    return mCost;
}

void ExtraCurricularSpaces::SetComplete( shared_ptr<CPlayer> player )
{
    mCompletedPlayers.push_back(player);
}