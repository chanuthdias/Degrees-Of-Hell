#include <iostream>
#include <string>
#include "GameManager.h"
using namespace std;

int main()
{
    GameManager game;
    game.AddPlayer("Vyvyan");
    game.AddPlayer("Rick");
    game.GameStart(20);
}
