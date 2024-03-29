#pragma once
#include <string>
using namespace std;

class Bonus {
public:
    string name;
    int motivataionGain;
    Bonus(string name, int gain) :name(name), motivataionGain(gain) {}
};