#include <iostream>
#include <string>
#include "Degrees.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;

int main( )
{
    Degrees game;
    game.AddPlayer( "Vyvyan" );
    game.AddPlayer( "Rick" );
    game.AddPlayer( "Neil" );
    game.AddPlayer( "Mike" );
    game.GameStart( 50 );

    // for memory leak detection
    //int *a = new int (5);

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

