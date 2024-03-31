#pragma once
#include <vector>
#include "CPlayer.h"
#include "CSpace.h"

/**
 * @brief Type definition for a vector of shared pointers to CSpace objects.
 */
typedef vector<shared_ptr<CSpace>> spacesVectorType;

/**
 * @brief Type definition for a vector of shared pointers to CPlayer objects.
 */
typedef vector<shared_ptr<CPlayer>> playerVectorType;
