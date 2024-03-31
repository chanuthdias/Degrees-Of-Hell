#pragma once
#include "CSpace.h"
#include "Types.h"

/**
 * @brief CExtraCurricularspaces class represents extra-curricular spaces in the game.
 *
 * Detailed description if needed.
 */
class ExtraCurricularSpaces :
    public CSpace
{
private:
    int mCost; /**< Cost associated with the extra-curricular space. */
    playerVectorType mCompletedPlayers; /**< List of players who have completed the assignment. */

public:
    /**
     * @brief Constructor for CExtraCurricularspaces class.
     *
     * @param[in] name Name of the extra-curricular space.
     * @param[in] motivationalCost Motivational cost associated with the space.
     * @return No return value.
     */
    ExtraCurricularSpaces(string name, int motivationalCost);

    /**
     * @brief Checks if the extra-curricular activity is completed.
     *
     * @return True if completed, False otherwise.
     */
    bool IsCompleted();

    /**
    * @brief Checks if the assessment is completed by a specific player.
    *
    * @param[in] player The player to check completion for.
    * @return True if completed by the player, False otherwise.
    */
    bool IsCompleted(shared_ptr < CPlayer > player);

    /**
    * @brief Gets the list of players who have completed the assessment.
    *
    * @return List of completed players.
    */
    playerVectorType CompletedBy();

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
