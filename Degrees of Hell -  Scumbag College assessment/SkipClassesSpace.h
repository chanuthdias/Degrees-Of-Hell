#pragma once
#include "CSpace.h"
#include "CPlayer.h"

/**
 * @brief SkipClassesSpace class represents a space where a player can skip classes in the game.
 *
 * Detailed description if needed.
 */
class SkipClassesSpace :
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
     * @brief Constructor for SkipClassesSpace class.
     *
     * @param[in] name Name of the skip classes space.
     * @return No return value.
     */
    SkipClassesSpace(string name);
};
