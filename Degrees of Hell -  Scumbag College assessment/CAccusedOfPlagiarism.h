#pragma once
#include "CSpace.h"
#include "CPlayer.h"
class CAccusedOfPlagiarism :
    public CSpace
{
public:
    void Print(CPlayer *player)override;
    CAccusedOfPlagiarism(string name, SpaceTypes type);
};

