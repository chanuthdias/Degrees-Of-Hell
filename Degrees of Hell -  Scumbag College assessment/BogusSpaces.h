#pragma once
#include "CSpace.h"
#include "Bogus.h"
#include <vector>

/**
 * @brief CBogusSpaces class represents spaces containing bogus entities in the game.
 *
 * Detailed description if needed.
 */
class BogusSpaces :
    public CSpace
{
private:
    typedef vector<Bogus> BogusListType; /**< Type definition for a list of bogus entities. */
    BogusListType mBogusList; /**< List of bogus entities. */

public:
    /**
     * @brief Constructor for CBogusSpaces class.
     *
     * @param[in] name Name of the bogus space.
     * @return No return value.
     */
    BogusSpaces(string name);

    /**
     * @brief Handles the action when a player lands on this space.
     *
     * @param[in] player Player landing on the space.
     * @return No return value.
     */
    void Print(shared_ptr<CPlayer> player) override;
};
