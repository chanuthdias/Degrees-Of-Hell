#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class RandomNumberGenerator
{
	public:
		static int Random()
		{
			return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 10.0f + 1);
		}		
};

