#pragma once
#include "CSpace.h"

class CExtraCurricularspaces :
    public CSpace
{
private:
    int mCost;
    shared_ptr<CPlayer> mCompletedByPlayer = nullptr;

public:
    CExtraCurricularspaces( string name , int motivationalCost );
    bool IsCompleted( );
    shared_ptr<CPlayer> CompletedBy( );
    int GetMotivationCost( );
    void SetComplete( shared_ptr<CPlayer> player );
    void Print( shared_ptr<CPlayer> player ) override;
};