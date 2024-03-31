#pragma once
#include "CSpace.h"
#include "CPlayer.h"
#include "Types.h"
using namespace std;

/**
 * @brief Degrees class manages the game environment and players.
 *
 * Detailed description if needed.
 */
class Degrees
{
private:
    spacesVectorType mpSpaces; /**< Vector of spaces in the game. */
    playerVectorType mpPlayers; /**< Vector of players in the game. */

public:
    /**
     * @brief Reads spaces from a file and initializes the game.
     *
     * @param[in] path Path to the file containing space information.
     * @return True if successful, False otherwise.
     */
    bool ReadSpacesFormFile(string path);

    /**
     * @brief Starts the game with a specified number of rounds.
     *
     * @param[in] rounds Number of rounds to play.
     * @return No return value.
     */
    void GameStart(int rounds);

    /**
     * @brief Adds a player to the game.
     *
     * @param[in] name Name of the player to add.
     * @return No return value.
     */
    void AddPlayer(string name);

    /**
     * @brief Ends the game.
     *
     * @return No return value.
     */
    void GameOver();
};
