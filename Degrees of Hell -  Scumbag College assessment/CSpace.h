#pragma once
#include <iostream>
#include <string>
#include "CPlayer.h"
using namespace std;

/**
 * @brief CSpace class represents a space on the game board.
 *
 * Detailed description if needed.
 */
class CSpace
{
private:
    string mName; /**< Name of the space. */

public:
    /**
     * @brief Constructor for CSpace class.
     *
     * @param[in] name Name of the space.
     * @return No return value.
     */
    CSpace(string name);

    /**
     * @brief Virtual function to handle the action when a player lands on this space.
     *
     * @param[in] player Player landing on the space.
     * @return No return value.
     */
    virtual void Print(shared_ptr<CPlayer> player);

    /**
     * @brief Gets the name of the space.
     *
     * @return The name of the space.
     */
    string GetName();
};
