#include <iostream>
#include <string>
#include "Degrees.h"
using namespace std;

int main()
{
    Degrees game;
    game.AddPlayer("Vyvyan");
    game.AddPlayer("Rick");
    game.GameStart(60);
}
