#pragma once
#include <string>

using namespace std;

/**
 * @brief Bonus class represents a beneficial entity in the game.
 *
 * Detailed description if needed.
 */
class Bonus {
public: 
	string mName; /**< Name of the bonus entity. */
	int mMotivataionGain; /**< Amount of motivation gain provided by the bonus entity. */

	  /**
	   * @brief Constructor for Bonus class.
	   *
	   * @param[in] name Name of the bonus entity.
	   * @param[in] gain Amount of motivation gain provided by the bonus entity.
	   * @return No return value.
	   */
	  Bonus(string name, int gain) : mName(name),
		  mMotivataionGain(gain) {}
};