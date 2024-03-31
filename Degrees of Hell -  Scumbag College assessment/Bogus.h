#pragma once
#include <string>

using namespace std;

/**
 * @brief Bogus class represents a fictitious entity in the game.
 *
 * Detailed description if needed.
 */
class Bogus {
public: 
	string mName; /**< Name of the bogus entity. */
	int mMotivataionLoss; /**< Amount of motivation loss caused by the bogus entity. */

	  /**
	   * @brief Constructor for Bogus class.
	   *
	   * @param[in] name Name of the bogus entity.
	   * @param[in] gain Amount of motivation loss caused by the bogus entity.
	   * @return No return value.
	   */
	  Bogus(string name, int gain) : mName(name),
		  mMotivataionLoss(gain) {}
};