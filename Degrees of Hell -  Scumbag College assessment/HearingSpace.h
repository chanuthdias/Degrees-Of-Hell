#pragma once
#include "CSpace.h"
#include "CPlayer.h"

/**
 * @brief CHearingSpace class represents a space for hearings in the game.
 *
 * Detailed description if needed.
 */
class HearingSpace :
    public CSpace
{
public:
    /**
     * @brief Handles the action when a player lands on this space.
     *
     * @param[in] player Player landing on the space.
     * @return No return value.
     */
    void Print(shared_ptr<CPlayer> player) override;

    /**
     * @brief Constructor for CHearingSpace class.
     *
     * @param[in] name Name of the hearing space.
     * @return No return value.
     */
    HearingSpace(string name);
};
