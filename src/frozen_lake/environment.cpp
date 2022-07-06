#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#include "../../headers/frozen_lake/environment.h"


FrozenLake::FrozenLake()
{
    observationSpace = 4;
    actionSpace = 4;
    isSlippery = false;
    transitionProbability = 33.3333;
    startingPositionOnGrid = 0;
    currentPositionOnGrid = 0;

    env = {{"s", "f", "f", "f"},
           {"f", "h", "f", "h"},
           {"f", "f", "f", "h"},
           {"h", "f", "f", "g"}};

};

bool FrozenLake::checkIfValidAction(int action) const
{
    if (action == 0)
    {
        bool result = (this->currentPositionOnGrid < 4) ? false : true;
    } else if (action == 1)
    {

    }
}

std::tuple<int, double, bool> FrozenLake::step(int action)
{
    std::cout << checkIfValidAction(action);
}

FrozenLake::~FrozenLake() = default;
