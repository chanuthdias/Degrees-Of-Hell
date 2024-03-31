#pragma once
#include <iostream>
#include <ctime>
using namespace std;

/**
 * @brief RandomNumberGenerator class provides functionality for generating random numbers.
 *
 * Detailed description if needed.
 */
class RandomNumberGenerator
{
public:
    /**
     * @brief Generates a random number.
     *
     * @return The generated random number.
     */
    static int Random();

    /**
     * @brief Sets the seed for the random number generator.
     *
     * @return No return value.
     */
    static void SetSeed();
};
