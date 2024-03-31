#include <iostream>
#include <string>
#include "Degrees.h"
using namespace std;

int main( )
{
    Degrees game;
    game.AddPlayer( "Vyvyan" );
    game.AddPlayer( "Rick" );
    //game.AddPlayer( "Neil" );
    //game.AddPlayer( "Mike" );
    game.GameStart( 50 );
}