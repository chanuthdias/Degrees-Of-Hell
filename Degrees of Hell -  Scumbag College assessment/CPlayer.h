#pragma once
#include <iostream>
#include <string>
#include <set>
using namespace std;

/**
 * @brief CPlayer class represents a player in the game.
 *
 * Detailed description if needed.
 */
class CPlayer
{
private:
    string mName; /**< Name of the player. */
    int mMotivation; /**< Current motivation level of the player. */
    int mSuccess; /**< Current success score of the player. */
    int mPosition; /**< Current position of the player. */
    int mYear; /**< Current year level of the player. */
    typedef set<string> stringSetType; /**< Type definition for a set of strings. */
    stringSetType mAssessments[3]; /**< List of assessments completed by the player for each year. */

public:
    /**
     * @brief Constructor for CPlayer class.
     *
     * @param[in] name Name of the player.
     * @return No return value.
     */
    CPlayer(string name);

    /**
     * @brief Gets the name of the player.
     *
     * @return The name of the player.
     */
    string GetName();

    /**
     * @brief Moves the player for a given amount.
     *
     * @param[in] spin Amount to move the player.
     * @return True if movement is successful, False otherwise.
     */
    bool Move(int spin);

    /**
     * @brief Gets the current position of the player.
     *
     * @return The current position of the player.
     */
    int GetPosition();

    /**
     * @brief Sets the position of the player.
     *
     * @param[in] position The position to set.
     * @return No return value.
     */
    void SetPosition(int position);

    /**
     * @brief Gets the current year level of the player.
     *
     * @return The current year level of the player.
     */
    int GetYear();

    /**
     * @brief Gets the current motivation level of the player.
     *
     * @return The current motivation level.
     */
    int GetMotivation();

    /**
     * @brief Gets the current success score of the player.
     *
     * @return The current success score.
     */
    int GetSuccessScore();

    /**
     * @brief Updates the motivation level of the player.
     *
     * @param[in] delta Change in motivation level.
     * @return No return value.
     */
    void UpdateMotivation(int delta);

    /**
     * @brief Updates the success score of the player.
     *
     * @param[in] gamma Change in success score.
     * @return No return value.
     */
    void UpdateSuccess(int gamma);

    /**
     * @brief Adds the name of a completed assessment for the player for a given year.
     *
     * @param[in] year Year of the assessment.
     * @param[in] name Name of the assessment.
     * @return No return value.
     */
    void AddCompletedAssessment(int year, string name);
};
