#pragma once
#include <iostream>
#include "CSpace.h"
#include "Types.h"

class Assessment :
    public CSpace
{
private: int mSuccess; /**< Score given per student upon completing the assignment. */
       int mYear; /**< Year level of the assessment. */
       int mCost; /**< Cost associated with the assessment. */
       playerVectorType mCompletedPlayers; /**< List of players who have completed the assignment. */

public:
    /**
     * @brief Constructor for Assessment class.
     *
     * @param[in] assessmentsType Type of assessment.
     * @param[in] motivationalCost Cost of motivation required for the assessment.
     * @param[in] successScore Score assigned upon completion of the assessment.
     * @param[in] year Year level of the assessment.
     * @return No return value.
     */
    Assessment(string assessmentsType, int motivationalCost, int successScore, int year);

    /**
     * @brief Handles the assessment when a player lands on it.
     *
     * @param[in] player Player landing on the assessment.
     * @return No return value.
     */
    void Print(shared_ptr < CPlayer > player) override;

    /**
     * @brief Gets the success score of the assessment.
     *
     * @return The success score.
     */
    int GetSuccessScore();

    /**
     * @brief Gets the year level of the assessment.
     *
     * @return The year level.
     */
    int GetYear();

    /**
     * @brief Checks if the assessment is completed.
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
     * @brief Gets the motivation cost required for the assessment.
     *
     * @return The motivation cost.
     */
    int GetMotivationCost();

    /**
     * @brief Sets the assessment as completed by a specific player.
     *
     * @param[in] player The player who completed the assessment.
     * @return No return value.
     */
    void SetComplete(shared_ptr < CPlayer > player);
};