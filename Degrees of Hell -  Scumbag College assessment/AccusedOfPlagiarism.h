#pragma once
#include "CSpace.h"
#include "CPlayer.h"

/**
 * @brief CAccusedOfPlagiarism class represents a space where a player is accused of plagiarism.
 *
 * Detailed description if needed.
 */
class AccusedOfPlagiarism :
    public CSpace 
{
private: 
    int mHearingSpaceIndex; /**< Index of the hearing space. */
public:
    /**
     * @brief Handles the action when a player lands on this space.
     *
     * @param[in] player Player landing on the space.
     * @return No return value.
     */
    void Print(shared_ptr < CPlayer > player) override;

    /**
     * @brief Constructor for CAccusedOfPlagiarism class.
     *
     * @param[in] name Name of the accused.
     * @return No return value.
     */
    AccusedOfPlagiarism(string name);

    /**
     * @brief Sets the index of the hearing space.
     *
     * @param[in] index Index of the hearing space.
     * @return No return value.
     */
    void SetHearingSpaceIndex(int index);
};