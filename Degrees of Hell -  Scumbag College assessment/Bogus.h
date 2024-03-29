#pragma once
#include <string>
using namespace std;

class Bogus {
public:
    string name;
    int motivataionLoss;
    Bogus(string name, int gain) :name(name), motivataionLoss(gain) {}
};