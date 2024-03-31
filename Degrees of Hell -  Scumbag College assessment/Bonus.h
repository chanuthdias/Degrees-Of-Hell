#pragma once
#include <string>
using namespace std;

class Bonus 
{
public:
    string mName;
    int mMotivataionGain;
    Bonus( string name , int gain ) :mName( name ), mMotivataionGain( gain ) 
    {
    }
};