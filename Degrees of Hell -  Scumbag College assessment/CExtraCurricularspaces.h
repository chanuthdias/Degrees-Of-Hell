#pragma once
#include "CSpace.h"

/**
 * @brief CExtraCurricularspaces class represents extra-curricular spaces in the game.
 *
 * Detailed description if needed.
 */
class CExtraCurricularspaces :
    public CSpace
{
private:
    int mCost; /**< Cost associated with the extra-curricular space. */
    shared_ptr<CPlayer> mCompletedByPlayer = nullptr; /**< Player who completed the extra-curricular activity. */

public:
    /**
     * @brief Constructor for CExtraCurricularspaces class.
     *
     * @param[in] name Name of the extra-curricular space.
     * @param[in] motivationalCost Motivational cost associated with the space.
     * @return No return value.
     */
    CExtraCurricularspaces(string name, int motivationalCost);

    /**
     * @brief Checks if the extra-curricular activity is completed.
     *
     * @return True if completed, False otherwise.
     */
    bool IsCompleted();

    /**
     * @brief Gets the player who completed the extra-curricular activity.
     *
     * @return Pointer to the player who completed the activity.
     */
    shared_ptr<CPlayer> CompletedBy();

    /**
     * @brief Gets the motivational cost of the extra-curricular activity.
     *
     * @return The motivational cost.
     */
    int GetMotivationCost();

    /**
     * @brief Sets the extra-curricular activity as completed by a player.
     *
     * @param[in] player Player who completed the activity.
     * @return No return value.
     */
    void SetComplete(shared_ptr<CPlayer> player);

    /**
     * @brief Handles the action when a player lands on this space.
     *
     * @param[in] player Player landing on the space.
     * @return No return value.
     */
    void Print(shared_ptr<CPlayer> player) override;
};
