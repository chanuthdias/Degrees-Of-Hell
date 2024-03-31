#pragma once
#include <string>
using namespace std;

class Bogus 
{
public:
    string mName;
    int mMotivataionLoss;
    Bogus( string name , int gain ) :mName( name ), mMotivataionLoss( gain ) 
    {
    }
};