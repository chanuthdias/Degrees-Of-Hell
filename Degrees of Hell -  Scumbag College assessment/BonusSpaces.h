#pragma once
#include "CSpace.h"
#include "Bonus.h"
#include <vector>

/**
 * @brief CBonusSpaces class represents spaces containing bonus entities in the game.
 *
 * Detailed description if needed.
 */
class BonusSpaces :
    public CSpace
{
private:
    typedef vector<Bonus> BonusListType; /**< Type definition for a list of bonus entities. */
    BonusListType mBonusList; /**< List of bonus entities. */

public:
    /**
     * @brief Constructor for CBonusSpaces class.
     *
     * @param[in] name Name of the bonus space.
     * @return No return value.
     */
    BonusSpaces(string name);

    /**
     * @brief Handles the action when a player lands on this space.
     *
     * @param[in] player Player landing on the space.
     * @return No return value.
     */
    void Print(shared_ptr<CPlayer> player) override;
};
