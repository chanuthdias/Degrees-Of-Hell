#pragma once
#include "CSpace.h"
#include "CPlayer.h"
class CAccusedOfPlagiarism :
    public CSpace
{
public:
    void Print(shared_ptr<CPlayer> player)override;
    CAccusedOfPlagiarism(string name);
};

